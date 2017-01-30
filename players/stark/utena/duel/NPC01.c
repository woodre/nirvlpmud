inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Saionji Kyouichi");
    set_name("Saionji Kyouichi");
    set_alt_name("saionji");
    set_alias("kyouichi");
    set_gender("male");

MOCO("/players/stark/utena/obj/saionjisword.c"),this_object());
MOCO("/players/stark/utena/obj/s_ring.c"),this_object());
command("wield weapon");
command("wear ring");

set_level(20);
set_hp(500);
set_al(-1000);
set_wc(30);
set_ac(16);
set_no_clean(1);
set_aggressive(1);

set_chat_chance(3);
load_chat("Saionji practices at his Kendo.\n");
load_chat("Saionji looks at you with contempt.\n");
load_chat("Saionji demands: 'What is it that you want?'\n");
load_chat("Saionji remarks: 'You're disturbing me in my practice.'\n");
load_chat("Saionji chalanges: 'If you have nothing to offer, I would ask that you... leave.'\n");
set_a_chat_chance(5);
load_a_chat("Saionji cackles maniacally.\n");
load_a_chat("Saionji yells: 'You are nothing compared to my skill!\n");
load_a_chat("Saionji yells: 'I and only *I* am fit to have the Rose Bride!'\n");

set_long(
"Saionji Kyouichi is a member of the Ohtori Academy Student Council.  \n"+
"He wears a Student council outfit; A white jacket that buttons at the \n"+
"shoulder with a red lining and brass buttons, decorative gold cording \n"+
"and red shoulders.  His green pants match his long curly green hair, \n"+
"falling down the middle of his back.  He wants Anthy for his own love \n"+
"and to bring Revolution!\n");

  set_chance(25);
  set_spell_mess1(
"Saionji errupts with a dark laughter\n"+
"   He charges at his foe and pins them down with his sword\n"+
"      He pushes his attacker to the ground and "+WHT+BOLD+"S L A S H E S"+NORM+" at them!\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Saionji errupts with a dark laughter\n"+
"   He charges at you and pins you down with his sword\n"+
"      He pushes you to the ground and "+WHT+BOLD+"S L A S H E S"+NORM+" at you!\n"
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

