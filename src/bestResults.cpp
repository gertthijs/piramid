/*******************************************************************************
bestResults.cpp - Piramid
 
Copyright (C) 2005-2010 by Silicos NV
 
This file is part of the Open Babel project.
For more information, see <http://openbabel.sourceforge.net/>
 
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*******************************************************************************/



#include <bestResults.h>



BestResults::BestResults(unsigned int n)
{
   _bestList.clear();
   _size = n;
   _lowest = 0.0;
   _filled = 0;
}



BestResults::~BestResults(void)
{
	std::vector<SolutionInfo*>::iterator it;
	for (it = _bestList.begin(); it != _bestList.end(); ++it)
	{
		if (*it != NULL)
      {
			delete *it;
         *it = NULL;
		}
	}
}



bool
BestResults::add(SolutionInfo& res)
{
	std::vector<SolutionInfo* >::reverse_iterator it;
	if (_filled < _size)
	{
		SolutionInfo* i = new SolutionInfo(res);
		_bestList.push_back(i);
		++_filled;
	}
	else if (res.score < _lowest)
	{
		return false;
	}
	else
	{
		// delete last element
		it = _bestList.rbegin();
		if (*it != NULL)
      {
			delete *it;
         *it = NULL;
      }
		
		// make new info element in the list
		*it = new SolutionInfo(res);
	}
		
	std::sort(_bestList.begin(), _bestList.end(), BestResults::_compInfo());
	it = _bestList.rbegin();
	_lowest = (*it)->score;
	
	return true;
}



void
BestResults::writeMolecules(Options* uo)
{
	if (uo->molOutWriter == NULL)
   {
		return;
   }
	
	std::vector<SolutionInfo* >::iterator it;
	for (it = _bestList.begin(); it != _bestList.end(); ++it)
	{
		if (*it != NULL)
      {
			uo->molOutWriter->Write(&((*it)->dbMol), uo->molOutStream);
      }
	}
	return;
}



void
BestResults::writeScores(Options* uo)
{
   if (uo->scoreOutStream == NULL)
   {
      return;
   }
   
   std::vector<std::string> score(3);
	std::vector<SolutionInfo* >::iterator it;
	for (it = _bestList.begin(); it != _bestList.end(); ++it)
	{
		if (*it != NULL)
		{
         (*it)->printScores(*uo);
      }
	}
	return;
}
