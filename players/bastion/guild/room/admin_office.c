inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Office";
  long_desc = 
   "You are in someone's office.\n";
  dest_dir = ({"/players/bastion/guild/room/admin2", "southeast"});
  }
}
