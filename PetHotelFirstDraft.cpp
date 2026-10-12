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

    struct Room {
        bool isBooked = false;
        string petID;
    };

    Pet pets[10];
    Room rooms[5];
    bool roomOccupied[5];
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

        for (int i = 0; i < 5; i++) {
            roomOccupied[i] = false;
            rooms[i].isBooked = false;
        }
}
	//Menu
	void menu();
	
	//pet functions
	void add_pet();
	void view_pet();
	void delete_pet();
	void edit_pet();
	void view_petSelected();
	
	//room function
	void bookRoom();
	void viewAllBooking();
	void checkOut();
	void manageRoom();
	void viewRoomOccupancy();
	
	 	
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
	cout<<"9. Manage Room"<<endl;
	cout<<"10. View Room Occupancy" <<endl;
	cout<<"11. Back to Main Menu"<<endl;
	cout<<"Enter choice: ";
	cin>> choice;
	
	switch (choice){
		case 1: add_pet(); break;
		case 2: view_pet(); break;
		case 3: delete_pet(); break;
		case 4: edit_pet();break;
		case 5: view_petSelected(); break;
		case 6: bookRoom(); break;
		case 7: viewAllBooking();break;
		case 8: checkOut(); break;
		case 9: manageRoom(); break;
		case 10: viewRoomOccupancy(); break;
		case 11: cout<< "Returning to main menu...\n"; break;
		default: cout<<"Invalid choice!\n";
    	}

	}while(choice != 12);
	
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


void PetOwnerMenu::delete_pet() {
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
			if(pets[i].petID = petID){
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

void view_petSelected(){ if (petCount == 0) {
	
        cout << "No pets registered yet." << endl;
        return;
    }

    string id;
    cout << "Enter Pet ID to view: ";
    cin >> id;

    for (int i = 0; i < petCount; ++i) {
        if (pets[i].petID == id) {
            cout << "\nPet Details:" << endl;
            cout << "ID: " << pets[i].petID << endl;
            cout << "Name: " << pets[i].name << endl;
            cout << "Breed: " << pets[i].breed << endl;
            cout << "Age: " << pets[i].age << endl;
            return;
	
}
void bookRoom(){
	int roomNumber;
	int petID;
	
	cout << "Enter a room number to book (1-5):";
	cin >> roomNumber;
	
	if (roomNumber < 1 || roomNuber > 5) {
		cout << "Invalid number" << endl;
		return;
	}
	if(rooms[roomNUmber -1].isBooked){
		cout << "Room" << roomNumber << "is already booked. "<<endl;
		return;
	}
	
	cout << "Enter PetID :";
	cin.ignore();
	getline(cin, guestName);
	
	rooms[roomNumber - 1].isBooked = true;
    rooms[roomNumber - 1].PetID = guestName;
    
    cout << "Room" <<room[i].roomNumber<<"is already booked" << rooms[i].petID << "."<<endl; 
}
void viewAllBooking(){
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


void PetOwnerMenu::manageRoom() {
	
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



void viewRoomOccupancy(){ 
cout << "\nRoom Occupancy Status:" << endl;
    for (int i = 0; i < 5; i++) {
        if (roomOccupied[i]) {
            cout << "Room " << i << ": Occupied by Pet ID " << rooms[i].petID << endl;
        } else {
            cout << "Room " << i << ": Available" << endl;
        }
   }
}


int main (){
	cout << " Welcome to PetHotel main page";
	cout << " Please select a server :";
	PetOwnerMenu PetOwner;
	PetOwner.menu()
	
	return 0;
}