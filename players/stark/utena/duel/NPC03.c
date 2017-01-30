inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Kaoru Miki");
    set_name("Kaoru Miki");
    set_alt_name("miki");
    set_alias("kaoru");
    set_gender("male");

MOCO("/players/stark/utena/obj/mikisword.c"),this_object());
MOCO("/players/stark/utena/obj/m_ring.c"),this_object());
command("wield weapon");
command("wear ring");

set_level(20);
set_hp(500);
set_al(0);
set_wc(30);
set_ac(16);
set_no_clean(1);
set_aggressive(1);

set_chat_chance(3);
load_chat("Miki gently plays at his piano.\n");
load_chat("'The Sunlit Garden' is played with beauty and strength.\n");
load_chat("Miki whispers about finding his 'Shining Thing'.\n");
set_a_chat_chance(5);
load_a_chat("Miki yells: 'I will find that Shining Thing once again!'\n");
load_a_chat("Miki steps to the side and slashes at you.\n");
load_a_chat("Miki says: 'I can make Anthy happy!  I can let her play whenever she wants!'\n");

    set_long(
"Kaoru Miki is a member of the Ohtori Academy Student Council.  He \n"+
"wears a Student council outfit; A white jacket that buttons at the \n"+
"shoulder with a red lining and brass buttons, decorative gold cording \n"+
"and red shoulders.  His blue pants match his short-cropped blue hair.  \n"+
"He is searching for his 'shining thing' in life.  He believes that \n"+
"Anthy holds just that.\n");

  set_chance(25);
  set_spell_mess1(
"Miki unleashes a barrage of slashes and stabs!\n"+
"   Each attack strikes one after another\n"+
"      Miki clicks his stopwatch and looks astonished.\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Miki unleashes a barrage of slashes and stabs at you!\n"+
"   Each attack strikes one after another\n"+
"      Miki clicks his stopwatch and looks astonished.\n"
  ); /* 1ST PERSON */
  set_spell_dam(30);

  set_dead_ob(this_object());
}

monster_died(ob){
	destruct("sword");
	destruct("ring");
}

init() {
::init();
add_action("next","next");
}

next(){
	write(TO->query_name() +" stops you from advancing.\n");
return 1;}
