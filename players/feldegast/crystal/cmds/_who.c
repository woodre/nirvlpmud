/* 
Based entirely upon the who that Wocket constructed for the sorcerer guild.
Because it is THAT good.
*/

#include "../defs.h"

string cutstring(string str, int i)
{
  str = str + "                                      ";
  str = str[0..i-1];
  return str;
}

int greater_fun(object one, object two)
{
  if(!environment(one)) return 1;
  if(!environment(two)) return 0;

  if((int)one->query_level() == (int)two->query_level())
    return (int)one->query_extra_level() < (int)two->query_extra_level();
  else
    return (int)one->query_level() < (int)two->query_level();
}

string get_race(object obj)
{
  return cutstring((string)obj->query_race(),20);
}

string get_gender(object obj)
{
  return cutstring((string)obj->query_gender(),6);
}

string get_level(object obj)
{
  string str;
  if((int)obj->query_level() > 20)
    return BOLD+"wiz   "+NORM;
  str = (string)obj->query_level();
  if((int)obj->query_extra_level())
    str += "+"+(int)obj->query_extra_level();
  return cutstring(str,6);
}

string get_guild(object obj)
{
  if(!((string)obj->query_guild_name()))
    return "none  "; 
  switch((string)obj->query_guild_name()){
    case "healer":           return "healer";
    case "meijin":           return "meijin";
    case "cyberninja":       return "cyber ";
    case "knights templar":  return "knight";
    case "rangers":          return "ranger";
    case "dark rangers":     return "dark_r";
    case "polymorph":        return "poly  ";
    case "vampire":          return "vamp  ";
    case "dervish":          return "derv  ";
    case "necromancer":      return "necro ";
    case "":                 return "none  ";
    default:                 return cutstring((string)obj->query_guild_name(), 6);
  }
}

string get_enviro(object obj)
{
  if(environment(obj))
    return (string)environment(obj)->short()+NORM;
  else
    return "";
}

string get_oppt(object obj)
{
  if((object)obj->query_attack())
    return cutstring( (string)((object)obj->query_attack())->query_name(),14);
  else
    return "              ";
}

string get_spouse(object obj)
{
  if(present("wedding ring",obj))
    return cutstring((string)present("wedding ring",obj)->query_spouse(),12);
  else
    return "            ";
}

int do_cmd(string str)
{
  int i,a;
  int count;
  string msg;
  string name;
  object *ppl;
  if(str == "-old") return 0;

  /* Only wizzes get to see battles. */
  if((int)this_player()->query_level() < 20 && str == "-b")
    str = 0;

  if((int)this_player()->query_sp() < 10)
  {
    write(NOSP_MSG);
    return 1;
  }

  this_player()->add_spell_point(-10);

  count = 0;

  ppl = users();
  ppl = sort_array(ppl, "greater_fun", this_object());

  write(CYN+"\n        [-----------------------------["+HIC+"*"+NORM+CYN+"]-----------------------------]\n"+NORM);

  switch(str){
   case "-b":
      write(BOLD+"       Name           Oppt            Location\n"+NORM);
      break;
   case "-s":
      write(BOLD+"       Name         Level  Guild    Gender   Spouse        Race\n"+NORM);
      break;
   case "-t":
      write(BOLD+"            Title\n"+NORM);
      break;
   default:
      write(BOLD+"       Name         Level  Guild      Location\n"+NORM);
      break;
  }

  for(i=0, a=sizeof(ppl); i < a; i++)
  {
    msg = "  ";
    if((int)ppl[i]->query_invis() < (int)this_player()->query_level()){
    
      count++;

      if(in_editor(ppl[i]))
        msg += HIM+"]"+NORM;
      else
        msg += " ";

      if((int)ppl[i]->query_dead())
        msg += HIY+"*"+NORM;
      else
        msg += " ";

      if((int)ppl[i]->query_invis())
        msg += HIB+"*"+NORM;
      else
        msg += " ";

      if(environment(ppl[i]) && (string)environment(ppl[i])->realm() == "NT")
        msg += HIB+"X"+NORM;
      else
        msg += " ";

      if((int)ppl[i]->query_fight_area())
        msg += HIR+"*"+NORM;
      else
        msg += " ";

      name = cutstring((string)ppl[i]->query_name(),12);

      if((int)ppl[i]->query_pl_k())
        name = HIR+name+NORM;
    
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
            msg += cutstring((string)ppl[i]->short(),70)+" "+NORM;
          else
            msg += "  ("+(string)ppl[i]->query_name()+")";
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
  write(CYN+"       There are currently "+HIC+count+NORM+CYN+" players online\n"+NORM);
  write(CYN+"        [-----------------------------["+HIC+"*"+NORM+CYN+"]-----------------------------]\n"+NORM);
  return 1;
}
