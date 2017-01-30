inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Enchantment Department";
  long_desc = 
   "You are in front of the enchantment department.\n";
  dest_dir = ({"/players/bastion/guild/court4", "south",
               "/players/bastion/guild/room/enchantment2", "north"});
  }
}
