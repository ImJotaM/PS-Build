#include "ConfigReader.h"
#include "FileMaker.h"

int main() {

	SolutionData sln;
	std::vector<ProjectData> prjs;

	ReadConfig("Config/Config.txt", sln, prjs);
	CreateSolution(sln, prjs);
	CreateProject(sln, prjs);

	return 0;
}