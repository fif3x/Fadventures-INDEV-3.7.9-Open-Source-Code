#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <random>

//---------------------------------------------------------------------------------------------------------

class HSClass {
public:
    int currentHeartCount = 3;
    int medkit = 0;
    int bandages = 0;

    void takeDamage(){
        currentHeartCount -= 1;
    }
    
    void healBandage(){
        if (bandages > 0) {
            currentHeartCount += 1;
            bandages -= 1;
        } else {
            std::cout << "No bandages left to use!" << std::endl;
        }
    }
    
    void healMedkit(){
        if (medkit > 0) {
            currentHeartCount += 2;
            medkit -= 1;
        } else {
            std::cout << "No medkits left to use!" << std::endl;
        }
    }

};

//-----------------------------------------------------------------------------------------------------

class AntiCheat {
public:
    bool cheats = false;
    std::atomic<bool> stopChecking; // Atomic flag to control the continuous checking.

    // Constructor to initialize the cheats flag and checking control
    AntiCheat(bool cheatsEnabled = false) : cheats(cheatsEnabled), stopChecking(false) {}

    void start(HSClass& heartSystem) {
        std::thread([this, &heartSystem]() {
            while (!stopChecking) {
                check(heartSystem);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }).detach(); // Detach the thread so it runs independently
    }

    // Function to perform a single check on the heart system
    void check(HSClass& heartSystem) {
        if (cheats == false && heartSystem.currentHeartCount > 3) { // Fixed assignment issue
            std::cout << "AntiCheat: Heart count exceeds the allowed limit (3) with cheats disabled. Resetting to 1." << std::endl;
            heartSystem.currentHeartCount = 1;
        }
        if (cheats == false && heartSystem.currentHeartCount < 1){
            std::cout << "No hearts left, exiting game" << std::endl;
            exit(0);
        }
        if (cheats == false && heartSystem.bandages > 10){
            std::cout << "AntiCheat: Bandages exceed the allowed limit (10) with cheats disabled. Resetting to 1 heart(s) and 10 bandage(s)." << std::endl;
            heartSystem.currentHeartCount = 1;
            heartSystem.bandages = 10;
        }
        if (cheats == false && heartSystem.medkit > 5){
            std::cout << "AntiCheat: Medkits exceed the allowed limit (5) with cheats disabled. Resetting to 1 heart(s) and 5 medkit(s)" << std::endl;
            heartSystem.currentHeartCount = 1;
            heartSystem.medkit = 5;
        }
    
        }

    void stop() {
        stopChecking = true; // Properly stop the checking thread
    }
};





//---------------------------------------------------------------------------------





class verification {
public:

    long long int password;

    void check (){

        std::cout << "Input a correct password: ";
        std::cin >> password;
        switch (password){
            case 1234:
                std::cout << "Correct!" << std::endl;
                break;
            default:
                std::cout << "Incorrect. Exiting" << std::endl;
                exit (0);
        }

    }

};





//-----------------------------------------------------------------------------------

class startUp {
public:
    void boot(HSClass& heartSystem) {
        std::cout << "Starting";
        AntiCheat ac;
        ac.start(heartSystem);
        ac.check(heartSystem);
        for (int i = 0; i < 2; i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(333));
            std::cout << ".";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(333));
        std::cout << "." << std::endl;

    }

};


//---------------------------------------------------------------------------------------------------------

class engine{
public:
    
    HSClass hsc;

    void engn(){

        std::cout << "Welcome!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::cout << "Spawned in! Found: 1 Bandage, 1 Medkit!" << "\n";
        hsc.medkit += 1;
        hsc.bandages += 1;

        std::cout << "*TV Is ON and it's in the news channel*" << "\n";
        std::cout << "News Reporter: A new disease has spread widely across the globe that makes humans into Zombies.\n";
        std::cout << "*TV closes without you doing anything and the door is getting banged by a Zombie.*\n";
        std::cout << "The Zombie gets in your room.\n";
        std::cout << "What are you going to do? 1) Fight. 2) Try to run away\n";

        int zombieDecision;
        std::cin >> zombieDecision;

        if (zombieDecision == 1) {
            hsc.takeDamage();
            std::cout << "The zombie hit you once, you lost a heart but won the fight. You have " << hsc.currentHeartCount << " hearts right now.\n";
        } else if (zombieDecision == 2) {
            std::cout << "The Zombie blocked the way and made you lose all hearts. You died.\n";
            exit(0);
        }
        //end if
        std::cout << "Would you like to investigate the room? 1) Yes 2) No" << std::endl;
        int investigateroom;
        std::cin >> investigateroom;
        if (investigateroom == 1) {
            std::cout << "You found a letter, Would you like to collect it?" << std::endl;
            std::cout << "1) Yes 2) No" << std::endl;
            int collectletter;
            std::cin >> collectletter;
            if (collectletter == 1) {
                std::cout << "You collected the letter." << std::endl;
                std::cout << "Wanna read the letter? 1) Yes 2) No" << std::endl;
                int readletter;
                std::cin >> readletter;
                if (readletter == 1) {

                    std::random_device rd;  // Seed generator
                    std::mt19937 gen(rd()); // Mersenne Twister RNG seeded with random device
                    std::uniform_int_distribution<> dist(0, 9999);
                    int random_letternumber = dist(gen);

                    std::cout << "The letter says: 'The password is:  "<< random_letternumber << " '" << std::endl;
                } else {
                    std::cout << "You left the letter." << std::endl;
                }
            } else {
                std::cout << "You left the letter." << std::endl;
            }
        } else {
            std::cout << "You left the room without investigating." << std::endl;
        }
    }

};




//----------------------------------------------------------------------------------------------------------------



class selection {
public:

    int option;
    int menu;
    engine mach;

    void select(){
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1) Play" << std::endl;
        std::cout << "2) See where you can contact me" << std::endl;
        std::cout << "3) Quit to Desktop" << std::endl;
        std::cin >> option;
        switch (option){
            case 1:
                mach.engn();
                break;
            case 2:
                std::cout << "Discord: fif3x_" << std::endl;
                std::cout << "Github: fif3x" << std::endl;
                std::cout << "Wanna go to menu? 1) Yes";
                std::cin >> menu;
                switch (menu){
                    case 1:
                        select();
                        break;
                }
            case 3:
                exit(0);
                break;
        } 
    } 
};





//---------------------------------------------------------------------------------------------------------

//I hope you are enjoying learning from this Open-Source Code!!!










//---------------------------------------------------------------------------------------------------------





class kernel{
public:
    static int krnl(){
        HSClass hsc;
        verification vrfctn;
        selection slctn;
        startUp strtp;

        strtp.boot(hsc);
        vrfctn.check();
        slctn.select();


        std::cout << "Press Enter to exit... ";
        std::cin.ignore();
        std::cin.get();

        return 0;

   }
};





//------------------------------------------------------------------------------------------------------





int main() {

    kernel::krnl();

    return 0;

}