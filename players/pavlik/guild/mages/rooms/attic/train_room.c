#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
object obj;
reset(arg){
 if(!arg){
 set_light(1);
 short_desc="The Training Chamber";
 long_desc=
 "You walk through the heavy iron door and into the Training Chamber.  The\n"+
 "walls of this chamber are extremely thick and protected by powerful magics.\n"+
 "Spells that would crack open the Earth will not even chip the enchanted\n"+
 "walls of this room.  The Mages created this chamber as a place to practice\n"+
 "casting thier spells.  Many dangerous enchantments and deadly evocations\n"+
 "have been unleashed between these walls.  The heavy iron door in the south\n"+
 "wall provides the only exit.\n";

dest_dir=({
  "players/pavlik/guild/mages/rooms/guild_room2", "south",
});

if(!present("golem", this_object()))
  move_object(clone_object("players/pavlik/guild/mages/obj/stone_golem"),
  this_object());

    }
}

query_mguild(){ return "Training Chamber"; }

init(){
  ::init();
  add_action("guild_move","gm");
  mage_check();
}

