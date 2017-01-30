#include "/players/eurale/defs.h"
object ob;

/*  Show an item to those in the room  */

show_item(str) {
if(!str) {
  write("Use:  show <item name>\n");
  return 1; }

ob = present(str,TP);
if(!ob) {
  write("You don't seem to possess that item.\n");
  return 1; }

if(TPBPTS < 1) {
  write("You lack the blood energy to do that.\n");
  return 1; }

PFANGS->add_BLOODPTS(-1);
write("You show everyone your "+ob->short()+".\n");
FANGS->tell_my_room(
  capitalize(TPRN)+" shows everyone "+TP->query_possessive()+" "+
    ob->short()+".\n");
return 1;
}
