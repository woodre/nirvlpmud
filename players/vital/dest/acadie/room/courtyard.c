/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/18/01           */
/*    Realm:               */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";
object mob;
int x;

reset(arg) {
    x = 0;
    if(!arg) { 
    set_light(-1);
    short_desc = "Courtyard";
    long_desc =
"  Hidden Courtyard\n\
The alleyways all converge on this stone-paved courtyard. The \n\
shadows cover nearly everything. This once beautiful grotto has \n\
been forgotten and surrounded by other buildings. There is a \n\
small fountain in the center and trash litters the area.\n ";

items = ({
    "alleyways",
    "The dark, inter-connected passages that run in between ",
    "courtyard",
    "This is an old courtyard that has been forgotten by time and men",
    "pavement",
    "In the dark shadows you can see the smooth paving stones",
    "shadows",
    "The darkness covers nearly everything in an inpenatrable haze of black",
    "grotto",
    "This is an old courtyard that has been forgotten by time and men",
    "buildings",
    "The backs of buildings are all that can be made out in the dim light",
    "fountain",
    "The fountain is now dry and empty",
    "trash",
    "Everywhere there is trash piled high and fills the courtyard"
});

dest_dir = ({
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("move_south","south");
    add_action("move_east","east");
    add_action("move_southeast","southeast");
    add_action("move_northwest","northwest");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    if(str == "fountain") {
        if(!present("mad_machine")) {
            if(!x) {
                x = 1;
                MO(CO(ACADIE+"npc/mad_machine.c"),TO);
                write("Something scurries out from inbetween two buildings as you search\n\around the fountain.\n");
                say(CTPN+" searches furiously around the room.\n");
                return 1;
            }
        write("You search the fountain and manage to get your hands "+BLU+"wet"+NORM+".\n");
        say(CTPN+" searches furiously around the room.\n");
        return 1;
        }
    write("You search the fountain and manage to get your hands "+BLU+"wet"+NORM+".\n");
    say(CTPN+" searches furiously around the room.\n");
    return 1;
    }
    write("You furiously search the "+str+" but find nothing.\n");
    say(CTPN+" searches furiously around the room.\n");
}

move_southeast() {
      write("You stumble blindly out of the dark alley.\n");
      this_player()->move_player("stumbling out of the darkness#/players/vital/dest/acadie/room/alley9.c");
	return 1;
}

move_east() {
      write("You stumble blindly out of the dark alley.\n");
      this_player()->move_player("stumbling out of the darkness#/players/vital/dest/acadie/room/alley2.c");
	return 1;
}

move_south() {
      write("You stumble blindly out of the dark alley.\n");
      this_player()->move_player("stumbling out of the darkness#/players/vital/dest/acadie/room/alley7.c");
	return 1;
}

move_northwest() {
    write("You stumble blindly into a nearby building.\n");
    this_player()->move_player("stumbling out of the darkness#/players/vital/dest/acadie/room/home4.c");
    return 1;
}
