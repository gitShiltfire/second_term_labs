#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


char** str_split(char* a_str, const char a_delim){
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;
    //Count how many elements will be extracted.
    while (*tmp){
      if (a_delim == *tmp){
        count++;
        last_comma = tmp;
      }
      tmp++;
    }
    //Add space for trailing token.
    count += last_comma < (a_str + strlen(a_str) - 1);
    //Add space for terminating null string so caller
    //knows where the list of returned strings ends.
    count++;
    result = (char**)malloc(sizeof(char*) * count);
    if (result){
      size_t idx  = 0;
      char* token = strtok(a_str, delim);
      while (token){
        assert(idx < count);
        *(result + idx++) = strdup(token);
        token = strtok(0, delim);
      }
      assert(idx == count - 1);
      *(result + idx) = 0;
    }
    return result;
}
char *input_str(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
  char *str;
  int ch;
  int len = 0;

  str = (char*) realloc(NULL, size * sizeof(char));//size is start size

  if(!str) return str;
  while (EOF != (ch = fgetc(fp)) && ch != '\n'){
    str[len++] = ch;
    if(len == size){
      str = (char*)realloc(str, sizeof(*str)*(size+=16));
      if(!str) return str;
    }
  }

  str[len++]='\0';
  return (char*)realloc(str, sizeof(*str)*len);
}
int** dynamic_array_alloc(size_t N) {
  int** A = (int**)malloc(N * sizeof(int*));
  char * hlst = input_str(stdin, 10); //холостое считывание
  for (int i = 0; i < N; i++) {
    A[i] = input_str(stdin, 10);
  }
  return A;
}
void print_arr(char **arr, int n){
  for (int i = 0; i < n; i++){
    printf("%s ", arr[i]);
  }
}
int count_chr(char symbol, char* str){
  int count = 0;
  for (int i = 0; i < strlen(str); i++){
    if (str[i] == symbol) count++;
  }
  return count;
}

int the_statement_is_prime(char* statement, char** identifiers, int count) //массив идентификаторов
{
                                                                              /*
                    строка проходит проверку на простое выражение в 3 этапа:
                    1)проверяется, всё что находится за скобками
                    2)проверяется количество скобок
                    3)проверяется выражение в самых вложенных скобках, если оно верно,
                      то выражение в скобках заменяется на один символ 'A'
                                                                              */
  int flag = 1;

  //первая проверка
  if (count_chr('(', statement) != count_chr(')', statement)) flag = 0;

  //проверим символы за скобками
  if ((strchr(statement, '(') - statement) != 0){
    int count_l = 0;
    if (strchr("0123456789", statement[count_l])){
      count_l//проверка на <числовое значение>
      while (strchr("0123456789", statement[count])){

      }
  }

    // индекс последней скобки ( = strrchr(statement, '(') - statement{
        // индекс первой скобки ) = strchr(statement, ')') - statement

  }
  if (strchr("0123456789", statement[count])){ //проверка на <числовое значение>
    count++;
    while (strchr("0123456789", statement[count])){
      count++;
    }
  }

  else if (strchr("abcdefghijklmnopqrstuvwxyz", statement[count])){ //проверка на <идентификатор>
    count++;
    while (strchr("abcdefghijklmnopqrstuvwxyz0123456789_", statement[count])){
      count++;
    }
  }
  return flag;
}



char *str_replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}
int main(){
  int N; scanf("%d", &N);
  char** identifiers = dynamic_array_alloc(N);
  char *statement = input_str(stdin, 10);
  char* str = "(10+(b*(a-5)))";

  //printf("%d", count_chr('(', str));
  //scanf("%s", &statement);
  //printf("%s", statement);

}

