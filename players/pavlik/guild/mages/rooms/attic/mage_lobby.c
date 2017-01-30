#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
object obj;
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Mage's Tower";
long_desc=
"This is the lobby to the Mage's Residents Quarter.  This cozy chamber\n"+
"is furnished with large plush couches and high backed chairs.\n"+
"Sunlight filters through a beautiful stain glass window that occupies\n"+
"the entire east wall.  A portal at the north end of the room leads\n"+
"into the Mage's private quarters.\n";

items=({
"carpet",
"The carpet is a very elaborate, very expensive import from the\n"+
"eastern expanses.  The rug displays a myriad of colors that seem\n"+
"to be almost hypnotising if you stare at them to long",
"door",
"There are heavy iron doors to the north and south",
});

  if(!present("portal", this_object())){
    obj = clone_object("players/pavlik/guild/mages/obj/lobby_portal");
    move_object(obj, this_object());
    }

dest_dir=({
 "/players/pavlik/guild/mages/rooms/level3_hall", "south",
});

   }
}

query_mguild(){ return "Mage Lobby"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("go_hole","hole");
}

go_hole(){
  if(this_player()->query_level() < 99) return 0;
  move_object(this_player(),"players/pavlik/guild/mages/rooms/PROOMS/master-room");
  command("look", this_player());
  return 1;
}

