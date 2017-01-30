#include "/players/pestilence/ansi.h"

cmd_order() {
  int x, level, g_level, xlevel;
  string title, place;
  object ob, cob, peeps;
  peeps = users();

  write("\n");
  write(HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+HIW+" <  "+HIR+" O R D E R"+HIW+"   > "+HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
  write(HIG+pad("Name:", 15)+
        pad("Level:", 11)+
        pad("Guild Level:", 16)+
        pad("Location:", 30)+NORM+"\n");
  write(HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
  for(x=0;x<sizeof(peeps);x+=1){
    if(!peeps[x]->query_invis() && present("dknight_ob", peeps[x])){ 
        ob = peeps[x];
        write(pad(capitalize(ob->query_real_name()), 15));
        level = ob->query_level();
        xlevel = ob->query_extra_level();
        write(pad(level+"+"+xlevel, 15));
        g_level = ob->query_guild_rank();
        write(pad(g_level, 12));
        place = environment(ob)->short();
        write(place);
        write("\n");
    }
  }
  write(HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
  return 1;
}
