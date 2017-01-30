#include <ansi.h>

inherit "room/room";

int is_here;

reset(arg)
{
  ::reset(arg);
  if( !present("mason", this_object()) )
    move_object(clone_object("/players/angel/area/mansion/npc/entered_apprentice_01.c"), this_object());
  is_here=1;
  if(arg) return;
  set_light(1);
  short_desc = "Masonic shrine";
  long_desc =
"This room appears to be a masonic shrine filled with many mason\n\
artifacts.\n";

  items =
  ({
});
  dest_dir =
  ({
    "/players/angel/area/mansion/room/storage_room_10",   "storage",
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
  object saber;
  if(present("mason")) {
    write("You won't be going through that while I am here!\n");
    return 1;
  }

  if(!str) {
    write("Search what?\n");
    return 1;
  }
  if(str=="shelf" && is_here) {
    write("You find a masonic saber.\n");
    saber=clone_object("/players/angel/area/mansion/obj/masonic_saber_01");
    move_object(saber,this_player());
    is_here=0;
    return 1;
  }
  write("You find nothing.\n");
  return 1;
}