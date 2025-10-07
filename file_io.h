#ifndef FILE_IO_H
 #define FILE_IO_H
 #include "inventory.h"
 void loadInventory(Inventory *inventory, const char *filename);
 void saveInventory(Inventory *inventory, const char *filename);
 #endif
