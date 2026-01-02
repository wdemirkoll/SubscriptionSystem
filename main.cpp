#include <iostream>
#include <string>

std::string Name;
std::string SubscriptionType[2] = {"Monthly", "Yearly"}; // Subscription types
std::string MySubscription; // My subscription

double Money = 0;

int RemainingDays; // Remaining days
int Vote; // Menu selection-vote

// Check if the subscription has expired and reset it if needed
void Subscription_Logic(){
    if(MySubscription == SubscriptionType[0]){
        if(RemainingDays == 0){
            std::cout << "Your monthly subscription has expired." << std::endl << std::endl;
            MySubscription = ""; // reset subscription
        }
    }

    if(MySubscription == SubscriptionType[1]){
        if(RemainingDays == 0){
            std::cout << "Your yearly subscription has expired." << std::endl << std::endl;
            MySubscription = ""; // reset subscription
        }
    }
}

// Logic for buying a monthly subscription
void Monthly_Subscription_Logic(){
    // Check if there is no active subscription
    if(MySubscription != SubscriptionType[0] && MySubscription != SubscriptionType[1]){
        if(Money >= 100){ // Check if user has enough money
            Money -= 100; // Deduct money
            MySubscription = SubscriptionType[0]; // Set subscription type
            RemainingDays = 30; // Set subscription duration

            std::cout << "You purchased a monthly subscription!" << std::endl << std::endl;
        }
        else{
            std::cout << "Insufficient money" << std::endl << std::endl;
        }
    }
    else{
        std::cout << "There is an active subscription" << std::endl << std::endl;
    }
}

// Logic for buying a yearly subscription
void Yearly_Subscription_Logic(){
    // Check if there is no active subscription
    if(MySubscription != SubscriptionType[0] && MySubscription != SubscriptionType[1]){
        if(Money >= 1200){ // Check if user has enough money
            Money -= 1200; // Deduct money
            MySubscription = SubscriptionType[1]; // Set subscription type
            RemainingDays = 365; // Set subscription duration

            std::cout << "You purchased a yearly subscription!" << std::endl << std::endl;
        }
        else{
            std::cout << "Insufficient money" << std::endl << std::endl;
        }
    }
    else{
        std::cout << "There is an active subscription" << std::endl << std::endl;
    }
}

// Display the user's current statistics
void Statistics_Menu(){
    std::cout << "---------------------" << std::endl;
    std::cout << "Name: " << Name << std::endl; // Show user name
    std::cout << "Money: $" << Money << std::endl; // Show current money
    std::cout << "Subscription Type: " << MySubscription << std::endl; // Show subscription type
    std::cout << "Remaining Days: " << RemainingDays << std::endl; // Show remaining days
    std::cout << "---------------------" << std::endl << std::endl;
}

// Show main menu options and get user input
void MainMenu(){
    std::cout << "[1] - Buy Subscription" << std::endl;
    std::cout << "[2] - Spend The Day" << std::endl;
    std::cout << "[3] - Exit" << std::endl;
    std::cout << "Vote: ";
    std::cin >> Vote; // Get user choice
}

int main(){
    std::cout << "Hello, enter your name: ";
    getline(std::cin, Name);

    std::cout << "Welcome! " << Name << " You earned $100,000 for testing it :)" << std::endl;

    Money += 100000; // Give initial testing money

    while(true){
        Subscription_Logic(); // Check subscription expiration
        Statistics_Menu();   // Show user statistics
        MainMenu();         // Show menu and get input

        switch(Vote){
            case 1: { // Buy subscription
                std::cout << "[1] - Monthly [$100]" << std::endl;
                std::cout << "[2] - Yearly [$1200]" << std::endl;
                std::cout << "Select subscription type: ";
                std::cin >> Vote; // Choose subscription

                switch(Vote){
                    case 1:
                        Monthly_Subscription_Logic(); // Process monthly subscription
                        break;
                    case 2:
                        Yearly_Subscription_Logic(); // Process yearly subscription
                        break;
                    default:
                        std::cout << "Invalid Selection!" << std::endl << std::endl;
                        break;
                }
                break;
            }

            case 2: // Spend a day
                if(RemainingDays > 0){
                    RemainingDays--; // Reduce remaining days
                    std::cout << "You spent a day!" << std::endl << std::endl;
                }
                else{
                    std::cout << "You do not have an active subscription." << std::endl << std::endl;
                }
                break;

            case 3: // Exit the program
                return 0;

            default: // Invalid menu selection
                std::cout << "Invalid Selection!" << std::endl << std::endl;
                break;
        }
    }

  return 0;
}
