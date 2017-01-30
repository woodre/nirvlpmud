inherit "obj/treasure.c";
static string w,title, str;
static int page,line, last;
int page_num;
reset(arg) {
  if(arg) return;
  set_id("bookmaker");
  set_alias("tools");
  set_short("A Scribe's Tools");
  set_long("The tools needed to scribe a book.\n"+
           "scribe <name> will start making a book.\n"+
           "book <name> <last> will make a book for \n"+
           "you to read.\n");
  set_weight(1);
  set_value(0);
}

init() {
 ::init();
 add_action("scribe","scribe");
 add_action("bookmake","book");
 add_action("erase_book","erase");
 }
 
scribe(str){
if(!str) {write("Title?\n"); return 1;}
title = lower_case(str);
if(read_file("/players/mythos/closed/guild/books/"+title)=="1") {
  write("That book already exists!\n"); return 1;}
  write("You have started to write a book entitled "+capitalize(str)+".\n"+
        "Use ** to end the book, use @@ to erase page being worked on,\n"+
        "use %% to erase the current book.\n"+
        "Understand that most screens are set to 80 chars in length.\n");
  write_file("/players/mythos/closed/guild/books/"+title,"1");
  write_file("/players/mythos/closed/guild/books/"+title+".0",
             "\n\n\n\n\n\n\n\n"+
             "                                 "+capitalize(title)+"\n\n\n"+
             "                                             scribed by "+
             capitalize(this_player()->query_real_name())+"\n\n\n\n\n");
  page=1;
  line=1;
  write(">>");
  input_to("type");
return 1;}

type(w) {
   if(w=="**"){
               page_num = page;
               save_object("/players/mythos/closed/guild/books/"+title);
               write("\nThe book is finished.\n\n"); 
               return 1;}
   if(w=="@@"){rm("/players/mythos/closed/guild/books/"+title+"."+page); 
               write("\nPage "+page+" has been erased.\n\n>>");
               input_to("type"); 
               return 1;}
   if(w=="%%"){
        for(page;page<0;page--) {
        rm("/players/mythos/closed/guild/books/"+title+"."+page);
        }
        rm("/players/mythos/closed/guild/books/"+title);
        rm("/players/mythos/closed/guild/books/"+title+".o");
        write("\n\nThe Book has been erased.\n\nMoving out of scribing mode.\n\n");
        return 1;}
    write_file("/players/mythos/closed/guild/books/"+title+"."+page,w+"\n");
    line=line+1;
    if(line==20) {
    write_file("/players/mythos/closed/guild/books/"+title+"."+page,
    "                                "+page+"\n");
      page=page+1;
      write("\nNext page- page: "+page+"\n\n");
      }
     write(">>");
     input_to("type");
return 1;}

erase_book(str) {
if(this_player()->query_real_name() != "mythos") {write("You may not do this.\n");
   return 1;}
if(!str) {write("Title to erase?\n");}
if(read_file("/players/mythos/closed/guild/books/"+str)=="1"){
restore_object("/players/mythos/closed/guild/books/"+title);
page=0;
  for(page;page<page_num;page++) {
    rm("/players/mythos/closed/guild/books/"+title+"."+page);
    }
    rm("/players/mythos/closed/guild/books/"+title);
    rm("/players/mythos/closed/guild/books/"+title+".o");
    write(capitalize(str)+" has been erased.\n");
    command("ls /players/mythos/closed/guild/book",this_player());
    return 1;}
  write("Doesnt exist.\n");
  return 1;}

bookmake(str) {
string name;
int last;
object ob;
  if(sscanf(str,"%s %d",name,last) != 2) { 
    write("Usage: book <name> <last>\n");
  return 1;} 
  ob=clone_object("/players/mythos/closed/guild/books/book.c");
  ob->set_title(name);
  ob->set_cond(0);
  ob->set_last(last);
  move_object(ob,this_player());
  tell_room(environment(this_player()),"\nA demon appears and hands "+
            capitalize(this_player()->query_real_name())+" a book.\n"+
            "\nThe demon bows and vanishes.\n\n");
return 1;}
