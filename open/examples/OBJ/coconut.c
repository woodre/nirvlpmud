#include "ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("coconut");
  add_alias("example heal");
  set_short("A big juicy coconut");
  set_long("This is a coconut. Its purpose is to act as an example heal. \n"+
           "You feel that you can 'eat' the coconut.\n");

  set_msg("You bite into the coconut and drink from the juices.\n");
  set_msg2(" chomps heartily into a coconut.\n");

  add_cmd("eat");
  set_heal(50,35);
  set_charges(3);
  set_stuff(7);
  set_soak(4);
  set_value(0);

/* Cobain's Extensions */
  set_type("bites");              /* Plural description of charges */
  set_type_single("bite");        /* Singular description of 1 charge */

  set_msg_precharges("["+HIB);    /* Sets charge count display as [x] with x as HIB color */
  set_msg_postcharges(NORM+"]");

  set_msg_stuffed(NORM+HIW+"Your stomach is too full to eat any more coconut."+NORM);
  set_msg_soaked(NORM+HIW+"Liquid sloshes within your stomach as you reconsider drinking anything else."+NORM);

}

conditions_check(){
  /* The conditions_check() function can be used to check for conditions before applying
     the heal. Returning 0 from this function will cause the heal consumption to abort
     using the pre defined message given by notify_fail. If your heal doesn't have any
     condition check requirements then the function can be left out all together.
  */

  if (this_player()->query_level() < 21)
    /*If this player is not a wiz then the heal will not work for them */
    return (notify_fail("Only Wizes can use this heal!\n"), 0);
  else
    /* Continue healing if the player is a wiz */
    return 1;
}
