#include "/players/wocket/closed/ansi.h"

int pagenumber;
string *booktext;
string booktitle;
id(str){ return (str == "book" || str == booktitle); }

short(){ 
string str;
  str = HIB+booktitle+NORM+" (book)";
return str;
}

long(){
  write("This is a fine leather book entitled \""+HIB+booktitle+NORM+"\".\n"+
        "It's soft brown cover and light crisp pages gives the \n"+
        "impression of prestique.  You may 'read page #' to enjoy\n"+
        "all this book has to offer.\n"+
        "    The book contains:\n"+pagenumber+" pages\n");
}

reset(){
  booktext = ({});
  pagenumber = 0;
  booktitle = "book";
}

init(){
  add_action("read_page","read");
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
query_wocketbook(){ return 1; }
get(){ return 1; }
drop(){ return 0; }