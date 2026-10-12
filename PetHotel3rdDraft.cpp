#include <iostream>
#include <string>
using namespace std;

class PetOwnerMenu
{
	private:
	struct Pet {
        string petID;
        string name;
        string breed;
        int age;
        int roomNumber;
    };

    Pet pets[10];
    int petCount;
		
	public:
	//constructor
      PetOwnerMenu() {
        petCount = 5; // 5 preset pets

        pets[0] = {"Pet1", "Bode", "Golden Retriever", 3, -1};
        pets[1] = {"Pet2", "Amber", "Calico cat", 2, -1};
        pets[2] = {"Pet3", "Bome", "Bulldog", 4, -1};
        pets[3] = {"Pet4", "Paw", "Shiba", 5, -1};
        pets[4] = {"Pet5", "Bor", "Bombay cat", 1, -1};

}
	//Menu for owners
	void menu();
	
	//pet functions
	void add_pet();
	void view_pet();
	void delete_pet();
	void edit_pet();
	void bookRoom();
	void checkOut();
	void view_petSelected();
	 	
};

class StaffMenu {
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
        bool isBooked;
        string petID;
    };

    Pet* pets;
    Room* rooms;
    int& petCount;

public:
    StaffMenu(Room* r, Pet* p, int& count) : rooms(r), pets(p), petCount(count) {}

    void menu();
    void viewAllBooking();
    void manageRoom();
    void viewRoomOccupancy();
    void viewReports();
    void saveData();
    void loadData();
};

void PetOwnerMenu::menu (){
	int choice;
	do{ 
	cout<<"\n___Pet Owner Main Menu__"<<endl;
	cout<<"1. Register Pet"<<endl;
	cout<<"2. View My Pets"<<endl;
	cout<<"3. Delete a pet"<<endl;
	cout<<"4. Edit Pet"<<endl;
	cout<<"5. View Pet Selected"<<endl;
	cout<<"6. Book room" << endl;
	cout<<"7. View All Room"<<endl;
	cout<<"8. Check out"<<endl;
	cout<<"9. Back to Main Menu"<<endl;
	cout<<"Enter choice: ";
	cin>> choice;
	
	switch (choice){
		case 1: add_pet(); break;
		case 2: view_pet(); break;
		case 3: delete_pet(); break;
		case 4: edit_pet();break;
		case 5: view_petSelected(); break;
		case 6: bookRoom(); break;
		case 7: checkOut(); break;
		case 8: cout<< "Returning to main menu...\n"; break;
		default: cout<<"Invalid choice!\n";
    	}

	}while(choice != 8);
	
}
void StaffMenu::menu() {
    int choice;
    do {
        cout << "\n___Staff Menu___" << endl;
    	cout <<"1. View All Bookings"<<endl;
    	cout <<"2. Manage Room"<<endl;
    	cout <<"3. View Room Occupancy"<<endl;
    	cout <<"4. View Reports"<<endl;
    	cout <<"5. Exit to Main Menu"<<endl;
    	cout <<"Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: viewAllBooking(); break;
            case 2: manageRoom(); break;
            case 3: viewRoomOccupancy(); break;
            case 4: viewReports(); break;
            case 5: cout << "Returning to main menu..."; break;
            default: cout << "Invalid choice!";
        }
    } while (choice != 7);
}

void PetOwnerMenu::add_pet(){
		if(petCount>= 10){
		cout<<"Pet list full.Cannot add more pets."<<endl;
		return;
	}
	cout<<"\nRegistering new pet...."<<endl;
	cout<<"Enter Pet ID: ";
	cin>>pets[petCount].petID;
	cout<<"Enter Pet Name: ";
	cin.ignore();
	getline(cin, pets[petCount].name);
	cout<<"Enter Pet Breed:  ";
	getline(cin, pets[petCount].breed);
	cout<<"Enter Pet Age: ";
	cin>>pets[petCount].age;
	
	petCount++;
	cout<< "Pet registered successfully!"<<endl;
}


