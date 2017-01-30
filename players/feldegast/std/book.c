#include "/players/feldegast/defines.h"
#define PAGE_LENGTH 20
inherit "obj/treasure";

string book_file;

string *book_lines;
int pages;
int lines;
int current_line;

void set_file(string arg);
void show_page();
void book_prompt(string str);
int cmd_read(string arg);

void init() {
  ::init();
  add_action("cmd_read","read");
}

void set_file(string arg) {
  book_file=arg;
}

int cmd_read(string str) {

  string book_contents;

  notify_fail("Read what?\n");
  if(!str || !id(str)) return 0;
  if(!file_size(book_file)) {
    write("The lines of the text have become unreadable through\nyears of neglect.\n");
    return 1;
  }
  book_contents=read_file(book_file);
  lines=sizeof(explode(book_contents,"\n"));
  pages=lines/PAGE_LENGTH;
  current_line=1;
  book_prompt("");
  return 1;
}

void show_page() {
  int ep;
  if(PAGE_LENGTH+current_line > lines) ep=lines-current_line;
  else ep=PAGE_LENGTH;
  cat(book_file,current_line,ep);
}

void book_prompt(string str) {
  int ep;
  int pc;

  if(str=="") {
    if(current_line < lines) {
      show_page();
      current_line+=PAGE_LENGTH;
    }
    else
      write("You've reached the end of the text.\n");
  } 
  else if(str=="q" || str=="Q") return;
  else if(sscanf(str,"%d",pc)==1) {
    if(pc > 0 && pc <= pages+1) {
      current_line=(pc-1)*PAGE_LENGTH+1;
      show_page();
      current_line+=PAGE_LENGTH;
    }
    else write("The book does not have that many pages.\n");
  }
  write("Read: (1-"+(pages+1)+", q)");
  input_to("book_prompt");
}

