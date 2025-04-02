#include <iostream>
#include <vector>
#include <queue>

void printGraph(const std::vector<std::vector<int>>& graph) {
	std::cout << "структура графа (список смежности):\n";
	for (int i = 0; i < graph.size(); i++) {
		std::cout << "вершина " << i << " связана с: ";
		for (int neighbor : graph[i]) {
			std::cout << neighbor << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void bfs(const std::vector<std::vector<int>>& graph, int start) {
	std::cout << "начинаем обход BFS от вершины " << start << ":\n";

	std::queue<int> q;
	std::vector<bool> visited(graph.size(), false);

	q.push(start);
	visited[start] = true;

	int step = 1;
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		std::cout << "шаг " << step++ << ": посещаем вершину " << current << "\n";
		std::cout << "  очередь: ";
		std::queue<int> temp_q = q;
		while (!temp_q.empty()) {
			std::cout << temp_q.front() << " ";
			temp_q.pop();
		}
		std::cout << "\n";

		std::cout << "  добавляем в очередь соседей: ";
		for (int neighbor : graph[current]) {
			if (!visited[neighbor]) {
				std::cout << neighbor << " ";
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
		std::cout << "\n\n";
	}

	std::cout << "обход завершен!\n";
}

int main() {
	setlocale(LC_ALL, "Ru");
	// Неориентированный граф
	std::vector<std::vector<int>> graph = {
		{1, 2},  // 0 связан с 1 и 2
		{0, 3},  // 1 связан с 0 и 3
		{0, 4},  // 2 связан с 0 и 4
		{1},     // 3 связан с 1
		{2}      // 4 связан с 2
	};

	printGraph(graph);
	bfs(graph, 0);

	return 0;
}
