#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Dycedakis' Chambers";
long_desc=
"You have entered the chambers of shadow and illusion.  A dark foreboding\n"+
"creeps into your mind as you stand before the elements of Illusion and\n"+
"Necromancy.  Immaterial phantasms carelessly wander through the walls\n"+
"and the wailing of lost souls echoes piteously from some unknown place.\n"+
"A black cat lies dormant before a narrow doorway to the east.  The\n"+
"disturbing caw of a perched raven attempt to pierce your concentration.\n"+
"The hallway behind you seems very bright in comparison to this dark and\n"+
"shady chamber.\n";

items=({
"phantasms",
"Transparent forms float aimlessly through the room.  Although they appear\n"+
"harmless you find it impossible to relax in their presence",
"cat",
"A black cat rests lazily on the floor.  The animal seems to be sleeping\n"+
"yet you notice two flat yellow eyes staring into you",
"raven",
"The large black raven stand on it's perch and caws loudly",
});

dest_dir=({
 "/players/pavlik/guild/mages/rooms/spell_masters", "north",
 "/players/pavlik/guild/mages/rooms/BLAH", "east",
});

if(!present("dycedakis", this_object()))
  move_object(clone_object("players/pavlik/guild/mages/rooms/npc/dycedakis"),
  this_object());

   }
}

query_mguild(){ return "Dycedakis'"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("no_way","east");
  mage_check();
}

no_way(){
  write(
  "You make a move toward the eastern doorway but the flat yellow gaze\n"+
  "of the black cat makes you reconsider.\n");
  say("The shadows grow deeper and a bead of sweat rolls down your neck.\n");
  return 1;
}

