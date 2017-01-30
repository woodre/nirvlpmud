inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Pathway";
  long_desc = 
   "You are on a path between the guild master's house and the Alchemy Dept.\n";
  dest_dir = ({"/players/bastion/guild/court2", "northwest",
               "/players/bastion/guild/court1", "southeast"});
  }
}
