#ifndef FILEOP_H
#define FILEOP_H

string garbage;
int garbageint;

// displays all items in the info.txt
void display_info(string a)
{
  clear_screen();
  string line, line1;
  ifstream in;
  in.open(a);
  int i = 1;
  cout << "\n\t\t\t================================================================" << endl;
  for (line; getline(in, line);)
  {
    istringstream input(line);
    cout << "\t\t\t"<<i << ". ID: ";
    input >> garbage;
    cout << garbage << " ";
    input >> garbage;
    getline(input, line1);
    cout << "Name: "<< line1;
    cout << " Price: "<< garbage <<"tk"<< endl << endl;
    i++;
  }
  cout << "\n\t\t\t================================================================" << endl;
  in.close();
}
// takes input from user and adds them to text file
void add_info()
{
  clear_screen();
  ofstream file;
  file.open("info.txt", ofstream::out | ofstream::app);
  cout << "\n\t\t\tEnter ID: ";
  cin >> garbageint;
  file << garbageint << " ";
  cout << "\t\t\tEnter name of the book : ";
  cin.ignore();
  getline(cin, garbage);
  //file << garbage << " ";
  cout << "\t\t\tEnter price: ";
  cin >> garbageint;
  file << garbageint << " ";
  file << garbage << endl;
  file.close();
}
// deletes the info that the user choose
void delete_info()
{
  int line_delete;
  display_info("info.txt");

  cout << "\n\t\tWhich line do you want to remove: ";
  cin >> line_delete;
  int count = 1;

  string getcontent;

  ifstream file("info.txt");

  if (file.is_open())
  {
    while (!file.eof())
    {
      getline(file, getcontent);

      if (count != line_delete)
      {
        ofstream temp("temp.txt", ofstream::app | ofstream::out);

        if (getcontent.length() == 0)
        {
          continue;
        }
        temp << getcontent << endl;
      }
      count++;
    }
  }
  file.close();
  remove("info.txt");
  rename("temp.txt", "info.txt");
}
//deletes all items from the text file
void delete_all_records()
{
  ofstream file;
  file.open("temp.txt", ofstream::app | ofstream::out);
  file.close();
  remove("info.txt");
  rename("temp.txt", "info.txt");
}

// Adds the sales done in customer function
void add_sale(node *temp3, int total)
{
  time_t current_time = time(NULL);
  ofstream file;
  file.open("sale_track.txt", ofstream::app | ofstream::out);
  int i = 1;
  file << "Date: " <<ctime(&current_time);
   while (temp3 != NULL)
  {
        file << i << ". "<< temp3 -> ID  << " "<< temp3->name  << " " << temp3->price << "tk" << " Qty. : " << temp3 -> quantity <<endl; 
    temp3 = temp3->next;
    i++;
  }
  file << "*. Total sale: " << total << endl;
  file.close();
}

void display_sale_list()
{
  string line;
  int i = 1;
  ifstream(file);
  file.open("sale_track.txt");
  for (line; getline(file, line);)
  {
    istringstream input(line);
    input >> garbage;
    if (garbage == "Date:")
    {
      cout << "\n\t\tDate: ";
      getline(input, garbage);
      cout << garbage << endl;
      continue;
    }
    getline(input, garbage);
    cout << "\n\t\t\t" << garbage << endl;
  }
}

#endif