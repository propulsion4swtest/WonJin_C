
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int dir[8][2] = {
	{0, 1}, {1, 1},
	{1, 0},
	{1, -1},
	{0, -1},
	{-1, -1},
	{-1, 0},
	{-1, 1}
};

class Forest	{
	private:
	vector<vector<multiset<int> > > tree;
	vector<vector<int> > supply;
	vector<vector<int> > add_supply;

	set<pair<int, int> > hasTree;
	multiset<pair<int, int> > ext;
	
	int N, M, K;

	public:
	Forest(): N(0), M(0), K(0)	{}
	~Forest()	{
		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				tree[i][j].clear();
			}
			tree[i].clear();
		}
		tree.clear();

		for (int n = 0; n < N; n++)	{
			add_supply[n].clear();
			supply[n].clear();
		}
		supply.clear();
		add_supply.clear();

		N = M = K = 0;
	}
	
	void input()	{
		cin >> N >> M >> K;
		tree.resize(N);
		supply.resize(N);
		add_supply.resize(N);
		int sup;
		int r, c, age;

		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				cin >> sup;
				add_supply[i].push_back(sup);
				supply[i].push_back(5);
			}
			tree[i].resize(N);
		}

		for (int i = 0; i < M; i++)	{
			cin >> r >> c >> age;
			tree[r - 1][c - 1].insert(age);
			hasTree.insert({r - 1, c - 1});
		}
	}

	void spring_summer()	{
		int age;
		int *remain;
		bool flag;
		vector<int> tmp;
		set<pair<int, int> > t_hasTree;
		for (auto &p : hasTree)	{
			remain = &supply[p.first][p.second];
			flag = false;
			tmp.clear();
			for (auto a = tree[p.first][p.second].begin(); a != tree[p.first][p.second].end(); a++)	{
				if (*remain - *a < 0)	flag = true;
				if (flag)	{
					*remain += (*a / 2);
					tree[p.first][p.second].erase(*a);
				}
				else	{
					*remain -= *a;
					tmp.push_back((*a) + 1);
					tree[p.first][p.second].erase(*a);
				}
			}
			for (int i = 0; i < tmp.size(); i++)	{
				tree[p.first][p.second].insert(tmp[i]);
				if (tmp[i] % 5 == 0)	{
					ext.insert(p);
				}
			}
			if (!tree[p.first][p.second].empty())	t_hasTree.insert(p);
		}
		hasTree = t_hasTree;
	}

	void fall()	{
		for (auto &p : ext)	{
			for (int d = 0; d < 8; d++)	{
				int pr = p.first + dir[d][0];
				int pc = p.second + dir[d][1];
				if (pr < N && pc < N && pr >= 0 && pc >= 0)	{
					tree[pr][pc].insert(1);
					hasTree.insert({pr, pc});
				}
			}
		}
		ext.clear();
	}

	void winter()	{
		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				supply[i][j] += add_supply[i][j];
			}
		}
	}
	
	int getK()	{return K;}
	int getTree()	{
		int sum = 0;
		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				sum += tree[i][j].size();
			}
		}
		return sum;
	}

	void printTree()	{
		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				printf("{ ");
				for (auto &t : tree[i][j])	{
					printf("%d, ", t);
				}
				printf("}   ");
			}
			printf("\n");
		}
	}

	void printSupply()	{
		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				printf("[%d]  ", supply[i][j]);
			}
			puts("");
		}
	}
};

int main(void)	{
	ios::sync_with_stdio(false);

	
	Forest F;
	F.input();

	//puts("[INITIAL STATE]");
	//F.printTree();

	for (int k = 0; k < F.getK(); k++)	{
	//	puts("[SPRING_SUMMER]");
		F.spring_summer();
	//	F.printTree();
	//	puts("");
	//	puts("[SUPPLY]");
	//	F.printSupply();
	//	puts("");
	//	puts("[FALL]");
		F.fall();
	//	F.printTree();
	//	puts("");
	//	puts("[WINTER]");
		F.winter();
	//	F.printTree();
	//	puts("");
	//	puts("[SUPPLY]");
	//	F.printSupply();
	//	puts("");
	}
	cout << F.getTree() << endl;

	return 0;
}
