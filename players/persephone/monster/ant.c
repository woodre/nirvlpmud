/* Fixed a few typos.  [11-30-01] Verte */
inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object stic;
   stic = clone_object("players/persephone/obj/stick");
   move_object(stic, TOB);
   set_name("ant");
   set_short("A Little Ant");
   set_long("A harmless looking ant that seems to be minding its own\n" +
            "business.\n");
   set_level (1);
   set_wc(4);
   set_ac(3);
   set_hp(15);
   set_al(0);
   set_aggressive(0);
   set_gender(0);
   set_chat_chance(20);
    load_chat("The Ant scurries around.\n");
    load_chat("The Ant works without noticing you.\n");
    load_chat("The Ant twitches its feelers.\n");
  }
}
