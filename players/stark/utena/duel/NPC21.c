inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Ohtori Akio");
    set_name("Ohtori Akio");
    set_alt_name("akio");
    set_alias("ohtori");
    set_gender("male");

MOCO("/players/stark/utena/obj/tougasword.c"),this_object());
MOCO("/players/stark/utena/obj/a_ring.c"),this_object());
command("wear ring");
command("wield sword");


set_level(23);
set_hp(800);
set_al(-1000);
set_wc(40);
set_ac(21);
set_no_clean(1);
set_aggressive(1);

set_chat_chance(3);
load_chat("Akio lounges on his couch.\n");
load_chat("Akio flips his hair back and chuckles.\n");
load_chat("Akio gives you a fetching look.\n");
set_a_chat_chance(5);
load_a_chat("Akio laughs in your face.\n");
load_a_chat("Akio yells: You'll never escape here!\n");
load_a_chat("Akio asks: Did your prince look something like me?\n");

    set_long(
"Ohtori Akio has rich tan skin and a roguish look about him.  He has \n"+
"the glint of knowledge and danger in his eyes.  His very light purple \n"+
"hair is styled short on the top, but the length of it is pulled back \n"+
"into a ponytail hanging over his shoulder.  He wears a red western \n"+
"style shirt with a tie and blue detailing.  He is the older brother of \n"+
"Anthy's and the Deputy Trustee of the Ohtori Academy.  He holds some \n"+
"of the secrets of the Duels and the Rose Signet Code.\n");

  set_chance(30);
  set_spell_mess1(
"Akio stands back and opens his arms wide\n"+
"   Laughter resounds through the Planetarium\n"+
"      Akio slams his fist into his opponent!"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Akio stands back and opens his arms wide\n"+
"   Laughter resounds through the Planetarium\n"+
"      Akio slams his fist into your face!"
  ); /* 1ST PERSON */
  set_spell_dam(160);

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

