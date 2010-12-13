/*******************************************************************************
atomGaussian.h - Piramid
 
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



#ifndef __SILICOS_PIRAMID_ATOMGAUSSIAN_H__
#define __SILICOS_PIRAMID_ATOMGAUSSIAN_H__



// General
#include <math.h>

// OpenBabel

// Piramid
#include <coordinate.h>
#include <siMath.h>



class AtomGaussian
{
   public:
   
		Coordinate center;         ///< center of the gaussian
		double alpha;              ///< alpha parameter of the gaussian representation
		double volume;             ///< self-volume of the gaussian
		double C;                  ///< constant from gaussian g(r) = C.exp(-alpha(center -r )^2)
		unsigned int nbr;          ///< nbr of atoms that make up this overlap

      AtomGaussian(void);
      ~AtomGaussian(void);
};



AtomGaussian atomIntersection(AtomGaussian&, AtomGaussian&);



#endif
