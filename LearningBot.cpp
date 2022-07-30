#include "LearningBot.h"
#include "misc/Cgdi.h"
#include "misc/utils.h"
#include "2D/Transformations.h"
#include "2D/Geometry.h"
#include "lua/Raven_Scriptor.h"
#include "Raven_Game.h"
#include "navigation/Raven_PathPlanner.h"
#include "Raven_SteeringBehaviors.h"
#include "Raven_UserOptions.h"
#include "time/Regulator.h"
#include "Raven_WeaponSystem.h"
#include "Raven_SensoryMemory.h"

#include "Messaging/Telegram.h"
#include "Raven_Messages.h"
#include "Messaging/MessageDispatcher.h"

#include "goals/Raven_Goal_Types.h"
#include "goals/Goal_Think.h"


#include "Debug/DebugConsole.h"

LearningBot::LearningBot(Raven_Game* world, Vector2D pos) : Raven_Bot(world, pos) {
	m_ModeleAppris = world->getModeleApprentissage();

}

LearningBot::~LearningBot()
{
	debug_con << "deleting learning bot (id = " << ID() << ")" << "";

	delete m_pBrain;
	delete m_pPathPlanner;
	delete m_pSteering;
	delete m_pWeaponSelectionRegulator;
	delete m_pTargSys;
	delete m_pGoalArbitrationRegulator;
	delete m_pTargetSelectionRegulator;
	delete m_pTriggerTestRegulator;
	delete m_pVisionUpdateRegulator;
	delete m_pWeaponSys;
	delete m_pSensoryMem;
}


//-------------------------------- Update -------------------------------------
//
void LearningBot::Update()
{
	//process the currently active goal. Note this is required even if the bot
	//is under user control. This is because a goal is created whenever a user 
	//clicks on an area of the map that necessitates a path planning request.
	m_pBrain->Process();

	//Calculate the steering force and update the bot's velocity and position
	UpdateMovement();

	//add one frame to TimeSinceTargetSeen
	//AddOneFrameToTargetSeen();

	//if the bot is under AI control but not scripted
	if (!isPossessed())
	{
		//examine all the opponents in the bots sensory memory and select one
		//to be the current target
		if (m_pTargetSelectionRegulator->isReady())
		{
			m_pTargSys->Update();
		}

		//appraise and arbitrate between all possible high level goals
		if (m_pGoalArbitrationRegulator->isReady())
		{
			m_pBrain->Arbitrate();
		}

		//update the sensory memory with any visual stimulus
		if (m_pVisionUpdateRegulator->isReady())
		{
			m_pSensoryMem->UpdateVision();
		}

		//select the appropriate weapon to use from the weapons currently in
		//the inventory
		if (m_pWeaponSelectionRegulator->isReady())
		{
			m_pWeaponSys->SelectWeapon();
		}

		//this method aims the bot's current weapon at the current target
		//and takes a shot if a shot is possible

		if (m_pTargSys->isTargetPresent()) {

			m_vecObservation.clear();

			m_vecObservation.push_back((Pos().Distance(m_pTargSys->GetTarget()->Pos())));
			m_vecObservation.push_back(m_pTargSys->isTargetWithinFOV());
			m_vecObservation.push_back(m_pWeaponSys->GetAmmoRemainingForWeapon(m_pWeaponSys->GetCurrentWeapon()->GetType()));
			m_vecObservation.push_back(m_pWeaponSys->GetCurrentWeapon()->GetType());
			m_vecObservation.push_back((Health()));


			std::vector<double> output = m_ModeleAppris.Update(m_vecObservation);

			bool canShoot = false;

			if (output.size() > 0)
				canShoot = output[0];

			if (canShoot)
				m_pWeaponSys->TakeAimAndShoot();

		}
	}
}


