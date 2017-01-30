#include <ansi.h>

int main(string str)
{
  object obj;
  
  if(!str) {
    write("Resurrect which newbie?\n");
    return 1;
  }
  
  if(!(obj = present(str, environment(this_player()))))
  {
    write("You don't see \""+str+"\".\n");
    return 1;
  }
  
  if((int)obj->query_level() >= 8) {
    write(capitalize(str)+" is not a newbie.\n"+
          "Level 7 and under please!\n");
    return 1;
  }
  
  if(!obj->query_ghost())
  {
    write(capitalize(str)+" is not dead.\n");
    return 1;
  }
  
  write("You hold up your hands.\n"+HIG+"Life"+NORM
  +" swirls around "+(string)obj->query_name()+".\n");
  say((string)this_player()->query_name()+" holds up "+
  possessive(this_player())+" hands.\n"+HIG+"Life"+NORM
  +" swirls around "+(string)obj->query_name()+".\n",obj);
  tell_object(obj, (string)this_player()->query_name()+
  " holds up "+possessive(this_player())+" hands.\n"+
  HIG+"Life"+NORM+" swirls around you.\n");
  
  obj->remove_ghost();
  return 1;
}
