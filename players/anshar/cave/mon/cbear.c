#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "obj/monster";

reset(arg)
{
  object skin;
  ::reset(arg);
  if(arg) return;
  set_name("bear");
  set_race("bear");
  set_alias("cave bear");
  set_short("A cave bear");
  set_long(
    "   This tower of shaggy fur stands about 12' tall on its hind legs.\n\
Huge arms end in paws the size of a good sized shield and are tipped\n\
with vicious claws.\n");
  set_level(20);
  set_hp(500);
  set_al(0);
  set_wc(30);
  set_ac(17);
  set_aggressive(1);
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("A growl echoes from deep within the bear's chest.\n");
  load_chat("The bear rears up menacingly.\n");
  load_a_chat("The bear ROARS loudly.\n");
  set_chance(25);
  set_spell_dam(20);
  set_spell_mess1("The bear grapples his opponent furiously.\n");
  set_spell_mess2("The bear pulls you into a crushing embrace. Bones crack with the force of the hug.\n");
  skin=clone_object(CITEM+"bskin.c");
  move_object(skin,this_object());
}
