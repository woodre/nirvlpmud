inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("A-Ko");
    set_short();
    set_alias("a-ko");
    set_alt_name("girl");
    /*set_gender("female");*/

set_level(18);
set_hp(450);
set_al(0);
set_wc(26);
set_ac(15);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(1);
load_chat("A-ko says: 'I wonder, I wonder... do you know what I wonder?'\n");
set_a_chat_chance(5);
load_a_chat("A-ko seeps back into the shadows\n");

    set_long(
"  Shadow Girl A-Ko\n"+
"A-Ko is a performer in a Shadow play. From her shadow you can tell \n"+
"she wears the traditional fuku (uniform) for a girl.  She wears a \n"+
"ribbon in her hair.  She is always seen alongside B-Ko.\n");

  set_chance(10);
  set_spell_mess1(
"A-ko says: \"I wonder, I wonder... do you know what I wonder?\"\n"+
"   A-ko raises up a shadow and remarks: \"Warriors are so easily distracted!\"\n"+
"      An unseen hand smacks her foe across the back of your head!\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"A-ko says: \"I wonder, I wonder... do you know what I wonder?\"\n"+
"   A-ko raises up a shadow and remarks: \"Warriors are so easily distracted!\"\n"+
"      The shadow of her hand smacks you across the back of your head!\n"
  ); /* 1ST PERSON */
  set_spell_dam(25);

  set_dead_ob(this_object());
}


monster_died(ob){
object s;
	if(present("B-Ko",ETO)){
		write("....kashira... kashira... motto kashiraaaaa\n");
		return 1;
	}
	write("As the last Shadow Girl dies, you see a small kit fall in the shadows.\n");
	MOCO("/players/stark/utena/obj/a_b_shadowkit"),ETO);
    s=present("a_b_small kit", ETO);
    s->set_coins(1000+random(2000));
	return 1;
}


