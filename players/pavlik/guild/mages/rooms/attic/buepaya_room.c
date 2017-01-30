#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Buepaya's Chambers";
long_desc=
"You have walked into the peaceful solitude of Buepaya's chambers.\n"+
"The smell of incense fills the air and large green ferns provide\n"+
"a natural decor.  Buepaya spends most of her time here in medi-\n"+
"tation.  A small fountain bubbles in the corner.  A door to the\n"+
"north leads out and a door in the west wall leads to Buepaya's\n"+
"private rooms.\n";

items=({
"incense",
"Dozens of incense candles are placed about the room.  They\n"+
"permeate the air with a pleasant odor and provide gentle\n"+
"lighting to the room",
"ferns",
"The rooms is full of lush plant life.  The ferns give you\n"+
"a sense of peace and harmony with nature",
"fountain",
"A tiny fountain bubbles away quietly.  You spot several fish\n"+
"swimming inside of its bowl",
"fish",
"Several different breeds of fish swim happily inside the fountain",
});

dest_dir=({
 "/players/pavlik/guild/mages/rooms/masters_hall", "north",
 "/players/pavlik/guild/mages/rooms/BLAH", "west",
});

if(!present("buepaya", this_object()))
  move_object(clone_object("players/pavlik/guild/mages/rooms/npc/buepaya"),
  this_object());

   }
}

query_mguild(){ return "Buepaya's"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("no_way","west");
  mage_check();
}

no_way(){
  write(
  "You move towards the western door and the burning candles\n"+
  "flare alarmingly.  You think better of going there.\n");
  say("The candles flare brightly for a moment.\n");
  return 1;
}

