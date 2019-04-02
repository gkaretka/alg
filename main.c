#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char **game_field;
void find_largest_blob(int size);
int check_blobs_nearby(int num, int size);
int blobs[10];

int main(void *args)
{
  int size;

  scanf("%d", &size);
  printf("%dx%d\n", size, size);
  printf("%d\n", size*size);

  game_field = calloc(size*size, sizeof(char));

  for (int i = 0; i <= size*size; i++) {
    scanf("%c", &game_field[i]);
    if (i % size == 0 && i != 0) getchar();
  }

  for (int i = 0; i <= size*size; i++) {
    printf("%c", game_field[i]);
    if (i % size == 0 && i != 0) printf("\n");
  }
  
  find_largest_blob(size);

  for (int i = 0; i <= size*size; i++) {
    printf("%c", game_field[i]);
    if (i % size == 0 && i != 0) printf("\n");
  }

  return 0;
}

void find_largest_blob(int size)
{
  for (int i = 0; i <= size*size; i++) {
    int blob_size = check_blobs_nearby(i, size);
    if (blob_size != 0) {
      printf("blob of size %d starting at %d\n", blob_size, i);
    }
  }
}

int check_blobs_nearby(int num, int size)
{
  int sum = 0;
  if (game_field[num] == (char*)'1') {
    game_field[num] = (char*)'x';
    sum = 1;

    if (num - 1 > 0) {
      sum += check_blobs_nearby(num-1, size);
    }
    if (num + 1 <= size*size) {
      sum += check_blobs_nearby(num+1, size);
    }
    if (num - size > 0) {
      sum += check_blobs_nearby(num-size, size);
    }
    if (num + size <= size*size) {
      sum += check_blobs_nearby(num+size, size);
    }
  }

  return sum;
}

