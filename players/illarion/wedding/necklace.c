#include "/players/illarion/dfns.h"
inherit "players/illarion/obj/clothes";
#define NAME "lyric"

void reset(status arg) {
  if(arg) return;
  
  set_id("necklace");
  set_short("A `WHITE`s`white`i`BLACK`lv`white`e`WHITE`r`off` necklace supporting three perfect `blue`s`BLUE`ap`WHITE`p`BLUE`h`WHITE`i`BLUE`re`blue`s`off`");
  set_long(
"The silver chain of this necklace is so thin it seems almost impossible\n"+
"that it should support the three perfect sapphires the silver wraps\n"+
"around like a spider's web.  Single silver chains run betweem the\n"+
"sapphires, linking them in a glittering triangle that hangs with the point\n"+ "down.\n");
   set_wear_mess("wear_self","You carefully fasten the necklace about your "+
                              "neck.");
   set_wear_mess("wear_room","&NAME& fastens a silver necklace around &POSS& "+
                             "neck.");
   set_wear_mess("remove_self","You unfasten and remove the necklace.");
   set_wear_mess("remove_room","&NAME& unfastens and removes a silver "+
                               "necklace from around &POSS& neck.");   
   set_weight(1);
   set_move_emote("self","You feel a pulse of warmth from the necklace.\n");
}
