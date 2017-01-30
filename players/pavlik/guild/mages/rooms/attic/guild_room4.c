#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Mage's Tower";
long_desc=
"You are in the Mage's Tower.  This room is empty except for an\n"+
"intricate carpet covering the entire floor, and a small end table\n"+
"in the southeast corner.  The walls are made of the spiraling\n"+
"staircase that continues up and downwards from here.  There are\n"+
"doors to the west and south.  The door to the south has a tiny bell\n"+
"over it.  The door to the west is covered with powerful runes.\n";

items=({
"carpet",
"The carpet is a very elaborate, very expensive import from the\n"+
"eastern expanses.  The rug displays a myriad of colors that seem\n"+
"to be almost hypnotizing if you stare at them too long",
"table",
"There is a little end table in the southeast corner.\n"+
"There is nothing on the table",
"stairs",
"The stairs go both up and down from this point",
"door",
"There are doors to the south and west",
"south door",
"A small wooden door in the south wall.  There is a tiny bell over\n"+
"this door",
"west door",
"This wooded door is covered with magical runes.  You fear for any\n"+
"uninvited guest that might try to pass through this portal",
"runes",
"There are powerful runes of protection on the west door.  You\n"+
"fear for any uninvited guest that might try to pass",
"bell",
"There is a tiny bell over the south door.  It seems to be placed so\n"+
"that the bell will chime when the door opens",
});


dest_dir=({
 "/players/pavlik/guild/mages/rooms/mage_shop", "south",
 "/players/pavlik/guild/mages/rooms/ante_room", "west",
 "/players/pavlik/guild/mages/rooms/guild_room3", "down",
 "/players/pavlik/guild/mages/rooms/guild_room5", "up",
});

   }
}

query_mguild(){ return "Guild Room 3"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("enter_shop","south");
  mage_check();
}

enter_shop(){
  tell_room(this_object(),
  "A tiny bell chimes as the south door opens.\n");
  write("You open the south door.\n");
  move_object(this_player(), "players/pavlik/guild/mages/rooms/mage_shop");
  say("The tiny bell above the door chimes as "+
  capitalize(this_player()->query_name())+" enters the shop.\n");
  command("look", this_player());
  return 1;
}
