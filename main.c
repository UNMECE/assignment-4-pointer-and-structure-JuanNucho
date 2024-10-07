#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

// Function to add an item to the item list
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) { // Allocate memory for the string fields since they are pointers
    item_list[index].sku = malloc(strlen(sku) + 1); // +1 for null terminator
    item_list[index].name = malloc(strlen(name) + 1);
    item_list[index].category = malloc(strlen(category) + 1);

    // Copy the values into the item at the given index
    strcpy(item_list[index].sku, sku);
    strcpy(item_list[index].name, name);
    strcpy(item_list[index].category, category);
    item_list[index].price = price;
}
// Function to print all items
void print_items(Item *item_list, int size) { 
    for (int i = 0; i < size; i++) {
        printf("##################\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %f\n", item_list[i].price);
        printf("#################\n");
    }
}

// Function to calculate the average price of all items
double average_price(Item *item_list, int size) {
    double total_price = 0.0;
    for (int i = 0; i < size; i++) {
        total_price += item_list[i].price;
    }
    return total_price / size;
}

// Function to free memory allocated for each item
void free_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        // Free each string field that was allocated dynamically
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
    }
}

int main(int argc, char *argv[]) {
    // Dynamically allocate memory for 5 items
    int num_items = 5;
    Item *item_list = malloc(num_items * sizeof(Item)); // Allocates space for 5 items

    // add 5 different items using add_item function
    add_item(item_list, 5.00, "19282", "breakfast", "Oatmeal", 0);
    add_item(item_list, 4.00, "79862", "dairy", "Milk", 1);
    add_item(item_list, 2.50, "12345", "beverage", "Sprite", 2);
    add_item(item_list, 4.75, "54321", "snacks", "Pretzels", 3);
    add_item(item_list, 3.00, "67890", "produce", "Oranges", 4);

    // Print all items to the screen
    print_items(item_list, num_items);

    // Calculate and print the average price
    double avg_price = average_price(item_list, num_items);
    printf("Average price of items = %f\n", avg_price);

    // If an argument is provided, search for the item by its SKU
    if (argc > 1) {
        char *search_sku = argv[1];
        int i = 0;
        // Use a while loop to search for the SKU
        while (i < num_items && strcmp(item_list[i].sku, search_sku) != 0) {
            i++;
        }
        if (i < num_items) {
            // print the item's details
            printf("Item found:\n");
            printf("Item name = %s\n", item_list[i].name);
            printf("Item sku = %s\n", item_list[i].sku);
            printf("Item category = %s\n", item_list[i].category);
            printf("Item price = %f\n", item_list[i].price);
        } else {
            // If not found, print not found message
            printf("Item not found.\n");
        }
    }

    // Free allocated memory
    free_items(item_list, num_items);
    free(item_list); // Free array

    return 0;
}