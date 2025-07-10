#include <iostream>
#include <unordered_map>
#include <iomanip>

class CurrencyWallet {
private:
    std::unordered_map<std::string, double> balances;

public:
    void deposit(const std::string& currency, double amount) {
        if (amount <= 0) {
            std::cout << "Amount must be positive.\n";
            return;
        }
        balances[currency] += amount;
        std::cout << "Deposited " << amount << " " << currency << ".\n";
    }

    void withdraw(const std::string& currency, double amount) {
        if (amount <= 0) {
            std::cout << "Amount must be positive.\n";
            return;
        }
        if (balances[currency] < amount) {
            std::cout << "Insufficient funds in " << currency << ".\n";
            return;
        }
        balances[currency] -= amount;
        std::cout << "Withdrew " << amount << " " << currency << ".\n";
    }

    void showBalances() const {
        std::cout << "\n📊 Current Wallet Balances:\n";
        for (const auto& pair : balances) {
            std::cout << std::fixed << std::setprecision(2)
                      << pair.first << ": " << pair.second << "\n";
        }
    }
};

int main() {
    CurrencyWallet wallet;
    int choice;
    std::string currency;
    double amount;

    do {
        std::cout << "\n=== Currency Wallet Menu ===\n";
        std::cout << "1. Deposit\n2. Withdraw\n3. Show Balances\n4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter currency (e.g., USD, INR): ";
                std::cin >> currency;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                wallet.deposit(currency, amount);
                break;
            case 2:
                std::cout << "Enter currency (e.g., USD, INR): ";
                std::cin >> currency;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                wallet.withdraw(currency, amount);
                break;
            case 3:
                wallet.showBalances();
                break;
            case 4:
                std::cout << "Exiting wallet. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}




