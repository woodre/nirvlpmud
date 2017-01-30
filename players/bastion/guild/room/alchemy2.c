inherit	"room/room";
inherit "players/bastion/guild/guildroom";
inherit "players/bastion/guild/room/class";

reset(arg) { 
  if(!arg) {
  set_light(1);
  DEPT = "alchemy";
  TOPIC = "the elements, the cohesion of matter and the need for strong " +
   "strong walls in the labs";
  short_desc = "Alchemy Department";
  long_desc = 
   "This is a temporary classroom. There are some empty seats.\n";
  dest_dir = ({"/players/bastion/guild/room/alchemy", "east"});
  }
}

init(arg) {
  add_commands();
  ::init(arg);
}
