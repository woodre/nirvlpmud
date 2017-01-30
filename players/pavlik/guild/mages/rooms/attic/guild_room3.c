#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Mage's Tower";
long_desc=
"You are in the Mage's Tower.  The walls of this chamber are actually the\n"+
"enormous spiral staircase that runs the height of the tower itself.\n"+
"There is a large oak door to the north wall and a smaller metal door in\n"+
"the south.  The metal door is locked with powerful magic.\n";

dest_dir=({
 "/players/pavlik/guild/mages/rooms/gc_room", "south",
 "/players/pavlik/guild/mages/rooms/level3_hall", "north",
 "/players/pavlik/guild/mages/rooms/guild_room2", "down",
 "/players/pavlik/guild/mages/rooms/guild_room4", "up",
});

   }
}

query_mguild(){ return "Guild Room 3"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("gc_room","south");
  mage_check();
}

gc_room(){
  if(this_player()->query_guild_rank() < 72){
    write("You cannot open this door.\n");
    write("You DARE not open this door.\n");
    return 1;
    }
  write("You cast a spell and walk straight through the metal barrier.\n");
  say(capitalize(this_player()->query_name())+" utters a magic word and walks "+
  "through the metal door.\n");
  move_object(this_player(), "players/pavlik/guild/mages/rooms/gc_room");
  say(capitalize(this_player()->query_name())+" enters.\n");
  return 1;
}
