/* Sliph.c
 *
 * 3/20/06 - Data
 *
 * Sliph is a part of castle entrance as well as ways to move around my areas
 *
*/
#include <ansi.h>
#include "/players/data/defs.h"
inherit "obj/treasure";
int busy, moving_time;
object gifted;
object ob;
object location;

 reset(arg)
{   if (arg) return; 
   set_id("mover");
   set_short();
   set_long();
   moving_time = 10; 
   
}
set_location(str) { location = str; }
/* we don't want this to be picked up */
get() { return 0; }

init()
{
   ::init();

 call_out("mother_cry", 3, this_player());  
  
}

mother_cry(object gifted){
    if(moving_time <= 0)
	{
	move_object(TP,location);
	command("look", this_player());
	destruct(this_object());
	return;
	}
	
    moving_time -= 1;
    if (moving_time > 0)
   gifted=this_player();
   if(!present(gifted, environment())){
      return 1;
   }
switch(random(3)){
case 0:
      tell_object(gifted, "Your mother asks: Why wont you stay with me "+gifted->query_name()+"?\n");
break;
case 1:
   tell_object(gifted, "Your mother sighs: "+gifted->query_name()+", I can't stand you not being here.\n");
break;
case 2:
   tell_object(gifted, "Your mother cries: "+gifted->query_name()+", I gave birth to you in the living world and this is how I am repaid?!?\n");
break;
     }

call_out("mother_cry", 3, this_player());  
   }

