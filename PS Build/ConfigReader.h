#pragma once
#include "Core.h"

inline void ReadConfig(std::string ConfigPath , SolutionData& sln_data, std::vector<ProjectData>& prjs_data) {

	std::ifstream Config(ConfigPath);

	if (!Config.is_open()) return;

	std::string line;
	std::string section;

	std::unordered_map <std::string, std::string> SolutionInfo;
	std::vector<std::unordered_map <std::string, std::string>> ProjectInfo;

	int Prj_C = 0;

	while (std::getline(Config, line)) {

		if (line == "") {
			continue;
		}

		if (line == "Solution:") {
			section = "Solution";
			continue;
		}

		if (line == "Project:") {
			section = "Project";
			Prj_C++;
			ProjectInfo.resize(Prj_C);
			continue;
		}

		size_t pos = line.find("=");

		std::string key = line.substr(0, pos - 1);
		std::string value = line.substr(pos + 3, line.size() - pos - 4);

		if (section == "Solution") {
			SolutionInfo[key] = value;
		}
		else if (section == "Project") {
			ProjectInfo[Prj_C - 1][key] = value;
		}

	}

	Config.close();

	sln_data.Name = SolutionInfo["SolutionName"];

	prjs_data.resize(Prj_C);
	
	for (size_t i = 0; i < prjs_data.size(); i++) {
		prjs_data[i].Name = ProjectInfo[i]["ProjectName"];
	}

}