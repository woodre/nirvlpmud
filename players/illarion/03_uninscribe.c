#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob;
  if(!str)
    FAIL("Syntax: uninscribe <item>\n");
  ob=present(str,TP);
  if(!ob)
    FAIL("You don't have that item.\n");
  ob->remove_enchantment("bard_runes");
  ob->remove_enchantment("bard_runes2");
  ob->remove_enchantment("bard_runes3");
  write("You remove all Bardic Runes from "+NAME(ob)+".\n");
  return 1;
}