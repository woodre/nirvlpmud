inherit	"room/room";
inherit "players/bastion/guild/guildroom";
inherit "players/bastion/guild/room/class";

reset(arg) { 
  if(!arg) {
  set_light(1);
  DEPT = "enchantment";
  TOPIC = "hexes, charms and getting that special someone to notice you at " +
   "parties";
  short_desc = "Enchantment Department";
  long_desc = 
   "This is a temporary classroom. There are some empty seats.\n";
  dest_dir = ({"/players/bastion/guild/room/enchantment", "south"});
  }
}

init(arg) {
  add_commands();
  ::init(arg);
}
