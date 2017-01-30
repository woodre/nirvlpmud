inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("C-Ko");
    set_short();
    set_alt_name("girl");
    set_alias("c-ko");
    /*set_gender("female");*/

set_level(18);
set_hp(450);
set_al(0);
set_wc(26);
set_ac(15);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(1);
load_chat("C-ko says: 'Extra! Extra! Extra!'\n");
set_a_chat_chance(5);
load_a_chat("C-ko seeps back into the shadows\n");

    set_long(
"  Shadow Girl C-Ko\n"+
"C-Ko is a performer in a Shadow play. From her shadow you can tell \n"+
"she wears the traditional fuku (uniform) for a girl.  She wears her \n"+
"hair in a high ponytail.  She works alone in her Shadow Plays.\n");

  set_chance(10);
  set_spell_mess1(
"C-Ko sneaks up close to your group and pricks one of your group with a syringe\n"+
"   She slowly drains a vial of blood!?!?\n"+
"      C-Ko winks and remarks: \"Proof of Adulthood!\"\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"C-Ko sneaks up close to you and pricks you with a syringe\n"+
"   She slowly drains a vial of your blood!?!?\n"+
"      C-Ko winks and remarks: \"Proof of Adulthood!\"\n"
  ); /* 1ST PERSON */
  set_spell_dam(25);

  set_dead_ob(this_object());
}

monster_died(ob){
object s;
	say("As C-ko dies a small kit falls in the shadows\n");
	MOCO("/players/stark/utena/obj/c_shadowkit"),ETO);
    s=present("c_small kit", ETO);
    s->set_coins(500+random(1000));
	return 1;
}
