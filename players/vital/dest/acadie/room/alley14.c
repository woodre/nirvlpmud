/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/26/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
    if(!arg) { 
    set_light(0);
    short_desc = "Alley";
    long_desc =
    "  A Dark Alleyway\n\
This is a slight, open space between the walls of two buildings. \n\
The space overhead has been covered and blocks out any view of the \n\
sky. The people of this town have used this alley as a place to \n\
throw their trash and worthless junk. There are old piles of junk \n\
and trash cans overflowing with refuse and rubish.\n ";

items = ({
    "space",
    "This small distance between the walls of two buildings creating a dark alley",
    "buildings",
    "The buildings are low, stone structures that are found throughout the city",
    "overhead",
    "The sky is blocked out by some material placed across the gap between \n\
the two buildings",
    "sky",
    "The light "+CYN+"blue"+NORM+" sky is hidden from view",
    "people",
    "The stalwart inhabitants of this cold, forboding place don't often \n\
come here",
    "alley",
    "The narrow space here is filled and blocked with stuff",
    "town",
    "The town is composed of many buildings all surrounding a larger structure",
    "trash",
    "The offcast, material possessions and the packing materials that they \n\
came in lay scattered and piled here",
    "junk",
    "The stuff that no one wants has been thrown into this alley",
    "piles",
    "The trash and junk has formed into rough collections that must be \n\
navigated around",
    "cans",
    "The trash cans here are overflowing and something will have to be \n\
done soon",
    "refuse",
    "This is the organic parts of uneaten food and food by-products",
    "rubish",
    "The miscellaneous collection of things that cannot be described"
});

dest_dir = ({
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("move_northwest","northwest");
    add_action("move_east","east");
}

search_me(str) {
    object vermina, verminb;
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    switch(str) {
        case "rubish":
        case "refuse":
        case "boxes": if(!present("vermina",TO)) {
            vermina = CO("/players/vital/closed/std/monster.c");
            vermina->set_name("big vermin");
            vermina->set_id("vermina");
            vermina->set_short("This is a strange-looking rodent that most likely wants to chew your leg off.\n");
            vermina->set_level(7+random(7));
            vermina->set_aggro(1,100,100);
            vermina->set_align(-random(300) - 150);
            vermina->set_alias("vermin");
            vermina->set_race("vermin");
            MO(vermina, TO);
        }
        case "pile":
        case "trash":
        case "cans": if(!present("vermina",TO)) {
            verminb = CO("/players/vital/closed/std/monster.c");
            verminb->set_name("big vermin");
            verminb->set_id("verminb");
            verminb->set_level(7+random(7));
            verminb->set_aggro(1,100,100);
            vermina->set_align(-random(300) - 150);
            verminb->set_alias("vermin");
            verminb->set_race("vermin");
            MO(verminb, TO);
        }            
        default: write("You furiously search the "+str+" but find nothing.\n");
    }
}

move_northwest() {
    if(!present("vermina", TO) && !present("verminb",TO)) {
      write("You stumble blindly into the dark alley.\n");
      this_player()->move_player("stumbling into darkness#/players/vital/dest/acadie/room/sidewalk31.c");
	return 1;
    }
    write("You can't get past the vermin running around in front of you.\n");
    return 1;
}

move_east() {
    if(!present("vermina",TO) && !present("verminb",TO)) {
      write("You stumble blindly out of the dark alley.\n");
      this_player()->move_player("stumbling out of the darkness#/players/vital/dest/acadie/room/sidewalk36.c");
	return 1;
    }
    write("You can't get past the vermin running around in front of you.\n");
    return 1;
}
