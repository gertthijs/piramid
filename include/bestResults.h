/*******************************************************************************
bestResults.h - Piramid
 
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



#ifndef __SILICOS_PIRAMID_BESTRESULTS_H__
#define __SILICOS_PIRAMID_BESTRESULTS_H__




// General
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

// OpenBabel

// Piramid
#include <solutionInfo.h>



class BestResults
{
   private:
   
      std::vector<SolutionInfo *>   _bestList;   ///< Local list to best N solutions
			
      double                        _lowest;     ///< lowest score in the list
      unsigned int                  _size;       ///< total number of elements to be stored in the list
      unsigned int                  _filled;     ///< number of elements stored in the list sofar
			
      class _compInfo
      {
         public:
         
				bool operator()(const SolutionInfo* a, const SolutionInfo* b)
            {
						return a->score > b->score;
            };
      };
			
   public:
      
      BestResults(unsigned int n = 100);
      ~BestResults(void);
			
      bool add(SolutionInfo& res);
			
      void writeMolecules(Options*);
      void writeScores(Options*);
};



#endif