void PetOwnerMenu::view_pet(){

if (petCount == 0) {
        cout << "No pets registered yet." << endl;
        return;
    }

    for (int i = 0; i < petCount; ++i) {
        cout << "\nPet #" << (i + 1) << endl;
        cout << "ID: " << pets[i].petID << endl;
        cout << "Name: " << pets[i].name << endl;
        cout << "Breed: " << pets[i].breed << endl;
        cout << "Age: " << pets[i].age << endl;
        
}


void PetOwnerMenu::delete_pet()
{
	if(petCount == 0){
	cout<<"There is no pet registered"<<endl;
	return;
}
	else {
		string petID;
		cout << "Enter the pet Id that you want to delete:";
		cin >> petID;
		
		//finding the pet ID
		int petInfo = -1;
		for(int i=0; i < petCount; i++){
			if(pets[i].petID == petID){
				petInfo = i;
				break;
			}
		}
		if(petIndex = -1) {
			cout << "This pet ID "<< petID << "is not exist."<< endl;
			return;
		}
		for(int i = petInfo; i<petCount - 1; 1++){
			pets[i] = pets[i+1];
		}
		petCount--;
		cout<< "Pet ID "<< petID << "had been deleted"<< endl;
		}
}//end remove
void PetOwnerMenu::edit_pet(){
if (petCount == 0) {
        cout << "No pets registered to edit." << endl;
        return;
    }

    string petID;
    cout << "Enter Pet ID of the pet you want to edit: ";
    cin >> petID;

    // Find the pet by ID
    int petInfo = -1;
    for (int i = 0; i < petCount; i++) {
        if (pets[i].petID == petID) {
            petInfo = i;
            break;
        }
    }

    if (petInfo == -1) {
        cout << "Pet with ID " << petID << " not found." << endl;
        return;
    }

    // Display current details
    cout << "Current details of the pet:" << endl;
    cout << "Pet ID: " << pets[petIndex].petID << endl;
    cout << "Name: " << pets[petIndex].name << endl;
    cout << "Breed: " << pets[petIndex].breed << endl;
    cout << "Age: " << pets[petIndex].age << endl;

    // Ask for new details
    cout << "Enter new name (leave blank to keep current): ";
    cin.ignore();
    string newName;
    getline(cin, newName);
    if (!newName.empty()) {
        pets[petIndex].name = newName;
    }

    cout << "Enter new breed (leave blank to keep current): ";
    string newBreed;
    getline(cin, newBreed);
    if (!newBreed.empty()) {
        pets[petIndex].breed = newBreed;
    }

    cout << "Enter new age (enter -1 to keep current): ";
    int newAge;
    cin >> newAge;
    if (newAge != -1) {
        pets[petIndex].age = newAge;
    }

    cout << "Pet details updated successfully!" << endl;
}	

}

