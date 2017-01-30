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
int busy, summoned, moving_time;
string location;
query_summoned() { return summoned; }
object gifted;
object Here;
query_location() { return location; }
reset(arg)
{
/*
 * moved if(arg) statement before the call_out spawn
 * so it doesn't constantly call_out on reset(1)
 * added root() check so the master object isn't destructed
 */
 if(arg || root()) return;
  


   set_value(0);


}
id(str)
{
   if(summoned) return str == "sliph";
   else
       return str == "well";
}

short()
{
   if(this_object()->query_summoned())
     {
  return HIW+"The "+NORM+HIK+"Silver "+NORM+HIW+"Sliph"+NORM;
	 }  
   else
     {  
	return HIC+"A Stone Well"+NORM;
	}
}

long()
{
   if(this_object()->query_summoned())
     {
  write( HIW+
      "The silver Sliph appears to be made out of living quicksilver.\n"+
      "She stretches out of her well yet seems connected to it. Long ago\n"+
      "she was a very exclusive prostitute, but the wizards of old had a\n"+
      "far more of a use for her, and so used their magic powers to turn\n"+
	  "her into the Silver Sliph. She never betrays her clients."+NORM+"\n");
	return 1;  
	 }
	 
   else
     {  
	write(HIW+
	"This old well has been worn down by weather and time, making it \n"+
	 "unattractive. Nothing but darkness can be seen in the well's depths\n"+
	 "The stones are worn and a few appear to be missing. There is an engraving\n"+
	 "on the well that says to '"+HIB+"summon Sliph"+HIW+"'."+NORM+"\n");
     return 1;
	}
}

/* we don't want this to be picked up */
get() { return 0; }

init()
{
   Here = environment(this_object());
   ::init();
   
   command("look", this_player());
   add_action("travel_place", "travel");
   add_action("listen_to", "ask");
   add_action("summon_sliph", "summon");  
  
}
summon_sliph(str)
{
if(str == "sliph" || str == "well")
    {
   write("You summon the Sliph.\n");
   say(TPN+" summons the Sliph.\n");
   summoned = 1;
   call_out("self_destruct",50);
 return 1;
   }
}
listen_to(str)
{
if(str == "sliph"){
write("You may ask the sliph about location, history.\n");
return 1;
   }
if(str == "sliph history")
  {
if(!busy)
     {
     call_out("mother_cry01", 2, this_player());
     busy = 1;
	} 
	return 1;
 }
 
 notify_fail("Ask who what?\n");
}
/* Sometimes the best way to do things is the less elegant way. */
/* This is the Sliph's welcome message */
mother_cry01(object who)
{
   /* sanity check */
   if(!who) return 0;
   if(moving_time) return 0;


   

  tell_room(Here, GRN+"The Sliph Whispers"+HIW+": Welcome "+who->query_name()+". I am called the Silver\n"+
                      "Sliph. Ages ago I was created by the Wizards of old as a\n"+
                      "weapon. I could travel great distances within only one day,\n"+
					  "no matter the distance.\n"+NORM+
                      "\n");



   call_out("mother_cry02", 10, who);
}


/* the callouts are chained... */

mother_cry02(object who)
{
   /* sanity check */
   if(!who) return 0;
   if(moving_time) return 0;
   tell_room(Here, HIG+"The Silver Sliph shifts her mass and peers at you, her face\n"+
                       "inches from yours.\n"+NORM+
                    "\n");
   call_out("mother_cry03", 5, who);
}

mother_cry03(object who)
{
   /* sanity check */
   if(!who) return 0;
   if(moving_time) return 0;
   tell_room(Here, GRN+"The Sliph whispers"+HIW+": Centuries later, First Wizard Data\n"+
                       "brought me back and told me that if anyone was in need of\n"+
					   "of traveling help them so that is why I am here.\n"+NORM+
                       "\n");
   call_out("mother_cry04", 8, who);
}

