
// (3) Linear Cellular Automaton Evolution
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void applyRule(vector<int>& cells, int idx) {
    if (idx > 0 && idx < cells.size() - 1) {
        if (cells[idx - 1] == 1 && cells[idx + 1] == 1 && cells[idx] == 0) {
            cells[idx] = 1;
        }
    }
}

void evolveCommunity(vector<int>& initial_state, int num_steps) {
    vector<int> community = initial_state;
    int n = initial_state.size();

    for (int step = 1; step <= num_steps; step++) {
        int new_cell_idx = rand() % n;
        community[new_cell_idx] = 1;

        for (int i = 0; i < n; i++) {
            applyRule(community, i);
        }

        cout << "E" << step << ": ";
        for (int cell : community) {
            cout << "[" << cell << "]";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    vector<int> initial_state = {0, 1, 1, 0, 0, 0, 0, 0, 1, 0};
    evolveCommunity(initial_state, 3);

    return 0;
}

//Implement this in C++,by following these steps:First step: defining a function to randomly initialize the initial state of the community.Then apply the simple rule to evolve the community from one state to the next.
//After that we have to write a main function to control the evolution process and display each state.
