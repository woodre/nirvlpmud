/*Used in part from the necro guild, Thanx */
#include <security.h>
#include "/players/vertebraker/closed/shardak/std.h"
#include "/players/pestilence/ansi.h"
inherit CMD;

main (string str)
{
  int i,a;
  int count,cost;
  string msg;
  string name;
  object *ppl;
  if(str == "-old") return 0;
  count = 0;
  ppl = users();
  ppl = sort_array(ppl,"greater_fun",this_object());
  write(HIR+"You pay a small price to the gods of darkness for this information.\n\n"+NORM);
  write("\t"+HIK+"<"+HIR+"DARK ORDER GAME WHO"+HIK+">-------------------------------------->\n\n"+NORM);

 switch(str){
 case "-b":
    write(HIK+"       Name           Oppt            Location\n"+NORM);
    cost = 10;
    break;
  default:
    write(HIK+"       Name         Level  Guild    Gender   Spouse        Race\n"+NORM);
    cost = 10;
    break;
 }

  for(i=0,a=sizeof(ppl); i<a ;i++){
  msg = " ";
  if(ppl[i]->query_level() < this_player()->query_level() || this_player()->query_level() > 21){
    
    count++;
    if((this_player()->query_level() > 20)  && in_editor(ppl[i]))
      msg += HIM+"]"+NORM;
      else
      msg += " ";
    if(ppl[i]->query_ghost())
      msg += HIW+"*"+NORM;
      else
      msg += " ";
    if(ppl[i]->query_invis())
      msg += HIM+"*"+NORM;
      else
      msg += " ";
    if(environment(ppl[i]) && environment(ppl[i])->realm() == "NT")
      msg += HIC+"X"+NORM;
      else
      msg += " ";
    if(query_idle(ppl[i]) > 300)
      msg += HIY+"i"+NORM;
      else
      msg += " ";
    if(ppl[i]->query_fight_area())
      msg += HIR+"*"+NORM;
      else
      msg += " ";
    name = cutstring(capitalize(ppl[i]->query_real_name()),12);
    if(ppl[i]->query_pl_k())
      name = RED+name+NORM;
    
 switch(str){
 case "-b": 
    msg += name;
    msg += " ";
    msg += get_oppt(ppl[i]);
    msg += "  ";
    msg += get_enviro(ppl[i]);
    break; 
default  :
    msg += name;
    msg += " ";
    msg += get_level(ppl[i]);
    msg += " ";
    msg += get_guild(ppl[i]);
    msg += "   ";
    msg += get_gender(ppl[i]);
    msg += "   ";
    msg += get_spouse(ppl[i]);
    msg += "  ";
    msg += get_race(ppl[i]);
    break;
}
    
   write(msg+"\n");
   }
   }
write(WHT+"\n         There are currently "+BLINK+count+NORM+WHT+" players online\n"+NORM);
write(WHT+"\n"+HIY+" i"+NORM+" = idle, "+HIC+"X"+NORM+" = no teleport, "+HIM+"*"+NORM+" = invis, "+HIW+"*"+NORM+" = ghost, "+HIM+"]"+NORM+" = editting, "+HIR+"*"+NORM+" = pk room\n"+NORM);
write("\t"+HIK+"<---------------------------------------------------------->\n\n"+NORM);
if(this_player()->query_sp() > cost)
this_player()->add_spell_point(-cost);
return 1;
}



get_race(obj){
 return cutstring(obj->query_race(),20);
}

get_gender(obj){
 return cutstring(obj->query_gender(),6);
}

get_level(obj){
  string str;
  if(obj->query_level() > 20)
    return CYN+"wizard"+NORM;
  str = obj->query_level();
  if(obj->query_extra_level())
    str += "+"+obj->query_extra_level();
  return cutstring(str,6);
}

get_guild(obj){
 if(!obj->query_guild_name()) return "none  "; 
 switch(obj->query_guild_name()){
  case "healer":           return "healer";
  case "cyberninja":       return "cyber ";
  case "knights templar":  return "knight";
  case "rangers":          return "ranger";
  case "Dark Order":       return "Order ";
  case "polymorph":        return "poly  ";
  case "vampire":          return "vamp  ";
  case "dervish":          return "derv  ";
  case "necromancer":      return "necro ";
  case "symbiotes":        return "symb  ";
  case "fallen":           return "fallen";
  case "Black circle":     return "bcmage";
  case "":                 return "none  ";
  default:                 return cutstring(obj->query_guild_name(),6);
  }
}

get_enviro(obj){
  if(environment(obj))
    return cutstring(environment(obj)->short(),40)+" "+NORM;
  return "";
}

get_oppt(obj){
  if(obj->query_attack())
    return cutstring(obj->query_attack()->query_name(),14);
  return "              ";
}

get_spouse(obj){
  if(present("wedding ring",obj))
    return cutstring(present("wedding ring",obj)->query_spouse(),12);
  return "            ";
}

cutstring(string str,int i){
  str = str+"                                      ";
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
