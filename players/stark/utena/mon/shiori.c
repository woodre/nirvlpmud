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

set_level(19);
set_hp(475);
set_al(-200);
set_wc(28);
set_ac(16);
set_no_clean(1);
set_aggressive(0);

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

  set_chance(10);
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
  set_spell_dam(25);

  set_dead_ob(this_object());
}

monster_died(ob){
object s;
        MOCO("/players/stark/utena/obj/purse.c"),this_object());
        s=present("Purse", TO);
        s->set_coins(1000+random(2000));
}

