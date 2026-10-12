#include <iostream>
#include <string>
using namespace std;

//  Global struct definitions for shared access between classes
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
    
class PetOwnerMenu {     // PetOwnerMenu class
	
  public:
    Pet pets[10];       // stores up to 10 pet records
    Room rooms[5];      // stores up to 5 rooms
    int petCount;       // Keeps track of total pets registered
    
    

    // Constructor-initializes 5 samples pets
    PetOwnerMenu() {
        petCount = 5;
        pets[0] = {"001", "Bode", "Golden Retriever", 3, -1};
        pets[1] = {"002", "Amber", "Calico cat", 2, -1};
        pets[2] = {"003", "Bome", "Bulldog", 4, -1};
        pets[3] = {"004", "Paw", "Shiba", 5, -1};
        pets[4] = {"005", "Bor", "Bombay cat", 1, -1};

        for (int i = 0; i < 5; i++) {       //  resets room availability
            rooms[i].roomNumber = i;
            rooms[i].isOccupied = false;
            rooms[i].petID = "";
        }
    }

    // PetOwnerMenu and Functions
    int menu();
    void add_pet();
    void view_pet();
    void delete_pet();
    void edit_pet();
    void view_petSelected();
    void bookRoom();
    void checkOut();
};


class StaffMenu {    //  StaffMenu class
	

    Pet* pets;         // Pointer to pets array from PetOwnerMenu
    Room* rooms;       // Pointer to rooms array from PetOwnerMenu
    int& petCount;     // References to pet count  from PetOwnerMenu

  public:
  	// constructor  intializes references
    StaffMenu(Room* r, Pet* p, int& count) : rooms(r), pets(p), petCount(count) {}

    // Menu and staff functions
    int menu();
    void viewAllBooking();
    void manageRoom();
    void viewRoomOccupancy();
    void viewReports();
};

//  menu for pet owners
int PetOwnerMenu::menu (){
	int choice;
	do{ 
	cout<<"\n__Pet Owner Main Menu__"<<endl;
	cout<<"1. Register Pet"<<endl;
	cout<<"2. View My Pets"<<endl;
	cout<<"3. Delete a pet"<<endl;
	cout<<"4. Edit Pet"<<endl;
	cout<<"5. View Pet Selected"<<endl;
	cout<<"6. Book room" << endl;
	cout<<"7. Check out"<<endl;
	cout<<"8. Back to Main Menu"<<endl;
	cout<<"9. Exit" << endl; 
	cout<<"Enter choice: ";
	cin>> choice;

// Menu choices for Pet Owner	
	switch (choice){
		case 1: add_pet(); break;
		case 2: view_pet(); break;
		case 3: delete_pet(); break;
		case 4: edit_pet();break;
		case 5: view_petSelected(); break;
		case 6: bookRoom(); break;
		case 7: checkOut(); break;
		case 8: cout<< "Returning to main menu...\n"; break;
		case 9: cout << "You are exiting the service. Thank you and have a good day!"<<endl; break; 
		default: cout<<"Invalid choice!\n";
    	}

	} while(choice != 8 && choice != 9);
	return 0;
}

// funtion to register a new pet
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
	cout<< "\nPet registered successfully!"<<endl;
}

// function to view pet registered
void PetOwnerMenu::view_pet(){

if (petCount == 0) {// to check if any pets registered
        cout << "No pets registered yet." << endl;
        return;
    }

    for (int i = 0; i < petCount; ++i) {//to display registered pets
        cout << "\nPet #" << (i + 1) << endl;
        cout << "ID: " << pets[i].petID << endl;
        cout << "Name: " << pets[i].name << endl;
        cout << "Breed: " << pets[i].breed << endl;
        cout << "Age: " << pets[i].age << endl;
        
    }
}



// function to delete pet registered by ID
void PetOwnerMenu::delete_pet() {
	
	if(petCount == 0){    // to check if any pets is registered
	cout<<"There is no pet registered"<<endl;
	return;
}
	else {
		string petID;
		cout << "Enter the pet Id that you want to delete:";
		cin >> petID;
		
		// finding the pet ID
		int petIndex = -1;
		for(int i=0; i < petCount; ++i){
			if(pets[i].petID == petID){
				petIndex = i;
				break;
			}
		}
		if(petIndex == -1) {
			cout << "This pet ID "<< petID << "is not exist."<< endl;
			return;
		}
		for(int i = petIndex; i < petCount -1; ++i){
			pets[i] = pets[i+1];
		}
		petCount--;
		cout<< "Pet ID "<< petID << " has been deleted"<< endl;
		}
}// end remove

