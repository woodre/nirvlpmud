inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Takatsuki Shiori");
    set_name("Takatsuki Shiori");
    set_alt_name("shiori");
    set_alias("takatsuko");
    set_gender("female");

MOCO("/players/stark/utena/obj/jurisword.c"),this_object());
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
load_chat("Shiori looks over the fencers without a care.\n");
load_chat("Shiori searches for Juri in the crowd.\n");
load_chat("Shiori looks at you with disdain.\n");
set_a_chat_chance(5);
load_a_chat("Shiori laughs at you as she backs up.\n");
load_a_chat("Shiori looks straight into your eyes.\n");
load_a_chat("Shiori whispers at you: 'Believe in a miracle, that your wish come true.'\n");

set_long(
"Takatsuki Shiori is a student at Ohtori Academy.  She wears the \n"+
"school's traditional fuku (uniform): A white blouse with fluffy \n"+
"sleeves tucked neatly into a green and white pleated skirt, knee high \n"+
"socks and a big red bow tied at her neck.  She has a close yet unknown \n"+
"bond with Juri.\n");

  set_chance(30);
  set_spell_mess1(
"Shiroi walks up to your group and bekons the closest person\n"+
"   She whispers: \"Trust in Miracles...\"\n"+
"      Shiroi digs a small dagger into them and ends: \"..and you will be fooled.\"\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Shiroi walks up to you and bekons\n"+
"   She whispers to you: \"Trust in Miracles...\"\n"+
"      Shiroi digs a small dagger into you and ends: \"..and you will be fooled.\"\n"
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
