#include "std.h"
#define HARRY 1

int count;

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("down", "down");
     add_action("look", "look");\
     add_action("look", "l");\
     add_action("look", "examine");

#if HARRY
object harry;
#undef EXTRA_RESET
#define EXTRA_RESET\
        starta_harry();
#endif

FOUR_EXIT("room/vill_road1","west",
	 "room/vill_road3","east",
	 "room/adv_guild","south",
	 "room/shop","north",
	 "Village road",
 "A long road going through the village. This road is well worn from\n" +
 "constant travel of people back and forth. There is a small shop to\n"+
 "north and a strong brick building to the south.\n"+
 "There are stairs going down.\n"
 , 1)

look(str) {
  if (!str) return 0;
  if (str == "at shop") {
    write("A small squarish brick building with no windows on this side.\n"+
    "The enterance is to the west along the north side of the main road.\n");
    return 1;
  }
  if (str == "at adventures guild" || str == "at guild" ||
      str=="at building" || str=="at strong brick building") {
    write("The adventurers guild is a small stone building with odd \n"+
      "symbols carved into the walls. The enterance is on the south side\n"+
      "of the road east along the main road.\n");
  return 1;
  }
  if (str == "at stairs") {
     write("Concrete stairs lead down to something underground.\n");
     return 1;
  }
  return 0;
}

#if HARRY
starta_harry() {
    if(!harry || !living(harry)) {
	harry = clone_object("obj/monster");
	call_other(harry, "set_name", "harry");
	call_other(harry, "set_alias", "fjant");
	call_other(harry, "set_short", "Harry the affectionate");
	call_other(harry, "set_long", "Harry has an agreeable look.\n");
	call_other(harry, "set_ac", 0);
	call_other(harry, "set_level",3);
	call_other(harry, "set_al",50);
	call_other(harry, "set_ep",2283);
	call_other(harry, "set_hp",30);
	call_other(harry, "set_wc",5);
	call_other(harry, "set_aggressive", 0);
	move_object(harry, "room/vill_road2");
	call_other(harry, "set_object", this_object());
	
	call_other(harry, "set_function", "follow");
	call_other(harry, "set_type", "leaves");
	call_other(harry, "set_match", " "); 
	

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
	call_other(harry, "init_command", where);
}
monster_died() {
    object obj, b;
    int num;
    obj = first_inventory(harry);
    while(obj) {
	b = next_inventory(harry);
	if(call_other(obj, "id", "bottle")) {
	    destruct(obj);
	    num = 1;
	}
	obj = b;
    }
    if(num)
	notify("There is a crushing sound of bottles breaking, as the body falls.\n");
}

#endif

