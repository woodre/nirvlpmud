#include "/players/maledicta/ansi.h"
#define NAME "Maledicta"
#define DEST "room/ravine"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "path";  }

short() {
    return "A small path leading into a ravine";
}

long(str) {
    write("This is a small path that leads west into the mountains.\n");
    return 1;
    }
/*
  if(str == "tower"){
    write(
    "Before you stands the Tower of Hope. It was constructed by the Knights\n"+
    "Templar in support of its allies. If you are an ally or Knight, you may\n"+    
    "'enter' it.\n");
    return 1;
   } 
}
*/
init() {
  add_action("enter", "west");
  add_action("enter", "w");
  /*  add_action("enter_tower", "enter"); */
}
/*
enter_tower(str){
if(!str){
write("Enter what?\n");
return 1;
}
if(str == "tower"){
  if(!present("KnightInvite", this_player())){
   write("You are not allowed into the Tower.\n");
   return 1;
   }
  tell_room(environment(this_player()),
  this_player()->query_name()+" enters the Tower of Hope.\n", ({ this_player() }));
  tell_object(this_player(),
  "You enter the Tower of Hope.\n");
    move_object(this_player(), "/players/maledicta/hope/rooms/hmain.c");
  command("look", this_player());
  tell_room(environment(this_player()),
  this_player()->query_name()+" arrives.\n", ({ this_player() }));
  return 1;
  }
write("Enter what?\n");
return 1;
}
*/

enter(str) {
    this_player()->move_player("path#players/maledicta/castle/rooms/m1.c");
tell_object(this_player(),
HIR+"\n\n    BY ENTERING THIS AREA YOU SUBJECT YOURSELF TO FORCES THAT MAY KILL YOU!\n\n"+
"                   !!!Go East NOW To Avoid This Danger!!!"+NORM+"\n\n");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
"/players/boltar/templar/items/bracer.c"->load_it();
"/players/maledicta/closed/lute.c"->load_it();
"/players/maledicta/closed/clan.c"->load_it();
"/players/maledicta/closed/dwarf.c"->load_it();
"/players/maledicta/closed/shamulet.c"->load_it();
"/players/maledicta/closed/saladin.c"->load_it();
"/players/maledicta/closed/symbio/clan.c"->load_it();
"/players/maledicta/closed/emoter/emoter.c"->load_it();
"/players/maledicta/templar/gdaemon.c"->start_it_up();

move_object(clone_object("/players/maledicta/cont/mobs/tower.c"), "players/maledicta/cont/rooms/79");

/* Obsolete shit 
"/players/maledicta/cont/mobs/tower.c"->load_it();
"/players/maledicta/closed/dealers/dealer.c"->load_it();
"/players/maledicta/town/obj/addiction.c"->load_it();
"/players/maledicta/templar/honorary.c"->load_it();
"/players/maledicta/venom2/neo_venom.c"->load_it();
"/players/maledicta/maltell.c"->load_it();
"/players/reflex/guilds/harem/crown.c"->load_it();
"/players/reflex/guilds/bards/instrument.c"->hey_ho_lets_go();
"/players/maledicta/templar/gdaemon.c"->load_it();
*/
/* "/players/maledicta/cont/war/war.c"->load_it(); */
}

is_castle(){return 1;}
