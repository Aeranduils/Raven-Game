#include "Goal_Do_a_360.h"
#include "../Raven_Bot.h"
#include "../Raven_SteeringBehaviors.h"
#include "../Raven_Game.h"

#include "Messaging/Telegram.h"
#include "../Raven_Messages.h"

#include "debug/DebugConsole.h"
#include "misc/cgdi.H"


//------------------------------- Activate ------------------------------------
//-----------------------------------------------------------------------------
void Goal_Do_a_360::Activate()
{
    Vector2D x;
    x = { 0,0 };
    m_iStatus = active;

    m_pOwner->GetSteering()->SeekOn();

    while (x != (Vector2D{ 1, 1 })) {

        m_pOwner->RotateFacingTowardPosition(x);
        x = x + Vector2D{ 1,1 };
    }
    m_iStatus = inactive;
    debug_con << "slt" << "";
}



//-------------------------- Process ------------------------------------------
//-----------------------------------------------------------------------------
int Goal_Do_a_360::Process()
{
    //if status is inactive, call Activate()
    ActivateIfInactive();

    return completed;
}

//---------------------------- Terminate --------------------------------------
//-----------------------------------------------------------------------------
void Goal_Do_a_360::Terminate()
{
    m_pOwner->GetSteering()->SeekOff();
}

//---------------------------- Render -----------------------------------------

void Goal_Do_a_360::Render()
{
    //#define SHOW_TARGET
#ifdef SHOW_TARGET
    gdi->OrangePen();
    gdi->HollowBrush();

    gdi->Line(m_pOwner->Pos(), m_vStrafeTarget);
    gdi->Circle(m_vStrafeTarget, 3);
#endif

}



