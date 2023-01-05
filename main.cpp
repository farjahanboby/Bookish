#include <bits/stdc++.h>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std; //something

//for both linux and windows compiler
void clear_screen()
{
#ifdef _WIN32
  system("CLS");
#else
  system("clear");
#endif
}

// Doubly link list
typedef struct Node
{
  struct Node *prev;
  int ID;
  char name[100];
  int price;
  int quantity;
  struct Node *next;
} node;

//============FILE OPERATIONS ===============================================
void add_sale(node *, int);
void display_info(string);
void add_info();
void delete_info();
void display_sale_list();
void delete_all_records();
//Doubly link list function
void getinfo();
void insertatend(int, char[100], int, int);
void display_list();
void print_invoice();
void remove_from_list();

int choice;
bool check_exit;

#include "fileop.h"
#include "doublyfunc.h"

//==========================================================================

void adminfunc();
void customer_func();
int main(void)
{
  check_exit = false;
  while (1)
  {
    if (check_exit == true)
      return 0;
    clear_screen();
    cout << "\n\n\t\t=====================================";
    cout << "Welcome to Bookish";
    cout << "=====================================\n";
    cout << "\n\t\t\t1. Admin\n\n\t\t\t2. Customer\n\n\n";
    cout << "\t\t\tEnter choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      adminfunc();
      cout << "\t\t\tPress any key to continue..." << endl;
      getchar();
      getchar();
      break;
    case 2:
      customer_func();
      cout << "\t\t\tPress any key to continue..." << endl;
      getchar();
      getchar();
      break;
    }
  }
  return 0;
}

void adminfunc()
{
  while (1)
  {
    clear_screen();
    cout << "\n\n\t\t\t1. Insert new item\n\n\t\t\t2. Display items\n\n\t\t\t3. Delete particular item\n\n\t\t\t4. Delete all items\n\n\t\t\t5. Display sale list\n\n\t\t\t6. Change interface\n\n\t\t\t7. Exit" << endl;
    cout << "\n\t\t\tYour choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:

      add_info();
      cout << "\t\t\tPress any key to continue..." << endl;
      getchar();
      getchar();
      break;
    case 2:

      display_info("info.txt");
      cout << "\t\t\tPress any key to continue..." << endl;
      getchar();
      getchar();
      break;
    case 3:
      delete_info();
      cout << "\t\t\tPress any key to continue..." << endl;
      getchar();
      getchar();
      break;
    case 4:
      delete_all_records();
      cout << "\t\t\tPress any key to continue..." << endl;
      getchar();
      getchar();
      break;
    case 5:
      display_sale_list();
      cout << "Press any key to continue..." << endl;
      getchar();
      getchar();
      break;
    case 6:
      return;
      break;
    case 7:
      check_exit = true;
      return;
    default:
      break;
    }
  }
}

void customer_func()
{

  while (1)
  {
    clear_screen();
    cout << "\n\n\t\t\tYour current items == " << endl;
    display_list();
    cout << "\n\n\t\t\t1. Add items to cartt\n\n\t\t\t2. Remove items from cart\n\n\t\t\t3. Print Invoice\n\n\t\t\t4. Change interface\n\n\t\t\t5. Exit\n";
    cout << "\n\t\t\tYour Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      clear_screen();
      getinfo();
      cout << "\t\t\tPress any key to continue..." << endl;
      getchar();
      getchar();
      break;
    case 2:
      remove_from_list();
      cout << "\t\t\tPress any key to continue..." << endl;
      getchar();
      getchar();
      break;
    case 3:
      print_invoice();
      getchar();
      getchar();
      break;
    case 4:
      return;
      break;
    case 5:
      check_exit = true;
      return;
    default:
      break;
    }
  }
}