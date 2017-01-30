#include "/players/wocket/closed/ansi.h"

cmd(str){
object me;
if(str == "-old") return 0;
me = this_player();
  if(me->query_dead()){
    write("You have not stats as a spirit.\n");
    return 1;
  }
write(MAG+"\n        [-----------------------------["+HIR+"*"+NORM+MAG+"]-----------------------------]\n"+NORM);
write("       Name: "+me->short()+"\n");
write("       Level: "+me->query_level());
if(this_player()->query_extra_level())
write("+"+me->query_extra_level());write("\n");
write("       Coins: "+cutstring(me->query_money(),35)+"Exp: "+me->query_exp()+"\n");
write("       Hit points: "+cutstring(me->query_hp()+"/"+me->query_mhp(),30)+"Spell points: "+me->query_sp()+"/"+me->query_msp()+"\n");
write("       Guild: "+cutstring(me->query_guild_name(),35)+"Race: "+me->query_race()+"\n");
write("       Player Killer: ");
if(this_player()->query_pl_k())
write(HIR+"YES"+NORM);
else
write(HIR+NORM+"no ");
write("                        Criminal: ");
if(this_player()->query_crime())
write(HIR+"YES"+NORM);
else
write(HIR+NORM+"no ");
write("\n");
write(MAG+"\n              Str: "+NORM+cutstring(me->query_attrib("str"),8));
write(MAG+"Sta: "+NORM+cutstring(me->query_attrib("sta"),8));
write(MAG+"Pie: "+NORM+cutstring(me->query_attrib("pie"),8));
write(MAG+"Wil: "+NORM+me->query_attrib("wil"));
write("\n");
write(MAG+"              Mag: "+NORM+cutstring(me->query_attrib("mag"),8));
write(MAG+"Luc: "+NORM+cutstring(me->query_attrib("luc"),8));
write(MAG+"Int: "+NORM+cutstring(me->query_attrib("int"),8));
write(MAG+"Ste: "+NORM+me->query_attrib("ste"));
write("\n\n");
if(me->query_pregnancy())
write("       Pregnancy: "+HIR+(me->query_age() - me->query_pregnancy())+"/16200\n"+NORM);
write("       Quest points: "+NORM+me->query_quest_point()+"\n");
write(display_age());
write(MAG+"\n        [-----------------------------["+HIR+"*"+NORM+MAG+"]-----------------------------]\n"+NORM);
return 1;
}

cutstring(str,i){
str = str + "                                   ";
str = str[0..i-1];
return str;
}

display_age() {
string msg;
  int i;
  msg = "       Age: ";
  i=this_player()->query_age();
  if(i/43200) {
  msg+=i/43200 + " days ";
    i=i - (i/43200) * 43200;
  }
  if(i/1800) {
  msg+=i/1800 + " hours ";
    i=i - (i/1800) * 1800;
  }
  if(i/30) {
  msg+=i/30 + " minutes ";
    i=i - (i/30) * 30;
  }
  msg+=i*2 + " seconds.";
  return msg;
}

