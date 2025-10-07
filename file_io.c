#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "file_io.h"
 void loadInventory(Inventory *inventory, const char *filename) {
    inventory->size = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found. Starting with an empty inventory.\n");
        return;
    }
    char id[10], name[50];
    int quantity;
    float price;
    while (inventory->size < MAX_PRODUCTS && fscanf(file, "%9s %49s %d %f", id, 
name, &quantity, &price) == 4) {
        if (quantity < 0 || price < 0) {
            printf("Invalid data in file: skipping entry.\n");
            continue;
        }
        id[9] = '\0';
        name[49] = '\0';
        strncpy(inventory->products[inventory->size].id, id, 9);
        inventory->products[inventory->size].id[9] = '\0';
        strncpy(inventory->products[inventory->size].name, name, 49);
        inventory->products[inventory->size].name[49] = '\0';
        inventory->products[inventory->size].quantity = quantity;
        inventory->products[inventory->size].price = price;
        inventory->size++;
        int c;
        while ((c = fgetc(file)) != '\n' && c != EOF);
    }
    fclose(file);
    printf("Loaded %d products from file.\n", inventory->size);
 }
 void saveInventory(Inventory *inventory, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }
    if (inventory->size < 0 || inventory->size > MAX_PRODUCTS) {
        printf("Error: Invalid inventory size (%d).\n", inventory->size);
        fclose(file);
        return;
    }
    for (int i = 0; i < inventory->size; i++) {
        if (!inventory->products[i].id[0] || !inventory->products[i].name[0]) {
            printf("Error: Invalid data at index %d. Skipping.\n", i);
            continue;
        }
        if (fprintf(file, "%s %s %d %.2f\n", inventory->products[i].id,
                    inventory->products[i].name,
                    inventory->products[i].quantity,
                    inventory->products[i].price) < 0) {
            printf("Error writing to file at index %d.\n", i);
            fclose(file);
            return;
        }
    }
    if (fflush(file) != 0 || fclose(file) != 0) {
        printf("Error flushing or closing file.\n");
        return;
    }
    printf("Inventory saved successfully.\n");
}
