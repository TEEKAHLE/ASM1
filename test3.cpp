#include <iostream>
#include <cstdlib> // random number libary
#include <ctime> // 

using namespace std;

const int TRACK_WIDTH = 10;
const int TRACK_HEIGHT = 7;
const int NUM_RACERS = 2;

// Function to generate random steps for a racer based on its speed
int generateSteps(int minSpeed, int maxSpeed) {
    return rand() % (maxSpeed - minSpeed + 1) + minSpeed;
}

// Function to update racer's position on the track
void updatePosition(int& position, int steps) {
    position += steps;
}

// Function to display the track with racers' positions
void displayTrack(int positions[], int numRacers) {
    char track[TRACK_HEIGHT][TRACK_WIDTH]; // 2D array to represent the track

    // Initialize track
    for (int i = 0; i < TRACK_HEIGHT; ++i) {
        for (int j = 0; j < TRACK_WIDTH; ++j) {
            track[i][j] = ' ';
        }
    }

    // Place racers on the track
    for (int i = 0; i < numRacers; ++i) {
        if (positions[i] >= 0 && positions[i] < TRACK_WIDTH) {
            track[0][positions[i]] = i == 0 ? 'X' : 'T'; // X for X Wing, T for Tie Fighter
            track[TRACK_HEIGHT - 1][positions[i]] = i == 0 ? 'X' : 'T'; // Place on the bottom row as well
        }
    }

    // Display track
    for (int i = 0; i < TRACK_HEIGHT; ++i) {
        for (int j = 0; j < TRACK_WIDTH; ++j) {
            cout << "+--";
        }
        cout << "+" << endl;
        for (int j = 0; j < TRACK_WIDTH; ++j) {
            cout << "| " << track[i][j];
        }
        cout << "|" << endl;
    }
    for (int j = 0; j < TRACK_WIDTH; ++j) {
        cout << "+--";
    }
    cout << "+" << endl;
}

int main() {
    srand(time(0)); // Seed the random number generator

    const int xWingMinSpeed = 2;
    const int xWingMaxSpeed = 4;
    const int tieFighterMinSpeed = 1;
    const int tieFighterMaxSpeed = 5;

    int positions[NUM_RACERS] = {0}; // Initialize racers' positions

    // Display initial track
    displayTrack(positions, NUM_RACERS);

    // Simulation loop
    while (true) {
        // Generate steps for each racer
        for (int i = 0; i < NUM_RACERS; ++i) {
            int steps = (i == 0) ? generateSteps(xWingMinSpeed, xWingMaxSpeed) : generateSteps(tieFighterMinSpeed, tieFighterMaxSpeed);
            updatePosition(positions[i], steps);
        }

        // Display track with updated positions
        displayTrack(positions, NUM_RACERS);

        // Check if any racer has reached the end
        for (int i = 0; i < NUM_RACERS; ++i) {
            if (positions[i] >= TRACK_WIDTH) {
                if (i == 0)
                    cout << "X Wing wins the race!" << endl;
                else
                    cout << "Tie Fighter wins the race!" << endl;
                return 0;
            }
        }

        // Pause before next iteration
        cout << "Press Enter to continue...";
        cin.ignore(); // Wait for Enter key
    }

    return 0;
}
