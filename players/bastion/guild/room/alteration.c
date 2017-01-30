inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Alteration Department";
  long_desc = 
   "You are in front of the alteration department.\n";
  dest_dir = ({"/players/bastion/guild/court2", "south",
               "/players/bastion/guild/room/alteration2", "north"});
  }
}
