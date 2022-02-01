int compare(int a, int b) {
  if (a > b)
    return 1;
  if (a < b)
    return -1;
  return 0;
}

//Week 11 question 1

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

//Week 11 question 2

void sort(int array[], int n)
{
  int i, j, temp;
  for(i = 0; i < n - 1; i++){
    for(j = i + 1; j < n; j++){
      if(array[j] < array[i]){
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

//Week 11 question 3

int elementAt(int *pointer, int n)
{
  return *(pointer + n-1);
}

//Week 12 Question 1

int between(int *a, int *b)
{
  int *i, sum = 0;
  for(i = a; i<b; i++)
  {
    sum += *(i);
  }
  return sum;
}

//Week 12 question 2

int merger(int *a, int *b, int *c)
{
    int i, j;
   for(i=0; i<5; i++)
   {
       c[i] = a[i];
   }
    for(j=0; j<5; j++)
   {
       c[j+i] = b[j];
   }
sort (c);
}
void sort(int array[])
{
   for (int i=0; i <10; i++)
   {
     int smallest = array[i];
     int min_index = i;
     for (int index = i + 1; index < 10; index++)
     {
     	if (array[index] < smallest)
        {
          	smallest = array[index];
          	min_index = index;
        }
     }
   int temp = array[i];
     array[i] = array[min_index];
     array[min_index] = temp;
   }
}

//Week 12 question 3

char *mystrcat(char *dest, char *src)
{
    char *a=dest;
    char *b=src;
    while (*a!='\0')
    {
        a++;
    }
    while (*b!='\0')
    {
        *a=*b;
         a++;
         b++;
    }
    *a='\0';
  return dest;
}
char *mystrncat(char *dest, char *src, int n)
{
    char *a=dest, *b=src;
     while (*a!='\0')
    {
        a++;
    }
    int i;
    for(i=0; *b!= '\0' && i<n; i++)
    {
        *a=*b;
        a++;
        b++;
    }
    *a='\0';
  	return dest;
}

//Week 13 question 1

char *trim(char *dest)
{
    char *c = dest; // dest = "   abc   "
    while (*c == '\n' || *c == ' ' || *c == '\t')
        c++;
    char *t = dest;
    while (*c)
        *(t++) = *(c++);
    *t = '\0'; // dest = "abc   "
    do {
        t--;
    } while (*t == '\n' || *t == ' ' || *t == '\t');
    *(t+1) = '\0'; // dest = "abc"
 return dest;
}

//Week 13 question 2

#include <stdio.h>
#include <string.h>
#define MAX 100

int backward_sentence()
{
    char reverse_str[MAX];

    if(scanf("%s", &reverse_str) == 1)
    {
        backward_sentence();
        printf("%s ", reverse_str);
    }
    return 0;
}
int main()
{
    backward_sentence();
}

//Week 13 question 4

#include<stdio.h>
#include<string.h>
int main(){

    int num_words, i, j;
    scanf("%d", &num_words);
    char string[num_words][100];

    for(i=0; i<num_words; i++)
    {
        scanf("%s", string[i]);
    }

    char temp[100];
    for (i = 0; i<num_words-1; i++)
    {
        for(j = i+1; j<num_words; j++)
        {
            if(strcmp(string[i], string[j])>0)
            {
                strcpy(temp, string[i]);
                strcpy(string[i], string[j]);
                strcpy(string[j], temp);
            }
        }
    }

    for(i=0; i<num_words; i++)
    {
        printf("%s\n", string[i]);
    }
return 0;
}

//Week 14 question 3

#include<stdio.h>
void func(int row, int col, int matrix[row][col], int row_start, int row_end, int col_start, int col_end);
int main(){

    int i, j, row, col;
    scanf("%d %d", &row, &col);
    int array[row][col];

    for (i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    func(row, col, array, 0, row, 0, col);

return 0;
}

void func(int row, int col, int matrix[row][col], int row_start, int row_end, int col_start, int col_end)
{
     int i, j;

    {
        for(j = col_start; j<col_end; j++)
        {
            i = row_start;
            printf("%d ", matrix[i][j]);
        }
        row_start++;

        for(i=row_start; i<row_end; i++)
        {
            j = col_end-1;
            printf("%d ", matrix[i][j]);
        }
        col_end--;

        for(j = col_end-1; j>=col_start; j--)
        {
            i = row_end-1;
            printf("%d ", matrix[i][j]);
        }
        row_end--;

        for(i = row_end-1; i>=row_start; i--)
        {
            j = col_start;
            printf("%d ", matrix[i][j]);
        }
        col_start++;

        if(row_start < row_end && col_start < col_end)
        {
            func(row, col, matrix, row_start, row_end, col_start, col_end);
        }

    }
}

//Week 15 question 1

#include<stdio.h>

int parser(char *expr, int *n)
{
    while(expr[*n] == ',' || expr[*n] == '(' || expr[*n] == ')')
        (*n) ++;
    if(expr[*n] == 'F')
    {
        (*n) ++;
        return parser(expr, n) + 1;
    }
    else if(expr[*n] == 'G')
    {
        (*n) ++;
        return parser(expr, n) + parser(expr, n);
    }
    else
    {
        int temp = 0;
        while(expr[*n] >= '0' && expr[*n] <= '9')
        {
            temp = temp * 10 + expr[*n] - '0';
            (*n) ++;
        }
        return temp;
    }
}

int main()
{
    int n = 0;
    char input[10000];
    gets(input);
    printf("%d", parser(input, &n));
}

//Week 15 question 2

#include<stdio.h>
#include<string.h>

void reverse(char *a)
{
    if(*a)
    {
        reverse(a+1);
        printf("%c", *a);
    }
}
int main (){
    char a[100];
    scanf("%s", &a);
    reverse(a);
return 0;
}

//Week 15 question 3

#include<stdio.h>
#include<string.h>
int main(){

    int i, j, bulls=0, cows=0;
    char secret_number[10];
    scanf("%s", &secret_number);
    char guess[10];
    scanf("%s", &guess);

    for(i=0; i<strlen(secret_number); i++)
    {
        for(j=0; j<strlen(guess); j++)
        {
            if(secret_number[i]==guess[j])
            {
                cows++;
                if(i==j)
                {
                    bulls++;
                    cows--;
                }
            }
        }
    }

    printf("%d %d", bulls, cows);

return 0;
}

//Week 16 question 2

#include<stdio.h>
#include<stdbool.h>
#define MAX 5
#define TOTAL 25

typedef struct{
    int bingoCard[MAX][MAX];
    int winAt;
    int index;
}Cards;

bool checkPattern(int pattern[], int length, Cards student);
bool checkExist(int arr[], int position, int number);
bool findStudent(int studentNum, int length, Cards arr[]);

int main(void){
   int students;

   scanf("%d", &students) ;
   Cards card[students];
   int teacher[TOTAL];
   int winnerPositions[TOTAL] = {0};
   int winners = 0;

    //collect student cards
    for (int i = 0; i < students; i++){
        for (int j = 0; j < MAX; j++){
            for (int k = 0; k < MAX; k++){
                scanf("%d", &card[i].bingoCard[j][k]);
            }
        }
        card[i].winAt = - 1; //initialize winning position
        card[i].index = i + 1;
    }

    //collect teachers scores
    for (int j = 0; j < TOTAL; j++){
        scanf("%d", &teacher[j]);
    }

    //start from 5th element (nobody wins when we don't have at least 5 numbers)
    int position = MAX - 1; //index 4

    //check bingo winners until all have won
    while(winners < students){
        for(int i = 0; i < students; i++){
                if(checkPattern(teacher, position, card[i])){
                    if(card[i].winAt == -1){
                        card[i].winAt = position;
                        winners++;
                        winnerPositions[position]++;
                    }
                }
        }
        position++;
    }

    //print winners
    for (int j = MAX - 1; j < TOTAL; j++){
        if (winnerPositions[j] > 0 ){
            printf("%d:", j+1);
            for(int i = 0; i < students; i++){
                if(card[i].winAt == j){
                    printf(" %d", card[i].index);
                }
            }
                printf("\n");
        }
    }

   return 0;
}

bool checkPattern(int pattern[], int length, Cards student){
    int count = 0;

    //check rows
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if(checkExist(pattern, length, student.bingoCard[i][j]))
                count++;
        }
        if(count == 5)
            return true;
        count = 0;
    }

    //check columns
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if(checkExist(pattern, length, student.bingoCard[j][i]))
                count++;
        }
        if(count == 5)
            return true;
        count = 0;
    }

    //check diagonal right
    for (int i = 0; i < MAX; i++){
        if(checkExist(pattern, length, student.bingoCard[i][i]))
            count++;
        if(count == 5)
             return true;
    }

    count = 0;

//    check diagonal left
    for (int i = 0; i < MAX; i++){
        if(checkExist(pattern, length, student.bingoCard[i][(MAX - 1) - i]))
            count++;
        if(count == 5)
             return true;
    }

    count = 0;

    return false;
}

bool checkExist(int arr[], int position, int number){
    for(int i = 0; i <= position; i++){
        if(number == arr[i]){
            return true;
        }
    }

    return false;
}

bool findStudent(int studentNum, int length, Cards arr[]){
    for(int i = 0; i <= length; i++){
        if (arr[i].index == studentNum) return true;
    }
    return false;
}

//Week 16 question 3
