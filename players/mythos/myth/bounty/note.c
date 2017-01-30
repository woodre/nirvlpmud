#include "/players/mythos/closed/ansi.h"
string name, level, place, reward;

id(str) { return str == "wanted ad" || str == "ad" || str == "note" ||
                 str == "wanted" || str == "blood note"; }
                 
short() { return RED+"Blood Note "+NORM+"[wanted ad]"; }

long() { write("This is a Blood note listing the creatures\n"+
               "that are wanted by the Bounty Hunter's Collection\n"+
               "Guild.  To look at the list of today's wanted list\n"+
               "type <read ad>.\n");
       }
       
drop() { return 1; }

get() { return 0; }

init() {
  add_action("read_ad","read");
}

read_ad(str) {
int h;
  if(!str) { write("read what?\n"); return 1;}
  if(id(str)) {
  restore_object("players/mythos/bounty/wanted");
  write("Today's Wanted:\n\n");
  write(BOLD+"NAME\t\tLEVEL\tPLACE\tREWARD\n"+NORM);
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  for(h=0;h<sizeof(name);h++) {
  if(name[h] && name[h] != "EMPTY") {
    write(RED+name[h]+NORM);
    if(strlen(name[h]) < 8) write("\t");
    write("\t"+BLU+level[h]+NORM+"\t"+place[h]+"\t"+reward[h]+"\n"); }
  }
  write("\nBring the corpse of the wanted creature to the Collection Office\n"+
          "[Mythos' Realm] and 'hand corpse to officer'.\n"+
          "Be sure that the right corpse is at the top of your inventory.\n"+
          "\nDirections to Office:\n"+
          "   from church- 1s,all the east,pass,bounty\n"+
          "   from goportal- empire,portal,bounty.\n");
  return 1; }
}