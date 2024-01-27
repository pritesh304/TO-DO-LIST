#include <iostream>
#include <vector>
#include <iomanip>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task added successfully!" << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "Task List:" << std::endl;
            std::cout << std::setw(4) << "ID" << std::setw(20) << "Description" << std::setw(12) << "Status" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << std::setw(4) << i + 1 << std::setw(20) << tasks[i].description;
                std::cout << std::setw(12) << (tasks[i].completed ? "Completed" : "Pending") << std::endl;
            }
        }
    }

    void markAsCompleted(size_t taskId) {
        if (taskId > 0 && taskId <= tasks.size()) {
            tasks[taskId - 1].completed = true;
            std::cout << "Task marked as completed!" << std::endl;
        } else {
            std::cout << "Invalid task ID." << std::endl;
        }
    }

    void removeTask(size_t taskId) {
        if (taskId > 0 && taskId <= tasks.size()) {
            tasks.erase(tasks.begin() + taskId - 1);
            std::cout << "Task removed successfully!" << std::endl;
        } else {
            std::cout << "Invalid task ID." << std::endl;
        }
    }
};

int main() {
    TodoList todoList;

    char choice;
    do {
        std::cout << "===== To-Do List Manager =====" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                {
                    std::string taskDescription;
                    std::cout << "Enter task description: ";
                    std::cin.ignore(); // Clear the newline from the buffer
                    std::getline(std::cin, taskDescription);
                    todoList.addTask(taskDescription);
                    break;
                }
            case '2':
                todoList.viewTasks();
                break;
            case '3':
                {
                    size_t taskId;
                    std::cout << "Enter the task ID to mark as completed: ";
                    std::cin >> taskId;
                    todoList.markAsCompleted(taskId);
                    break;
                }
            case '4':
                {
                    size_t taskId;
                    std::cout << "Enter the task ID to remove: ";
                    std::cin >> taskId;
                    todoList.removeTask(taskId);
                    break;
                }
            case '5':
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option (1-5)." << std::endl;
        }

    } while (choice != '5');

    return 0;
}

