inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Kiryuu Touga");
    set_name("Kiryuu Touga");
    set_alt_name("touga");
    set_alias("kiryuu");
    set_gender("male");

MOCO("/players/stark/utena/obj/tougasword.c"),this_object());
MOCO("/players/stark/utena/obj/t_ring.c"),this_object());
command("wield weapon");
command("wear ring");

set_level(20);
set_hp(500);
set_al(-1000);
set_wc(30);
set_ac(16);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("Touga shakes his head so his red hair can flow in the wind.\n");
load_chat("Touga looks you over and smiles seductivly.\n");
load_chat("There is a light ringing.\n");
load_chat("Touga picks up his cell phone and talks softly into it.\n");
load_chat("Touga lounges against a wall and watches over Ohtori Academy.\n");
load_chat("Touga reads over a small letter.\n");
load_chat("Touga says: 'It would seem there will be new Duelists soon...'\n");
set_a_chat_chance(5);
load_a_chat("Touga raises his Katana high in the air simply for effect.\n");
load_a_chat("Touga flashes a smile at you.\n");
load_a_chat("Touga says: 'You are too weak to bring Revolution!'\n");
load_a_chat("Touga charges at you with his Katana raised!\n");

set_long(
"Kiryuu Touga is a member of the Ohtori Academy Student Council.  He \n"+
"wears a Student council outfit; A white jacket that buttons at the \n"+
"shoulder with a red lining and brass buttons, decorative gold cording \n"+
"and red shoulders.  His dark red hair flows down past his shoulders.  \n"+
"His white pants distinguish him as the Council President.  He controls \n"+
"who can fight in the Dueling Arena.  He also believes he can be Utena's \n"+
"true Prince.  With her, he will be the one to bring Revolution!\n");

  set_chance(30);
  set_spell_mess1(
"Touga smiles seductively at his attacker as he drops his sword\n"+
"   \"Was... I something like your prince?\"\n"+
"      Touga picks up his sword and edges it into their heart!\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Touga smiles seductively at you as he drops his sword\n"+
"   \"Was... I something like your prince?\"\n"+
"      Touga picks up his sword and edges it into your heart!\n"
  ); /* 1ST PERSON */
  set_spell_dam(37);

  set_dead_ob(this_object());
}

monster_died(ob){
object s;
		MOCO("/players/stark/utena/obj/tougajacket.c"),this_object());
        MOCO("/players/stark/utena/obj/wallet.c"),this_object());
        s=present("Wallet", TO);
        s->set_coins(500+random(2000));
}



