#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

object own;

extra_init() {
   add_action("pay","pay");
   add_action("exa","exa");
   add_action("kill","kill");
  add_action("spellf","missile");
  add_action("spellf","shock");
  add_action("spellf","fireball");
  add_action("spellf","flare");
   }
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
     if(!present("keeper")) {
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","keeper");
       call_other(own,"set_alias","gate keeper");
       call_other(own,"set_short","Gate Keeper");
       call_other(own,"set_long","This is the Gate Keeper\n");
       call_other(own,"set_ac",15);
       call_other(own,"set_wc",15);
       call_other(own,"set_level",2);
       call_other(own,"set_al",50);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","Gate Keeper says: You must pay to enter.\n");
       move_object(own,this_object());
   }
 }

   ONE_EXIT("players/rumplemintz/room/elanding", "north",
    "Entrance to Elevallie",
	"This is the entrance to Elevallie, a peaceful, serene town where you will\n"+
        "find a shop, a pub, a magic shop, a toy shop, a weaponry, and an armory.\n"+
	"This is one of the most popular attractions on the mud, to enter, you must\n"+
	"pay the keeper of the gate.\n"+
	"Beyond the gate keeper, you see a gate.\n",1)
pay(str) {
   if (!own || !living(own)) { return 0; }
   if (!call_other(own, "id", str)) {
      write("You must pay the KEEPER.\n");
      return 1;
   }
   call_other(this_player(),"add_money",-1);
   write("The gate keeper opens the gate,\n");
   write("and beckons you to go south.\n");
   add_action("south","south");
   return 1;
   }
south() {
 write("You are told to move south into Elevallie.\n");
  this_player()->move_player("goes through the gate#players/rumplemintz/room/elevall/room1");
 return 1;
 }
kill(str) {
  if(str=="keeper"||str=="gate keeper") {
  write("You can't do that!!!!\n");
  return 1;
  }
 return 1;
 }
spellf(arg) {
   if(!"keeper"||!"gate keeper"||!"gatekeeper") {return 0;}
    write("You really shouldn't do that!!!\n");
    return 1;
  }
exa(str) {
   if(str=="gate") {
      write("You see an immense gate before you, however,\n");
      write("there is a gatekeeper blocking the way.\n");
      return 1;
     }
  return 0;
 }
