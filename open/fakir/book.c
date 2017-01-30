#include "../../defs.h"
inherit "/obj/treasure.c";

string *pages;
string title;
string alt_title;
int open;
int currentpage;
int save;

id(str){ return str == "book" || str == title || str == alt_title; }

short(){ 
  if(open){
    return title+" (book) (open)"; 
  }
  return title+" (book) (closed)";
}

long(){
  write("  A leather bound book entitled: "+YEL+title+OFF+".\n"+
        "Ribbons billow out of the crisp pages, slightly yellowed\n"+
        "by time.  The cover holds small cracks from much use but the\n"+
        "binding remains strong.  One could open the book to read,\n"+
        "and turn through the pages.  The book is currently ");
  if(open){
    write("open and on\npage "+BOLD+(currentpage+1)+OFF+" of "+BOLD+sizeof(pages)+OFF+".\n");
  }
  else{
    write("closed.\n");
  }
  write("Cmds: open book, close book, read book, turn page (tp), turn page back (tp -).\n");
  return 1;
}

reset(){
  save = 1;
  set_id("book");
  pages = ({ });
  no_clean = 1;
}

init(){
  add_action("open_book","open");
  add_action("close_book","close");
  add_action("turnpage","turn");
  add_action("turnpage","tp");
  add_action("read","read");      
}

open_book(str){
  if(!str){
    notify_fail("What would you like to open?\n");
    return 0;
  }
  if(present(str,this_player()) != this_object()){
    notify_fail("What would you like to open?\n");
    return 0; 
  }
  if(open){
    write("The book is already open.\n");
    return 1;
  }
  write("You open the book to the first page.\n");
  say(tpn+" opens the book to the first page.\n");
  open = 1;
  currentpage = 0;
  return 1;
}

close_book(str){
  if(!str){
    notify_fail("What would you like to close?\n");
    return 0;
  }
  if(present(str,this_player()) != this_object()){
    notify_fail("What would you like to close?\n");
    return 0;
  }
  if(!open){
    write("The book is already closed.\n");
    return 1;
  }
  write("You close the book shut.\n");
  say(tpn+" closes the book shut.\n");
  open = 0;
  return 1;
}

set_title(t){ title = t; }
set_alt_title(t){ alt_title = t; }
add_page(p){ pages += p; }

turnpage(str){
int pagenumber;
  if(query_verb() == "turn"){
    if(str != "page" && str != "page back"){
      notify_fail("What would you like to turn?\n");
      return 0;
    }
  }
  if(!open){
    write("The book is not open.\n");
    return 1;
  }
  if(!str || str == "page"){
    if(currentpage + 1 > sizeof(pages)-1){
      write("There is not another page to turn to.\n");
      return 1;
    }
    currentpage = currentpage + 1;  
    write("You turn the book to the next page.\n");
    read("necro_autoread");
    return 1;
  }
  if(str == "page back" || str == "-"){
    if(currentpage - 1 < 0){
      write("There is not another page to turn back to.\n");
      return 1;
    }
    currentpage = currentpage - 1;
    write("You turn the book back a page.\n");
    read("necro_autoread");
    return 1;
  } 
  sscanf(str,"%d",pagenumber);
  if(pagenumber){
    if(pagenumber < 1 || pagenumber > sizeof(pages)){
      write("That is not a page number you can turn to.\n");
      return 1;
    }
    currentpage = pagenumber - 1;
    write("You turn the book to page "+pagenumber+".\n");
    read("necro_autoread");
    return 1;
  }
}

read(str){
   if(!str){
    notify_fail("What would you like to open?\n");
    return 0;
  }
  if(str != "necro_autoread"){
    if(present(str,this_player()) != this_object()){
      notify_fail("What would you like to read?\n");
      return 0; 
    }
  }
  if(!open){
    write("The book is not open.\n");
    return 1;
  }
  cat(pages[currentpage]);
  write("\t- Page "+(currentpage+1)+" --\n");
  return 1;
}

query_book(){ return 1; }
query_open(){ return open; }
query_save_flag(){ return save; }
