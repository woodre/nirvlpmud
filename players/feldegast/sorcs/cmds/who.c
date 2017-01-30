#include "/players/wocket/closed/ansi.h"

cmd(str){
  int i,a;
  int count;
  string msg;
  string name;
  object *ppl;
  if(str == "-old") return 0;
  count = 0;
  ppl = users();
  ppl = sort_array(ppl,"greater_fun",this_object());
  write(MAG+"\n        [-----------------------------["+HIR+"*"+NORM+MAG+"]-----------------------------]\n"+OFF);

 switch(str){
 case "-b":
    write(MAG+"       Name           Oppt            Location\n"+OFF);
    break;
 case "-s":
    write(MAG+"       Name         Level  Guild    Gender   Spouse        Race\n"+OFF);
    break;
 case "-t":
    write(MAG+"            Title\n"+OFF);
    break;
 default:
    write(MAG+"       Name         Level  Guild      Location\n"+OFF);
    break;
 }

  for(i=0,a=sizeof(ppl); i<a ;i++){
  msg = "  ";
  if(ppl[i]->query_invis() < this_player()->query_level()){
    
    count++;
    if(in_editor(ppl[i]))
      msg += HIM+"]"+OFF;
      else
      msg += " ";
    if(ppl[i]->query_dead())
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
    if(ppl[i]->query_fight_area())
      msg += HIR+"*"+OFF;
      else
      msg += " ";
    name = cutstring(ppl[i]->query_name(),12);
    if(ppl[i]->query_pl_k())
      name = HIR+name+OFF;
    
 switch(str){
 case "-b": 
    msg += name;
    msg += " ";
    msg += get_oppt(ppl[i]);
    msg += "  ";
    msg += get_enviro(ppl[i]);
    break; 
 case "-s":
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
 case "-t":
    if(ppl[i]->short())
    msg += cutstring(ppl[i]->short(),70)+" "+OFF;
    else
    msg += "  ("+ppl[i]->query_name()+")";
    break; 
 default :
    msg += name;
    msg += " ";
    msg += get_level(ppl[i]);
    msg += " ";
    msg += get_guild(ppl[i]);
    msg += "   "; 
    msg += get_enviro(ppl[i]);
   break;
}
    
   write(msg+"\n");
   }
   }
write(MAG+"       There are currently "+HIR+count+NORM+MAG+" players online\n"+NORM);
write(MAG+"        [-----------------------------["+HIR+"*"+NORM+MAG+"]-----------------------------]\n"+NORM);
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
    return BOLD+"wiz   "+OFF;
  str = obj->query_level();
  if(obj->query_extra_level())
    str += "+"+obj->query_extra_level();
  return cutstring(str,6);
}

get_guild(obj){
 if(!obj->query_guild_name()) return "none  "; 
 switch(obj->query_guild_name()){
  case "healer":           return "healer";
  case "meijin":           return "meijin";
  case "cyberninja":       return "cyber ";
  case "knights templar":  return "knight";
  case "rangers":          return "ranger";
  case "dark rangers":     return "dark_r";
  case "polymorph":        return "poly  ";
  case "vampire":          return "vamp  ";
  case "dervish":          return "derv  ";
  case "necromancer":         return "necro ";
  case "":                 return "none  ";
  default:                 return cutstring(obj->query_guild_name(),6);
  }
}

get_enviro(obj){
  if(environment(obj))
    return cutstring(environment(obj)->short(),40)+" "+OFF;
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
