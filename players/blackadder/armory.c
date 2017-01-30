#include "std.h"
int door_is_open, door_is_locked;
object knight, armor1, weapon, key, money;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
   door_is_open = 0; door_is_locked = 1;
   if (!knight || !living(knight)) {
      knight = clone_object("obj/monster.c");
      call_other(knight,"set_name","knight");
      call_other(knight,"set_short","A Knight in shining armor");
      call_other(knight,"set_long",
         "The knight is a magical creature set to guard the armory from\n" +
         "intrusions by unwanted visitors.\n");
      call_other(knight,"set_level",19);
      call_other(knight,"set_hp",1000);
      call_other(knight,"set_ac",17);
      move_object(knight,this_object());
      money = clone_object("obj/money");
      call_other(money,"set_money",random(1000)+500);
      move_object(money,knight);
      call_other(knight,"set_chat_chance",20);
      call_other(knight,"set_a_chat_chance",33);
      call_other(knight,"load_chat","Knight says: Halt!\n");
      call_other(knight,"load_chat","Knight says: Advance No further!\n");
      call_other(knight,"load_chat","Knight says: Begone lest I carve thee!\n");
      call_other(knight,"load_chat","Knight says: None shall Pass!\n");
      call_other(knight,"load_chat","Knight says: I take my work very seriously.\n");
      call_other(knight,"load_a_chat","Knight laughs heartily!\n");
      call_other(knight,"load_a_chat","Knight smirks.\n");
      call_other(knight,"load_a_chat","Knight says: I've been hurt worse.\n");
      call_other(knight,"load_a_chat","Knight says: Isn't war wonderful?\n");
      weapon = clone_object("obj/weapon");
      call_other(weapon,"set_name","broadsword");
      call_other(weapon,"set_short","An ancient Broadsword");
      call_other(weapon,"set_alias","sword");
      call_other(weapon,"set_long",
         "An ancient broadsword with runic inscriptions.\n");
      call_other(weapon,"set_class",18);
      call_other(weapon,"set_value",2500);
      call_other(weapon,"set_weight",3);
      transfer(weapon,knight);
      call_other(knight,"init_command","wield sword");
      armor1 = clone_object("obj/armor");
      call_other(armor1,"set_name","armor");
      call_other(armor1,"set_short","Shining Armor");
      call_other(armor1,"set_long","Shining Armor.\n");
call_other(armor1, "set_value", 2000);
      call_other(armor1,"set_ac",4);
      call_other(armor1,"set_type","armor");
      call_other(weapon,"set_weight",3);
      transfer(armor1,knight);
      call_other(knight,"init_command","wear armor");
      call_other(knight,"set_ac",17);
      key = clone_object("obj/treasure");
      call_other(key, "set_id", "key");
      call_other(key, "set_alias", "armory key");
      call_other(key, "set_short", "A steel key");
      call_other(key, "set_value", 10);
      call_other(key, "set_weight", 1);
      transfer(key, knight);
   }
}

#undef EXTRA_LONG
#define EXTRA_LONG\
if (str == "door") {\
   if (door_is_open) {\
      write("The door is open.\n");\
      return;\
   }\
   write("The door is closed.\n");\
   return;\
}
#undef EXTRA_INIT
#define EXTRA_INIT\
add_action("open","open");\
add_action("unlock","unlock");\
add_action("west","west");\
add_action("telekenetics","telekenetics");\
add_action("search","search");

ONE_EXIT("/players/blackadder/hall3","east",
   "The armory",
   "This is the armory.  A coat of arms bearing the Blackadder family crest\n"
   + "hangs on one wall.  Cabinets full of armor and weapons stand against\n"
   + "the walls of this room, however they are locked by some magical spell\n"
   + "known only to lord Blackadder himself.  There is a steel door leading\n"
   + "to the west\n", 1)

id(str) {
   return str == "door";
}
open(str) {
   if (str && str != "door")
      return 0;
   if (door_is_open)
      return 0;
   if (door_is_locked) {
      write("The door is locked.\n");
      return 1;
   }
   door_is_open = 1;
   write("Ok.\n");
   say(call_other(this_player(), "query_name") + " opened the door.\n");
   return 1;
}
unlock(str) {
   if (str && str != "door")
      return 0;
   if (door_is_open || !door_is_locked)
      return 0;
   if (!present("armory key", this_player())) {
      if (present("key", this_player()))
         write("You don't have the right key.\n");
      else
         write("You need a key.\n");
      return 1;
   }
   door_is_locked = 0;
   write("ok.\n");
   say(call_other(this_player(), "query_name") + " unlocked the door.\n");
   return 1;
}
west() {
   if (!door_is_open) {
      write("The door is closed.\n");
      return 1;
   }
   if (knight && present(knight, this_object())) {
      write("The knight bars your way.\n");
      say("Knight says: I challenge you to mortal combat!\n");
      write("Knight says: I challenge you to mortal combat!\n");
      return 1;
   }
   call_other(this_player(), "move_player", "west#/players/blackadder/armory1");
   return 1;
}
telekenetics() {
   write("The door is more than it seems!\n");
   write("It's inherint magik resists your mental powers!\n");
   return 1;
}
search() {
   write("Nothing unusual found here.\n");
   return 1;
}
query_door() {
   return !door_is_open;
}
open_door_inside() {
   door_is_locked = 0;
   door_is_open = 1;
}
query_drop_castle() {
   return 1;
}
