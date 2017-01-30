#include <ansi.h>

int main(string str)
{
  object *inv, att; int s, noob;
  if(str) return 0;
  
  inv = all_inventory(environment(this_player()));
  
  s = sizeof(inv);
  while(s-- && !noob) {
    if(inv[s] && inv[s]->is_player() && 
       (int)inv[s]->query_level() < 8)
    {
      noob = 1;
    }
  }
  
  if(!noob)
  {
    write("There aren't any newbies here.\n");
    return 1;
  }
  
  write("You hold up your hands and "+HIC+"PEACE"+NORM
   +" sweeps over the room.\n");
  tell_room(environment(this_player()),
    (string)this_player()->query_name()+" holds up "+
    possessive(this_player())+" hands and "+HIC+"PEACE"+NORM
   +" sweeps over the room.\n");
   
  inv = all_inventory(environment(this_player()));
  
  s = sizeof(inv);
  
  while(s--)
  {
    if(att = (object)inv[s]->query_attack())
    {
      inv[s]->stop_fight();
      att->stop_fight();
    }
  }
  
  return 1;
}
