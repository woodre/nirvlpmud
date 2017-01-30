	/* Vibro whip of the Beastkeeper */

inherit "obj/weapon";
#include "/players/wren/ansi.h"

reset(arg)  {
    ::reset();
    if(arg) return;

set_id("weapon");
set_name("whip");
set_alias("vibro-whip");
set_short("coiled Vibro-whip");
set_long("This is a strange merging of technology and an old fashioned  \n"+
         "control device. The vibro-whip is made of monofiliment wires  \n"+
         "and silicon compiled in such a way as to create a simpathetic \n"+
         "frequency that gives the whip the capability to damage even   \n"+
         "high density materials, n important feature when trying to   \n"+
         "control creature with extremely dense hides.  \n");

set_type("whip");   /*sword,knife,club,axe,bow,polearm */
set_class(18);
set_weight(2);
set_value(1000);
set_hit_func(this_object());

}

weapon_hit(attacker) {
int W;
W = random(40);

if(W>8 && W<12)  {
    say(""+this_player()->query_name()+" snaps the whip rapidly across foes torso. \n");
    write("You snap the whip sharply several times to your foes torso. \n");
    return 7;
          }
if(W>=2 && W<=8)  {
    say("The vibro-whip flicks across its target faster than the eye can follow. \n");
    write("You flick the whip scoring only a minor nick on your opponent. \n");
    return 4;
          }
if(W<2)  {
  say("Energy surges across the whip, slicing foe ...               \n");
  say("                                                             \n");
  say("       SSSSS      NN      NN     AAA         PPPPPP       !! \n");
  say("     SSS   SS    NN NN   NN     AA AA       PP   PPP     !!  \n");
  say("     SSS        NN NN  NN     AA  AA      PP    PP     !!    \n");
  say("      SSS      NN  NN NN    AAAAAAA     PPPPPPP      !!     \n");
  say(" SS  SSSS    NN   NNN     AA   AA     PP                     \n");
  say("  SSSSS     NN    NN     AA   AA     PP           !!         \n");
  say("                                                             \n");  

  write("Energy surges across the whip, slicing foe ...               \n");
  write("                                                             \n");
  write("       SSSSS      NN      NN     AAA         PPPPPP       !! \n");
  write("     SSS   SS    NN NN   NN     AA AA       PP   PPP     !!  \n");
  write("     SSS        NN NN  NN     AA  AA      PP    PP     !!    \n");
  write("      SSS      NN  NN NN     AAAAAAA     PPPPPPP      !!     \n");
  write("SS  SSSS      NN   NNN     AA   AA     PP                    \n");
  write(" SSSSSS      NN    NN     AA   AA     PP           !!        \n");
  write("                                                             \n");
      return 15;
          }

return;
}
