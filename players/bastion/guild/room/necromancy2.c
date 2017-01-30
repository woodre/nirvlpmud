inherit	"room/room";
inherit "players/bastion/guild/guildroom";
inherit "players/bastion/guild/room/class";

reset(arg) { 
  if(!arg) {
  set_light(1);
  DEPT = "necromancy";
  TOPIC = "the spirit world and death";
  short_desc = "Necromancy Department";
  long_desc = 
   "This is a temporary classroom. There are some empty seats.\n";
  dest_dir = ({"/players/bastion/guild/room/necromancy", "south"});
  }
}

init(arg) {
  add_commands();
  ::init(arg);
}
