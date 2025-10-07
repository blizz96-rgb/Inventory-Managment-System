#include <stdio.h>
 #include <stdlib.h>
 #include "inventory.h"
 #include "file_io.h"
 void displayMenu() {
    printf("\nInventory Management System\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. Search Product\n");
    printf("4. Remove Product\n");
    printf("5. Display Inventory\n");
    printf("6. Save & Exit\n");
    printf("Enter your choice: ");
 }
 int main() {
    Inventory *inventory = malloc(sizeof(Inventory));
    if (inventory == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    inventory->size = 0;
    loadInventory(inventory, "inventory_data.txt");
    int choice;
    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1:
                addProduct(inventory);
                break;
            case 2:
                updateProduct(inventory);
                break;
            case 3:
                searchProduct(inventory);
                break;
            case 4:
                removeProduct(inventory);
                break;
            case 5:
                displayInventory(inventory);
                break;
            case 6:
                saveInventory(inventory, "inventory_data.txt");
                printf("Inventory saved. Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    free(inventory);
    return 0;
 }
