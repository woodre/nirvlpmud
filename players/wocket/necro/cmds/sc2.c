
#include "../defs.h"
#include "../skull.h"
#define BAR  "\t<----------------------------------------------------------->\n"
#define SPACE "       "

cmd(str) {
int g_level, glevel;
string lev;
object ob,me;

ob = GOB;
me = tp;
  if(!GOB) return 0;
  if(str == "-old") return 0;
  write("\n  "); 
  write("\t<"+HIR+"Necromantic Stat Score"+OFF+">------------------------------------>\n");
  write(SPACE+BOLD+BLK+"\t     Str: "+OFF+BOLD+cutstring(me->query_attrib("str"),5)+OFF);
  write(BOLD+BLK+"Sta: "+OFF+BOLD+cutstring(me->query_attrib("sta"),5)+OFF);
  write(BOLD+BLK+"Pie: "+OFF+BOLD+cutstring(me->query_attrib("pie"),5)+OFF);
  write(BOLD+BLK+"Wil: "+OFF+BOLD+cutstring(me->query_attrib("wil"),5)+OFF);
  write(BOLD+BLK+"Cha: "+OFF+BOLD+cutstring(me->query_attrib("cha"),5)+OFF);
  write("\n");
  write(SPACE+BOLD+BLK+"\t     Mag: "+OFF+BOLD+cutstring(me->query_attrib("mag"),5)+OFF);
  write(BOLD+BLK+"Luc: "+OFF+BOLD+cutstring(me->query_attrib("luc"),5)+OFF);
  write(BOLD+BLK+"Int: "+OFF+BOLD+cutstring(me->query_attrib("int"),5)+OFF);
  write(BOLD+BLK+"Ste: "+OFF+BOLD+cutstring(me->query_attrib("ste"),5)+OFF);
  write(BOLD+BLK+"Dex: "+OFF+BOLD+cutstring(me->query_attrib("dex"),5)+OFF);
  write("\n");
  write(BAR+"\n");
  return 1;
}

/*
      spell_points+"/"+max_spell+" I "+
      intoxicated*100/(level+3)+"% F "+stuffed*100/(level*8)+"% "+
      "S "+soaked*100/(level*8)+"% "+
      "T "+infuse*100/(9*level/2)+"% AHP "+
     attacker_ob->query_hp()*10/att_mhp+"/10  >>>>"+

*/
