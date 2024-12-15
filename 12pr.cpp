
#include <iostream>
#include <queue>
#include <string>
using namespace std;
class JobQueue {
private:
queue<string> jobs;
public:
void addJob(string job) {
jobs.push(job); 
cout << "Job added: " << job << endl;
}
void deleteJob() {
if (jobs.empty()) {
cout << "No jobs to delete." << endl;
} else {
cout << "Job deleted: " << jobs.front() << endl;
jobs.pop();
}
}
void displayJobs() {
if (jobs.empty()) {
cout << "No jobs in the queue." << endl;
return;
}
cout << "Current jobs in the queue: ";
queue<string> tempQueue = jobs;
while (!tempQueue.empty()) {
cout << tempQueue.front() << " ";
tempQueue.pop();
}
cout << endl;
}
};
int main() {
JobQueue jobQueue;
int choice;
string job;
while (true) {
cout << "\nJob Queue Menu:\n1. Add Job\n2. Delete Job\n3. Display
Jobs\n4. Exit\nEnter your choice: ";
cin >> choice;
if (choice == 1) {
cout << "Enter job name: ";
cin >> job;
jobQueue.addJob(job);
} else if (choice == 2) {
jobQueue.deleteJob();
} else if (choice == 3) {
jobQueue.displayJobs();
} else if (choice == 4) {
cout << "Exiting..." << endl;
break;
} else {
cout << "Invalid choice! Please try again." << endl;
}
}
return 0;
}
