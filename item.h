#ifndef ITEM_H
#define ITEM_H

struct _Item {
    double price;      
    char *sku;         
    char *name;        
    char *category;    
};

// Create alias 'Item' for the struct to make it easier to refer to.
typedef struct _Item Item;

#endif