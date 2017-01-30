/* duplicates when used later
#include "/players/pestilence/ansi.h"
*/

pwho() {
  int x, grank, level, g_level, xlevel, combat_lvl;
  string title, place;
  object ob, cob, peeps;
  peeps = users();

  write("\n");
  write(HIB+"-*-*-*-*-*-*-*-*-*-*-*-*"+HIW+" "+NORM+YEL+"A R M Y /"+HIK+" O R D E R"+HIR+"  O F  P E S T I L E N C E  "+NORM+HIB+"-*-*-*-*-*-*-*-*-*-*-*-\n"+NORM);
  write(HIG+pad("Name:", 20)+
       pad("Level:", 11)+
       pad("Glvl:", 7)+
        pad("Rank/Combat:", 14)+
        pad("Location:", 30)+NORM+"\n");
write(HIB+"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"+NORM);
  for(x=0;x<sizeof(peeps);x+=1){

    if(!peeps[x]->query_invis() && present("pesty_guild", peeps[x])){ 
        ob = peeps[x];
        write(pad(capitalize(ob->query_real_name()), 20));
        level = ob->query_level();
        xlevel = ob->query_extra_level();
        write(pad(level+"+"+xlevel, 11));
        g_level = ob->query_guild_rank();
        write(pad(g_level, 7));
             combat_lvl = present("pesty_guild",ob)->query_grank();
        write(pad(combat_lvl, 14));
        place = environment(ob)->short();
        write(place);
        write("\n");
    }
  }
write(HIB+"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"+NORM);
  return 1;
}
