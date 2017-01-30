inherit "/players/mizan/closed/poly/rsob.c";
#include "/players/mizan/closed/poly/definitions.h"
#include "/players/mizan/esc.h"


reset(arg)
{
   ::reset(arg);
   
   set_id(DIVYA_DSWORDS_ID);
   set_callouts(6);
   set_callout_freq(4);
}

do_event()
{
   if(attacker && !attacker->query_ghost())
   {
      say(ESC + "[1m" + ESC + "[36m" + "Dancing Sword [" + (callout_current + 1) + " of 6] rockets at full speed at " + attacker->query_name() + "!\n");
      say(attacker->query_name() + " is sliced by a dancing sword!\n");
      say("The dancing sword then disappears, blood droplets falling to the ground.\n" + ESC + "[0m");

      /* The player gets 13 sps per attack, with allowable of random(26) damage.
       * I am a little bit under that limit here */
      attacker->hit_player(random(20));
   }

   /* Make sure this comes LAST */
   ::do_event();
}

