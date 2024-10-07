#pragma once
#include "Core.h"
#include "GUIDSys.h"
#include "SolutionRules.h"

inline void CreateSolution(SolutionData& sln_data, std::vector<ProjectData>& prjs_data) {

	std::string SolutionName = sln_data.Name;
	sln_data.Guid = GuidSys::GenerateGuid();

	for (ProjectData& prj_data : prjs_data) {
		std::string ProjectName = prj_data.Name;
		prj_data.Guid = GuidSys::GenerateGuid();
	}

	std::filesystem::create_directories(SolutionName);

	std::ofstream SlnFile(SolutionName + "/" + SolutionName + ".sln");
	if (!SlnFile.is_open()) return;

	SlnRule::AddHeader(SlnFile);

	for (ProjectData& prj_data : prjs_data)
		SlnRule::AddProject(SlnFile, sln_data, prj_data);

	SlnFile.close();
}

inline void CreateProject(SolutionData& sln_data, std::vector<ProjectData>& prjs_data) {

	std::string SolutionName = sln_data.Name;

	for (ProjectData prj_data : prjs_data) {

		std::string ProjectName = prj_data.Name;
		std::string ProjectDir = SolutionName + "/" + ProjectName;

		std::filesystem::create_directories(ProjectDir);

		std::ofstream PrjFile(ProjectDir + "/" + ProjectName + ".vcxproj");
		if (!PrjFile.is_open()) return;

		PrjFile << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
		PrjFile << "<Project DefaultTargets=\"Build\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">\n";
		PrjFile << "  <ItemGroup Label=\"ProjectConfigurations\">\n";
		PrjFile << "    <ProjectConfiguration Include=\"Debug|x64\">\n";
		PrjFile << "      <Configuration>Debug</Configuration>\n";
		PrjFile << "      <Platform>x64</Platform>\n";
		PrjFile << "    </ProjectConfiguration>\n";
		PrjFile << "  </ItemGroup>\n";
		PrjFile << "</Project>\n";

		PrjFile.close();

	}
}