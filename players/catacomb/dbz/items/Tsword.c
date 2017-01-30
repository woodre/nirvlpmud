inherit "/obj/weapon.c";
#include <ansi.h>
#define tpn this_player()->query_name()

reset (arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("sword");
  set_short("An adamantium sword");
  set_long(
 "  A razor sharp weapon wielded by Trunks.  Its blade\n"+
 "is almost three feet long.  The sword's hilt is a midnight\n"+
 "black with a perfect grip.  The sword helped destroy the once\n"+
 "thought invulnerable androids.\n" );
  set_type("sword");
  set_class(17);
  set_weight(2);
  set_value(3000);
  set_hit_func(this_object());
}
  mixed
  weapon_hit(object attacker)
  {
   string name;
   int x;
   x = random(40);
   if(environment() && environment()->is_player())
   {
    name=(string)environment()->query_name(); 
   }
   if(!name)
   {
    return 0;
   }
   if(x > 34)
   {
     write("\nYou bring the sword down carving flesh and bone from "+attacker->query_name()+".\n");
     write(BOLD+RED+"           BLOOD\n\n"+NORM);
     write(BOLD+"    SPEWS"+NORM+" from their wounds.\n\n");
     say(name+" slices "+HIY+attacker->query_name()+NORM+"'s arm with all of "+name+"'s might.\n");
     return 5; 
   } 
  }

  
