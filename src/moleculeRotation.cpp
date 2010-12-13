/*******************************************************************************
moleculeRotation.cpp - Piramid
 
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



#include <moleculeRotation.h>



void
positionMolecule(OpenBabel::OBMol& m, Coordinate& centroid, SiMath::Matrix& rotation)
{
   std::vector<OpenBabel::OBAtom*>::iterator i;
   for (OpenBabel::OBAtom* a = m.BeginAtom(i); a; a = m.NextAtom(i))
   {
		// Translate point
		double x = a->GetX() - centroid.x;
		double y = a->GetY() - centroid.y;
		double z = a->GetZ() - centroid.z;
		
		// Rotate according to eigenvectors SVD
      a->SetVector(rotation[0][0] * x + rotation[1][0] * y + rotation[2][0] * z,
		             rotation[0][1] * x + rotation[1][1] * y + rotation[2][1] * z,
		             rotation[0][2] * x + rotation[1][2] * y + rotation[2][2] * z);
	}
	return;
}


void
repositionMolecule(OpenBabel::OBMol& m, SiMath::Matrix& rotation, Coordinate& centroid)
{
   std::vector<OpenBabel::OBAtom*>::iterator i;
   for (OpenBabel::OBAtom* a = m.BeginAtom(i); a; a = m.NextAtom(i))
   {
		// Get coordinates
		double x = a->GetX();
		double y = a->GetY();
		double z = a->GetZ();
		
		// Rotate according to eigenvectors SVD
		double xx = rotation[0][0] * x + rotation[0][1] * y + rotation[0][2] * z;
		double yy = rotation[1][0] * x + rotation[1][1] * y + rotation[1][2] * z;
		double zz = rotation[2][0] * x + rotation[2][1] * y + rotation[2][2] * z;
		
		a->SetVector(xx + centroid.x, yy + centroid.y, zz + centroid.z);
	}
	return;
}



void 
rotateMolecule(OpenBabel::OBMol& m, SiMath::Vector& rotor)
{
	// Build rotation matrix
	SiMath::Matrix rot(3,3,0.0);
	double r1 = rotor[1] * rotor[1];
	double r2 = rotor[2] * rotor[2];
	double r3 = rotor[3] * rotor[3];
	
	rot[0][0] = 1.0 - 2.0*r2 - 2.0*r3;
	rot[0][1] = 2.0 * (rotor[1]*rotor[2] - rotor[0]*rotor[3]);
	rot[0][2] = 2.0 * (rotor[1]*rotor[3] + rotor[0]*rotor[2]);
	rot[1][0] = 2.0 * (rotor[1]*rotor[2] + rotor[0]*rotor[3]);
	rot[1][1] = 1.0 - 2*r3 - 2*r1;
	rot[1][2] = 2.0 * (rotor[2]*rotor[3] - rotor[0]*rotor[1]);
	rot[2][0] = 2.0 * (rotor[1]*rotor[3] - rotor[0]*rotor[2]);
	rot[2][1] = 2.0 * (rotor[2]*rotor[3] + rotor[0]*rotor[1]);
	rot[2][2] = 1.0 - 2*r2 - 2*r1;
	
   std::vector<OpenBabel::OBAtom*>::iterator i;
   for (OpenBabel::OBAtom* a = m.BeginAtom(i); a; a = m.NextAtom(i))
   {
		// Translate point
		double x = a->GetX();
		double y = a->GetY();
		double z = a->GetZ();
		
		// rotate according to eigenvectors SVD
		a->SetVector(rot[0][0] * x + rot[0][1] * y + rot[0][2] * z,
		             rot[1][0] * x + rot[1][1] * y + rot[1][2] * z,
		             rot[2][0] * x + rot[2][1] * y + rot[2][2] * z);
	}
	return;
}
