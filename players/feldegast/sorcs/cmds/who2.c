#include "/players/wocket/closed/ansi.h"

cmd(string str){
object *ppl;
int i,a;
int count;
string msg;
string name;
if(str == "-old") return 0;
ppl = users();
ppl = sort_array(ppl,"greater_fun",this_object());
count = 0;
write(CYN+"\n        [-----------------------------["+HIR+"*"+OFF+CYN+"]-----------------------------]\n"+OFF);
write(MAG+"       Name         Area            Location\n"+OFF);
for(i=0,a=sizeof(ppl);i<a;i++){
if(ppl[i]->query_invis() < this_player()->query_level()){
  msg = "    ";
  if(ppl[i]->query_dead())
  msg += HIY+"*"+OFF;
  else
  msg += " ";
  if(ppl[i]->query_invis())
  msg += HIB+"*"+OFF;
  else
  msg += " ";
  if(ppl[i]->query_fight_area())
  msg += HIR+"*"+OFF;
  else
  msg += " ";
  name = cutstring(ppl[i]->query_name(),12);
  if(ppl[i]->query_pl_k())
  msg += HIR+name+OFF;
  else
  msg += name;
  msg += " ";
  if(environment(ppl[i])){
  if(creator(environment(ppl[i])))
  msg += cutstring(creator(environment(ppl[i])),12);
  else
  msg += "            ";
  msg += " ";
  msg += cutstring(environment(ppl[i])->short(),40)+" "+OFF;
  }
  count++;
  write(msg+"\n");
  
}
}
write(MAG+"       There are currently "+HIR+count+OFF+MAG+" players online\n");
write(CYN+"        [-----------------------------["+HIR+"*"+OFF+CYN+"]-----------------------------]\n"+OFF); 
return 1;
}



cutstring(string str,int i){
str = str + "                                       ";
str = str[0..i-1];
return str;
}

greater_fun(object one,object two){
if(one && two){
if(one->query_level() == two->query_level()) 
  if(one->query_extra_level() && two->query_extra_level())
  return one->query_extra_level() < two->query_extra_level();
else
  return one->query_level() < two->query_level();
}
}