mother_cry04(object who)
{
   /* sanity check */
   if(!who) return 0;
   if(moving_time) return 0;
   tell_room(Here, GRN+"The Sliph whispers"+HIW+": "+who->query_name()+", do you wish to 'travel'?\n"+NORM+
                    "\n");
	
}
/* Traveling, when a person travels the objects short changes
 * so that a new player may summon it anew.                  */
travel_place(str)
{
    object here, holdpen, mover;
	

    if(!str)
 {
    write(HIM+"The Sliph looks up and thinks for a moment before replying:\n"+NORM+HIW+
	      "\"I can travel to the following locations at this time. More\n"+
		  "locations will become available as they come to me, for the\n"+
		  "magic that Data used had side effects on me.\"\n"+NORM+HIB+
		  "\n"+
		  "\n"+
		  "Nirvana\n"+NORM+HIK+
		  "Outer Boundary..........Newbie\n"+NORM+HIM+
		  "\n"+
		  "To travel to one of these locations type: travel 'location'.\n"+NORM);
    return 1;
 }
	
    switch(str)
 {
    case "outer boundary": here="/players/data/OUTERB/ROOMS/entrance.c"; break;
    case "nirvana": here="room/south/sforst3"; break;
    default: write(HIM+"The Sliph says: I don't know that place, please choose another.\n"+NORM);
             return 1;
             break;
 }
  say("You tell the Sliph that you wish to travel to the "+str+".\n");
  say(HIW+TPN+" dives through the Silver Sliph's Froth."+NORM);
  gifted=this_player();
	holdpen = clone_object("/players/data/sliphhold.c");
	holdpen->set_own(TPN);
	move_object(TP,holdpen);
    mover = clone_object("/players/data/sliphbak.c");
	mover->here(here);
	move_object(mover,holdpen);
    summoned = 0;

    write("\n\n");
    write(HIW+"The Silver Sliph Whispers: While traveling in me, you must\n"+
	          "breathe me to live, now lets travel!\n"+NORM);
    write(HIW+"You breathe in the Sliph as you travel. Colors are all\n"+
	          "around you...this is rapture.\n\n\n"+NORM);

    return 1;
}

/*
heart_beat()
{
    if (moving_time <= 0)
        return;
    moving_time -= 1;
    if (moving_time > 0)
 {
	  tell_object(gifted, HIR+"You see bright swirling lights flash by as you travel...\n"+NORM);
      return;
 }

	tell_object(gifted, HIR+"You feel complete rapture as you inhale the essence of the Silver Sliph\n"+NORM);
    set_heart_beat(0);
    say("\n");
    tell_object(gifted, RED+"You are thrust out of the Sliph's well and carefully set down.\n"+
        "The Sliph tells you to breath her out, and breath in the air.\n\n"+NORM);
    tell_object(gifted, RED+"You breath out the Silver Sliph and breath in the alien air.\n"+
        "Sounds and lights explode through you.\n"+NORM);
    tell_room(location, HIR+"The Sliph bursts out of her well.\n"+NORM);
    move_object(gifted,"/players/data/OUTERB/ROOMS/entrance.c");
    tell_room(location, gifted->query_name()+ 
      HIR+" is carefully set onto the ground by the Silver Sliph\n"+NORM);
    move_object(gifted, location);  
    tell_room(location, HIW+"The Sliph smiles then sinks back into "+
      "her well.\n"+NORM);
    remove_call_out("self_destruct");
}*/

self_destruct()
{
  object here;
  here=first_inventory(this_object());
  if(here && here->is_player())
 {
   while(remove_call_out("self_destruct") != -1); 
   call_out("self_destruct", 50);
   return 1;
 }
  here=Here;
  if(here)
  tell_room(here,HIK+"The Sliph yawns and dissapears down her well as her services aren't needed.\n"+NORM);
  summoned = 0;
  return 1;
}