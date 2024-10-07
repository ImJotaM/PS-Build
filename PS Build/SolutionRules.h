#pragma once
#include "Core.h"

namespace SlnRule {

	inline void AddHeader(std::ofstream& SlnFile) {

		SlnFile << "Microsoft Visual Studio Solution File, Format Version 12.00" << std::endl;
		SlnFile << "# Visual Studio Version 17" << std::endl;

	}

	inline void AddProject(std::ofstream& SlnFile, SolutionData& sln_data, ProjectData& prj_data) {

		std::string SolutionName = sln_data.Name;
		std::string SolutionGuid = sln_data.Guid;

		std::string ProjectName = prj_data.Name;
		std::string ProjectGuid = prj_data.Guid;
		std::cout << prj_data.Guid << std::endl;

		SlnFile << "Project(\"" << SolutionGuid << "\") = \"" << ProjectName << "\", \"" << ProjectName << "\\" << ProjectName << ".vcxproj\", \"" << ProjectGuid << "\"" << std::endl;
		SlnFile << "EndProject" << std::endl;

	}

}