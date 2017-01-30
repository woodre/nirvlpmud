#include "../def.h"

cmd_kneel(str)
{
  object obj;
  
  if(TP->query_guild_rank() < 1) return 0;

  if(!str)
  {
    write("Kneel before what?\n");
    return 1;
  }
  
  if(TP->query_ghost()) return 0;
  if(!TP->query_weapon())
  {
    write("You must be wielding a weapon.\n");
    return 1;
  }
  
  if(!(obj = present(str, ENV(TP))))
  {
    write("You don't see \""+str+"\" here.\n");
    return 1;
  }
  
  if(!obj->is_corpse())
  {
    write("You can't kneel before anything but a corpse.\n");
    return 1;
  }
  
  write("\
You kneel before "+obj->short()+"\nand delicately plunge your "+
TP->query_weapon()->QN+"\n"+
"into its body, draining the remaining "+CYN+"life essence"+NORM+"\n"+
"into your own reserves. The ancients smile upon you.\n");

  say(TP->QN+" kneels before "+obj->short()+"\nand delicately plunges "+
  possessive(TP)+" "+TP->query_weapon()->QN+" into its body.\n"+
TP->QN+" pulses with "+CYN+"life essence"+NORM+".\n");

  TP->heal_self(obj->heal_value());

  destruct(obj);
  return 1;
}
