#include "/players/pestilence/ansi.h"


main() {
  int x, level, g_level, xlevel, combat_lvl, plev;
  string title, place;
  object ob, cob, peeps;
  peeps = users();

  write("\n");
  write(HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+HIW+" <  "+HIR+" O R D E R"+HIW+"   > "+HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
  write(HIG+pad("Name:", 15)+
        pad("Level:", 10)+
        pad("Glvl:", 9)+
        pad("Combat", 8)+
        pad("Location:", 30)+NORM+"\n");
  write(HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
  for(x=0;x<sizeof(peeps);x+=1){
    if(!peeps[x]->query_invis() && present("dknight_ob", peeps[x])){ 
        ob = peeps[x];
        write(pad(capitalize(ob->query_real_name()), 15));
        level = ob->query_level();
        xlevel = ob->query_extra_level();
		plev = ob->query_prestige_level();

        write(pad(level+"+"+xlevel+"("+plev+")", 12));
        g_level = ob->query_guild_rank();
        write(pad(g_level, 10));
             combat_lvl = present("dknight_ob",ob)->query_combat();
        write(pad(combat_lvl, 5));
        place = environment(ob)->short();
        write(place);
        write("\n");
    }
  }
  write(HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
  return 1;
}
