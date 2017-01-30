/*
  Send an item to the guild donation room
*/

#include "/players/eurale/defs.h"

/* -------- transfer item to guild donation room ---------- */
donate_item(str) {
  object item_obj;
  string item_name;
  int item_weight;

if(!str) { write("Donate what?\n"); return 1; }

if(TPL < 12 || TPGEXP < 668) {
  write("You lack the skills for that ability.\n");
  return 1; }

if(ROOM->realm() == "NT") {
    write("You can't do that from this location.\n");
  return 1; }

if(TPSP < 25) {
  write("You don't have enough magic to do that.\n");
  return 1; }

item_obj = present(str, TP);
if(!item_obj || !item_obj->short()) {
  write("You do not have a '"+item_name+"'.\n");
  return 1; }

if(TPBPTS < 2) {
  write("You lack the blood energy to summon a donation bat.\n");
  return 1; }

if(item_obj->drop() || item_obj->query_auto_load()) {
  write("The bat cannot take the '"+item_name+"' from you.\n");
  return 1; }

write("A strong "+HIY+"golden bat"+NORM+" takes the "+str+
      " from you and flies away.\n");
FANGS->tell_my_room(
 "A strong "+HIY+"golden bat"+NORM+" takes something from "+
  capitalize(TPRN)+" and flys away.\n");

move_object(item_obj,"/players/eurale/VAMPIRES/RMS/donation.c");
item_weight = item_obj->query_weight();
TP->add_weight(-item_weight);
TP->add_spell_point(- 25);
PFANGS->add_BLOODPTS(-2);
return 1;
}
