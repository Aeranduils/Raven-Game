#ifndef GOAL_DO_A_360_H
#define GOAL_DO_A_360_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   Goal_Do_a_360.h
//
//  Author: moi 
//
//  Desc:   this goal makes the bot rotate 360
//
//-----------------------------------------------------------------------------
#include "Goals/Goal.h"
#include "../Raven_Bot.h"





class Goal_Do_a_360 : public Goal<Raven_Bot>
{
private:


public:

    Goal_Do_a_360(Raven_Bot* pBot);

    void Activate();

    int  Process();

    void Render();

    void Terminate();

};






#endif
