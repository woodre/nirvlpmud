#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Mage's Tower";
long_desc=
"You are in the Mage's Tower.  The Library and the Training Chamber\n"+
"are located on this level.  The floor of this chamber is constructed\n"+
"of millions of tiny little tiles.  The tiles are fit to depict a\n"+
"fearsome dragon, breathing searing flames.  The mural looks so real\n"+
"you think the dragon could spring out of the floor at any moment.\n"+
"The double doors to the east lead into the Mage's Library and an iron\n"+
"door in the north wall leads to the Training Chamber.\n";

items=({
"floor",
"The floor is made up of millions of tiny tiles.  Each tile is\n"+
"crafted to look like to scale of a dragon.  The overall picture\n"+
"is that of a fiercesome fire-breathing dragon.  The mural is so\n"+
"perfectedly crafted, that it looks like the picture could spring\n"+
"to life at any moment!",
});



dest_dir=({
 "/players/pavlik/guild/mages/rooms/train_room", "north",
 "/players/pavlik/guild/mages/rooms/library", "east",
 "/players/pavlik/guild/mages/rooms/guild_room", "down",
 "/players/pavlik/guild/mages/rooms/guild_room3", "up",
});

   }
}

query_mguild(){ return "Guild Room 2"; }

init(){
  ::init();
  add_action("guild_move","gm");
  mage_check();
}
