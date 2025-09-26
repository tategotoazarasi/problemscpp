//
// Created by wangzhiheng on 26/09/2025.
//
#include "comp526.h"

#include <climits>
#include <vector>

using namespace std;

namespace comp526 {
	namespace stable_matching {
		vector<int> Solution::match(vector<vector<int>> s2c, vector<vector<int>> c2s) {
			int N     = s2c.size();
			students  = vector<Student *>();
			companies = vector<Company *>();
			for(int i = 0; i < N; i++) {
				Student *stu    = new Student(i);
				stu->c_priority = unordered_map<Company *, int>();
				stu->priority_c = unordered_map<int, Company *>();
				students.emplace_back(stu);
				Company *com  = new Company(i);
				com->priority = unordered_map<Student *, int>();
				companies.emplace_back(com);
			}
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					students[i]->c_priority[companies[j]] = s2c[i][j];
					students[i]->priority_c[s2c[i][j]]    = companies[j];
					companies[i]->priority[students[j]]   = c2s[i][j];
				}
			}
			bool flag = true;
			while(flag) {
				flag = false;
				for(int i = 0; i < N; i++) {
					auto stu = students[i];
					if(stu->matched_company == nullptr) {
						flag = true;
						stu->priority_c[stu->current_priority++]->proposed_students.insert(stu);
					}
				}

				for(int i = 0; i < N; i++) {
					auto com                         = companies[i];
					Student *current_matched_student = com->matched_student;
					if(com->proposed_students.size() > 0) {
						int min_priority       = com->matched_student ? com->priority[com->matched_student] : INT_MAX;
						Student *max_p_student = com->matched_student;
						for(auto stu: com->proposed_students) {
							if(com->priority[stu] < min_priority) {
								min_priority  = com->priority[stu];
								max_p_student = stu;
								flag          = true;
							}
						}
						if(flag) {
							if(current_matched_student != nullptr) {
								current_matched_student->matched_company = nullptr;
							}
							com->matched_student           = max_p_student;
							max_p_student->matched_company = com;
						}
						com->proposed_students.clear();
					}
				}
			}
			vector<int> ans = vector<int>(N, -1);
			for(int i = 0; i < N; i++) {
				ans[i] = students[i]->matched_company->id;
			}
			return ans;
		}
	}// namespace stable_matching
}// namespace comp526
