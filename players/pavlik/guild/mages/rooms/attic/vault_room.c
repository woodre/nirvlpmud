#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
object obj;
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Mage's Vault";
long_desc=
"You are in the Mage's Vault Room.  In the center of this rounded room\n"+
"is an enchanted treasure chest.  The chest can only be accessed by\n"+
"members of the guild.  This room is a storage cell, so that members\n"+
"of the guild may leave items here for their less equipped brethren.\n"+
"There are magical inscriptions on the chest, as well as on the wall\n"+
"next to the door.  There is a small alcove to the west.\n";

items=({"wall",
"A small sign written in the magic language:\n"+
"The Vault Room is for sharing needed equipment among the guild\n"+
"members.  Taking items from here for the purpose of selling is\n"+
"forbidden, unless a) The person selling is the one to have left\n"+
"the item in the first place, or b) The person selling has the\n"+
"permission of the donor.  Look at the Vault for more instructions\n"+
"on withdrawing and depositing equipment.\n",
});

dest_dir=({
  "/players/pavlik/guild/mages/rooms/guild_room", "south",
  "/players/pavlik/guild/mages/rooms/vault_alcove", "west",
});

  if(!present("mage's vault", this_object())){
    obj = clone_object("players/pavlik/guild/mages/obj/vault.c");
    move_object(obj, this_object());
    }
   }
}

query_mguild(){ return "Vault"; }

init(){
  ::init();
  add_action("guild_move","gm");
  mage_check();
}

