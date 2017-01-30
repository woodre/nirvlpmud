#define ROOT "/players/guilds/healers/docs/books/"
#define tb this_player()
#define hob present("mythos_healer",tb)

static int save_flag, page, con,p,last;
static string title;
static int shop_dest_flag;

id(str) { return str == "book" || str == title || str == lower_case(title); }

reset(arg) {
  if(arg) return;
  con = 0;
  page = 0;
}

short() { return "Book: "+capitalize(title);}
long() {
        cat(ROOT+title+".0");
        write("'book_help' for a help file.\n");}
query_value() { return 0; }

set_title(str) { title=str;}
set_cond(p) {con=p; page=p;}
set_last(n) { last = n;}

get() { return 1;}
drop() { write("You drop the "+short()+".\nIt disappears.\n"); destruct(this_object()); return 1;}
query_weight() { return 1;}

init() {
  if(tb == environment(this_object())) {
    if(!hob){ drop(); return 1; }
    add_action("open","open");
    add_action("close","close");
    add_action("turn","tp");
    add_action("book_help","book_help");
  }
}

query_save_flag() { return 1;}

open(str) {
if(!str) {write("Open what?\n"); return 1;}
if(id(str)) {
  if(con==0) {
    con=1;
    page=1;
    say(tb->query_name()+" opens "+ capitalize(title)+
      " and begins to read.\n");
    cat(ROOT+title+"."+page);
  return 1;}
  write("The book is already open to page: "+page+".\n");
  return 1;}
}

close(str) {
  if(!str) {write("Close what?\n"); return 1;}
  if(id(str)) {
   if(con==1) {
    con=0;
    page=0;
    say(tb->query_name()+" closes "+capitalize(title)+"\n");
    write("You close the book: "+ capitalize(title)+"\n");
  return 1;}
  write("The book is already closed!\n");
  return 1;}
}

turn(str) {
if(con == 0) {write("The book is closed!\n"); return 1;}
if(!str) {
  if(page==last) { 
    write("You are already on the last page.\n"); 
  return 1;}
   page=page+1;}
   if(str) {
       if(str=="-"){
        if(page==1) {
            write("You are already on the first page.\n"); 
        return 1;}
         page=page-1;}
          else {
           sscanf(str,"%d",page);
             if(page>(last)) {
               write("There are not that many pages in this book.\n");
             return 1;}
          }
   }
cat(ROOT+title+"."+page);
return 1;}

book_help(){
  cat("/players/guilds/healers/room/bookhelp");
return 1;}
