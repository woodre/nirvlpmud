inherit	"room/room";
inherit "players/bastion/guild/guildroom";
inherit "players/bastion/guild/room/class";

reset(arg) { 
  if(!arg) {
  set_light(1);
  DEPT = "conjuration";
  TOPIC = "pulling things from rabbits and raining hellfire";
  short_desc = "Conjuration Department";
  long_desc = 
   "This is a temporary classroom. There are some empty seats.\n";
  dest_dir = ({"/players/bastion/guild/room/conjuration", "north"});
  }
}

init(arg) {
  add_commands();
  ::init(arg);
}
