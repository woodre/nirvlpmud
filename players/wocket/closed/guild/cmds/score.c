#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/closed/guild/defs.h"

cmd(){
object tp;
string msg;
tp = this_player();
msg = MAG+"\t\tScore:\n"+NORM;
msg += tp->short()+"\n";
msg += "Hp: "+tp->query_hp()+"/"+tp->query_mhp()+"\t\t\t\t"+"Level: "+tp->query_level();
if(tp->query_extra_level()){
   msg+= "+"+tp->query_extra_level()+"\n";
}
  else  msg += "\n";
msg += "Sp: "+tp->query_sp()+"/"+tp->query_msp();
msg += "\t\t\t\t";
msg += "Exp: "+tp->query_exp()+"\n";
msg += "Gold: "+tp->query_money();
msg += "\t\t\t\t";
msg += "Qp: "+tp->query_quest_point()+"\n";
if(tp->query_pl_k()) msg += "-"+BOLD+"PK"+NORM+"- ";
if(tp->query_invis()) msg += "-"+BOLD+"INVIS"+NORM+"- ";
if(tp->query_wimpy()) msg += "-"+BOLD+"WIMPY"+NORM+"- ";
if(tp->query_tellblock()) msg += "-"+BOLD+"TELLBLOCK"+NORM+"- ";
if(tp->query_dead()) msg += "-"+BOLD+"DEAD"+NORM+"- ";
if(tp->query_pregnancy()) msg += "-"+BOLD+"PREGGO "+(tp->query_age()-tp->query_pregnancy())+"/16200"+NORM+"- ";
msg += "\n";
msg += "Str: "+tp->query_attrib("str")+"\t\t";
msg += "Sta: "+tp->query_attrib("sta")+"\t\t";
msg += "Mag: "+tp->query_attrib("mag")+"\t\t";
msg += "Int: "+tp->query_attrib("int")+"\n";
msg += "Luc: "+tp->query_attrib("luc")+"\t\t";
msg += "Wil: "+tp->query_attrib("wil")+"\t\t";
msg += "Pie: "+tp->query_attrib("pie")+"\t\t";
msg += "Ste: "+tp->query_attrib("ste")+"\n";

msg += "\n";
msg += get_age()+"\n";
msg += "Time (CST): "+ctime()+"\n";
msg += "Intox: "+tp->query_intoxination()+"%\t\t";
msg += "Stuffed: "+((tp->query_stuffed()*100)/(tp->query_level()*8))+"%\t\t";
msg += "Soaked: "+((tp->query_soaked()*100)/(tp->query_level()*8))+"%\n";
msg += "\n";
write(msg);
return 1;
}

get_age(int i){
string msg;
if(!i){
i = this_player()->query_age();
}
msg = "Age: ";
if(i/43200){
  msg += (i/43200)+" days ";
  i = i-(i/43200)*43200;
}
if(i/1800){
  msg += (i/1800)+" hours ";
  i = i-(i/1800)*1800;
}
if(i/30){
  msg += (i/30)+" minutes ";
  i = i-(i/30)*30;
}
i = i*2;
msg += i+" seconds.";
return msg;
}
