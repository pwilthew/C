/* Name: product2.c
 * Description: Gets a file with products sold with price and quantity
 * and a product name to search for and will print that product's info
 * Student: Patricia Wilthew.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[15];
    double unit_price;
    double pounds_sold;
    double sale_volume;
    
};

struct product make_product(char *name, double unit_price, double pounds_sold);
void print_product(struct product p);
void selection_sort(struct product p[], int n);
void find_product(struct product p[], int n, char *name);

int main(int argc, char *argv[]) {

    if (argc != 2) {
    
        printf("Usage: ./a.out productname\n");
        return(1);
    }

    //argv[1] contains the product name to search for 

    //a product instance called p
    struct product p;

    //array of products
    struct product products[1000];

    //input and output files' pointers
    FILE *input_file;
    input_file = fopen("sale.txt", "r");

    //attributes of a product, in this case to give a value to p
    char name[15];
    double unit_price;
    double pounds_sold;

    int i = 0;

    //verify that file exists and can be read
    if (input_file == NULL) {
 
        printf("Can't open file\n");
    }

    //create an array of products
    while (fscanf(input_file, "%s", name)==1) { //first word of a line contains name of product

        fscanf(input_file, "%lf", &unit_price); //second number of a line contains price of product
        fscanf(input_file, "%lf", &pounds_sold); //third number of a line contains pounds sold of product

        p = make_product(name, unit_price, pounds_sold); //make a product with the previous data

        products[i++] = p; //add product to array of products

     }

    find_product(products, i, argv[1]);
    
    fclose(input_file);

    return(0);
}

/* Function: make_product()
 * Input: name, unit price, and pounds sold of a product
 * Output: a product (struct)
 */
struct product make_product(char *name, double unit_price, double pounds_sold) {

    struct product p;

    strcpy(p.name, name);
    p.unit_price = unit_price;
    p.pounds_sold = pounds_sold;
    p.sale_volume = unit_price * pounds_sold;

    return p;
}

/* Function: print_product()
 * Input: a product (struct) 
 * Output: void
 * Description: prints the data of a product 
 */ 
void print_product(struct product p) {

    printf("Name: %s\n", p.name);
    printf("Unit Price: %lf\n", p.unit_price);
    printf("Number of Pounds Sold: %lf\n", p.pounds_sold);
    printf("Sale Volume: %lf\n", p.sale_volume);

}

/* Function: find_product()
 * Input: a product (struct) array and its size and a name to search for
 * Output: void
 * Description: print the info corresponding to the product name
 */
void find_product(struct product p[], int n, char *name) {

    int i;

    for (i = 0; i < n; i++) {

        if (strcmp(name, p[i].name)==0) {
            break;
        }
    }

    if (i==n) 
        printf("Product not found.\n");

    else 
        print_product(p[i]);
}


