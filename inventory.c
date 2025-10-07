#include <stdio.h>
 #include <string.h>
 #include "inventory.h"
 void addProduct(Inventory *inventory) {
    if (inventory->size >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    Product newProduct;
    printf("Enter Product ID: ");
    scanf("%9s", newProduct.id);
    printf("Enter Product Name: ");
    scanf(" %49[^\n]", newProduct.name);
    printf("Enter Quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter Price per Unit: ");
    scanf("%f", &newProduct.price);
    if (newProduct.quantity < 0 || newProduct.price < 0) {
        printf("Invalid quantity or price. Product not added.\n");
        return;
    }
    inventory->products[inventory->size++] = newProduct;
    printf("Product added successfully.\n");
 }
 void updateProduct(Inventory *inventory) {
    char id[10];
    printf("Enter Product ID to update: ");
    scanf("%9s", id);
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i].id, id) == 0) {
            printf("Enter new Quantity: ");
            scanf("%d", &inventory->products[i].quantity);
            printf("Enter new Price per Unit: ");
            scanf("%f", &inventory->products[i].price);
            if (inventory->products[i].quantity < 0 || inventory->products[i].price 
< 0) {
    }
                printf("Invalid quantity or price. Update aborted.\n");
                return;
            }
            printf("Product updated successfully.\n");
            return;
        }
    printf("Product not found.\n");
 }
 void searchProduct(Inventory *inventory) {
    char id[10];
    printf("Enter Product ID to search: ");
    scanf("%9s", id);
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i].id, id) == 0) {
            printf("Product Found:\nID: %s, Name: %s, Quantity: %d, Price: %.2f\n",
                   inventory->products[i].id, inventory->products[i].name,
                   inventory->products[i].quantity, inventory->products[i].price);
            return;
        }
    }
    printf("Product not found.\n");
 }
 void removeProduct(Inventory *inventory) {
    char id[10];
    printf("Enter Product ID to remove: ");
    scanf("%9s", id);
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i].id, id) == 0) {
            for (int j = i; j < inventory->size - 1; j++) {
                inventory->products[j] = inventory->products[j + 1];
            }
            inventory->size--;
            printf("Product removed successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
 }
 void displayInventory(Inventory *inventory) {
    if (inventory->size == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < inventory->size; i++) {
        printf("%s\t%-10s\t%d\t\t%.2f\n",
               inventory->products[i].id,
               inventory->products[i].name,
               inventory->products[i].quantity,
               inventory->products[i].price);
    }
}
