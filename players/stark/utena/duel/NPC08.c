inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Kanae Ohtori");
    set_name("Kanae Ohtori");
    set_alt_name("kanae");
    set_alias("ohtori");
    set_gender("female");

MOCO("/players/stark/utena/obj/nanamisword.c"),this_object());
MOCO("/players/stark/utena/obj/black_ring.c"),this_object());
command("wear ring");
command("wield weapon");

set_level(20);
set_hp(525);
set_al(-1000);
set_wc(30);
set_ac(15);
set_no_clean(1);
set_aggressive(1);

set_chat_chance(3);
load_chat(".\n");
set_a_chat_chance(5);
load_a_chat(".\n");

set_long(
".\n");

  set_chance(30);
  set_spell_mess1(
  ); /* 3RD PERSON */
  set_spell_mess2(
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
