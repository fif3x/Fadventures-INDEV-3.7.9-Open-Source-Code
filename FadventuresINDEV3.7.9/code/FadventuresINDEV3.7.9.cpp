#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <random>
#include <fstream>
#include <string>
#include <stdlib.h>

//---------------------------------------------------------------------------------------------------------

bool started = false;

class HSClass {
public:
    int currentHeartCount = 3;
    int medkit = 0;
    int bandages = 0;

    void takeDamage() {
        currentHeartCount -= 1;
    }

    void healBandage() {
        if (bandages > 0) {
            currentHeartCount += 1;
            bandages -= 1;
        } else {
            std::cout << "No bandages left to use!" << std::endl;
        }
    }

    void healMedkit() {
        if (medkit > 0) {
            currentHeartCount += 2;
            medkit -= 1;
        } else {
            std::cout << "No medkits left to use!" << std::endl;
        }
    }
};

//---------------------------------------------------------------------------------------------------------

class AntiCheat {
public:
    bool cheats = false;
    std::atomic<bool> stopChecking; // Atomic flag to control the continuous checking.

    AntiCheat(bool cheatsEnabled = false) : cheats(cheatsEnabled), stopChecking(false) {}
    void start(HSClass& heartSystem) {
        std::thread([this, &heartSystem]() {
            while (!stopChecking) {
                check(heartSystem);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }); // Detach the thread so it runs independently
    }

    void check(HSClass& heartSystem) {
        if (cheats == false && heartSystem.currentHeartCount > 3) {
            std::cout << "AntiCheat: Heart count exceeds the allowed limit (3) with cheats disabled. Resetting to 1." << std::endl;
            heartSystem.currentHeartCount = 1;
        }
        if (cheats == false && heartSystem.currentHeartCount < 1) {
            std::cout << "No hearts left, exiting game" << std::endl;
            exit(0);
        }
        if (cheats == false && heartSystem.bandages > 10) {
            std::cout << "AntiCheat: Bandages exceed the allowed limit (10) with cheats disabled. Resetting to 1 heart(s) and 10 bandage(s)." << std::endl;
            heartSystem.currentHeartCount = 1;
            heartSystem.bandages = 10;
        }
        if (cheats == false && heartSystem.medkit > 5) {
            std::cout << "AntiCheat: Medkits exceed the allowed limit (5) with cheats disabled. Resetting to 1 heart(s) and 5 medkit(s)" << std::endl;
            heartSystem.currentHeartCount = 1;
            heartSystem.medkit = 5;
        }
    }

    void stop() {
        stopChecking = true; // Properly stop the checking thread
    }
};

//---------------------------------------------------------------------------------------------------------

class engine {
public:
    HSClass hsc;

    void engn() {
        std::cout << "Welcome!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        if (started == true){


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
            system("cls");
            system("clear");
            std::cout << "The zombie hit you once, you lost a heart but won the fight. You have " << hsc.currentHeartCount << " hearts right now.\n";
        } else if (zombieDecision == 2) {
            system("cls");
            system("clear");
            std::cout << "The Zombie blocked the way and made you lose all hearts. You died.\n";
            exit(0);
        }

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
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> dist(0, 9999);
                    int random_letternumber = dist(gen);

                    std::cout << "The letter says: 'The password is: " << random_letternumber << " '" << std::endl;
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
    }
};





//---------------------------------------------------------------------------------------------------------





class modificationSystem {
public:
    AntiCheat ac;
    HSClass hsc;

