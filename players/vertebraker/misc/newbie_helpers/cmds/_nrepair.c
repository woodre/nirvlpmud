#include <ansi.h>

int main(string str)
{
  object obj;
  object wep;
  
  if(!str) {
    write("Repair which newbie's weapon?\n");
    return 1;
  }
  
  if(!(obj = present(str, environment(this_player())))) {
    write("You don't see \""+str+"\" here.\n");
    return 1;
  }
  
  if((int)obj->query_level() >= 8) {
    write(capitalize(str)+" is not a newbie.\n"+
          "Level 7 and under please!\n");
    return 1;
  }
  
  if(!(wep = (object)obj->query_weapon()))
  {
    write(capitalize(str)+" is not wielding a weapon.\n");
    return 1;
  }
  
  if(!wep->query_broke())
  {
    write(capitalize(str)+"'s weapon is not broken.\n");
    return 1;
  }
  
  command("unwield "+(string)wep->query_name(), obj);
  wep->fix_weapon();
  
  write("You have repaired "+(string)obj->query_name()
   +"'s "+(string)wep->query_short()+".\n");
  
  tell_room(environment(obj),
    HIB+"Newbie Helper"+NORM+" "+
    (string)this_player()->query_name()+" has repaired "+
    (string)obj->query_name()+"'s "+(string)wep->query_short()+".\n",
  ({ obj, this_player() }));
  
  tell_object(obj,
    HIB+"Newbie Helper"+NORM+" "+
    (string)this_player()->query_name()+" has repaired your "+
    (string)wep->query_short()+".\n");
  
  command("wield "+(string)wep->query_name(), obj);
  return 1;
}
