//
// Created by tategotoazarasi on 24-5-7.
//

#include "acwing408.h"
#include "templates.h"
#include <algorithm>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

namespace acwing {
	namespace acwing3378 {
		int main(istream &cin, ostream &cout) {
			int n;
			int rule;
			cin >> n >> rule;
			unordered_map<student *, unsigned> index;
			vector<student *> students(n);
			for(int i = 0; i < n; i++) {
				students[i] = new student();
				cin >> students[i]->name >> students[i]->score;
				if(index.find(students[i]) == index.end())
					index[students[i]] = i;
			}
			sort(students.begin(), students.end(), [rule, &index](student *a, student *b) {
				if(a->score == b->score) {
					return index[a] < index[b];
				}
				if(rule == 0) {
					return a->score > b->score;
				} else {
					return a->score < b->score;
				}
			});
			for(const auto &s: students) {
				cout << s->name << ' ' << s->score << endl;
			}
			return 0;
		}
	}// namespace acwing3378

	namespace acwing3376 {
		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			vector<student> students(n);
			for(int i = 0; i < n; i++) {
				cin >> students[i].id >> students[i].score;
				students[i].id_numeric = stoi(students[i].id);
			}
			sort(students.begin(), students.end(), [](const student &a, const student &b) {
				if(a.score == b.score) {
					return a.id_numeric < b.id_numeric;
				}
				return a.score < b.score;
			});
			for(const auto &s: students) {
				cout << s.id << ' ' << s.score << endl;
			}
			return 0;
		}
	}// namespace acwing3376

	namespace acwing3374 {
		int main(istream &cin, ostream &cout) {
			int m, n;
			string x;
			cin >> m >> n >> x;
			if(x == "0") {
				cout << "0";
				return 0;
			}
			vector<unsigned short> input   = vector<unsigned short>();
			vector<unsigned short> ans     = vector<unsigned short>();
			queue<unsigned short> quotient = queue<unsigned short>();
			for(auto i = x.begin(); i != x.end(); i++) {
				if(isdigit(*i)) {
					input.push_back(*i - '0');
				} else if(isupper(*i)) {
					input.push_back(*i - 'A' + 10);
				}
			}
			do {
				unsigned int current = 0;
				quotient             = queue<unsigned short>();
				for(auto i = input.begin(); i != input.end(); i++) {
					current *= m;
					current += *i;
					quotient.push(current / n);
					current %= n;
				}
				while(!quotient.empty() && quotient.front() == 0) {
					quotient.pop();
				}
				ans.push_back(current);
				input = vector<unsigned short>(quotient.size());
				for(unsigned int i = 0; i < input.size(); i++) {
					input[i] = quotient.front();
					quotient.pop();
				}
			} while(!input.empty());
			for(auto i = ans.rbegin(); i != ans.rend(); i++) {
				if(*i < 10) {
					cout << *i;
				} else {
					cout << (char) (*i - 10 + 'a');
				}
			}
			return 0;
		}
	}// namespace acwing3374

	namespace acwing3757 {
		void rearrangedList(struct ListNode *head) {
			if(head == NULL || head->next == NULL)
				return;
			int len = 0;
			for(struct ListNode *p = head; p != NULL; p = p->next)
				len++;
			int mid            = (len + 1) / 2;
			struct ListNode *a = head;
			for(int i = 0; i < mid - 1; i++) {
				a = a->next;
			}
			struct ListNode *b = a->next;
			struct ListNode *c = b->next;
			a->next            = NULL;
			b->next            = NULL;
			while(c) {
				struct ListNode *tmp = c->next;
				c->next              = b;
				b                    = c;
				c                    = tmp;
			}
			struct ListNode *p = head;
			struct ListNode *q = b;
			while(q) {
				auto qq = q->next;
				// 插入结点
				q->next = p->next;
				p->next = q;
				// 移动p和q
				p = q->next;
				q = qq;
			}
		}
	}// namespace acwing3757
}// namespace acwing