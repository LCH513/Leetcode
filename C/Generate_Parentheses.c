//Catalan Number: 1, 1, 2, 5, 14, 42, 132, 429, 1430....

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void generate(int left, int right, int current_index, int *returnSize, char *current_solution, char **result){
    if(left == 0 && right == 0){
        result[*returnSize] = (char*)calloc((current_index + 1) , sizeof(char));
        strcpy(result[*returnSize],current_solution);
        (*returnSize)++;
        return;
    }
    if(left > 0){
        current_solution[current_index] = '(';
        generate(left - 1, right, current_index + 1, returnSize, current_solution, result);
    }
    
    if(right > left){
        current_solution[current_index] = ')';
        generate(left, right - 1, current_index + 1, returnSize, current_solution, result);
    }
    
}


char ** generateParenthesis(int n, int* returnSize){
    int solutionlength = 2 * n + 1;
    int current_index = 0;
    char *current_solution = (char*)calloc(solutionlength, sizeof(char));
    char **result = (char**)calloc(1430, sizeof(char*));
    *returnSize = 0;
    generate(n, n, current_index, returnSize, current_solution, result);
    return result;
}
