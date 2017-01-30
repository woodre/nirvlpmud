inherit "/players/mizan/closed/poly/rsob.c";
#include "/players/mizan/closed/poly/definitions.h"
#include "/players/mizan/esc.h"


reset(arg)
{
   ::reset(arg);
   
   set_id(PHB_MICR_ID);
   set_callouts(8);
   set_callout_freq(4);
}

do_event()
{
   if(attacker && !attacker->query_ghost())
   {
      say(ESC + "[41m" + "Micromanagement Noose [" + (callout_current + 1) + " of 8] reaches out and crushes the will and patience of " + attacker->query_name() + "!\n" + ESC + "[0m");
      say(attacker->query_name() + " is burdened with a " + ESC + "[41m" + "Micromanagement Noose" + ESC + "[0m" + "!\n");
      say("The noose then disappears, flickering out as if it were vaporware.\n" + ESC + "[0m");

      /* The player gets 13 sps per attack, with allowable of random(26) damage.
       * I am a little bit under that limit here */
      attacker->hit_player(random(20), "other|mental");
   }

   /* Make sure this comes LAST */
   ::do_event();
}

