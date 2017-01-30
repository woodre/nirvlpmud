/*this is the file for fangs that will slow down the wielder's enemy from fleeing
  while at the same time poisoning them, should be difficult for the special
  to go off that will place this item on their enemy*/



#include "/players/data/defs.h"
#include "/players/data/ansi.h"

inherit "/obj/treasure.c";
reset(arg) {
  if(arg) return;
  set_id("wounds");
  set_long(BLK+"The puncture wounds glow "+HIM+"violet"+BLK+" with venom, making it difficult to move."+NORM+"\n");
  set_weight(0);
  set_value(0);

}
extra_look(){
if(environment() == this_player())
write(HIM+"You have twin puncture wounds in your thigh."+NORM+"\n");
			
		else
			write(HIM+environment()->query_cap_name() +" has twin puncture wounds in their thigh."+NORM+"\n");
		

}
 init() {
 
      	call_out("poison_me", 5);
	    call_out("destruct_me", 100);
      add_action("no_flee", "west");
       add_action("no_flee", "east");
       add_action("no_flee", "north");
       add_action("no_flee", "south");
       add_action("no_flee", "northwest");
       add_action("no_flee", "northeast");
       add_action("no_flee", "southwest");
       add_action("no_flee", "southeast");
       add_action("no_flee", "up");
       add_action("no_flee", "down");
       add_action("no_flee", "enter"); 
       add_action("no_flee", "goportal");      
      add_action("no_flee", "pass");      
      add_action("no_flee", "travel");      
      add_action("no_flee", "step");      
      add_action("no_flee", "church");      
      add_action("no_flee", "teleport");      
      add_action("no_flee", "back");      
      add_action("no_flee", "out");      
      add_action("no_flee", "exit");      
      add_action("no_flee", "leave");      
      add_action("no_flee", "around");
       add_action("no_flee", "rat");
      
      

}


poison_me()
{
environment(this_object())->reduce_hit_point(random(5)+10);
write(HIM+"You feel your veins burn with venom from the Fangs."+NORM+"\n");
say(HIM+this_player()->query_cap_name()+" stumbles as the venom burns through their veins."+NORM+"\n");
remove_call_out("poison_me");
call_out("poison_me", 5);
return 1;
}


no_flee()

{
int w;

  w=random(1);
 if(!w) {

              write(HIR+"The venom slows your retreat!"+NORM+"\n");
              return 1;
          


    }
  }

destruct_me()
{
  write(HIR+"The venom wears off."+NORM+"\n");
  remove_call_out("poison_me");
  destruct(this_object());
  return 1;
}

