#define DEST "room/mount_pass"
#include <ansi.h>
#define OWNER "hogath"
id(str) { return str == "rift" || str == "castle"; }

short() {
    return HIB+"A "+HIR+"rift"+HIY+" in"+BLK+" space"+NORM;
}

long() {
    write("A Rift to a New World has been opened here.\n"+
          "It's magical energy crackles in the air, and\n"+
          "seems to discourge any vegation from growing or\n"+
          "animals from approaching it.\n");
          
          }

init() {
    add_action("enter","enter");
    }

enter(str) {
    if (!id(str))
      return 0;
    else
     {write("You step through a rift into a new place.\n");
     move_object(this_player(),"/players/hogath/area/entrance1.c");
     command("look", this_player());
     return 1;}
}


reset(arg) {
    if (arg)
	  return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