    int check() {
        system("title Modifying");
        int currentLine = 0;
        int targetLineHearts = 13;
        int targetLineACM = 10;

        int modifyGame;

        std::cout << "Wanna modify the game? 1) Yes 2) No" << std::endl;
        std::cin >> modifyGame;

        if (modifyGame == 1) {
            std::string lines;
            

            std::ifstream mainModFile("C:/Program Files/Fadventures/Mods/mods.txt");
            if (mainModFile.is_open()) {
                while (std::getline(mainModFile, lines)) {
                    currentLine++;
                    if (currentLine == targetLineACM){
                        std::string cheatMod;
                        if (cheatMod == "acm = false"){
                            ac.cheats = false;
                        }
                        else if(cheatMod == "acm = true"){
                            ac.cheats = true;
                        }
                        else{
                            std::cout << "File has been broken!" << std::endl;
                        }
                    }
                    if (currentLine == targetLineHearts){
                        std::string heartsMod;
                        if (heartsMod == "hearts = 0"){
                            hsc.currentHeartCount = 0;
                        }
                        else if (heartsMod == "hearts = 1"){
                            hsc.currentHeartCount = 1;
                        }
                        else if (heartsMod == "hearts = 3"){
                            hsc.currentHeartCount = 3;
                        }
                        else if (heartsMod == "hearts = 5"){
                            hsc.currentHeartCount = 5;
                        }
                        else if (heartsMod == "hearts = 10"){
                            hsc.currentHeartCount = 10;
                        }
                        else if (heartsMod == "hearts = 25"){
                            hsc.currentHeartCount = 25;
                        }
                        else if (heartsMod == "hearts = 50"){
                            hsc.currentHeartCount = 50;
                        }
                        else if (heartsMod == "hearts = 100"){
                            hsc.currentHeartCount = 100;
                        }
                        else if (heartsMod == "hearts = 1000"){
                            hsc.currentHeartCount = 1000;
                        }
                        else if (heartsMod == "hearts = 10000"){
                            hsc.currentHeartCount = 10000;
                        }
                        else if (heartsMod == "hearts = 999999"){
                            hsc.currentHeartCount = 999999;
                        }else{
                            std::cout << "Please check the MODIFICATIONS.txt file!" << std::endl;
                        }
                               
                        }
                            
                    }
                    
                }
            } else {
                std::cerr << "Unable to open file." << std::endl;
            }

            std::cout << "Current Heart Count: " << hsc.currentHeartCount << std::endl;
            std::cout << "AntiCheat Boolean: " << (ac.cheats ? "true" : "false") << std::endl;

            std::cout << "Press Enter to exit... ";
            std::cin.ignore();
            std::cin.get();

            

            return 0;
        }

    };






//---------------------------------------------------------------------------------------------------------





class selection {
public:
    int option;
    int menu;
    engine mach;
    modificationSystem ms;

    void select() {
    while(true){
        system("title MENU");
        system("cls");
        system("clear");
        std::cout << "           MENU" << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1) Play" << std::endl;
        std::cout << "2) See where you can contact me" << std::endl;
        std::cout << "3) Modify Game" << std::endl;
        std::cout << "4) Quit to Desktop" << std::endl;
        std::cin >> option;

        switch (option) {
            case 1:
                mach.engn();
                break;
            case 2:
                std::cout << "Discord: fif3x_" << std::endl;
                std::cout << "Github: fif3x" << std::endl;
                std::cout << "Wanna go to menu? 1) Yes";
                std::cin >> menu;
                if (menu == 1) {
                    select();
                }
                break;
            case 3:
                ms.check();
                
                break;
            case 4:
                exit(0);
                break;
            }
        }
    }
};





//---------------------------------------------------------------------------------------------------------





class resetSystem{
public:
    void reset(){
    HSClass hsc;

        hsc.currentHeartCount = 3;
        hsc.medkit = 0;
        hsc.bandages = 0;

    
    }
};





//--------------------------------------------------------------------------------------------------






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





//-------------------------------------------------------------------------------------------------





class startUp {
public:
verification vrfctn;
selection slctn;
HSClass hsc;
engine mach;
resetSystem rst;

    void testFunctions(){
        //Quickly tests all functions
        hsc.takeDamage();
        hsc.healBandage();
        hsc.healMedkit();
        mach.engn();
        rst.reset();
    }

    void VAS(){
        //VAS: Verify And Select
        vrfctn.check();
        slctn.select();
    }

    void boot(){
        std::cout << "Starting";

        std::this_thread::sleep_for(std::chrono::milliseconds(333));
        std::cout << ".";

        testFunctions();
        VAS();

        started = true;

    }

    
};





//---------------------------------------------------------------------------------------------------------





//-----------------------------------------------------------------------------------------------------------





class kernel {
public:
    static int run() {

        startUp strtp;

        strtp.boot();

        std::cout << "Press Enter to exit... ";
        std::cin.ignore();
        std::cin.get();

        return 0;
    }
};





//---------------------------------------------------------------------------------------------------------





int main() {
    return kernel::run();
}
