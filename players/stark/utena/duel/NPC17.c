inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Tsuchiya Ruka");
    set_name("Tsuchiya Ruka");
    set_alt_name("ruka");
    set_alias("tsuchiya");
    set_gender("male");

MOCO("/players/stark/utena/obj/rukasword.c"),this_object());
MOCO("/players/stark/utena/obj/r_ring.c"),this_object());
command("wield weapon");
command("wear ring");

set_level(21);
set_hp(600);
set_al(-1000);
set_wc(34);
set_ac(19);
set_no_clean(1);
set_aggressive(1);

set_chat_chance(3);
load_chat("Ruka is surrounded by his female fans.\n");
load_chat("Ruka brushes off his small but dense crowd.\n");
load_chat("Ruka shows a fencer some simple moves.\n");
load_chat("Ruka brushes his hair to the side and smiles at the spectators.\n");
set_a_chat_chance(5);
load_a_chat("Ruka shows off to the crowd as he dodges your strikes.\n");
load_a_chat("Ruka laughs merrily as he slashes at you.\n");
load_a_chat("Ruka remarks with a smile: 'You are better than I thought, good job...'\n");

set_long(
"Saionji Kyouichi is a member of the Ohtori Academy Student Council.  \n"+
"He wears a Student council outfit; A white jacket that buttons at the \n"+
"shoulder with a red lining and brass buttons, decorative gold cording \n"+
"and red shoulders.  His green pants match his long curly green hair, \n"+
"falling down the middle of his back.  He wants Anthy for his own love \n"+
"and to bring Revolution!\n");

  set_chance(30);
  set_spell_mess1(
"Ruka sneers as he lets his guard drop\n"+
"   Seeing the opening one of the group charges forward at him\n"+
"      With a sidestep, Ruka slashes his foe in the side!\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Ruka sneers at you as he lets his guard drop\n"+
"   Seeing the opening you charge forward at him\n"+
"      With a sidestep, Ruka slashes across your side!\n"
  ); /* 1ST PERSON */
  set_spell_dam(45);

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

