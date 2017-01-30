#include "/obj/clean.c"

static int save_flag, page, con,p,last;
static string title;
static int shop_dest_flag;

id(str){ return str == "book" || str == title;}

reset(arg) {
  if(arg) return;
  con = 0;
  page = 0;
}

short() { write("Book: "+capitalize(title)+"\n");}
long() {
        cat("/players/mythos/lmisc/book/"+title+".0");
        write("'book_help' for a help file.\n");}
query_value() { return 0; }

set_title(str) { title=str;}
set_cond(p) {con=p; page=p;}

get() { return 1;}
drop() {return 0;}
query_weight() { return 1;}

init() {
    add_action("open","open");
    add_action("close","close");
    add_action("turn","tp");
    add_action("book_help","book_help");
}

save_thing(str){ save_object(str); return 1;}
restore_thing(str){ restore_object(str); return 1;}
set_save_flag() {save_flag = 1;}
query_save_flag() { return 1;}
query_dest_flag() {return 1;}

open(str) {
if(!str) {write("Open what?\n"); return 1;}
if(str==title) {
if(con==0) {
con=1;
page=1;
  say(capitalize(this_player()->query_real_name())+" opens "+ capitalize(title)+
      " and begins to read.\n");
  cat("/players/mythos/lmisc/book/"+title+"."+page);
  return 1;}
  write("The book is already open to page: "+page+".\n");
  return 1;}
}

close(str) {
if(!str) {write("Close what?\n"); return 1;}
if(str==title) {
if(con==1) {
con=0;
page=0;
  say(capitalize(this_playe()->query_real_name())+" closes "+capitalize(title)+"\n");
  write("You close the book: "+ capitalize(title)+"\n");
  return 1;}
  write("The book is already closed!\n");
  return 1;}
}

turn(str) {
restore_object("/players/mythos/lmisc/book/"+title);
if(con == 0) {write("The book is closed!\n"); return 1;}
if(!str) {
  if(page==last) {write("You are already on the last page.\n"); return 1;}
  page=page+1;}
else if(str) {
if(str=="-"){
  if(page==1) {write("You are already on the first page.\n"); return 1;}
  page=page-1;}
else {
  sscanf(str,"%d",page);
  if(page>last) {write("There are not that many pages in this book.\n"); return 1;}
  }}
cat("/players/mythos/lmisc/book/"+title+"."+page);
return 1;}

book_help(){
  cat("/players/mythos/lmisc/bookhelp");
return 1;}