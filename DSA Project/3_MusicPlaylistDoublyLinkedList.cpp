#include <iostream>
using namespace std;

struct SongNode 
{
    string title;
    string producer;
    string singer;
    string genre;
    SongNode* nextSongNode;
    SongNode* prevSongNode;

    SongNode(string t, string p, string s, string g) : title(t), producer(p), singer(s), genre(g), nextSongNode(NULL), prevSongNode(NULL) {}
};

void addSong(SongNode* &head, string title, string producer, string singer, string genre) {
    SongNode* newSong = new SongNode(title, producer, singer, genre);

    if (!head) {
        head = newSong;
    } else {
        SongNode* currentSong = head;
        while (currentSong->nextSongNode) {
            currentSong = currentSong->nextSongNode;
        }
        currentSong->nextSongNode = newSong;
        newSong->prevSongNode = currentSong;
    }
}

void displayByProducer(SongNode* head, string producer) {
    SongNode* currentSong = head;
    while (currentSong) {
        if (currentSong->producer == producer) {
            cout << "Title: " << currentSong->title << ", Singer: " << currentSong->singer << ", Genre: " << currentSong->genre << endl;
        }
        currentSong = currentSong->nextSongNode;
    }
}

void displayBySinger(SongNode* head, string singer) {
    SongNode* currentSong = head;
    while (currentSong) {
        if (currentSong->singer == singer) {
            cout << "Title: " << currentSong->title << ", Producer: " << currentSong->producer << ", Genre: " << currentSong->genre << endl;
        }
        currentSong = currentSong->nextSongNode;
    }
}

void displayByGenre(SongNode* head, string genre) {
    SongNode* currentSong = head;
    while (currentSong) {
        if (currentSong->genre == genre) {
            cout << "Title: " << currentSong->title << ", Producer: " << currentSong->producer << ", Singer: " << currentSong->singer << endl;
        }
        currentSong = currentSong->nextSongNode;
    }
}

void displayPlaylist(SongNode* head) {
    SongNode* currentSong = head;
    while (currentSong) {
        cout << "Title: " << currentSong->title << ", Producer: " << currentSong->producer << ", Singer: " << currentSong->singer << ", Genre: " << currentSong->genre << endl;
        currentSong = currentSong->nextSongNode;
    }
}

int main() {
    SongNode* playlist = NULL;
    int choice;

    do {
        cout << endl << "Menu:" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Display by Producer" << endl;
        cout << "3. Display by Singer" << endl;
        cout << "4. Display by Genre" << endl;
        cout << "5. Display Entire Playlist" << endl;
        cout << "0. Exit" << endl;

        cout << "Select: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, producer, singer, genre;
                cout << "Enter song title: ";
                cin>>title;
                cout << "Enter producer: ";
                cin>>producer;
                cout << "Enter singer: ";
                cin>>singer;
                cout << "Enter genre: ";
                cin>>genre;
                addSong(playlist, title, producer, singer, genre);
                break;
            }
            case 2: {
                string producer;
                cout << "Enter producer to display songs: ";
                cin>>producer;
                displayByProducer(playlist, producer);
                break;
            }
            case 3: {
                string singer;
                cout << "Enter singer to display songs: ";
                cin>>singer;
                displayBySinger(playlist, singer);
                break;
            }
            case 4: {
                string genre;
                cout << "Enter genre to display songs: ";
                cin>>genre;
                displayByGenre(playlist, genre);
                break;
            }
            case 5:
                cout << "Playlist:" << endl;
                displayPlaylist(playlist);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}