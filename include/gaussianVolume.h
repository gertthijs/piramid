/*******************************************************************************
gaussianVolume.h - Piramid
 
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



#ifndef __SILICOS_PIRAMID_GAUSSIANVOLUME_H__
#define __SILICOS_PIRAMID_GAUSSIANVOLUME_H__



// General
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>

// OpenBabel
#include <openbabel/mol.h>
#include <openbabel/atom.h>

// Piramid
#include <siMath.h>
#include <coordinate.h>
#include <atomGaussian.h>
#include <alignmentInfo.h>
#include <options.h>



const double GCI = 2.828427125;
const double GLI = 1.480960979;
const double VCUTOFF = 2.0;
const unsigned int LEVEL = 6;
const double EPS = 0.03;
const double GRADSCALE = 0.9;
const double PENALTY = 5.00;	



class GaussianVolume
{
   public:
   
		double                     volume;       ///< Molecular volume
		double                     overlap;      ///< Self-overlap of the molecule
		Coordinate                 centroid;     ///< center of the gaussian volume
		SiMath::Matrix					rotation;     ///< rotation matrix to align molecule to principal axes
		std::vector<AtomGaussian>  gaussians;    ///< vector of all atom gaussians and their overlaps
		std::vector<std::vector<unsigned int> * > childOverlaps;   ///< vector to keep track of which overlaps are formed with one gaussian
		std::vector<unsigned int>  levels;                         ///< indicates where in the vector the level of overlaps changes
			
		GaussianVolume(void);
      ~GaussianVolume(void);
};



void listAtomVolumes(OpenBabel::OBMol& mol, GaussianVolume& gv);
void initOrientation(GaussianVolume&);
double atomOverlap(GaussianVolume&, GaussianVolume&);
double GAlpha(unsigned int); 
double getScore(std::string&, double, double, double);
void checkVolumes(GaussianVolume&, GaussianVolume&, AlignmentInfo&);



#endif

