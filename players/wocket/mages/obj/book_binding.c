#include "/players/wocket/closed/ansi.h"

int pagenumber;
string *booktext;
string booktitle;
id(str){ return (str == "book" || str == "binding" || str == "wocketbook"); }

short(){ 
string str;
  str = "A book binding ";
  if(!pagenumber)
  str += "(empty)";
  else
  str += "("+pagenumber+" pages)";
return str;
}

long(){
  write("This is a leather book binding to hold pages.  This book can\n"+
        "be sealed and stored at most local scribes.  You can 'add_page's,\n"+
        "'remove_page's, or 'title_book' the book.  You may 'read page #'\nas well.\n"+
        "    This book is entitled: "+booktitle+"\n"+
        "    This book contains:\n"+pagenumber+" pages\n");

}


reset(){
  booktext = ({});
  pagenumber = 0;
}

init(){
  add_action("add_page","add_page");
  add_action("remove_page","remove_page");
  add_action("read_page","read");
  add_action("title_set","title_book");
}

title_set(str){
  if(!str){
  notify_fail("What you like to set the books title to?\n");
  return 0;
  }
  booktitle = lower_case(str);
  write("You set the books title to: "+str+"\n");
  return 1;
}

read_page(str){
string page;
int number;
if(!str){
  notify_fail("What would you like to read?\n");
  return 0;
}
if(sscanf(str,"%s %d",page,number)!= 2)
   page = str;
if(page == "book"){
  notify_fail("What page would you like to read?\n");
  return 0;
}
if(page != "page"){
  notify_fail("What would you like to read?\n");
  return 0;
}
if(!number){
  write("Which page would you like to read?\n");
  return 1;
}
if(number > pagenumber || number < 1){
  write("That page is not held within the book.\n");
  return 1;
}
write("You begin to read page number "+number+".\nIt reads:\n\n");
write(booktext[number-1]);
write("\n\t\tPage "+number+"\n");
return 1;
}

add_page(){
  string temptext;
  object page;
  page = present("wocketbookpage",this_player());
  if(!page){
  notify_fail("You do not have a page that can be bound to this book.\n");
  return 0;
  }
  write("You quickly sew a new page into your book.\n");
  temptext = (string) page->query_page_text();
  booktext += ({ temptext });
  pagenumber++;
  destruct(page);
  return 1;
}

remove_page(str){
int number;
object page;
if(!str){
  notify_fail("Which page would you like to remove?\n");
  return 0;
}
sscanf(str,"%d",number);
if(!number){
  notify_fail("Which page would you like to remove?\n");
  return 0;
}
if(number < 1 || number > pagenumber){
  notify_fail("That page is not held within the book.\n");
  return 0;
}
write("You carefully unsew the page from the book.\n");
page = clone_object("/players/wocket/mages/obj/blankpage.c");
page->set_page_text(booktext[number-1]);
move_object(page,this_player());
booktext -= booktext[number-1];
pagenumber--;
return 1;
}

query_booktitle(){ return booktitle; }
query_pagenumber(){ return pagenumber; }
query_booktext(i){ return booktext[i]; }
get(){ return 1; }
drop(){ return 0; }