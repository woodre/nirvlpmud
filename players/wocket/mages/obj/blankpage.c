#include "/players/wocket/closed/ansi.h"

string page_text;
id(str){ return (str == "page" || str == "wocketbookpage"); }
short(){
  string str;
  if(page_text != "")
  str = "A blank page (filled)";
  else
  str = "A blank page (empty)"; 
  return str;
}  

long(){
write("A fine parchment page.  With this page you may 'scribe' it\n"+
      "or 'wipe' it of all text.\n"+
      "    Currently written upon the page:\n \n"+page_text+"\n");
}
      
reset(){
  page_text = "";
}

init(){
  add_action("scribe","scribe");
  add_action("wipe","wipe");
}

scribe(str){
  if(str != "page"){
  notify_fail("What would you like to scribe?\n");
  return 0;  
  }
  write("You begin to scribe upon the page.\n"+
        "Cancel or save scribing by entering '~q' or '.' on a blank line.\n");
  write("]");
  input_to("nextline");
  return 1;
}

nextline(str){
  if(str == "~q"){
    write("Wiping the page.\n");
    page_text = "";
    return;
  }
  if(str == "."){
    write("Page written.\n");
    return;
  }
  page_text += "\t"+str+"\n";
  write("]");
  input_to("nextline");
}

wipe(str){
  if(str != "page"){
  notify_fail("What would you like to wipe?\n");
  return 0;
  }
  write("You wipe the page of all its text.\n");
  page_text = "";
  return 1;
}

query_page_text(){ return page_text; }
set_page_text(str){ page_text = str; }
get(){ return 1; }
drop(){ return 0; }
