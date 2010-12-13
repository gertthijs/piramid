/*******************************************************************************
options.cpp - Piramid
 
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



#include <options.h>

      

Options::Options(void)
{
   refInpFile = "";
   refInpStream = NULL;
   refInpReader = NULL;

   dbInpFile = "";
   dbInpStream = NULL;
	dbInpReader = NULL;
   
   molOutFile = "";
   molOutStream = NULL;
   molOutWriter = NULL;

   scoreOutFile = "";
   scoreOutStream = NULL;

   bestHits = 0;
   cutOff = 0.0;
   maxIter = 0;
   
   whichScore = tanimoto;
   
   scoreOnly = false;
   showRef = true;
   
   version = false;
   help = false;
}




Options::~Options(void)
{
   // reference input
   if (!refInpFile.empty())
   {
      refInpFile = "";
   };
   if (refInpStream)
   {
      delete refInpStream;
      refInpStream = NULL;
   };
   if (refInpReader)
   {
      delete refInpReader;
      refInpReader = NULL;
   };


   // Database input
   if (!dbInpFile.empty())
   {
      dbInpFile = "";
   };
   if (dbInpStream)
   {
      delete dbInpStream;
      dbInpStream = NULL;
   };
   if (dbInpReader)
   {
      delete dbInpReader;
      dbInpReader = NULL;
   };


   // Molecule output
   if (!molOutFile.empty())
   {
      molOutFile = "";
   };
   if (molOutStream)
   {
      delete molOutStream;
      molOutStream = NULL;
   };
   if (molOutWriter)
   {
      delete molOutWriter;
      molOutWriter = NULL;
   };
   
   
   // Score output
   if (!scoreOutFile.empty())
   {
      scoreOutFile = "";
   };
   if (scoreOutStream)
   {
      delete scoreOutStream;
      scoreOutStream = NULL;
   };
}



std::string
Options::print(void) const
{
   std::ostringstream os;
   os << std::endl;
   os << "COMMAND_LINE OPTIONS:" << std::endl;
   os << std::endl;
   os << "  -> Reference file:    " << refInpFile << std::endl;
   os << "  -> Database file:     " << dbInpFile << std::endl;
   os << "  -> Output file:       " << (molOutFile.empty() ? "no" : molOutFile) << std::endl;
   os << "  -> Scores file:       " << (scoreOutFile.empty() ? "no" : scoreOutFile) << std::endl;
   os << "  -> Best hits:         ";
   if (bestHits)
   {
      os << bestHits << std::endl;
   }
   else
   {
      os << "no" << std::endl;
   }
   os << "  -> Scoring only:      " << (scoreOnly ? "yes" : "no") << std::endl;
   os << "  -> Extra iterations:  ";
   if (maxIter)
   {
      os << maxIter << std::endl;
   }
   else
   {
      os << "no" << std::endl;
   }
   os << "  -> Rank by:           " << whichScore << std::endl;
   os << "  -> Cutoff:            ";
   if (cutOff)
   {
      os << cutOff << std::endl;
   }
   else
   {
      os << "no" << std::endl;
   }
   os << "  -> Output reference   " << (showRef ? "yes" : "no") << std::endl;
   
   os << std::endl;   
   std::string r = os.str();
   return r;
}
