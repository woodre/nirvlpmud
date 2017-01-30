/*
File: writebook.c
Author: Feldegast @ nirvana.mudservices.com
Date: 3-4-01
Description:
  This is a book that players can write in.  It is specifically designed
for a library to be placed in Nirvana's village.
*/
#define MAX_PAGES 10
#define MAX_LINES 25
#define SAVE_PATH "/players/feldegast/library/temp/"

inherit "/obj/treasure.c";

string title;
string author;
string *page;

static int writing_page;
static int line_count;

string query_title() { return title; }
string query_author() { return author; }

void reset(int arg) {
  if(arg) return;
  set_id("book");
  set_alias("library of nirvana writebook");
  set_short("A leather-bound book");
  set_long(
"This is a leather-bound book with blank loose-bound pages which\n\
you can read and write upon.  It is a work-in-progress, and comes\n\
with a quill pen and a pot of ink.\n\
Commands:\n\
  read page #\n\
  write page #\n\
  title book\n"
  );
  set_weight(2);
  set_value(1000);
  page=allocate(10);
}

void init() 
{
  add_action("cmd_read","read");
  add_action("cmd_write", "write");
  add_action("cmd_title", "title");
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

int cmd_write(string str) 
{
  int page_number;
  if(sscanf(str,"page %d", page_number)!=1) {
    notify_fail("Usage: write page #\n");
    return 0;
  }
  if(page_number!=1 && !page[page_number-1]) {
    write("You must write page "+(page_number-1)+" first.\n");
    return 1;
  }
  if(page_number > MAX_PAGES) {
    write("You cannot write more than "+MAX_PAGES+" pages.  If you wish to write\n"+
          "more pages and have a good reason for doing so, then speak to Feldegast\n"+
          "about getting a special book with extra pages.\n"
    );
    return 1;
  }
  write(
"Enter the text you want placed on page "+page_number+".  You may type\n\
up to "+MAX_LINES+" lines.  When you are done entering text, put ** on the last\n\
line.  You may abort by entering ~q.\n]"
  );
  say((string)this_player()->query_name()+" starts writing in a book.\n");
  writing_page=page_number;
  line_count=0;
  page[page_number]="";
  input_to("write_line");
  return 1;
}

void write_line(string str)
{
  line_count++;
  if(str=="**")
    write("Done.\n");  
  else if(str=="~q") {
    write("Aborted.\n");
    page[writing_page]=0;
  }
  else {
    if(strlen(str) > 70) {
      write("The line cannot be longer than 70 characters.  Please enter it again.\n");
      line_count--;
    }
    else
      page[writing_page]+=str+"\n";
    if(line_count < MAX_LINES) {
      write("]");
      input_to("write_line");
    }
  }
}

int cmd_title(string str) {
  if(str=="book") {
    write("Please enter a title for this book: ");
    input_to("input_title");
    return 1;
  }
  notify_fail("Title book?\n");
}

void input_title(string str) {
  if(strlen(str) > 40)
    write("That title is too long.\n");
  else {
     write("You title the book '"+str+"'.\n");
     title=str;
  }
}

int query_save_flag() { return 1; }

string short() {
  if(title)
    return "A book entitled, '"+title+"'";
  else
    return (string)::short();
}

int save_to_file(string dir) {
  string file;
  file=implode(explode(title," "),"_");
  if(exists(file)) {
    write("There is already a book by that name.  Try changing the title.\n");
    return -1;
  }
  if(this_player())
    author=(string)this_player()->query_name();
  save_object(dir+file);
  return 0;
}
