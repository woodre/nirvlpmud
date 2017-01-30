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
This dark, humid area between buildings has become the home to \n\
trash, boxes and unsavory characters. The trash is piled high and \n\
the town tries hard to forget that both the trash and the alley \n\
are here. The sky is blotted out by the material hanging overhead, \n\
and the floor is hidden by the horrible collection of trash and junk.\n ";

items = ({
    "buildings",
    "The low, stone, standard structures that make up this town",
    "trash",
    "The rubish and refuse is deep here",
    "boxes",
    "The boxes look chewed upon and rotting",
    "characters",
    "If there was going to be something evil in EdmonTown, it would be here",
    "town",
    "The town is a collection of low stone buildings",
    "alley",
    "This place is full of trash and vermin",
    "sky",
    "From here, you cannot see the sky",
    "material",
    "The sky is blotted out by this strange, cloth-like material",
    "floor",
    "The ground is covered with trash and junk, piled high",
    "collection",
    "Here is the wildest remnant of society, off-cast and destroyed"
});

dest_dir = ({
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("move_northwest","northwest");
    add_action("move_northeast","northeast");
}

move_northwest() {
    object vermina, verminb;
    if(!present("vermina",TO) && !present("verminb",TO)) {
      write("You stumble blindly into the dark alley.\n");
      this_player()->move_player("stumbling into darkness#/players/vital/dest/acadie/room/sidewalk12.c");
	return 1;
    }
    write("You can't get past the vermin running around in front of you.\n");
    return 1;
}

move_northeast() {
    object vermina, verminb;
    if(!present("vermina",TO) && !present("verminb",TO)) {
      write("You stumble blindly into the dark alley.\n");
      this_player()->move_player("stumbling into darkness#/players/vital/dest/acadie/room/alley4.c");
	return 1;
    }
    write("You can't get past the vermin running around in front of you.\n");
    return 1;
}

search_me(str) {
    object vermina, verminb;
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    switch(str) {
        case "boxes": if(!present("vermina",TO)) {
            vermina = CO("/players/vital/closed/std/monster.c");
            vermina->set_name("vermin");
            vermina->set_id("vermina");
            vermina->set_short("This is a strange-looking rodent that most likely wants to chew your leg off.\n");
            vermina->set_level(5+random(3));
            vermina->set_aggro(1,100,100);
            vermina->set_alias("rat");
            vermina->set_align(-250);
            vermina->set_race("vermin");
            MO(vermina, TO);
        }
        break;
        case "receptacles":
        case "receptacle": if(!present("vermina",TO)) {
            verminb = CO("/players/vital/closed/std/monster.c");
            verminb->set_name("vermin");
            verminb->set_id("verminb");
            verminb->set_level(5+random(3));
            verminb->set_aggro(1,100,100);
            vermina->set_align(-250);
            verminb->set_alias("rat");
            verminb->set_race("vermin");
            MO(verminb, TO);
        }
        break;
        default: write("You furiously search the "+str+" but find nothing.\n");
    }
    return 1;
}
