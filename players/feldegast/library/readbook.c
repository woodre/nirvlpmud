/*
File: readbook.c
Author: Feldegast @ nirvana.mudservices.com
Date: 3-4-01
Description:
  This is a readable book.  To write a book, you need a writebook.
*/
#define SAVE_PATH "/players/feldegast/library/temp/"

string title;
string author;
string *page;

string query_title() { return title; }
string query_author() { return author; }

int id(string str) {
  return str=="book" ||
         str=="library of nirvana readbook";
}

string short() {
  if(title)
    return "A book entitled, '"+title+"' by "+author;
  else
    return "A leather bound book";
}

void long() {
  write(
"This is a leather-bound book with vellum pages.  On the spine is\n\
written '"+title+"'.\n\
Commands:\n\
  read page #\n");
}

query_weight() { return 2; }

query_value() { return 1000; }

void reset(int arg) {
  if(!arg)
    page=allocate(10);
}

void init() 
{
  add_action("cmd_read","read");
  add_action("restore_book", "restore");
}

int cmd_read(string str) {
  int page_number;
  if(sscanf(str,"page %d", page_number)!=1) {
    notify_fail("Usage: read page #\n");
    return 0;
  }
  if(!page[page_number]) {
    write("There is no page "+page_number+".\n");
    return 1;
  }
  write("[----------------------------= Page "+page_number+" =------------------------------]\n");
  write(page[page_number]);
  write("[--------------------------------------------------------------------]\n");
  return 1;
}

int restore_book(string str) {
  write("RB: "+str+"\n");
/*
  if(exists(str)) {
    write("Restoring...\n");
*/
    restore_object(str);
    return 0;
/*
  }
  write("File not found.\n");
  return -1;
*/
}

int query_save_flag() { return 1; }

