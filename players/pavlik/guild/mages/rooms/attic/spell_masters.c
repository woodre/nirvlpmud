#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Master's Hallway";
long_desc=
"You have ascended into the ante chamber of the Spell Masters.  This\n"+
"triangular room is the portal to the most powerful of Guild Masters.\n"+
"The Spell Masters are responsible for teaching a Mage the specific spheres\n"+
"of magical powers and granting the young Mage with new spells.  There are\n"+
"doorways to the north, south and west.  The sound of soft piano music can\n"+
"be heard to the north.  Dark foreboding shadows darken the southern door.\n"+
"A sprial staircase leads down.\n";


dest_dir=({
 "/players/pavlik/guild/mages/rooms/yshir_room", "north",
 "/players/pavlik/guild/mages/rooms/ansari_room", "west",
 "/players/pavlik/guild/mages/rooms/dycedakis_room", "south",
 "/players/pavlik/guild/mages/rooms/masters_hall", "down",
});

   }
}

query_mguild(){ return "Masters Hallway"; }

init(){
 ::init();
  mage_check();
  add_action("guild_move","gm");
}
