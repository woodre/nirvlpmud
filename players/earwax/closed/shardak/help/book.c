/* *************************************************************************
 * Shardak Tome
 *
 * Earwax 7/30/03
 *
 * *************************************************************************
 * 
 * Given to prospective members, or members to be reinstated.  They are 
 * responsible for knowing and understanding the contents.  Once they agree
 * to become a Shardak, they are fully accountable for that knowledge.
 *
 * *************************************************************************
*/

#include "../include/ansi.h"

#define TPATH "/players/earwax/closed/shardak/help/"

int Page;
string *Pages;

void reset(status arg) {

  if (arg)
  {
    say("The Book of Shardak erupts into flames and is consumed.\n");
    destruct(this_object());
  }

  Pages = ({ "theme","rules","rules2","hierarchy","inactive","abandon","punishments"});
  Page = 0;
}

int query_weight() { return 1; }
int query_value()  { return 0; }
int drop()         { return 1; }
int get()          { return 1; }

status id(string arg) { 
  return ( arg == "book" || arg == "book of shardak");
}

string short() { return HIK+"The Book of Shardak"+NORM+NORM; }

void long() {

  write(short()+"\n");
  write("\
You have been given this book because you have expressed interest in \n\
becoming a Servant of Shardak.  It is very important that you read the\n\ contents of this book fully, as there are grave penalties and punishments\n\
in this guild.  Once you are a full member, you are completely responsible\n\
for the knowledge contained in here.  Now, and as a member, you can view\n\
this information with the command 'shardak'.\n\n\
Table of contents:\n\n\
Theme\nRules\nRules2\nHierarchy\nInactive\nAbandon\nPunishments\n\n\
Note: just type 'shardak' by itself to read the pages in order.\n");
}

status do_read(string arg) {
  if (arg == "book" || arg == "book of shardak")
  {
    write("Use 'shardak' to read, or 'shardak <topic>'.\n");
    return 1;
  }
  notify_fail("Read what?");
  return 0;
}

status show_file(string arg) {
  int i;

  if (!arg) {
    cat(TPATH+Pages[Page]);
    if (Page == 6)
      Page = 0;
    else
      Page++;
    return 1;
  }

  i = member_array(arg,Pages);
  if (i == -1) {
    write("Invalid selection.  Look at the book for appropriate topics.\n");
    return 1;
  }
  cat(TPATH+Pages[i]);
  return 1;
}

void init() {

  add_action("show_file","shardak");
  add_action("do_read","read");
}

