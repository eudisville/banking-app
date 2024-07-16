#include <stdio.h>
#include <string.h>

// Définir une structure pour stocker les informations du client
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

// Fonction pour afficher les informations d'un compte
void displayAccount(Account acc) {
    printf("Numéro de compte : %d\n", acc.accountNumber);
    printf("Nom : %s\n", acc.name); 
    printf("Solde : %.2f\n", acc.balance);  
}

// Fonction pour créer un nouveau compte
Account createAccount(int accountNumber, char name[], float initialDeposit) {  
    Account newAccount;
    newAccount.accountNumber = accountNumber;
    strcpy(newAccount.name, name);
    newAccount.balance = initialDeposit;
    return newAccount;
}

// Fonction pour déposer de l'argent
void deposit(Account *acc, float amount) {
    if (amount > 0) {
        acc->balance += amount;
        printf("Dépôt réussi ! Nouveau solde : %.2f\n", acc->balance);  
    } else {
        printf("Le montant du dépôt doit être positif.\n");
    }
}

// Fonction pour retirer de l'argent
void withdraw(Account *acc, float amount) {  
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("Retrait réussi ! Nouveau solde : %.2f\n", acc->balance);
    } else {
        printf("Montant invalide ou solde insuffisant.\n");
    }
}

// Fonction pour afficher le menu et obtenir le choix de l'utilisateur
int menu() {
    int choice;
    printf("\nSystème de gestion bancaire\n");
    printf("1. Créer un nouveau compte\n");
    printf("2. Déposer de l'argent\n");
    printf("3. Retirer de l'argent\n");
    printf("4. Afficher les informations du compte\n");
    printf("5. Quitter\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    Account myAccount;
    int accountCreated = 0; // Variable pour vérifier si un compte a été créé

    while (1) {
        int choice = menu();
        int accNumber;
        char name[50];
        float amount;

        switch (choice) {
            case 1:
                if (accountCreated) {
                    printf("Un compte a déjà été créé.\n");
                } else {
                    printf("Entrez le numéro de compte : ");
                    scanf("%d", &accNumber);
                    printf("Entrez le nom : ");
                    scanf("%s", name);
                    printf("Entrez le dépôt initial : ");
                    scanf("%f", &amount);
                    myAccount = createAccount(accNumber, name, amount);
                    accountCreated = 1;
                }
                break;
            case 2:
                if (accountCreated) {
                    printf("Entrez le montant à déposer : ");
                    scanf("%f", &amount);
                    deposit(&myAccount, amount);
                } else {
                    printf("Créez un compte d'abord.\n");
                }
                break;
            case 3:
                if (accountCreated) {
                    printf("Entrez le montant à retirer : ");
                    scanf("%f", &amount);
                    withdraw(&myAccount, amount);
                } else {
                    printf("Créez un compte d'abord.\n");
                }
                break;
            case 4:
                if (accountCreated) {
                    displayAccount(myAccount);
                } else {
                    printf("Créez un compte d'abord.\n");
                }
                break;
            case 5:
                printf("Au revoir !\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}
