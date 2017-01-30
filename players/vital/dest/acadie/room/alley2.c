/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/19/01           */
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
The alleyway continues on in darkness. the buildings crowd in \n\
with shadows and darkness chases away the light. The gap overhead, \n\
between the buildings has been covered with some material to \n\
blockout the light of the sky. There are boxes and trash receptacles \n\
here and probably vermin as well.\n ";

items = ({
    "everything",
    "There are many pieces of trash and scrap here in the alley",
    "buildings",
    "The buildings are low, stone structures that are crowded together",
    "shadows",
    "The shadows are deep, and filled with mystery",
    "darkness",
    "You strain your eyes to see images in the darkness",
    "light",
    "There is no extra light here in this dark alleyway",
    "gap",
    "The gap between the two low buildings has been covered with some dark material to block out the light from the sky overhead",
    "material",
    "The material is some kind of manufactured planking",
    "sky",
    "From the alleyway it is impossible to see the sky overhead",
    "boxes",
    "These are used boxes, that now lie discarded in the alleyway",
    "receptacles",
    "These are large bins used to place refuse and trash into",
    "vermin",
    "There are droppings and the boxes bare the markings of being chewed"
});

dest_dir = ({
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("move_west","west");
    add_action("move_east","east");
}

move_west() {
    object vermina, verminb;
    if(!present("vermina",TO) && !present("verminb",TO)) {
      write("You stumble blindly into the dark alley.\n");
      this_player()->move_player("stumbling into darkness#/players/vital/dest/acadie/room/courtyard.c");
	return 1;
    }
    write("You can't get past the vermin running around in front of you.\n");
    return 1;
}

move_east() {
    object vermina, verminb;
    if(!present("vermina",TO) && !present("verminb",TO)) {
      write("You stumble blindly into the dark alley.\n");
      this_player()->move_player("stumbling into darkness#/players/vital/dest/acadie/room/alley1.c");
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
        case "rubish":
        case "refuse":
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
            vermina->set_short("This is a strange-looking rodent that most likely wants to chew your leg off.\n");
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