void PetOwnerMenu::view_petSelected()
{ if (petCount == 0) {
	
        cout << "No pets registered yet." << endl;
        return;
    }

    string id;
    cout << "Enter Pet ID to view: "; //ask id detail to view pet
    cin >> id;
    
    //display pet details
    for (int i = 0; i < petCount; ++i) {
        if (pets[i].petID == id) {
            cout << "\nPet Details:" << endl;
            cout << "ID: " << pets[i].petID << endl;
            cout << "Name: " << pets[i].name << endl;
            cout << "Breed: " << pets[i].breed << endl;
            cout << "Age: " << pets[i].age << endl;
            return;
	
}
void PetOwnerMenu::bookRoom(){// to book room function
	int roomNumber;
	int petID;
	
	cout << "Enter a room number to book (1-5):";
	cin >> roomNumber;
	
	if (roomNumber < 1 || roomNuber > 5) {//to limit room from 1-5
		cout << "Invalid number" << endl;
		return;
	}
	if(rooms[roomNUmber -1].isBooked){
		cout << "Room" << roomNumber << "is already booked. "<<endl;//display booked room
		return;
	}
	
	cout << "Enter PetID :";
	cin.ignore();
	getline(cin, guestName);
	
	rooms[roomNumber - 1].isBooked = true;
    rooms[roomNumber - 1].PetID = guestName;
    
    cout << "Room" <<room[i].roomNumber<<"is already booked" << rooms[i].petID << "."<<endl; 
}
void StaffMenu::viewAllBooking(){
	cout << "\nBooked Rooms: " << endl;
	for(int i = 0; i < 5; i++) {
		if(rooms[i].isBooked) {
			cout << "Room" << room[i].rommNumber << " already booked." 
		}
	}
}

void PetOwnerMenu::checkOut() {
	
    if (petCount == 0) {
        cout << "No pets to check out." << endl;
        return;
    }

    string id;
    cout << "Enter Pet ID to check out: ";
    cin >> id;

    int petIndex = -1;
    for (int i = 0; i < petCount; ++i) {
        if (pets[i].petID == id) {
            petIndex = i;
            break;
        }
    }

    if (petIndex == -1) {
        cout << "Pet not found." << endl;
        return;
    }

    if (pets[petIndex].roomNumber == -1) {
        cout << "Pet is not checked into any room." << endl;
        return;
    }

    int room = pets[petIndex].roomNumber;
    roomOccupied[room] = false;
    pets[petIndex].roomNumber = -1;

    cout << "Pet " << pets[petIndex].name << " checked out from room " << room << "." << endl;
	
}


void StaffMenu::manageRoom() {
	
    if (petCount == 0) {
        cout << "No pets to assign rooms to." << endl;
        return;
    }

    string id;
    cout << "Enter Pet ID to assign a room: ";
    cin >> id;

    int petIndex = -1;
    for (int i = 0; i < petCount; ++i) {
        if (pets[i].petID == id) {
            petIndex = i;
            break;
        }
    }

    if (petIndex == -1) {
        cout << "Pet not found." << endl;
        return;
    }

    if (pets[petIndex].roomNumber != -1) {
        cout << "Pet is already assigned to room " << pets[petIndex].roomNumber << "." << endl;
        return;
    }

    cout << "Available rooms: ";
    bool anyAvailable = false;
    for (int i = 0; i < 5; ++i) {
        if (!roomOccupied[i]) {
            cout << i << " ";
            anyAvailable = true;
        }
    }
    cout << endl;

    if (!anyAvailable) {
        cout << "No rooms available!" << endl;
        return;
    }

    int chosenRoom;
    cout << "Enter room number to assign: ";
    cin >> chosenRoom;

    if (chosenRoom < 0 || chosenRoom >= 5 || roomOccupied[chosenRoom]) {
        cout << "Invalid room or already occupied!" << endl;
        return;
    }

    pets[petIndex].roomNumber = chosenRoom;
    roomOccupied[chosenRoom] = true;
    cout << "Room " << chosenRoom << " assigned to " << pets[petIndex].name << "." << endl;
}



void StaffMenu::viewRoomOccupancy(){ 
cout << "\nRoom Occupancy Status:" << endl;
    for (int i = 0; i < 5; i++) {
        if (roomOccupied[i]) {
            cout << "Room " << i << ": Occupied by Pet ID " << rooms[i].petID << endl;
        } else {
            cout << "Room " << i << ": Available" << endl;
        }
   }
}
void StaffMenu::viewReports() {
    cout << "__Hotel Report__" << endl;
    cout << "Total Pets Registered: " << petCount << endl;
    int booked = 0;
    for (int i = 0; i < 10; i++) {
        if (rooms[i].isBooked) booked++;
    }
    cout << "Total Rooms: 10";
	cout<< "Rooms Booked: " << booked << "Rooms Available: " << (10 - booked) << endl;
}


int main (){
	PetOwnerMenu petOwner;
    StaffMenu staff(petOwner.rooms, petOwner.pets, petOwner.roomOccupied, petOwner.petCount);
    int choice;
    do {
        cout << "\n=== Welcome to Pet Hotel ===" << endl;
        cout << "1. Pet Owner" << endl;
        cout << "2. Staff" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: petOwner.menu(); break;
            case 2: staff.menu(); break;
            case 3: cout << "Exiting system...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 3);
    return 0;
}