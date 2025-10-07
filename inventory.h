#ifndef INVENTORY_H
 #define INVENTORY_H
 #define MAX_PRODUCTS 100
 typedef struct {
    char id[10];
    char name[50];
    int quantity;
    float price;
 } Product;
 typedef struct {
    Product products[MAX_PRODUCTS];
    int size;
 } Inventory;
 void addProduct(Inventory *inventory);
 void updateProduct(Inventory *inventory);
 void searchProduct(Inventory *inventory);
 void removeProduct(Inventory *inventory);
 void displayInventory(Inventory *inventory);
 #endif
