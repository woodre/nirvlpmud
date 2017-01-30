inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Necromancy Department";
  long_desc = 
   "You are in front of the necromancy department.\n";
  dest_dir = ({"/players/bastion/guild/court3", "south",
               "/players/bastion/guild/room/necromancy2", "north"});
  }
}
