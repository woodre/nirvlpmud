inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Arisugawa Juri");
    set_name("Arisugawa Juri");
    set_alt_name("juri");
    set_alias("arisugawa");
    set_gender("female");

MOCO("/players/stark/utena/obj/jurisword.c"),this_object());
MOCO("/players/stark/utena/obj/jurilocket.c"),this_object());
MOCO("/players/stark/utena/obj/j_ring.c"),this_object());
command("wield weapon");
command("wear ring");
command("wear locket");

set_level(20);
set_hp(500);
set_al(0);
set_wc(30);
set_ac(15);
set_no_clean(1);
set_aggressive(1);

set_chat_chance(3);
load_chat("Juri stabs forward at an opponent.\nJuri yells: Tsugi!\n");
load_chat("Juri slashes at her next opponent.\nJuri yells: Tsugi!\n");
load_chat("Juri sidesteps and taps the shoulder of her opponent.\nJuri yells: Tsugi!\n");
set_a_chat_chance(5);
load_a_chat("Juri laughs at you.\n");
load_a_chat("Juri yells: There are no miracles in this world!\n");
load_a_chat("Juri yells: I will find the power to disprove all miracles!\n");

    set_long(
"Arisugawa Juri is a member of the Ohtori Academy Student Council.  She \n"+
"wears a Student council outfit; A white jacket that buttons at the \n"+
"shoulder with a red lining and brass buttons, decorative gold cording \n"+
"and red shoulders.  Her strawberry red pants match the curls of \n"+
"strawberry blond that fall just past her shoulders.  She wants to \n"+
"disprove miracles by bringing the world Revolution!\n");

  set_chance(25);
  set_spell_mess1(
"Juri points her foil at her foe\n"+
"   \"There are no such things as Miracles!\"\n"+
"      Juri stabs her foil in deep to show off her abilities.\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Juri points her foil at you\n"+
"   \"There are no such things as Miracles!\"\n"+
"      Juri stabs her foil deep in to your body.\n"
  ); /* 1ST PERSON */
  set_spell_dam(30);

  set_dead_ob(this_object());
}

monster_died(ob){
	destruct("sword");
	destruct("ring");
	destruct("locket");
}

init() {
::init();
add_action("next","next");
}

next(){
	write(TO->query_name() +" stops you from advancing.\n");
return 1;}
