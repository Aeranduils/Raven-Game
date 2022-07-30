#pragma once
#include "Raven_Bot.h"
#include "Raven_Game.h"
#include "CData.h"
#include "CNeuralNet.h"

class LearningBot : public Raven_Bot
{
private:
	CNeuralNet m_ModeleAppris;

public:

	LearningBot(Raven_Game* world, Vector2D pos);
	~LearningBot();


	void Update();


};

