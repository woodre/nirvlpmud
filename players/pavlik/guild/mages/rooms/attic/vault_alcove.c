#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="the Vault Alcove";
long_desc=
"This alcove is a tiny room hidden in the shadows of the Mage's Vault.\n"+
"Members of the guild can leave items here that they plan to come back\n"+
"for later.  Please DO NOT take any items from here other than your own\n"+
"without permission.\n"+
"Water slowly drips from a crack on the ceiling.\n";

items=({"ceiling",
"A tiny fracture disrupts the smooth surface of the ceiling.\n"+
"Droplets of water plummet to the floor.\n"+
"There is something strange about this water ..",
});


dest_dir=({
  "/players/pavlik/guild/mages/rooms/vault_room", "east",
});

   }
}

query_mguild(){ return "Alcove"; }

init(){
  ::init();
  add_action("guild_move","gm");
  mage_check();
}
