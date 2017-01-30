inherit	"room/room";
inherit "players/bastion/guild/guildroom";
inherit "players/bastion/guild/room/class";

reset(arg) { 
  if(!arg) {
  set_light(1);
  DEPT = "alteration";
  TOPIC = "energy fields and toads";
  short_desc = "Alteration Department";
  long_desc = 
   "This is a temporary classroom. There are some empty seats.\n";
  dest_dir = ({"/players/bastion/guild/room/alteration", "south"});
  }
}

init(arg) {
  add_commands();
  ::init(arg);
}
