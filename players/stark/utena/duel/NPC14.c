inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Mikage Souji");
    set_name("Mikage Souji");
    set_alt_name("mikage");
    set_alias("souji");
    set_gender("male");

MOCO("/players/stark/utena/obj/tougasword.c"),this_object());
MOCO("/players/stark/utena/obj/black_ring.c"),this_object());
command("wear ring");
command("wield weapon");

set_level(20);
set_hp(525);
set_al(-1000);
set_wc(30);
set_ac(16);
set_no_clean(1);
set_aggressive(1);

set_chat_chance(3);
load_chat("Mikage looks over his black rose.\n");
load_chat("Mikage touches his Black Rose ring and smiles darkly at you.\n");
load_chat("Mikage asks: Would you like to attend my seminar some day?\n");
set_a_chat_chance(5);
load_a_chat("Mikage steps in front of his roses to protect them.\n");
load_a_chat("Mikage flicks his hair in the air and charges at you.\n");

set_long(
"Mikage Souji of the Mikage Seminar, also known as the Black Rose \n"+
"Society.  Although only still a student, he is highly regarded even \n"+
"among the Professors at Ohtori Academy.  His white hair is shoulder \n"+
"length with bangs just past his eyes.  He wears a blue male uniform for \n"+
"the college level.  He is a slender, but not a frail man.  He plans to \n"+
"replace the Rose Bride with his own.  The ultimate goal of the Black \n"+
"Rose Society is to find Eternity; to bring Revolution.\n");

  set_chance(30);
  set_spell_mess1(
"Mikage opens up one of many caskets\n"+
"   With insane laughter he grabs a saber out of the coffin\n"+
"      Mikage expertly slices at his target with his dark saber\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Mikage opens up one of many caskets\n"+
"   With insane laughter he grabs a saber out of the coffin\n"+
"      Mikage expertly slices you with his dark saber\n"
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
