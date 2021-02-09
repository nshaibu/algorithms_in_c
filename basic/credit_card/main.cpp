#include <vector>
#include "credit_card.hpp"


int main(void) {
    vector<CreditCard*> wallet(3);

    wallet[0] = new CreditCard("4545 545454", "NS", 545, 12);
    wallet[1] = new CreditCard("2432 423342", "JS", 5412);
    wallet[2] = new CreditCard("3344 342233", "MN", 512);

    for (int i = 1; i <= 16; i++) {
        wallet[0]->chargelt((double)i);
        wallet[1]->chargelt(2 * i);
        wallet[2]->chargelt(3 * i);
    }

    cout << "Card payments:\n";

    for (int i = 0; i < 3; i++) {
        cout << *wallet[i];
        while (wallet[i]->getBalance() > 100.0) {
            wallet[i]->makePayment(100.0);
            cout << "New balance = " << wallet[i]->getBalance() << "\n";
        }
        cout << "\n"; 
        delete wallet[i];
    }

    return 0;
}
