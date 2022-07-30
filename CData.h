#ifndef DATA_H
#define DATA_H

//turn off the warnings for the STL
#pragma warning (disable : 4786)

//------------------------------------------------------------------------
//
//	Name: CData.h
//
//  Author: Mat Buckland 2002
//
//  Desc: class to manipulate the gesture data for the RecognizeIt mouse
//        gesture recognition code project
//-------------------------------------------------------------------------

#include <vector>
#include <iomanip>
#include <windows.h>


#include "misc/utils.h"

using namespace std;



//------------------------------------------------------------------------
//
//  class to handle the training data
//------------------------------------------------------------------------
class CData
{
private:

	int nb_input;  // nombre de variables ou attributs qui caract�risent une observation ou une situation de tir
	int nb_target; // nombre de tagert � � consid�rer. Par d�faut. c'est toujours 1.

  // Input & Output Vector
	vector<vector<double> > m_vecInputs;
	vector<vector<double> > m_vecTargets;

public:

	CData()
	{
		nb_input = 0;
		nb_target = 0;

		m_vecInputs = vector< vector<double> >(0);
		m_vecTargets = vector< vector<double> >(0);
	}
	CData(int inputs, int targets)
	{
		nb_input = inputs;
		nb_target = targets;

		m_vecInputs = vector< vector<double> >(0);
		m_vecTargets = vector< vector<double> >(0);
	}

	// Add new data
	void    AddData(vector<double>& data, vector<double>& targets);


	vector<vector<double> > GetInputSet() { return m_vecInputs; }
	vector<vector<double> > GetOutputSet() { return m_vecTargets; }
	int GetInputNb() { return nb_input; }
	int GetTargetsNb() { return nb_target; }
	double GetNbShooting();
};

#endif
