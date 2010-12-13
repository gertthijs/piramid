/*******************************************************************************
options.h - Piramid
 
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



#ifndef __SILICOS_PIRAMID_OPTIONS_H__
#define __SILICOS_PIRAMID_OPTIONS_H__



// General
#include <string>
#include <iostream>
#include <fstream>

// OpenBabel
#include <openbabel/obconversion.h>

// Piramid
const std::string tanimoto = "Piramid::Tanimoto"; 
const std::string tversky_ref = "Piramid::Tversky_Ref"; 
const std::string tversky_db = "Piramid::Tversky_Db"; 



class Options
{
   public:
   
      std::string             refInpFile;       //  -r  --reference
      std::ifstream*          refInpStream;
      OpenBabel::OBConversion* refInpReader;
      
      std::string             dbInpFile;        //  -d  --dbase
      std::ifstream*          dbInpStream;
      OpenBabel::OBConversion* dbInpReader;
      
      std::string             molOutFile;       //  -o  --out
      std::ofstream*          molOutStream;
      OpenBabel::OBConversion* molOutWriter;
      
      std::string             scoreOutFile;     //  -s  --score
      std::ofstream*          scoreOutStream;
      
      unsigned int            bestHits;         //      --best
      double                  cutOff;           //      --cutOff
      double                  maxIter;          //      --maxIterations
  
      std::string             whichScore;       //      --rankBy
      
      bool                    scoreOnly;        //      --scoreOnly
      bool                    showRef;          //      --noRef
  
      bool                    version;          //  -v  --version
      bool                    help;             //  -h  --help
   
      Options(void);
      ~Options(void);
      
      std::string print(void) const;
};



#endif __SILICOS_PIRAMID_OPTIONS_H__
