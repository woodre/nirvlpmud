/*   Inn */

#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_short(HIG+"Inn of New Ares"+NORM);
   set_light(1);
   set_long(
   "  This is the huge Inn of New Ares.  The walls are made of a polished\n"+
   "oak wood with several paintings and other decorations covering them. A\n"+
   "large fireplace stands in the far corner, its small fire lending a\n"+
   "soft wavering light to the room.  A desk stands next to a winding set\n"+
   "of stairs.\n");

   add_item(
      "walls",
      "Beautifully polished oak walls");
   add_item(
      "paintings",
      "Paintings that depict the woodlands and plains of the surrounding\n"+
      "area");
   add_item(
      "decorations",
      "Numerous decorations meant to bring warmth to the room");
   add_item(
      "fireplace",
      "A huge stone fireplace with a small fire in it");
   add_item(
      "corner",
      "The corner of the room");
   add_item(
      "fire",
      "A small fire that lends a bit of light to the room");
   add_item(
      "light", 
      "It wavers and creates shadows in the room");
   add_item("desk",
      "A desk where you can checkin or checkout of the inn. There is\n"+
      "a sign sitting on it");
   add_item("stairs",
      "beautiful wooden stairs that lead up to the rooms");
   add_item("sign",
      "The sign reads...\n"+
      "   1 stay is 1000 coins.\n"+
      "   '"+HIW+"Checkin"+NORM+"' to reserve a room"); 

   add_exit(ROOMS+"city7","out"); 
   }

init(){
 ::init();
 add_action("checkin", "checkin");
 }

checkin(){
object daroom;
object daother;

if(this_player()->query_money() < 1000){
  write("You do not have enough coins to reserve a room.\n");
  return 1;
  }
if(this_player()->query_ghost()){
  write("You don't need a room, you need a PRIEST!\n");
  return 1;
  }
daother = clone_object("/players/maledicta/ares/rooms/inn_obj.c");
daroom = clone_object("/players/maledicta/ares/rooms/inn_room.c");
tell_room(environment(this_player()),
this_player()->query_name()+" leaves upstairs to "+this_player()->query_possessive()+" room.\n");
move_object(this_player(), daroom);
move_object(daother, this_player());
this_player()->add_money(-1000);
return 1;
}