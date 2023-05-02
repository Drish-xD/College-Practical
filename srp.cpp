#include <iostream>
#include <string.h>

using namespace std;

struct prodn {
  char p1[10];
  char p2[10];
};

int main() {
  printf("Drish RA2011030030026\n");
  char input[20], stack[50] = "", temp[50], ch[2], *t1, *t2, *t;
  int i, j, s1, s2, s, count = 0;
  struct prodn p[10];

  cout << "Enter the productions (one per line, format: LHS->RHS):\n";
  while (true) {
    cin.getline(temp, 50);
    if (strlen(temp) == 0) {
      break;
    }
    t1 = strtok(temp, "->");
    t2 = strtok(NULL, "->");
    strcpy(p[count].p1, t1);
    strcpy(p[count].p2, t2);
    count++;
  }

  cout << "\nEnter the Input String:\n";
  cin >> input;

  i = 0;
  while (true) {
    if (i < strlen(input)) {
      ch[0] = input[i];
      ch[1] = '\0';
      i++;
      strcat(stack, ch);
      cout << "\n"
           << stack;
    }

    for (j = 0; j < count; j++) {
      t = strstr(stack, p[j].p2);
      if (t != NULL) {
        s1 = strlen(stack);
        s2 = strlen(t);
        s = s1 - s2;
        stack[s] = '\0';
        strcat(stack, p[j].p1);
        cout << "\n"
             << stack;
        j = -1;
      }
    }

    if (strcmp(stack, "E") == 0 && i == strlen(input)) {
      cout << "\n\nAccepted";
      break;
    }
    if (i == strlen(input)) {
      cout << "\n\nNot Accepted";
      break;
    }
  }

  return 0;
}
