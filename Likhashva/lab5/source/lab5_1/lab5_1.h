#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>


class Bor {
public:
	Bor* parent;   // ������������ ������� 
	Bor* SufLink; // ���������� ������
	Bor* EndLink;  // �������� ������
	char ToParent;	// �����, �� �������� ������ �� ������������ �������
	bool IsTerminal;  // ����������� ������� ��� ��� (����� �������)
	std::map<char, Bor*> next;  //����� �� ������� ����� ����������
	std::vector<int> NumPattern;  // ������ ��������, � ������� ������ ������, �� �������� ������
	int TermNumPattern;

	Bor(Bor* parent = nullptr, char ToPrnt = 0) : parent(parent), ToParent(ToPrnt), SufLink(nullptr), EndLink(nullptr), IsTerminal(false) {
		if (parent == nullptr || ToPrnt == 0) { // �������� �����
			this->parent = this;
			this->SufLink = this;
		}
	}

	~Bor() {
		for (auto i : this->next) {
			delete i.second;
		}
	}

	Bor* GetLink(const char& symbol) {
		if (this->next.find(symbol) != this->next.end()) { // ���� ���� ���� �� ��������� ������� �� ������� �������
			return this->next.at(symbol);
		}
		if (this->SufLink == this) { // ���� � ����� � ���� �� ������
			return this;
		}
		return this->SufLink->GetLink(symbol); // �� � ����� � ���� �� ������
	}
};


Bor* CreateBor(const std::vector<std::pair<std::string, int>>& patterns);
void Automaton(Bor* bor);
std::pair<int, int> LongestChain(Bor* bor, Bor* root, int& depth);
void AhoCorasick(const std::string& t, const std::vector<std::pair<std::string, int>>& patterns, std::vector<std::pair<int, int>>& result);