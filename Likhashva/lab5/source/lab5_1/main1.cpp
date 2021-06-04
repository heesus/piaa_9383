#include "lab5_1.h"

int main() {
	setlocale(LC_ALL, "Russian");
	std::string T;
	std::vector<std::pair<std::string, int>> patterns;
	std::vector<std::pair<int, int>> result;
	int n = 0;

	std::cout << "������� ����� � ����� n:\n";
	std::cin >> T;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cout << "������� ������:\n";
		std::string s;
		std::cin >> s;
		patterns.push_back({ s, 0 });
	}
	AhoCorasick(T, patterns, result);
	sort(result.begin(), result.end());

	std::cout << "\n_���������� ������_\n";
	std::cout << "������ ��������� � ������ � ���������� ����� �������:\n";
	for (auto i : result) {
		std::cout << i.first;
		std::cout << ' ' << i.second << '\n';
	}
	return 0;
}