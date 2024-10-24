#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

void showMenu() {
    cout << "\n===== To-Do List Menu =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

void addTask(vector<Task> &tasks) {
    string taskDescription;
    cout << "Enter the task description: ";
    cin.ignore(); // To handle any leftover newline character
    getline(cin, taskDescription);
    tasks.push_back(Task(taskDescription));
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available!" << endl;
    } else {
        cout << "\n===== To-Do List =====" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) {
                cout << " [Completed]";
            }
            cout << endl;
        }
    }
}

void markTaskCompleted(vector<Task> &tasks) {
    int taskNumber;
    viewTasks(tasks);
    if (!tasks.empty()) {
        cout << "Enter the task number to mark as completed: ";
        cin >> taskNumber;
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
}

void deleteTask(vector<Task> &tasks) {
    int taskNumber;
    viewTasks(tasks);
    if (!tasks.empty()) {
        cout << "Enter the task number to delete: ";
        cin >> taskNumber;
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                cout << "Exiting the To-Do List application. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
      }
      }
return 0;
}