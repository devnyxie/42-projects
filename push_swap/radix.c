#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

void print_bucket(struct node *bucket) {
    if (!bucket) {
        // printf("bucket empty\n");
        return;
    }

    struct node *curr = bucket;
    while (curr) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void print_all_buckets(struct node *buckets[]) {
    int i = 0;
    while (i < 10) {
        print_bucket(buckets[i]);
        i++;
    }
}

int find_largest(int *arr, size_t size) {
    int result = arr[0];
    int i = 1;
    while (i < size) {
        if (result < arr[i]) {
            result = arr[i];
        }
        i++;
    }
    return(result);
}

int count_digits(int num) {
    int result = 1;
    while (num > 0) {
        num /= 10;
        result++;
    }
    return result;
}

int get_digit_offset(int num, int offset) {
    if (offset == 0)
        return num % 10;
    
    int result = num;
    while (offset--) {
        result /= 10;
    }
    return result % 10;
}

struct node *findLast(struct node *bucket) {
    if (!bucket) return NULL;

    while (bucket->next) {
        bucket = bucket->next;
    }
    return bucket;
}

void push(struct node *buckets[], int bucket, int value) {
    struct node *new = malloc(sizeof(struct node));
    if (!new)
        return;
    
    new->data = value;
    new->next = NULL;
    if (!buckets[bucket]) {  
        // printf("setting as head\n");
        // Set as head if empty
        buckets[bucket] = new;
    } else {
        // printf("setting as NON head\n");
        struct node *last = findLast(buckets[bucket]);
        last->next = new;
    }
}

void free_buckets(struct node *buckets[]) {
    for (int i = 0; i < 10; i++) {
        struct node *curr = buckets[i];
        while (curr) {
            struct node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

void radix_sort(int *arr, size_t arr_size) {
    if (!arr_size || arr_size == 1) {
        return;
    }
    int largest = find_largest(arr, arr_size);
    int largest_digits_count = count_digits(largest);
    int sorted_count = 0;

    // max amount of digits = max loops
    while (largest_digits_count > sorted_count) {
        printf("=== iteration %d === \n", sorted_count);
        struct node *buckets[10] = {NULL};
        int i = 0;
        // Loop through each digit
        while (i < arr_size) {
            int bucket_digit = get_digit_offset(arr[i], sorted_count);
            push(buckets, bucket_digit, arr[i]); 
            i++;           
        }
        
        // 1. After setting buckets, go through each sub-bucket and assign values directly to *arr
        i = 0;
        for (int j = 0; j < 10; j++) {
            struct node *curr = buckets[j];
            while (curr) {
                arr[i++] = curr->data;
                curr = curr->next;
            }
        }

        print_all_buckets(buckets);
        
        // 2. Free all subnodes
        free_buckets(buckets);
        
        sorted_count++;
    }
}

int main(void) {
    size_t size = 3;
    // int data[] = {12, 10, 2, 19, 1000};
    int data[] = {400, 22, 3};

    radix_sort(data, size);

    // After sorting, print the result
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    return 0;
}
