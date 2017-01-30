inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("B-Ko");
    set_short();
    set_alt_name("girl");
    set_alias("b-ko");
    /*set_gender("female");*/

set_level(18);
set_hp(450);
set_al(0);
set_wc(26);
set_ac(15);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(1);
load_chat("B-ko says: 'I wonder, I wonder... do you know what I wonder?'\n");
set_a_chat_chance(5);
load_a_chat("B-ko seeps back into the shadows\n");


    set_long(
"  Shadow Girl B-Ko\n"+
"B-Ko is a performer in a Shadow play. From her shadow you can tell \n"+
"she wears the traditional fuku (uniform) for a girl.  She wears her \n"+
"hair in pigtails.  She is always seen alongside A-Ko.\n");

  set_chance(10);
  set_spell_mess1(
"B-ko puts an apple on her opponents head\n"+
"   B-ko says: \"3,584...\" as she shoots it off.\n"+
"      She serves up another apple and aims lower this time.\n"+
"         3,585......err\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"B-ko puts an apple on your head\n"+
"   B-ko says: \"3,584...\" as she shoots it off your head.\n"+
"      She places another apple on your head and aims lower this time.\n"+
"         3,585......err\n"
  ); /* 1ST PERSON */
  set_spell_dam(25);

  set_dead_ob(this_object());
}


monster_died(ob){
object s;
	if(present("A-Ko",ETO)){
		write("....kashira... kashira... motto kashiraaaaa\n");
		return 1;
	}
	write("As the last Shadow Girl dies, you see a small kit fall in the shadows.\n");
	MOCO("/players/stark/utena/obj/a_b_shadowkit"),ETO);
    s=present("a_b_small kit", ETO);
    s->set_coins(1000+random(2000));
	return 1;
}