// function to edit pet registered
void PetOwnerMenu::edit_pet(){
if (petCount == 0) {
        cout << "No pets registered to edit." << endl;
        return;
    }

    string petID;
    cout << "Enter Pet ID of the pet you want to edit: ";
    cin >> petID;

    // Find the pet by ID
    int petIndex = -1;
    for (int i = 0; i < petCount; ++i) {
        if (pets[i].petID == petID) {
            petIndex = i;
            break;
        }
    }

    if (petIndex == -1) {
        cout << "Pet with ID " << petID << " not found." << endl;
        return;
    }

    // display current details
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
    cin.ignore(); 
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

// function to view a specific pet by ID
void PetOwnerMenu:: view_petSelected(){
	
 if(petCount == 0) {
	cout << "No pets registered yet." << endl;
        return;
    }

    string id;        // viewing pet through ID
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
   }
}

// function to book room
void PetOwnerMenu::bookRoom(){
	
	if(petCount == 0){
		cout << "\nNo pets is registered to book a room." <<endl;
		return;
	}
    string petID;
    cout <<"Enter pet ID to book a room: " ;
	cin >> petID;
	
	int petIndex = -1;
	for (int i = 0; i < petCount; ++i) {
		if(pets[i].petID == petID){
			petIndex = i;
			break;
		}
	} 
	if(petIndex == -1){
		cout << "\nPet ID " <<petID<<"not registered." <<endl;
		return;
	}
	
    bool roomBooked = false;
	for(int i = 0; i < 5; ++i){
		if(!rooms[i].isOccupied){
			rooms[i].isOccupied = true;
			rooms[i].petID = petID;
			pets[petIndex].roomNumber = i + 1;
			roomBooked = true;
			
			cout << "\nRoom" << (i+1)<<" has been booked successfully for pet ID:"  << petID << "." << endl;
			break;
		}
	}
	if(!roomBooked){
		cout << "There is no avalable room." << endl;
	} 
}

//check out function
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
    rooms[room].isOccupied = false;
    rooms[room].petID ="";
    pets[petIndex].roomNumber = -1;

    cout << "Pet " << pets[petIndex].name << " checked out from room " << room << "." << endl;
	
}

// menu function for staff
int StaffMenu::menu() {
    int choice;
    do {
        cout << "\n___Staff Menu___" << endl;
        cout << "1. View All Bookings" << endl;
        cout << "2. Manage Room" << endl;
        cout << "3. View Room Occupancy" << endl;
        cout << "4. View Reports" << endl;
        cout << "5. Exit to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: viewAllBooking(); break;
            case 2: manageRoom(); break;
            case 3: viewRoomOccupancy(); break;
            case 4: viewReports(); break;
            case 5: cout << "Returning to main menu...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}

// function to view all the bookings
void StaffMenu::viewAllBooking() {
    for (int i = 0; i < 5; ++i) {
        cout << "\nRoom:" << rooms[i].roomNumber << ":";
        if (rooms[i].isOccupied) {
            cout << "Occupied by Pet ID:" << rooms[i].petID << endl;
        } else {
            cout << "Available" << endl;
        }
    }
}

// function for staff to manage room
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
        if (!rooms[i].isOccupied) {
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

    if (chosenRoom < 0 || chosenRoom >= 5 || rooms[chosenRoom].isOccupied) { // fixed: was >5
        cout << "Invalid room or already occupied!" << endl;
        return;
    }

    pets[petIndex].roomNumber = chosenRoom;
    rooms[chosenRoom].isOccupied = true;
    rooms[chosenRoom].isBooked = true; 
    rooms[chosenRoom].petID = pets[petIndex].petID; // optional: make sure petID is assigned
    cout << "Room " << chosenRoom << " assigned to " << pets[petIndex].name << "." << endl;
}

// function to view room occupancy
void StaffMenu::viewRoomOccupancy() {
    cout << "\n___Room Occupancy___" << endl;
    for (int i = 0; i < 5; ++i) { // assuming 5 rooms
        if (rooms[i].isOccupied) {
            cout << "Room " << rooms[i].roomNumber << " is occupied by pet ID: " << rooms[i].petID << "." << endl;
        } else {
            cout << "Room " << rooms[i].roomNumber << " is available." << endl;
        }
    }
}

// function to view report
void StaffMenu::viewReports() {
    cout << "\n__Hotel Report__" << endl;
    cout << "Total Pets Registered: " << petCount << endl;

    int booked = 0;
    for (int i = 0; i < 5; i++) { // fixed: match room count
        if (rooms[i].isBooked) booked++;
    }

    cout << "Total Rooms: 5" << endl;
    cout << "Rooms Booked: " << booked << "\nRooms Available: " << (5 - booked) << endl;
}

int main() {
    PetOwnerMenu petOwner;//Calling the pet owner menu function
    StaffMenu staff((Room*)petOwner.rooms, (Pet*)petOwner.pets, petOwner.petCount);//calling the staff menu function
   
    int choice;
    do {
        cout << "\n____Welcome to Pet Hotel____" << endl;
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