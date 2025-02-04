#include <stddef.h>
#include <stdio.h>

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

char get_val(char **area, t_point node){
    return(area[node.y][node.x]);
}

void check_val(char **area, t_point node){
    area[node.y][node.x] = 'F';
}

int is_valid(char **area, t_point size, t_point node, char c){
    if (node.x < 0 || node.x >= size.x || node.y < 0 || node.y >= size.y)
        return(-1);
    char next_node_val = get_val(area, node);
    if(next_node_val != c)
        return(-1);
    return(1);
}

void traverse(char **area, t_point size, t_point node, char c){
    if(is_valid(area, size, node, c) == 1){
        check_val(area, node);
        t_point arr[] = {
            {node.x, node.y+1}, //top
            {node.x, node.y-1}, //bottom
            {node.x+1, node.y}, // right
            {node.x-1, node.y} // left
        };
        int i = 3;
        while(i >= 0){
            t_point next_node = arr[i];
            traverse(area, size, next_node, c);
            i--;
        }
    }
}

void flood_fill(char **area, t_point size, t_point begin){
    char c = get_val(area, begin); // starting character
    // t_point size_corrected = {size.x-1, size.y-1};
    traverse(area, size, begin, c);
}