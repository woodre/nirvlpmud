#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Ansari's Chambers";
long_desc=
"The Chamber's of Ansari are noticably more spartan than those of\n"+
"the other Masters.  This simple round chamber is barren except\n"+
"for a straw tutami mat which covers the floor and a small circular\n"+
"bowl which is placed at the center of the room.  Even the walls are\n"+
"all devoid of any decoration.  A door to the south leads to\n"+
"Ansari's private chambers.\n";

items=({
"mat",
"A plain tutami mat covers the floor.  The mat is made of tightly\n"+
"woven straw.  The bristles of straw crunch quietly when you walk\n"+
"on the mat",
"bowl",
"The bowl appears to be a simple piece of pottery.  There are no\n"+
"markings or inscriptions upon it.  Looking closely you see a very\n"+
"fine, almost invisisble, vapor rising slowly from the bowl",
"vapor",
"The vapor is so hard to see you are not even positive at is there",
});

dest_dir=({
 "/players/pavlik/guild/mages/rooms/spell_masters", "east",
 "/players/pavlik/guild/mages/rooms/BLAH", "south",
});

if(!present("ansari", this_object()))
  move_object(clone_object("players/pavlik/guild/mages/rooms/npc/ansari"),
  this_object());

   }
}

query_mguild(){ return "Ansari's Chambers"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("no_way","south");
  mage_check();
}

no_way(){
  write(
  "You ponder entering the door to the south and decide against it.\n");
  return 1;
}

