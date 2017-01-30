#include "/obj/ansi.h"
inherit "/players/mizan/core/heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("wienernut");
  add_alias("weinernut");
  set_short("A wienernut");
  set_long("This is a wienernut. It is a hot dog shaped in the form of a donut.\n"+
           "Hence the logical name of a 'Wienernut'. There is a hole in the \n"+
           "middle that can be used to slop over cheese or really thick ketchup.\n"+
           "Surprisingly the wienernut is still very warm to the touch.\n"+
           "You feel that you can 'eat' the wienernut.\n");

  set_msg("You take a bite into the wienernut and relish its hot-dog goodness.\n");
  set_msg2(" takes a bite into a wienernut! Satisfaction ensues.\n");

  add_cmd("eat");
  set_heal(55,35);
  set_charges(5);
  set_stuff(8);
  set_soak(1);
  set_value(300);

  set_type("bites");              /* Plural description of charges */
  set_type_single("bite");        /* Singular description of 1 charge */

  set_msg_precharges("["+HIW);    /* Sets charge count display as [x] with x as HIB color */
  set_msg_postcharges(NORM+"]");

  set_msg_stuffed(NORM+HIW+"Whoa! Slow down! You're no champion Coney Island Wienernut competitive eater!\nAny more and you would simply BURST like a water balloon!"+NORM);
  set_msg_soaked(NORM+HIW+"Your stomach is too Pacific Ocean [tm] to handle the juicy\ngoodness of a large Wienernut chunk."+NORM);

}

conditions_check(){
  /* The conditions_check() function can be used to check for conditions before applying
     the heal. Returning 0 from this function will cause the heal consumption to abort
     using the pre defined message given by notify_fail. If your heal doesn't have any
     condition check requirements then the function can be left out all together.
  */


  if (this_player()->query_level() < 3)
 
   
    return (notify_fail("Unfortunately, your stomach is not large enough to handle the\nmight of a wienernut just yet!\n"), 0);
  else
 
 
    /* Continue healing if the conditions are satisfied */
    return 1;
}
