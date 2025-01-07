/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> employeeMap;

    // DFS helper function
    int dfs(int id) {
        auto employee = employeeMap[id];
        int totalImportance = employee->importance;

        for (int subId : employee->subordinates) {
            totalImportance += dfs(subId); // Recursive call for subordinates
        }

        return totalImportance;
    }

    int getImportance(vector<Employee*> employees, int id) {
        // Map employees by ID for quick access
        for (auto emp : employees) {
            employeeMap[emp->id] = emp;
        }

        return dfs(id); // Start DFS from the given employee ID
    }
};