#include "/players/pestilence/define.h"
#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";
int OPEN;

reset(arg) {
  if(arg) return;
    if(!present("notice")) move_object(clone_object("/players/feldegast/obj/pkobit"), this_object());
    if(!present("portal")) move_object(clone_object("/players/pestilence/closed/dark/OBJ/portal.c"), this_object());

long_desc =
"    This the entrance room to the Dark Order Guild.  To the north leads\n"+
"to the main room of the large cave system.  Out leads back out to the\n"+
"sewer system of the town of Amity.\n";
set_light(-2);

items = ({
"rock","Large rocks that surround everything",
"rocks","Large rocks that surround everything",
"cave","A large cave leading into the ground",
"tunnel","A dark tunnel leading to the north and south",
});

dest_dir = ({
  "/room/south/sforst7.c","out",
  "/players/pestilence/closed/dark/room/hall2.c","north",
});
} 
short() {
    return ""+HIK+"Dark Cave Entrance"+NORM+"";
}

realm() { return "NT"; }

init() {
  ::init();
  add_action("church","church");
  add_action("portal","portal");
  add_action("hotel","hotel");
     this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }

church() {
  if (this_player()->query_guild_name() == "Dark Order") {
     TP->move_player("church#room/church.c");
     return 1; }
        else
            write("You must be part of the guild to use this portal.\n");
        return 1;
    }

portal() {
  if (this_player()->query_guild_name() == "Dark Order") {
     TP->move_player("portal#/players/saber/ryllian/portal.c");
     return 1; }
        else
            write("You must be part of the guild to use this portal.\n");
        return 1;
    }

hotel() {
  if (this_player()->query_guild_name() == "Dark Order") {
     TP->move_player("hotel#/players/boltar/hotel/hotel.c");
     return 1; }
        else
            write("You must be part of the guild to use this portal.\n");
        return 1;
    }
