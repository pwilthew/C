/* Name: product.c
 * Description: Gets a file with products sold with price and quantity
 * and returns a file with sorted products but now including their sale
 * volume.
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
void print_product(struct product p, FILE *output_file);
void selection_sort(struct product p[], int n);

int main() {

    //a product instance called p
    struct product p;

    //array of products
    struct product products[1000];

    //input and output files' pointers
    FILE *input_file, *output_file;
    input_file = fopen("sale.txt", "r");
    output_file = fopen("sorted_products.txt", "w");

    //attributes of a product, in this case to give a value to p
    char name[15];
    double unit_price;
    double pounds_sold;

    int i = 0, j = 0;

    //verify that file exists and can be read
    if (input_file == NULL) {
 
        printf("Can't open file\n");
    }

    //for each line
    while (fscanf(input_file, "%s", name)==1) { //first word of a line contains name of product

        fscanf(input_file, "%lf", &unit_price); //second number of a line contains price of product
        fscanf(input_file, "%lf", &pounds_sold); //third number of a line contains pounds sold of product

        p = make_product(name, unit_price, pounds_sold); //make a product with the previous data

        products[i++] = p; //add product to array of products

     }
    
    //sort array of products by sale_volume
    selection_sort(products, i);

    //i is the total size of the array
    //write product data from the array to the output file
    for (j = 0; j < i; j++)
        print_product(products[j], output_file);

    //close both opened files
    fclose(input_file);
    fclose(output_file);

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
 * Input: a product (struct) and a file pointer
 * Output: void
 * Description: prints the data of a product in a file
 */ 
void print_product(struct product p, FILE *output_file) {

    fprintf(output_file, "%s\t", p.name);
    fprintf(output_file, "%lf\t", p.unit_price);
    fprintf(output_file, "%lf\t", p.pounds_sold);
    fprintf(output_file, "%lf\n", p.sale_volume);

}

/* Function: selection_sort()
 * Input: a product (struct) array and its size
 * Output: void
 * Description: given the array of products (structs), sorts them based on their sale_volume attribute
 */
void selection_sort(struct product p[], int n) {

    int i, largest = 0;
    struct product temp; 
    
    if (n == 1)
        return;

    for (i = 1; i < n; i++)
        if (p[i].sale_volume > p[largest].sale_volume)
            largest = i;

    if (largest < n - 1) {
        temp = p[n-1];
        p[n-1] = p[largest];
        p[largest] = temp;
    }

    selection_sort(p, n - 1);
}

