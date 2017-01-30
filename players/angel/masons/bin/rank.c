#include "defs.h"

status main(string str, int glevel) {
  object gob;
  int gexp;
  status muffled;

  gob = present(MGOB_ID, this_player());
  gexp = (int)gob->query_gexp();
  muffled = (status)gob->query_muffle();

  write((string)this_player()->short()+" ("+(int)this_player()->query_level()+")\n");
  write("Hit points: "+(int)this_player()->query_hp()+"\n");
  write("Spell points:  "+(int)this_player()->query_spell_point()+"\n");
  write("Experience: "+(int)this_player()->query_exp()+"\n");
  write("Gold coins: "+(int)this_player()->query_money()+"\n");
  write("Guild rank: "+glevel+"\n");
  write("Guild experience: "+gexp+"\n");
  write("Guild loan: "+(int)gob->query_loan()+"\n");
  write("In the old days, guild wimpy status would go here as well.\n");
  write("Guildmuffles are: "+(muffled ? "on" : "off") + ".\n");
/*
  if(muffled == 1) {
    write("Guildmuffles are on.\n");
  } else
  write("Guildmuffs are off.\n");
*/
  return 1;
}
