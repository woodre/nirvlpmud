#include "/players/mythos/closed/guild/def.h"
dscore() {
write("\n");
write(BLU+
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
write(NORM+ "Name: "+tp->query_pretitle()+" "+capitalize(tpn)+" "+tp->query_title()+"\n");
write("Level: "+tl+"       Xlvl: "+tx+"        hp: "+tp->query_hp()+" / "+tp->query_mhp()+
      "       sp: "+tp->query_sp()+" / "+tp->query_msp()+"\n");
write("Experience: "+txp+"       Coins: "+tp->query_money()+"        Qp: "+
tp->query_quest_point()+"\t\n");
write("Alignment: "+tp->query_al_title()+"\n\n");
write(BLU+"Guild Level: "+tgl+NORM+"\n");
write(RED+"Fae: "+qtf+"          "+NORM);
write("Sta: "+call_other(tp,"query_attrib","sta")+"          ");
write("Mag: "+call_other(tp,"query_attrib","mag")+"\n");
write("Str: "+call_other(tp,"query_attrib","str")+"          ");
write("Luc: "+call_other(tp,"query_attrib","luc")+"          ");
write("Pie: "+call_other(tp,"query_attrib","pie")+"\n");
write("Int: "+call_other(tp,"query_attrib","int")+"          ");
write("Wil: "+call_other(tp,"query_attrib","wil")+"          ");
write("Ste: "+call_other(tp,"query_attrib","ste")+"\n");
write("\nStuffed: "+tp->query_stuffed()+"            Soaked: "+tp->query_soaked()+"\n");
if(tp->query_pregnancy()) { write("Pregnant: "+(tp->query_age() - tp->query_pregnancy())+
                              " / 16200\n");} 
if(tp->query_weapon()) {write("Wielding: "+RED+(tp->query_weapon())->short()+NORM+"\n");}
if(tp->query_crime()) {write("Crime is set.\n"); }
if(dpp) { write(HIR+"MAY USE SPELLS ON PLAYERS!\n"+NORM);}
tp->show_age();

write(BLU+"\n"+
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n"+NORM);
return 1;}
