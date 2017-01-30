#define DIR "players/feldegast/library/lib1/"

#include "defs.h"

inherit ROOM;

int *checked_out;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Library of Nirvana";
  long_desc=
"  This solemn and studious building is the Library of Nirvana.  Monks\n\
and scholars wander the stacks seeking rare, dusty volumes.  Near\n\
the front of the library is a mahogany desk with a sign on it.  A\n\
pair of swinging doors with leather padding lead back out.\n\
Commands: list, withdraw, return\n";
  dest_dir=({
    "/room/northroad3", "south",
  });
  items=({
    "building", "reflexive",
    "monks", "They stand and sit around the library, looking through the stacks\n"+
             "reading voluminous tomes",
    "scholars","They stand and sit around the library, looking through the stacks\n"+
               "reading voluminous tomes",
    "volumes", "The library is filled with thousands of books",
    "stacks", "The library is filled wall-to-wall with bookshelves",
    "library", "reflexive",
    "desk", "It is a mahogany librarian's desk with a sign on it",
    "sign", "The sign is written in the common language of Nirvana.  You\n"+
            "can 'read' it",
    "doors", "A pair of swinging doors with leather padding and metal studs\n"+
             "lead back out",
  });
  no_clean=1;
  checked_out=allocate(sizeof(get_dir("/"+DIR)));
}

void init() {
  ::init();
  add_action("cmd_read", "read");
  add_action("cmd_list", "list");
  add_action("cmd_withdraw", "withdraw");
  add_action("cmd_return", "return");
  add_action("cmd_submit", "submit");
}

int cmd_read(string str) {
  if(str=="sign") {
    write(
"  Nirvana's library is written not only by the wizards of Nirvana,\n\
but also by Nirvana's player population.  If you wish to write a book,\n\
then you may 'buy' a 'blank book' for 5000 coins.  When you are done\n\
writing it, take it back to the library and 'submit' your 'book'.\n\
Your book will be immediately available to the public.\n\
  Nirvana's library has a finite amount of storage space, so books\n\
that are of poor quality or inappropriate content will be removed.\n\
\n                                   -Feldegast\n\
"   );
    return 1;
  }
}

int cmd_list(string str) {
  string *files;
  int i;
  files=get_dir("/"+DIR);
  write("Titles:\n"+
        "-------------------------------------------\n"
  );
  for(i=0; i < sizeof(files); i++) {
    write( (i+1) + ". " + implode(explode(files[i],"_")," ")[0..strlen(files[i])-2]);
    if(checked_out[i])
      write(" [Checked out]\n");
    else
      write("\n");
  }
  return 1;
}

int cmd_submit(string str) 
{
  object ob;
  ob=present(str, this_player());
  if(!ob->id("library of nirvana writebook")) {
    write("You cannot submit that book.\n");
    return 1;
  }
  if(ob->save_to_file(DIR) == 0) {
    write("You submit " + (string)ob->query_title() + " by "+ (string)ob->query_author()+".\n");
    destruct(ob);
    return 1;
  }
  write("Submission failed.\n");
  return 1;
}

int cmd_withdraw(string str) {
  object book;
  string *dir;
  string file;
  int index;
  dir=get_dir("/"+DIR);
  if(sscanf(str,"%d",index)!=1) {
    write("Usage: withdraw #\n");
    return 1;
  }
  --index;
  if(index < 0 || index >= sizeof(dir)) {
    write("That is not a valid index.\n");
    return 1;
  }
  if(checked_out[index]==1) {
    write("That book has already been checked out.\n");
    return 1;
  }
  file=DIR+dir[index];
  file=file[0..strlen(file)-3]; /* Mwahahahaha! */
  book=clone_object(PATH+"readbook.c");
  if((int)book->restore_book(file) != 0) {
    write("No such book.\n");
    return 1;
  }
  checked_out[index] = 1;
  move_object(book, this_player());
  this_player()->add_weight((int)book->query_weight());
  write("You withdraw "+(string)book->short()+".\n");
  say(TPN+" withdraws a book.\n");
  return 1;
}

int cmd_return(string str) {
  object book;
  string file;
  int index;
  book=present(str, this_player());
  if(!book) {
    write("You don't have a "+str+" to return.\n");
    return 1;
  }
  if(!book->id("library of nirvana readbook")) {
    write("You cannot return that book.\n");
    return 1;
  }
  file=(string)book->query_title();
  file=implode(explode(file," "),"_");
  file+=".o";
  if( file_size("/"+DIR+file[0..strlen(file)-1])==-1 ) {
    write("That book doesn't belong here.\n");
    return 1;
  }
  index = member_array(file, get_dir("/"+DIR));
  checked_out[index]=0;
  write("You return "+(string)book->query_title()+".\n");
  this_player()->add_weight(-((int)book->query_weight()));
  destruct(book);
  return 1;
}
