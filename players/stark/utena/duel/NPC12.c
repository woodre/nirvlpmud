inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Shinohara Wakaba");
    set_name("Shinohara Wakaba");
    set_alt_name("wakaba");
    set_alias("shinohara");
    set_gender("female");

MOCO("/players/stark/utena/obj/saionjisword.c"),this_object());
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
load_chat("Wakaba taps her foot waiting for Utena\n");
load_chat("Wakaba thinks outloud: 'Where is my Utena!?'\n");
load_chat("Wakaba yells at the dorm: 'UTEEENNAAAAAAA!!!!!'\n");
set_a_chat_chance(5);
load_a_chat("Wakaba jumps on your back!\n");
load_a_chat("Wakaba slaps you across the face, leaving a red mark!\n");
load_a_chat("Wakaba yells: 'Stay away from me!  Someone help!'\n");

set_long(
"Shinohara Wakaba is a female student at Ohtori Academy.  She wears \n"+
"the school's traditional fuku (uniform):  A white blouse with fluffy \n"+
"sleeves tucked neatly into a green and white pleated skirt, knee high \n"+
"socks and a big red bow tied at her neck.   Her big brown eyes are full \n"+
"of life and vigor, and she bounces happily through life.  She is \n"+
"Utena's best friend and hangs on her constantly.\n");

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
