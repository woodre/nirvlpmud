#include <ansi.h>

int main(string str)
{
  object obj;
  
  if(!str) {
    write("Teleport to which newbie ?\n");
    return 1;
  }
  
  if(!(obj = find_player(str)) || !environment(obj)) {
    write("You don't see \""+str+"\" in Nirvana.\n");
    return 1;
  }
  
  if((int)obj->query_level() >= 8) {
    write(capitalize(str)+" is not a newbie.\n"+
          "Level 7 and under please!\n");
    return 1;
  }
  
  if(environment(obj) == environment(this_player())){
    write(capitalize(str)+" is already here.\n");
    return 1;
  }
  
  write("You teleport to "+capitalize(str)+" the Newbie.\n");
  tell_room(environment(this_player()),
    (string)this_player()->query_name()+" vanishes in a flash!\n",
     ({ this_player() }));
  move_object(this_player(), environment(obj));
  command("look", this_player());
  tell_object(obj,
    "The "+HIB+"newbie helper"+NORM+
    " "+(string)this_player()->query_name()+
    " has teleported to you!\n");
  return 1;
}
