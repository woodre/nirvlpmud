#include "../defs.h"

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
write("You ask the Realm of Death for knowledge which they gladly give you for a price.\n\n");
write("\t<"+HIR+"Necromantic Mud Who"+OFF+">-------------------------------------->\n\n"+OFF);
write(BOLD+BLK+"       Name         Area            Location\n"+OFF);
for(i=0,a=sizeof(ppl);i<a;i++){
if(!ppl[i]->query_invis() || ppl[i]->query_level() < this_player()->query_level() || this_player()->query_level() > 21){
  msg = " ";
  if( (tp->query_level() > 20) && in_editor(ppl[i]))
    msg += HIM+"]"+OFF;
  else
    msg += " ";
  if(ppl[i]->query_ghost())
  msg += HIY+"*"+OFF;
  else
  msg += " ";
  if(ppl[i]->query_invis())
  msg += HIB+"*"+OFF;
  else
  msg += " ";
  if(environment(ppl[i]) && environment(ppl[i])->realm() == "NT")
    msg += HIB+"X"+OFF;
  else
    msg += " ";
  if(query_idle(ppl[i]) > 300)
    msg += BOLD+"i"+OFF;
  else
    msg += " ";
  if(ppl[i]->query_fight_area())
  msg += HIR+"*"+OFF;
  else
  msg += " ";
  name = cutstring(capitalize(ppl[i]->query_real_name()),12);
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
write(BOLD+BLK+"\n         There are currently "+HIR+count+OFF+BOLD+BLK+" players online\n"+OFF);
write("\t<---------------------------------------------------------->\n\n"+NORM);
if(tp->query_sp() > 5)
tp->add_spell_point(-5);
return 1;
}



cutstring(string str,int i){
str = str + "                                       ";
str = str[0..i-1];
return str;
}

greater_fun(one,two){
  if(!environment(one)) return 1;
  if(!environment(two)) return 0;
  if(one->query_level() == two->query_level())
  return one->query_extra_level() < two->query_extra_level();
  return one->query_level() < two->query_level();
}

