#include "/open/ansi.h"
#define TP this_player()
inherit "/obj/treasure.c";
   object who;
string target;
int mode,prefix;
reset(int arg) {
  if(arg) return;
  set_id("wand");
set_short("A title Maker");
}

init() {
    ::init();
      add_action("hero","hero");
      add_action("test","test");
      add_action("spark","spark");
      add_action("send","lt");
    }

hero() {
  TP->set_pretitle("Hero of the"+RED+" LUNAR"+NORM+" empire -");
  TP->set_title(BOLD+"the Razoress"+NORM);
  TP->set_guild_name("Luner");
  return 1;}

spark() {
  TP->set_pretitle(BOLD+MAG+"Bourb"+YEL+"on Street");
  TP->set_title(BOLD+"the bu"+NORM+BOLD+"xom ba"+YEL+"you girl "+MAG+"gone wild! "+NORM+"(Crazy)"+NORM);
  TP->set_guild_name("Anti-Paladin");
  return 1;}

test() {
  TP->set_pretitle(BOLD+RED+"[ Jareels Test Char ]"+NORM);
  return 1;}

drop() {
  write(""+YEL+"The wand breaks as it hits the ground."+NORM+"\n");
  destruct(this_object());
  return 1; }

give() {
  write(""+YEL+"Do you really think anyone would want this?"+NORM+"\n");
  return 1; }

send(str) {
   string history; /* added by verte */
   object list;
   object AURA;
   int i;
   string myname;
   if (!str) { write("Send what?\n"); return 1; }
   list = users();
  return 1;
  }

