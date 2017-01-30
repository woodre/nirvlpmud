#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Master's Hallway";
long_desc=
(
"This small hallway leads to the Master's quarters.  The Masters of the\n"+
"Circle of Mages live and teach from within these walls.\n"+
"Master's Buepaya's chambers are located through the door to the south.\n"+
"A spiral staircase leads upwards into the chambers of the Spell Masters.\n");

dest_dir=({
 "/players/pavlik/guild/mages/rooms/buepaya_room", "south",
 "/players/pavlik/guild/mages/rooms/masters_hall2", "west",
 "/players/pavlik/guild/mages/rooms/ante_room", "east",
 "/players/pavlik/guild/mages/rooms/spell_masters", "up",
});

   }
}

query_mguild(){ return "Masters Hallway"; }

init(){
  ::init();
  add_action("guild_move","gm");
  mage_check();
}

