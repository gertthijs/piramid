/*******************************************************************************
atomGaussian.cpp - Piramid
 
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



#include <atomGaussian.h>



AtomGaussian::AtomGaussian(void) 
: center(0.0, 0.0, 0.0)
, alpha(0.0)
, volume(0.0)
, C(0.0)
, nbr(0)
{
}



AtomGaussian::~AtomGaussian(void) 
{
}



AtomGaussian 
atomIntersection(AtomGaussian& a, AtomGaussian& b)
{
	AtomGaussian c;
	
	// new alpha 
	c.alpha = a.alpha + b.alpha;
	
	// new center
	c.center.x = (a.alpha * a.center.x + b.alpha * b.center.x)/c.alpha; 
	c.center.y = (a.alpha * a.center.y + b.alpha * b.center.y)/c.alpha; 
	c.center.z = (a.alpha * a.center.z + b.alpha * b.center.z)/c.alpha; 
		
	// self-volume 
	double d = (a.center.x - b.center.x)*(a.center.x - b.center.x)
            + (a.center.y - b.center.y)*(a.center.y - b.center.y)
		      + (a.center.z - b.center.z)*(a.center.z - b.center.z);
	
	c.C = a.C * b.C * exp(- a.alpha * b.alpha/c.alpha * d);
	
	double scale = PI/(c.alpha);
	
	c.volume = c.C * scale * sqrt(scale);
	
	// set the number of gaussians 
	c.nbr = a.nbr + b.nbr;
	
	return c;
}
