#include <ansi.h>

inherit "room/room";

int is_here;

reset(arg)
{
  ::reset(arg);
  if( !present("mayor", this_object()) )
    move_object(clone_object("/players/angel/area/mansion/npc/mayor_ray.c"), this_object());
  is_here=1;
  if(arg) return;
  set_light(1);
  short_desc = "Office";
  long_desc =
"   This is Mayor Bob Ray's office. The cities business along with\n\
mayor's personal company's business occurs here on a daily basis.\n\
The room has 15 feet high ceilings with elegant tapestry around the\n\
room. The room has thick wood trim that add to the elegance of the\n\
room. There is a brick fireplace on the south side of the room. The\n\
area is fill with heavy oak furniture and a beautiful mahogany desk.\n";

  items =
  ({
    "office",
    "",
    "company",
    "",
    "tapestry",
    "",
    "wood",
    "",
    "fireplace",
    "",
    "furniture",
    "",
    "desk",
    "",
});
  dest_dir =
  ({
    "/players/angel/area/mansion/room/entrance_10",     "entrance",
    "/players/angel/area/mansion/room/living_room_10",   "living",
    "/players/angel/area/mansion/room/mansion_01",      "outside",
  });
}

init(){ 
  ::init();
    add_action("search","search");
    this_player()->set_fight_area();
      }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }

search(str) {
  object key;
  if(present("mayor")) {
    write("Get out of my desk before I have you arrested!\n");
    return 1;
  }

  if(!str) {
    write("Search what?\n");
    return 1;
  }
  if(str=="desk" && is_here) {
    write("You find a old skelton key.\n");
    key=clone_object("/players/angel/area/mansion/obj/hirams_key");
    move_object(key,this_player());
    is_here=0;
    return 1;
  }
  write("You find nothing.\n");
  return 1;
}