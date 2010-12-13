/*******************************************************************************
printUsage.cpp - Piramid
 
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



#include <printUsage.h>



void printUsage(void)
{
	printHeader();
	std::cerr << std::endl;
	std::cerr << "TASK:" << std::endl << std::endl;
	std::cerr << "  Piramid is a tool to align pairs of molecules based on the maximal volume overlap." << std::endl;
	std::cerr << std::endl;
	std::cerr << "REQUIRED OPTIONS: " << std::endl << std::endl;
	std::cerr << "  -r|--ref <file>" << std::endl;
	std::cerr << "           File of the reference molecule with 3D coordinates." << std::endl;
	std::cerr << "           Only the first molecule in the reference file will be used." << std::endl;
	std::cerr << "           Piramid can also handle a gzipped files if the extension is '.gz'" << std::endl;
	std::cerr << "           All input formats which are recognized by Open Babel are allowed." << std::endl;
	std::cerr << "  -d|--dbase <file>" << std::endl;
	std::cerr << "           File of the database molecules with 3D coordinates." << std::endl;
	std::cerr << "           Piramid can also handle gzipped files if the extension is '.gz'" << std::endl;
	std::cerr << "           All input formats which are recognized by Open Babel are allowed." << std::endl;
	std::cerr << std::endl;
	std::cerr << "OUTPUT OPTIONS: " << std::endl << std::endl;
	std::cerr << "           One of these two output options is required." << std::endl;
	std::cerr << "  -o|--out <file>" << std::endl;
	std::cerr << "           File to write all database or the N best molecules such that their" << std::endl;
	std::cerr << "           coordinates correspond to the best alignment with the reference molecule." << std::endl;
	std::cerr << "           The first molecule in the file is the reference molecule. When this file" << std::endl;
	std::cerr << "           if of type 'sdf', then each molecule contains a set of properties in which" << std::endl;
	std::cerr << "           the respective scores are reported. These fields are labeled with an identifier" << std::endl;
	std::cerr << "           starting with the tag Piramid::" << std::endl;
	std::cerr << "  -s|--scores <file>" << std::endl;
	std::cerr << "           Tab-delimited text file with the scores of molecules." << std::endl;
	std::cerr << "           When the N best scoring molecules are reported the molecules are ranked" << std::endl;
	std::cerr << "           with the descending scores." << std::endl;
	std::cerr << std::endl;
	std::cerr << "OPTIONAL OPTIONS: " << std::endl << std::endl;
	std::cerr << "  --best <N> " << std::endl;
	std::cerr << "           When this option is used, only the N best scoring alignments will be reported." <<  std::endl;
	std::cerr << "           The scoring function is defined by the --rankBy option." << std::endl;
	std::cerr << "           By default all molecules in the database are reported with their respective" << std::endl;
	std::cerr << "           scores without any ordering." << std::endl;
	std::cerr << "  --scoreOnly" << std::endl;
	std::cerr << "           When this option is used the molecules are not aligned, only the volume overlap" << std::endl;
	std::cerr << "           between the reference and the given pose is computed." << std::endl;
	std::cerr << "  --addIterations <nbr>" << std::endl;
	std::cerr << "           Sets the number of additional iterations in the simulated annealing optimization step." << std::endl;
	std::cerr << "           The default value is set to 0, which refers to only a local gradient ascent." << std::endl;
	std::cerr << "           Increasing the number of iterations will add additional steps, and might give better" << std::endl;
	std::cerr << "           alignments but it also takes more time." << std::endl;
	std::cerr << "  --rankBy <code>" << std::endl;
	std::cerr << "           This option can be used in combination with --best of --cutoff to rank the molecules" << std::endl;
	std::cerr << "           according to a given scoring function. The type of scoring function is indicated with" << std::endl;
	std::cerr << "           a code:" << std::endl;
	std::cerr << "             - TANIMOTO = Taninoto" << std::endl;
	std::cerr << "             - TVERSKY_REF = reference Tversky" << std::endl;
	std::cerr << "             - TVERSKY_DB = database Tversky" << std::endl;
	std::cerr << "           By default TANIMOTO is used." << std::endl;
	std::cerr << "  --cutoff <value>" << std::endl;
	std::cerr << "           Defines a cutoff value. Only molecules with a score higher than the cutoff" << std::endl;
	std::cerr << "           are reported in the results files. Default value is set to 0.0." << std::endl;
	std::cerr << "           The scoring function is defined by the --rankBy option." << std::endl;
	std::cerr << "  --noRef" << std::endl;
	std::cerr << "           By default the reference molecule is written in the output files." << std::endl;
	std::cerr << "           Use this option to switch off this behavior." << std::endl;
	std::cerr << std::endl;
	std::cerr << "HELP: " << std::endl << std::endl;
	std::cerr << "  -h|--help" << std::endl;
	std::cerr << "           Prints this help overview." << std::endl;
	std::cerr << "  -v|--version" << std::endl;
	std::cerr << "           Prints the version of the program." << std::endl;
	std::cerr << std::endl;
   return;
}
