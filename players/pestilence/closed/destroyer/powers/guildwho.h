#include "/players/pestilence/ansi.h"

cmd_guildwho() {
  int x, level, g_level, xlevel, combat_lvl;
  string title, place;
  object ob, cob, peeps;
  peeps = users();

  write("\n");
  write(YEL+"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"+HIW+" "+NORM+YEL+"A R M Y  O F  P E S T I L E N C E"+HIW+" "+NORM+YEL+"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"+NORM);
  write(HIG+pad("Name:", 16)+
       pad("Class:", 15)+
       pad("Glvl:", 7)+
        pad("Rank:", 14)+
        pad("Location:", 30)+NORM+"\n");
write(YEL+"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"+NORM);
  for(x=0;x<sizeof(peeps);x+=1){
/*
    if(!peeps[x]->query_invis() && present("dknight_ob", peeps[x])){ 
*/
    if(present("destroyer_ob", peeps[x])){ 
        ob = peeps[x];
        write(pad(capitalize(ob->query_real_name()), 16));
             level = present("destroyer_ob",ob)->query_pclass();
        xlevel = ob->query_extra_level();
        write(pad(level, 15));
        g_level = ob->query_guild_rank();
        write(pad(g_level, 7));
             combat_lvl = present("destroyer_ob",ob)->query_grank();
        write(pad(combat_lvl, 14));
        place = environment(ob)->short();
        write(place);
        write("\n");
    }
  }
write(YEL+"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"+NORM);
  return 1;
}
