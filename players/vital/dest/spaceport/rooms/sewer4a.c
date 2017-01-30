/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   3/5/01            */
/*    Realm:      Spaceport         */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "room/room";

reset(arg) {
    if(!arg) { 
    set_light(0);
    short_desc = "Sewer";
    long_desc =
    "  The Sewers\n\
This is a long tunnel that continues, curves and twists off \n\
to the south and east. The floor curves up to become the \n\
walls which in turn curve on up to become the ceiling. The \n\
darkness could hide anything down here.\n ";

items = ({
    "tunnel",
    "This is a long, curving concrete tube",
    "northeast",
    "The tunnel heads off in that direction",
    "floor",
    "The floor is covered in a couple inches of water",
    "walls",
    "The walls are curved and look gross",
    "ceiling",
    "The ceiling is covered in moss and barely 2 meters tall",
    "darkness",
    "The darkness is probably covering something that you do not want to see"
});

dest_dir = ({
    SPROOM+"sewer3.c","south",
    SPROOM+"sewer5.c","east"
  });
call_out("add_monster",2);
  }
}

init() {
    ::init();
    add_action("search_me","search");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    else write("You furiously search the "+str+" but find nothing.\n");
}

add_monster() {
    object ob;
    if(!present("stupid_monster")) {
    ob = CO("/players/vital/closed/std/monster.c");
    ob->set_id("stupid_monster");
    ob->set_name("sewer monster");
    ob->set_alias("monster");
    ob->set_short(HIG+"Sewer "+HIB+"Monster"+NORM);
    ob->set_long("\
The depths of the N.U.T.S. sewer has spawned a terror that seeks to \n\
destroy you. You can run from the monsters of the sewer, but you \n\
cannot hide!\n");
    ob->set_wander(5, 0, ({"grate"}));
    ob->set_level(20);
    ob->set_aggro(1,75,15);
    ob->set_chance(25);
    ob->set_spell_mess1("The "+HIG+"Sewer "+NORM+"monster oozes with acidic particles.\n");
    ob->set_spell_mess2("The monster tosses trash into the fray!\n");
    ob->set_spell_dam(random(15)+10);
    ob->set_info("These monsters are the result of illegal genetic testing and \nthe dumping of highly mutanagenic waster.\n");
    ob->set_race("mutant");
    ob->set_message_hit( ({"gave"," fits of pain and acidic burns","smushed","'s head into a small pancake sized ball","banged"," over the head with big, crushing blows","hurt"," with repeated punching","hurt","","grappled"," with the massive arms","poked"," in the stomach with a mangled appendage"}) );
    ob->add_money(4100+random(1500));
    MO(ob, TO);
    }
    return 1;
}
