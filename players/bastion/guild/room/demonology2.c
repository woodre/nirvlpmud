inherit	"room/room";
inherit "players/bastion/guild/guildroom";
inherit "players/bastion/guild/room/class";

reset(arg) { 
  if(!arg) {
  set_light(1);
  DEPT = "demonology";
  TOPIC = "true names and ritual sacrifice";
  short_desc = "Demonology Department";
  long_desc = 
   "This is a temporary classroom. There are some empty seats.\n";
  dest_dir = ({"/players/bastion/guild/room/demonology", "east"});
  }
}

init(arg) {
  add_commands();
  ::init(arg);
}
