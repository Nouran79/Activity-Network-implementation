#include <iostream>
#include <String>
#include <list>
#include <unordered_map>
#include <iterator>
#include <queue>
#include <stack>
using namespace std;

struct stageInfo {
	char SName='*';
	int earlyStart=0;
	int earlyFinish=0;
	int lastStart = 0;
	int lastFinish = 0;
	int duration;
	int noDepend = 0;
	char depend[10];
};
//
//stageInfo independent[100];
//stageInfo dependent[100];
unordered_map<char, stageInfo> totalDepStages;
unordered_map<char, stageInfo> totalIndepStages;
unordered_map<char, stageInfo> activityNetwork;
int main() {

	stageInfo Stage;
	int noOfStages = 0;
	int Dcount = 0, InDcount = 0;
	cin >> noOfStages;
	for (int i = 0; i < noOfStages; i++) {
		cin >> Stage.SName;
		cin >> Stage.duration;
		cin >> Stage.noDepend;
		for (int j = 0; j < Stage.noDepend; j++) {
			cin >> Stage.depend[j];
		}
		if (Stage.noDepend == 0) {
			Stage.earlyStart = 0;
			Stage.earlyFinish = Stage.duration + Stage.earlyStart;
			totalIndepStages[Stage.SName] = Stage;
			InDcount++;
		}
		else {
			totalDepStages[Stage.SName] = Stage;
			Dcount++;
		}
	}
	for (auto it = totalDepStages.begin(); it != totalDepStages.end(); ++it) {
		int max = 0;
		for (const auto& d : it->second.depend) {
		if(totalIndepStages[d].SName!='*') {
			if (totalIndepStages[d].duration > max) max = totalIndepStages[d].duration;
		}
		}
	}

	/*int max = 0;
	for (const auto& s : dependent) {
		
		for (const auto& d : s.depend) {
			if (findDep(d) > max) max = findDep(d);
		}
	}*/

	return 0;
}
//int findDep(char d) {
//	for (const auto& s : dependent) {
//		if (d == s.name) return s.duration;
//	}
//	for (const auto& s : independent) {
//		if (d == s.name) return s.duration;
//	}
//}