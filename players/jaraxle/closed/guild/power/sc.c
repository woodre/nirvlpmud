#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
main(string str, object gob, object player)
{
   int intox_level;
   int x, y, z;
   string where;
   string tmp;
   int tmpp;
   
   if((string)this_player()->query_real_name() == "guest" ||
         ((x = (int)this_player()->query_level()) > 19) ||
      (x < 1))
   return 0;
   if(x >= 19){ 
      x=(int)this_player()->query_extra_level();
      where = "/room/exlv_guild"; }
   else
      where = "/room/adv_guild";
   z = ((int)where->get_next_exp(x)-(int)this_player()->query_exp());
   write("\n");
   write(USER->short()+"\n");
   write(HIG+"Elemental"+NORM);
   write("\t\t\tGuild Level: "+YEL+GOB->query_glvl()+NORM+"\n");
   write("Level: "+LEVEL);
   if(XLEVEL) write("+"+XLEVEL);
   write("\t\t\tExpierence: "+USER->query_exp()+"\n");
   write("Coins: "+HIY+USER->query_money()+NORM);
   if(z <= 0) write("\t\t\tExp Next:   Go Advance\n");
   else write("\t\t\tExp Next:   "+z+"\n");
   write(HIW+"Hit points: "+HIR+HP+"/"+MHP+NORM+"     ");
   write("\t\t");
   write(HIW+"Spell points: "+HIB+SP+"/"+MSP+NORM+"\n");
   write(HIW+"Skill Points Avalable "+HIR+"["+HIW+GOB->query_skillpts()+HIR+"]"+NORM);
   write(HIW+"\tEcost: "+HIR+"["+HIW+GOB->query_cost_toggle()+HIR+"]"+NORM+"\n");
   
   write("Element Levels:\n");
   write(RED+"   Fire "+HIR+"["+HIW+GOB->query_fire_element()+HIR+"]"+NORM);
   write(BLU+"   Water "+HIB+"["+HIW+GOB->query_water_element()+HIB+"]"+NORM);
   write(CYN+"   Wind "+HIC+"["+HIW+GOB->query_wind_element()+HIC+"]"+NORM);
   write(YEL+"   Earth "+HIY+"["+HIW+GOB->query_earth_element()+HIY+"]\n\n"+NORM);
   write("Strength:       "+USER->query_attrib("str")+"   Stamina:      " +USER->query_attrib("sta") + "   Will Power: "+USER->query_attrib("wil") + "\n");
   write("Magic aptitude: " + USER->query_attrib("mag") + "   Piety:        "+USER->query_attrib("pie")+"   Stealth:    "+USER->query_attrib("ste")+"\n");
   write("Luck:           "+USER->query_attrib("luc")+"   Intelligence: " +USER->query_attrib("int")+"\n\n");
   write("[ "+YEL+"Intox: "+HIY+((USER->query_intoxination()*100)/(LEVEL+3))+NORM+"% ]  " );
   write("[ "+GRN+"Food: "+HIG+((USER->query_stuffed()*100)/(LEVEL*8))+NORM+"% ]  " );
   write("[ "+CYN+"Soak: "+HIC+((USER->query_soaked()*100)/(LEVEL*8))+NORM+"% ]  ");
   write("[ "+MAG+"Infuse: "+HIM+((USER->query_infuse()*100)/(9*LEVEL/2))+NORM+"% ]  ");
   write("\n");
   USER->show_age();
   if(USER->query_fight_area()) write(HIW+"\t\t[ "+HIR+"You are in a "+HIW+"PK"+HIR+" area "+HIW+"]\n"+NORM);
   write("\n");
   return 1;
}
