#include <ansi.h>
#include "/players/data/defs.h"
inherit "obj/treasure";

int moving_time;
object gifted;

reset(arg){
  call_out("self_destruct",50);

   if(arg) return;
   set_id("slyph");
   set_alias("well");
   set_value(0);

   set_short(HIC+"A Stone Well <"+HIB+"Slyph"+HIC+">"+NORM);
   set_long(
      "This old well has been worn down by weather and time, making \n"+
      "it unattractive. As you look down deep in the dephs, you see\n"+
      "nothing but darkness. Maybe if you 'throw rock well'\n"+
      "you can listen for anything that might be living \n");

}


/* we don't want this to be picked up */
get() { return 0; }

init()
{
   ::init();

   add_action("travel_list", "travel");
   add_action("travel_place", "travel");
   call_out("mother_cry01", 3, this_player());
}

/* Sometimes the best way to do things is the less elegant way. */
mother_cry01(object who)
{
   /* sanity check */
   if(!who) return 0;

   tell_object(who, GRN+"The Slyph Whispers"+HIW+": Welcome "+who->query_name()+", I am called the Silver Slyph. Ages ago I was\n"+
                    "created by the Wizards of old as a weapon. I could travel great distances within\n"+
                    "only one day, no matter the distance.\n"+NORM+
                    "\n");
   call_out("mother_cry02", 10, who);
}

/* the callouts are chained... */
mother_cry02(object who)
{
   /* sanity check */
   if(!who) return 0;
   tell_object(who, HIG+"The Silver Slyph shifts her mass and peers at you, her face inches from yours.\n"+NORM+
                    "\n");
   call_out("mother_cry03", 5, who);
}

mother_cry03(object who)
{
   /* sanity check */
   if(!who) return 0;
   tell_object(who, GRN+"The Slyph whispers"+HIW+": Centuries later, First Wizard Data brought me back, and told\n"+
                    "me that if anyone was in need of traveling to help them so that is why I am here.\n"+NORM+
                    "\n");
   call_out("mother_cry04", 8, who);
}

mother_cry04(object who)
{
   /* sanity check */
   if(!who) return 0;
   tell_object(who, GRN+"The Slyph whispers"+HIW+": "+who->query_name()+", do you wish to 'travel'?\n"+NORM+
                    "\n");
}

travel_place(str) {
    object here;
    if (str && !id(str)) return 0;

    gifted=this_player();
    here=environment(this_object());
    move_object(gifted,this_object());
       tell_room(here,this_player()->query_name()+" is pulled inside the well by the Silver Slyph"+
             "and vanishes into it.\n");
    tell_room(here,"There is Silence.\n");
    move_object(clone_object("/players/data/well.c"), environment());
    move_object(this_object(),"/players/data/OUTERB/ROOMS/entrance.c");
    write("\n\n");
    write("The Silver Slyph Whispers: While traveling in me, you must breath me to live, now lets travel!\n");
    write("You breath in the Slyph as you travel, colors are all around you...this is rapture.\n\n\n");
    moving_time = 5;
    set_heart_beat(1);
    
    return 1;
}


heart_beat() {
    if (moving_time <= 0)
        return;
    moving_time -= 1;
    if (moving_time > 0) {
      say("You see bright swirling lights flash by as you travel...\n\n");
      return;
    }
    say("You feel complete rapture as you inhale the essense of the Silver Slyph\n");
    set_heart_beat(0);
    say("\n");
    say("You are thrust out of the Slyph's well, and carefully set down, the slyph\n"+
        "tells you to breath her out, and breath in the air.\n\n");
    say("You breath out the Silver Slyph, and breath in the alien air, sounds and\n"+
        "lights explode through you.\n");
    tell_room("/players/data/OUTERB/ROOMS/entrance.c", "The Slyph bursts out of her well.\n");
    move_object(this_object(),"/players/data/OUTERB/ROOMS/entrance.c");
    tell_room("/players/data/OUTERB/ROOMS/entrance.c", gifted->query_name()+ 
      " is carefully set onto the ground by the Silver Slyph\n");
    move_object(gifted,"/players/data/OUTERB/ROOMS/entrance.c");  
    tell_room("/players/data/OUTERB/ROOMS/entrance.c", "The Slyph smiles then sinks back into "+
      "her well.\n");
    destruct(this_object());
}

self_destruct() {
  object here;
  here=first_inventory(this_object());
  if(here && here->is_player()) {
   call_out("self_destruct", 2);
   return 1;
  }
  here=environment(this_object());
  if(here)
  tell_room(here,"The Slyph yawns and dissapears down her well...obviously she was bored.\n");
  move_object(clone_object("/players/data/well.c"), environment());
  destruct(this_object());
  return 1;
}

