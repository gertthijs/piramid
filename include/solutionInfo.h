/*******************************************************************************
solutionInfo.h - Piramid
 
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



#ifndef __SILICOS_PIRAMID_SOLUTIONINFO_H__
#define __SILICOS_PIRAMID_SOLUTIONINFO_H__



// General
#include <string>
#include <iomanip>

// OpenBabel
#include <openbabel/mol.h>

// Piramid
#include <coordinate.h>
#include <siMath.h>
#include <alignmentInfo.h>
#include <gaussianVolume.h>
#include <options.h>



class SolutionInfo
{
   public:
   
      std::string       refName;
      double            refAtomVolume;
      Coordinate        refCenter;
      SiMath::Matrix    refRotation;
		
      OpenBabel::OBMol  dbMol;
      std::string       dbName;
      double            dbAtomVolume;
      Coordinate        dbCenter;
      SiMath::Matrix    dbRotation;
		
      double            atomOverlap;
      double            score;
      SiMath::Vector    rotor;
		
      SolutionInfo(void);
      ~SolutionInfo(void);
      
      void printScores(Options&); 
};



void setAllScores(SolutionInfo&);
void updateSolutionInfo(SolutionInfo&, AlignmentInfo&, double, GaussianVolume&);



#endif

