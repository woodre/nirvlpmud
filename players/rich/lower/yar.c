#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 extra_init() {
   add_action("lay" ,"lay");
    }

object yar;

extra_reset() {
   object weapon;
    if (!present("yar")) {
	yar = clone_object("obj/monster");
	call_other(yar, "set_name", "tasha yar");
	call_other(yar, "set_alias", "yar");
	call_other(yar, "set_short", "Tasha Yar");
call_other(yar,"set_long","Tasha Yar\n");
	call_other(yar, "set_wc", 16);
	call_other(yar, "set_ac", 6);
call_other(yar, "set_hp",350);
	call_other(yar, "set_al", 60);
call_other(yar, "set_level", 11);
	call_other(yar, "set_aggressive", 0);
call_other(yar, "set_chat_chance", 40);
call_other(yar,"load_chat","Tasha Yar says: Now Data is a REAL man!!!\n");
call_other(yar,"load_chat","Tasha Yar says: Data has 3 speeds slow medium and aahhhhh!!!\n");
call_other(yar,"load_chat","Tasha Yar says: Oh no not another oil slick!!\n");
	move_object(yar, this_object());
	weapon = clone_object("obj/weapon");
	call_other(weapon, "set_name", "whip");
	call_other(weapon, "set_alias", "whip");
	call_other(weapon, "set_short", "whip");
call_other(weapon, "set_long", "whip");
	call_other(weapon, "set_class", 13);
	call_other(weapon, "set_weight", 3);
	call_other(weapon, "set_value", 700);
	move_object(weapon, yar);
    }
}

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

ONE_EXIT("players/rich/lower/hall3d", "east",

         "Tasha Yar`s Quarters",
         "This is Tasha Yar`s room,on the walls\n" +
         "You see many kinds of weapons,whips and chains.\n" +
         "In the center of the room you see before\n" +
         "an extremely LARGE bed.\n" +
         "To the east you see a hallway\n",
       1)

lay(str) {
 string me,bedob;
  sscanf(str,"%s %s",me,bedob);
   if(me!="on") {
    write("Try laying ON the bed.\n");
    return 1;
    }
   if(bedob!="bed") {
    write("Lay on the bed you schmuck!!!\n");
    return 1;
   }
  write("Tasha slowly takes off her clothes....\n");
  write("lays down on the bed beside you.......\n");
  write("and the two of you have the time of your life!!!\n");
  call_other(this_player(),"set_title","enjoys the company of Tasha Yar");
  return 1;
 }
realm(){return "enterprise";}
