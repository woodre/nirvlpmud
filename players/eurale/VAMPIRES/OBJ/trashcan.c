 
#include "/players/eurale/closed/ansi.h"
#define TP this_player()
object item;
 
id(str) { return str == "trashcan"; }
 
short() { return BOLD+"Trashcan"+NORM; }
 
long() { write(
  "This is a large black trashcan.  You may use it to dispose of\n"+
  "unwanted or usless items.  Disposing of such items helps keep\n"+
  "Nirvana clean and cuts down on the lag.  It's simple enough to\n"+
  "to do, just 'trash <item>'.\n");
return 1; }
 
reset(arg) {
  if(arg) return;
}
 
init() {
  add_action("trash_item","trash");
}
 
trash_item(str) {
object item;
if(!str) { write("Trash what?\n"); return 1; }
 
if(!present(str,TP)) {
  write("You don't seem to have a "+str+".\n");
  return 1; }
 
item = present(str, TP);
  
if(!item->short() || item->query_auto_load()) return;
  
write("You trash a "+item->short()+".\n");
say(capitalize(TP->query_real_name())+" trashes a "+item->short()+".\n");
destruct(item);
  return 1;
}

get() { return 0; }
