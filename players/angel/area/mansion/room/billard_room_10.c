#include <ansi.h>

inherit "room/room";

int saber;

int enter;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Billard room";
  long_desc =
"The billard room. \n";

  items =
  ({
});
  dest_dir =
  ({
    "/players/angel/area/mansion/room/broiler_room_10",   "broiler",
  });
}

init(){ 
  ::init();
    add_action("open","open");
    add_action("place","place");
    add_action("place","hang");
    add_action("enter","enter");
    this_player()->set_fight_area();
      }

open(str) {
  if(!str) { write("Open what?\n"); return 1;}
  if(str=="door") {
    write("There aren't any additional visible doorways.\n");
    return 1;
  }
  write("Open what?\n");
  return 1;
}

place(str) {
  if(!str) {write("Place what?\n");return 1;}
  if(str!="saber") { write("Place what?\n"); return 1; }
  if(present("saber",this_player())) {
    destruct(present("saber",this_player()));
    write("You place the saber on its scabbard.\n");
    saber=1;
    call_out("enter_passage",1);
    return 1;
}}

enter_passage() {
	if(saber) {
	 tell_room(this_object(),
"A large section of the wood paneling wall slides open into a passageway.\n"
    );
  }
}

enter(str) {
    if(saber) {
      this_player()->move_player("enter#"+"/players/angel/area/mansion/room/hiram_lair_01");
      return 1;
  }
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }