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
private:
void _getImportance(vector<Employee*> employees, int id, int& sum)
{
    if (employees.size() == 0)
        return;
        
    for (Employee* e : employees)
        if (e->id == id)
        {
            sum += e->importance;
            for (int x : e->subordinates)
                _getImportance(employees, x, sum);
            break;
        }
}
    
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        _getImportance(employees, id, sum);
        
        return sum;
    }
};
