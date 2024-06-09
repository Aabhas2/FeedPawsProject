#include <iostream>

using namespace std;

class DogRecord {
public:
    string photo;
    string location;
    bool injured;
};

void printOrganizationMessage() {
    cout << "Welcome to FeedPaws, a Non-government-organization dedicated to helping stray dogs/animals!\n";
    cout << "FeedPaws is expanding its camps in Delhi to make a positive impact on the lives of stray animals.\n";
    cout << "Join us in our mission to create a better environment for these poor animals.\n";
}

void recordInjuredDog(DogRecord dogRecords[], int& numDogs) {
    if (numDogs < 100) {
        cout << "Do you want to upload a photo for the injured dog? (yes/no): ";
        cin >> ws;
        getline(cin, dogRecords[numDogs].photo);

        cout << "Enter the location of the injured dog: ";
        getline(cin, dogRecords[numDogs].location);

        dogRecords[numDogs].injured = true;
        numDogs++;

        cout << "Thank you! Our team will rescue the injured dog tomorrow.\n";
    } else {
        cout << "Cannot record more dogs. Maximum limit reached.\n";
    }
}

void recordNewStrayDogs(DogRecord dogRecords[], int& numDogs) {
    int numDogsInLocation;
    cout << "Enter the number of stray dogs in the location: ";
    cin >> numDogsInLocation;

    for (int i = 0; i < numDogsInLocation; ++i) {
        if (numDogs < 100) {
            cout << "Do you want to upload a photo for the stray dog? (yes/no): ";
            cin >> ws;
            getline(cin, dogRecords[numDogs].photo);

            cout << "Enter the location of the stray dog: ";
            getline(cin, dogRecords[numDogs].location);

            dogRecords[numDogs].injured = false;
            numDogs++;

            cout << "Stray dog recorded successfully.\n";
        } else {
            cout << "Cannot record more dogs. Maximum limit reached.\n";
            break;
        }
    }

    cout << "Thank you! Our team will distribute food in your area in the morning and evening.\n";
}

void joinNgoCamps(DogRecord dogRecords[], int& numDogs) {
    cout << "Choose the branch you want to join:\n";
    cout << "1. Ghaziabad Branch\n";
    cout << "2. East Delhi\n";
    cout << "3. West Delhi\n";
    cout << "4. South Delhi\n";
    cout << "5. North Delhi\n";

    int branchChoice;
    cout << "Enter your choice (1-5): ";
    cin >> branchChoice;

    string branch, camp1, camp2;
    string name, dob, aadhar;
    int age;

    switch (branchChoice) {
        case 1:
            branch = "Ghaziabad Branch";
            camp1 = "Suryanagar Camp";
            camp2 = "Vaishali Camp";
            break;
        case 2:
            branch = "East Delhi";
            camp1 = "Surajmal Vihar Camp";
            camp2 = "Preet Vihar Camp";
            break;
        case 3:
            branch = "West Delhi";
            camp1 = "Punjabi Bagh Camp";
            camp2 = "Rajouri Garden Camp";
            break;
        case 4:
            branch = "South Delhi";
            camp1 = "Vasant Kunj Camp";
            camp2 = "Green Park Camp";
            break;
        case 5:
            branch = "North Delhi";
            camp1 = "Kamla Nagar Camp";
            camp2 = "Gulabi Bagh Camp";
            break;
        default:
            cout << "Invalid choice. Returning to the main menu.\n";
            return;
    }

    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your date of birth (DOB): ";
    cin.ignore();
    getline(cin, dob);

    cout << "Enter your Aadhar card number: ";
    cin >> aadhar;

    cout << "Thank you, " << name << "! Our team at " << branch << " will contact you shortly.\n";
    cout << "Please visit either " << camp1 << " or " << camp2 << ".\n";
}

int main() {
    const int MAX_DOGS = 100;
    DogRecord dogRecords[MAX_DOGS];
    int numDogs = 0;

    printOrganizationMessage();

    while (true) {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Report new stray dogs\n";
        cout << "2. Report an injured dog\n";
        cout << "3. Join nearby NGO camps\n";
        cout << "4. Display recorded information\n";
        cout << "5. Exit\n";

        // user choice
        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: // Report new stray dogs
                recordNewStrayDogs(dogRecords, numDogs);
                break;

            case 2: // Report an injured dog
                recordInjuredDog(dogRecords, numDogs);
                break;

            case 3: // Join nearby NGO camps
                joinNgoCamps(dogRecords, numDogs);
                break;

            case 4: // Display recorded information
                if (numDogs > 0) {
                    cout << "\nRecorded information:\n";
                    for (int i = 0; i < numDogs; ++i) {
                        cout << "Location: " << dogRecords[i].location << "\t";
                        cout << "Injured: " << (dogRecords[i].injured ? "Yes" : "No") << "\n";
                    }
                } else {
                    cout << "No dogs recorded yet.\n";
                }
                break;

            case 5: // Exit
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
