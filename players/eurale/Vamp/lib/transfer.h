/*
  transfer_item.h
*/

#include "/players/eurale/defs.h"

/* -------- transfer item to another player ---------- */
transfer(str) {
  object item_obj, destination_room_obj, destination_player_obj;
  string who_name, item_name, coins_msg;
  int item_weight;

if(!str || sscanf(str, "%s to %s", item_name, who_name) != 2) {
  write("Use:  transfer <item> to <who>\n");
  return 1; }

if(TPL < 17 || TPGEXP < 669) {
  write("You lack the skills for that ability.\n");
  return 1; }

if(ROOM->realm() == "NT") {
    write("You can't do that from this location.\n");
  return 1; }

if(TPSP < 25) {
  write("You don't have enough magic to make the transfer.\n");
  return 1; }

item_obj = present(item_name, TP);
if(!item_obj) {
  write("You do not have a '"+item_name+"'.\n");
  return 1; }

if(item_obj->drop()) {
  write("The bat cannot take the '"+item_name+"' from you.\n");
  return 1; }

if(!find_player(who_name)) {
  write("The bat cannot find "+capitalize(who_name)+".\n");
  return 1; }

destination_player_obj = find_player(who_name);
destination_room_obj = environment(destination_player_obj);
if(destination_room_obj->realm() == "NT") {
  write("Your bat refuses to fly to that area!\n");
  return 1; }

item_weight = item_obj->query_weight();
write("A strong "+HIY+"golden bat"+NORM+" takes the "+item_name+
      " from you and flies away.\n");
EFANGS->tell_my_room(
 "A strong "+HIY+"golden bat"+NORM+" takes something from "+
  capitalize(TPRN)+" and flys away.\n");

if(destination_player_obj->add_weight(item_weight)) {
  tell_room(destination_room_obj,
    "A strong "+HIY+"golden bat"+NORM+" flys in carrying a "+item_name+"\n"+
    " and hands it to "+capitalize(who_name)+" before flying away.\n");
move_object(item_obj, destination_player_obj);
destination_player_obj->add_weight(item_weight);
}
else {
  tell_room(destination_room_obj,
    "A strong "+HIY+"golden bat"+NORM+" flys in carrying a "+
    item_name+" and drops it on the \n"+
    "ground in front of "+capitalize(who_name)+" before flying off.\n");
  move_object(item_obj, destination_room_obj);
}
this_player()->add_weight(- item_weight);
TP->add_spell_point(- 25);
return 1;
}
