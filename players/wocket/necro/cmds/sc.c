/* Version 1.0 of the Necromancer Score Listing */
#include "../defs.h"
#include "../skull.h"
#define BAR  "\t<----------------------------------------------------------->\n"
cmd(str) {
int g_level, glevel;
string lev;
object ob,me;

ob = GOB;
me = tp;
  if(!GOB) return 0;
  if(str == "-old") return 0;
  write("\n  "); 

  write("\t<"+HIR+"Necromantic Quick Score"+OFF+">----------------------------------->\n");
  if(this_player()->query_pl_k())
      write("          ("+HIR+"PK"+OFF+") ");
  else write("          ");
  write(cutstring(tpn+" "+tp->query_title(),55)+" "+OFF+"\n");
  write(BOLD+BLK+"          guild rank: "+OFF+tp->query_guild_rank()+OFF+"\n");
   
  lev = BOLD+BLK+"level: "+OFF+tp->query_level();
    if(tp->query_extra_level()) lev += "+"+tp->query_extra_level(); 
  write("          "+cutstring(lev,30));
  
  write(BOLD+BLK+"coins: "+cutstring(OFF+tp->query_money(),16)+OFF);
  write(BOLD+BLK+"qpt: "+OFF);
    if(tp->query_quest_point())
      write(cutstring(tp->query_quest_point(),10)+OFF+"  ");
    else
      write(cutstring("-- ",12));
  write("\n          ");
  write(BOLD+BLK+"hp: "+OFF+BOLD+cutstring(tp->query_hp()+OFF+"/"+tp->query_mhp(),15)+"  ");
  write(BOLD+BLK+"sp: "+OFF+BOLD+cutstring(tp->query_sp()+OFF+"/"+tp->query_msp(),15)+"  "); 
  write(BOLD+BLK+"  exp: "+OFF+cutstring(tp->query_exp(),11)+OFF+"\n");
  write("          ");
  if(tp->query_fight_area())
      write("("+HIR+"pk area"+OFF+") ");
  if(this_player()->query_crime())
      write("("+HIR+"criminal"+OFF+") ");
  if(this_player()->query_invis())
      write("("+HIR+"invis"+OFF+") ");
  if(this_player()->query_wimpy())
      write("("+HIR+"wimpy"+OFF+") ");
  write("\n          ");
write("["+BOLD+BLK+"Intox: "+OFF+BOLD+((tp->query_intoxination()*100)/(tp->query_max_intox()))+OFF+"%]  " );
write("["+BOLD+BLK+"Food: "+OFF+BOLD+((tp->query_stuffed()*100)/(tp->query_max_stuff()))+OFF+"%]  " );
write("["+BOLD+BLK+"Soak: "+OFF+BOLD+((tp->query_soaked()*100)/(tp->query_max_soak()))+OFF+"%]  " );
write("["+BOLD+BLK+"Infuse: "+OFF+BOLD+((tp->query_infuse()*100)/(9*tp->query_level()/2))+OFF+"%]  ");
write("\n"+BAR+"\n");
return 1;
}

/*
      spell_points+"/"+max_spell+" I "+
      intoxicated*100/(level+3)+"% F "+stuffed*100/(level*8)+"% "+
      "S "+soaked*100/(level*8)+"% "+
      "T "+infuse*100/(9*level/2)+"% AHP "+
     attacker_ob->query_hp()*10/att_mhp+"/10  >>>>"+

*/
