/*
A wand for setting color titles.
Written by Feldegast
4/29/00
*/

#include "/players/feldegast/std/colorize.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("wand");
  set_alias("titler");
  set_short("Wand of Colorful Titles");
  set_long(
    "This is a wiztool for granting color titles.  You can use the\n"+
    "commands: <ctitle> and <cpretitle>.  The available colors are\n"+
    "BLU RED GRN CYN YEL MAG BLK WHT BOLD HIB HIR HIG HIC HIY HIM HIW.\n"+
    "You must follow all wizard guidelines regarding using this tool.\n"
  );
}

void init() {
  if((int)this_player()->query_level() > 20) {
    add_action("cmd_ctitle","ctitle");
    add_action("cmd_cpretitle","cpretitle");
  }
}

int cmd_ctitle(string str) {
  object targ;
  string name, title;
  if(!str || sscanf(str,"%s %s",name,title)!=2) {
    notify_fail("Usage: ctitle <player> <title>\n");
    return 0;
  }
  targ=find_player(name);
  if(!targ) {
    write("'"+capitalize(name)+"' is not on Nirvana.\n");
    return 1;
  }
  title=colorize(title);
  targ->set_title(title);
  write("You have set "+capitalize(name)+"'s title to '"+title+"'.\n");
  return 1;
}

int cmd_cpretitle(string str) {
  object targ;
  string name, title;
  if(!str || sscanf(str,"%s %s",name,title)!=2) {
    notify_fail("Usage: cpretitle <player> <title>\n");
    return 0;
  }
  targ=find_player(name);
  if(!targ) {
    write("'"+capitalize(name)+"' is not on Nirvana.\n");
    return 1;
  }
  title=colorize(title);
  targ->set_pretitle(title);
  write("You have set "+capitalize(name)+"'s title to '"+title+"'.\n");
  return 1;
}
