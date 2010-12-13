/*******************************************************************************
shapeAlignment.h - Piramid
 
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



#ifndef __SILICOS_PIRAMID_SHAPEALIGNMENT_H__
#define __SILICOS_PIRAMID_SHAPEALIGNMENT_H__



// General
#include <queue>
#include <vector>

// OpenBabel

// Piramid
#include <gaussianVolume.h>
#include <atomGaussian.h>
#include <alignmentInfo.h>
#include <siMath.h>



typedef std::map<unsigned int, double *> MatrixMap;
typedef std::map<unsigned int, double *>::iterator MatIter;
	
   
   
class ShapeAlignment 
{
   private:
      
      GaussianVolume * _gRef;
      GaussianVolume * _gDb;
				
      unsigned int _rAtoms;
      unsigned int _rGauss;
      unsigned int _dAtoms;
      unsigned int _dGauss;
      unsigned int _maxSize;
      unsigned int _maxIter;
			
      MatrixMap _matrixMap;
		
      double* _updateMatrixMap(AtomGaussian&, AtomGaussian&);
			
   public:
      
      ShapeAlignment(GaussianVolume&, GaussianVolume&);
      ~ShapeAlignment(void);
			
      AlignmentInfo gradientAscent(SiMath::Vector);
      AlignmentInfo simulatedAnnealing(SiMath::Vector);
			
      void setMaxIterations(unsigned int);
};


#endif
