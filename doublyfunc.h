#ifndef DOUBLYFUNC_H
#define DOUBLYFUNC_H

node *head, *tail, *temp, *temp1;
int total_count = 0;

//takes info from the user and adds to the list
void getinfo()
{
  string name;
  int id, price;
  display_info("info.txt");
  int buy, i = 1;
  cout << "\t\t\tWhich book do you want to buy? \n\n\t\t\tYour choice: " ;
  cin >> buy;
  string line;
  ifstream file;
  file.open("info.txt");
  for (line; getline(file, line);)
  {
    istringstream input(line);
    if (i == buy)
    {
      input >> id;
      input >> price;
      getline(input, name);
      char name1[name.length() + 1];
      strcpy(name1, name.c_str());
      while (head != NULL)
      {
        if (head->ID == id)
        {
          head->quantity++;
          head = temp1;
          return;
        }
        head = head->next;
      }
      head = temp1;
      //insertion done here
      insertatend(id, name1, price, 1);
      total_count++;
      break;
    }
    else
      i++;
  }
}
// insertion function
void insertatend(int id, char name[100], int price, int quantity)
{

  temp = (node *)malloc(1 * sizeof(node));
  temp->prev = NULL;
  temp->next = NULL;
  temp->ID = id;
  temp->price = price;
  temp->quantity = quantity;
  strcpy(temp->name, name);
  if (head == NULL)
  {
    head = tail = temp;
    temp1 = head;
  }
  else
  {
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
}
// prints the list 
void display_list()
{
  int i = 1;
  cout << "\n\t\t\t================================================================" << endl;
  if (head == NULL)
  {
    cout << "\t\t\tThe list is empty." << endl;
    cout << "\t\t\t================================================================" << endl;
    return;
  }
  while (head != NULL)
  {
    printf("\t\t\t%d. Book name: %s; Price: %dtk Qty.: %d\n", i, head->name, head->price, head->quantity);
    i++;
    head = head->next;
  }
  cout << "\t\t\t================================================================" << endl;
  head = temp1;
}

// deletion function
void remove_from_list()
{
  clear_screen();
  display_list();
  //base condition
  if (head == NULL)
    return;
  cout << "\n\t\t\tWhich line do you want to remove??" << endl;
  cout << "\n\n\t\t\tYour choice: ";
  cin >> choice;
  node *del;
  del = head;
  int i = 1;
  // newcode
  node* nodetodel;
  //transverse to the node that needs to be deleted
  for (int j = 1; j < choice && del != NULL; j++)
  {
    del = del -> next;
  }

  // -1 quantity of more than 1
  if (del->quantity > 1)
  {
    del->quantity--;
    return;
  }
  // if first node is to be deleted
  if (choice == 1)
  {
    
    if (head == NULL)
    {
      cout << "List is empty!!!" << endl;
      return;
    }
    // incase only one item in the list exist
    if (total_count = 1)
    {
      head = del -> next;
      temp1 = head;
    }
    else
    {
      nodetodel = head;
      head = head -> next;
      head -> prev = NULL;
      temp1 = head;
      free(nodetodel);
      total_count--;
    }
  }
  // for last node in the list
  else if (del == tail)
  {
    if (tail == NULL)
    {
      cout << "List is empty" << endl;
      return;
    }
    else{
      nodetodel = tail;
      tail = tail -> prev;
      tail -> next = NULL;
      free(nodetodel);
      total_count--;
    }
  }
  // for nodes in the middle
  else if (del != NULL)
  {
    del -> prev -> next = del -> next;
    del -> next -> prev = del -> prev;
    free(del);
    total_count--;
  }
  else
  {
    cout << "The given position is invalid" << endl;
  }
}
void print_invoice()
{
  clear_screen();
  if (head == NULL)
  {
    cout << "\n\t\t\tYour list is empty";
    return;
  }
  float totalPrice = 0;
  printf("\t\t================================================================================\n");
  printf("\t\t=============================INVOICE============================================\n");
  while (head != NULL)
  {
    printf("\t\t\tID: %d   Name: %s   TK: %d   Qty.: %d", head->ID, head->name, head->price, head->quantity);
    cout << endl;
    totalPrice += (head->quantity * head->price);
    head = head->next;
  }
  head = temp1;
  float vat = 0;
  vat = totalPrice * 0.15;
  totalPrice = vat + totalPrice;
  printf("\n\n\t\t\tVAT(15%): %.2f\n\t\t\tTOTAL: %.2f", vat, totalPrice);
  //defined in file operation; tracks sale list
  add_sale(head, totalPrice);
  cout << "\n\t\t\tThank you for you purchase!!!" <<endl;
  exit(1);
}

//==================================================================================================
#endif