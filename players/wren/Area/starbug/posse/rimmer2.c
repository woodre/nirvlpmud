	/* Rimmer2 */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob;

    ob = clone_object("/players/wren/Area/starbug/items/leaflets.c");
         move_object(ob,this_object());
   
set_name("rimmer");
set_alias("arnold");
set_short("Arnold Rimmer");
set_race("hologram");
set_long("Rimmer is looking more geek than usual in his cargo shorts  \n"+
         "and P.E.T.A T-shirt. He now sports a pair of black-rimmed   \n"+
         "glasses and a goatee. He is even now trying to pursuade the \n"+
         "crew of a nonviolent mean of dealing with an alien threat.  \n"+
         "He proposses they need to hit it hard and fast with a major \n"+
         "leaflet campaign, followed by television spots, and pickets.\n"+
         "Without anger he is even less likeable. Who'd have imagined.\n");

set_level(17);
set_ac(15);
set_wc(24);
set_hp(350);
set_al(500);    		 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/

load_chat("Rimmer's chews on his pipe.	\n");
load_chat("Rimmer says: 'A leaflet campaign and if that fails, bake sale'.	\n");
load_chat("Rimmer says: 'We'll make signs, 'Chameleonic Life Forms, No thanks'. \n");
load_chat("Rimmer says: 'Or perhaps a good hammond organ recital'. \n");
load_chat("Rimmer says: 'Maybe we can reason with it'.\n");

load_a_chat("Rimmer says: 'Violence isn't the answer.\n");
load_a_chat("Rimmer goes limp in nonviolent resistance. \n");
load_a_chat("Rimmer sing protest songs.\n");
load_a_chat("Rimmer says: 'Be reasonable'.\n");


    }
}

