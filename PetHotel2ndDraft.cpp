#include <iostream>
#include <string>
using namespace std;

class PetOwnerMenu {
private:
    struct Pet {
        string petID;
        string name;
        string breed;
        int age;
        int roomNumber;
    };

    struct Room {
        int roomNumber;
        bool isOccupied;
        string petID;
    };

    Pet pets[10];
    Room rooms[5];
    int petCount;

public:
    PetOwnerMenu() {
        petCount = 0;
        for (int i = 0; i < 10; i++) {
            pets[i].roomNumber = -1;
        }
        for (int i = 0; i < 5; i++) {
            rooms[i].isOccupied = false;
            rooms[i].roomNumber = i + 1;
        }
    }

    void menu();
    void add_pet();
    void view_pet();
    void delete_pet();
    void edit_pet();
    void view_petSelected();
    void bookRoom();
    void viewAllBooking();
    void checkOut();
    void manageRoom();
    void viewRoomOccupancy();
};

void PetOwnerMenu::menu() {
    int choice;
    do {
        cout << "\n___Pet Owner Main Menu__" << endl;
        cout << "1. Register Pet\n2. View My Pets\n3. Delete a Pet\n4. Edit Pet\n5. View Pet Selected" << endl;
        cout << "6. Book Room\n7. View All Rooms\n8. Check Out\n9. Manage Room\n10. View Room Occupancy" << endl;
        cout << "11. Back to Main Menu\n0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: add_pet(); break;
            case 2: view_pet(); break;
            case 3: delete_pet(); break;
            case 4: edit_pet(); break;
            case 5: view_petSelected(); break;
            case 6: bookRoom(); break;
            case 7: viewAllBooking(); break;
            case 8: checkOut(); break;
            case 9: manageRoom(); break;
            case 10: viewRoomOccupancy(); break;
            case 11: cout << "Returning to main menu...\n"; break;
            case 0: cout << "Exiting the system. Goodbye!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0 && choice != 11);
}

void PetOwnerMenu::add_pet() {
    if (petCount >= 10) {
        cout << "Pet list full. Cannot add more pets." << endl;
        return;
    }

    string id;
    cout << "Enter Pet ID: ";
    cin >> id;
    for (int i = 0; i < petCount; ++i) {
        if (pets[i].petID == id) {
            cout << "A pet with this ID already exists." << endl;
            return;
        }
    }

    pets[petCount].petID = id;
    cout << "Enter Pet Name: ";
    cin.ignore();
    getline(cin, pets[petCount].name);
    cout << "Enter Pet Breed: ";
    getline(cin, pets[petCount].breed);
    cout << "Enter Pet Age: ";
    cin >> pets[petCount].age;

    petCount++;
    cout << "Pet registered successfully!" << endl;
}

void PetOwnerMenu::view_pet() {
    if (petCount == 0) {
        cout << "No pets registered yet." << endl;
        return;
    }

    for (int i = 0; i < petCount; ++i) {
        cout << "\nPet #" << (i + 1) << "\nID: " << pets[i].petID << "\nName: " << pets[i].name
             << "\nBreed: " << pets[i].breed << "\nAge: " << pets[i].age << endl;
    }
}

void PetOwnerMenu::delete_pet() {
    if (petCount == 0) {
        cout << "There are no pets to delete." << endl;
        return;
    }

    string id;
    cout << "Enter Pet ID to delete: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < petCount; ++i) {
        if (pets[i].petID == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Pet ID " << id << " does not exist." << endl;
        return;
    }

    for (int i = index; i < petCount - 1; ++i) {
        pets[i] = pets[i + 1];
    }
    petCount--;
    cout << "Pet ID " << id << " has been deleted." << endl;
}

void PetOwnerMenu::edit_pet() {
    if (petCount == 0) {
        cout << "No pets to edit." << endl;
        return;
    }

    string id;
    cout << "Enter Pet ID to edit: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < petCount; ++i) {
        if (pets[i].petID == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Pet ID not found." << endl;
        return;
    }

    cout << "Enter new name (blank to keep current): ";
    cin.ignore();
    string name;
    getline(cin, name);
    if (!name.empty()) pets[index].name = name;

    cout << "Enter new breed (blank to keep current): ";
    string breed;
    getline(cin, breed);
    if (!breed.empty()) pets[index].breed = breed;

    cout << "Enter new age (-1 to keep current): ";
    int age;
    cin >> age;
    if (age != -1) pets[index].age = age;

    cout << "Pet details updated successfully!" << endl;
}

void PetOwnerMenu::view_petSelected() {
    if (petCount == 0) {
        cout << "No pets registered yet." << endl;
        return;
    }

    string id;
    cout << "Enter Pet ID to view: ";
    cin >> id;

    for (int i = 0; i < petCount; ++i) {
        if (pets[i].petID == id) {
            cout << "\nPet Details:\nID: " << pets[i].petID << "\nName: " << pets[i].name
                 << "\nBreed: " << pets[i].breed << "\nAge: " << pets[i].age << endl;
            return;
        }
    }
    cout << "Pet not found." << endl;
}

// Remaining room-related methods continue unchanged...

int main() {
    cout << "\nWelcome to the PetHotel System\n";
    PetOwnerMenu ownerMenu;
    ownerMenu.menu();
    return 0;
}
