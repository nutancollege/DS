
#include <iostream>
#include <string>
using namespace std;

class ClubMember
{
public:
    string prn;
    string name;
    ClubMember *next;

    ClubMember(const string &prn, const string &name) : prn(prn), name(name), next(nullptr) {}
};

class ClubLinkedList
{
private:
    ClubMember *president;
    ClubMember *secretary;

public:
    ClubLinkedList() : president(nullptr), secretary(nullptr) {}

    void addMember(const string &prn, const string &name)
    {
        ClubMember *newMember = new ClubMember(prn, name);

        if (!president)
        {
            // If the list is empty, set the new member as president and secretary
            president = secretary = newMember;
        }
        else
        {
            // Add the new member to the end of the list
            secretary->next = newMember;
            secretary = newMember;
        }

        cout << "Member added: " << name << " (PRN: " << prn << ")" << endl;
    }

    void deleteMember(const string &prn)
    {
        ClubMember *current = president;
        ClubMember *prev = nullptr;

        while (current)
        {
            if (current->prn == prn)
            {
                if (current == president)
                {
                    // Deleting the president, update the next president
                    president = president->next;
                }
                else
                {
                    // Delete the current member
                    prev->next = current->next;
                }

                delete current;
                cout << endl << "Member with PRN " << prn << " deleted." << endl;
                return;
            }

            prev = current;
            current = current->next;
        }

        cout << "Member with PRN " << prn << " not found." << endl;
    }

    int getTotalMembers() const
    {
        int count = 0;
        ClubMember *current = president;

        while (current)
        {
            count++;
            current = current->next;
        }

        return count;
    }
};

int main()
{
    ClubLinkedList club;

    // Example usage
    club.addMember("101", "Alice");
    club.addMember("102", "Bob");
    club.addMember("103", "Charlie");

    cout << "Total members: " << club.getTotalMembers() << endl;

    club.deleteMember("102");
    cout << "Total members after deletion: " << club.getTotalMembers() << endl;

    return 0;
}
