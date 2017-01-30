/* Dontayne - the quest holy man  */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("dontayne");
set_alias("hermit");
set_race("human");
set_short("hunch-backed hermit");
set_long(
  "A ragged beard adorns and hides most of the face of this old,\n"+
  "hunched-back hermit. His eyes seem unfocused and he shuffles along\n"+
  "the dark caverns with no apparent destination.  By the looks of his\n"+
  "dusty, tattered brown robe, he was once a man of God.\n");

set_level(14);
set_hp(210);
set_al(100);
set_wc(18);
set_ac(11);
set_aggressive(0);

set_chat_chance(6);
  load_chat("The hermit sniffs and then spits on the cave floor.\n");
  load_chat("The hermit mumbles, 'Can you help me?'\n");
  load_chat("The hermit stares into your eyes...\n");
  load_chat("'I must keep searching', whispers the hermit.\n");

gold = clone_object("obj/money");
gold->set_money(random(200)+50);
move_object(gold,this_object());
}
