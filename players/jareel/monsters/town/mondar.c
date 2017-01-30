inherit "/obj/monster";
#include "/players/jareel/define.h"

int M;
int sword;
reset(arg)
{
   ::reset(arg);

 if (arg) return;
    set_name("mondar");
    set_race("human");
    set_al(0);
    set_level(25);
    set_aggressive(0);
    set_hp(1000);
MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
MOCO("/players/jareel/armor/humakti_rune_sword_gauntlets.c"),this_object());
init_command("wear ring");
MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
sword = present("iron bastard sword",this_object());
sword->set_short("Iron Bastard Sword (offwielded)");
MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
init_command("wield sword");
    set_ac(25);
    set_wc(45);
set_ac_bonus(10);
set_wc_bonus(58);
    set_gender("male");
    set_dead_ob(this_object());
set_short(
     "Mondar - "+BOLD+BLK+"Rune Sword"+NORM+" of Humakt. (neutral)");
set_long(
     "Mondar is an old wrinkled man.  Having seen many\n"+
     "years of battles, his silver-white hair and scar \n"+
     "ridden body prove he is not someone to mess with.\n"+
     "A small lump rises in the back of your throat as\n"+
     "he catches you looking at him.\n");
set_chance(40);
set_spell_mess1(
     "Mondar shoots out a bolt of energy.\n");
set_spell_mess2(
     "Mondar casts a disruption at you.\n"+
     "\n"+
     "                     Your skin"+RED+" B O I L S!\n"+
     ""+NORM+"\n");
set_spell_dam(50);
set_chat_chance(10);
load_chat("Mondar says: 'The skeleton king gave me this scar.'\n");
load_chat("Mondar says: 'This realm is vast but secrets lie all around.'\n");
load_chat("Mondar says: 'Don't look at me punk.'\n");
load_chat("Mondar says: 'Don't look at me punk.'\n");
load_chat("Mondar says: 'You don't want a piece of me, move along now before I kill you.'\n");
load_chat("Mondar orders a beer.\n");
load_chat("Mondar surveys the adventurers.\n");
}

heart_beat(){
  ::heart_beat();
if(attacker_ob) {
    already_fight=0;
    attack();
M = random(10);
if(attacker_ob){
  if(M <= 2) M_parry();
  if(M == 3) M_fistsmash();
  if(M == 4) M_heal();
  if(M == 5) M_heal2();
  if(M == 6) M_allied();
  else if(M >= 7) M_bladesharp();
}
}
}

M_parry() {
tell_room(environment(TO),
 "Mondar parries the feeble attack.\n");
return;
}

M_fistsmash()  {
tell_room(environment(TO),
  "Mondar smashes "+attacker_ob->query_name()+" with a backhand, blood drips off his gauntlet.\n");
call_other(attacker_ob,"hit_player",random(25)+10);
return;
}

M_heal() {
tell_room(environment(TO),
 "Mondar takes a heal from his bag.\n"+
 "Mondar drinks a "+BOLD+BYEL+"potion"+NORM+".\n");
heal_self(random(50));
return;
}

M_heal2()  {
tell_room(environment(TO),
  "Mondar takes a heal out of a bag.\n"+
  "Mondar eats some "+BOLD+BGRN+"berries"+NORM+".\n");
heal_self(random(50));
return;
}

M_bladesharp() {
tell_room(environment(TO),
 "Mondar casts a bladesharp spell over his blade.\n"+
 "\n"+
 ""+BLINK+CYN+" E N E R G Y "+NORM+" flows over the blade.\n"+
 "\n");
call_other(attacker_ob,"hit_player",random(30)+5);
return;
}

M_allied()  {
tell_room(environment(TO),
  "Mondar summons a spirit from his sword.\n"+
  ""+BOLD+"\n"+
  "        An enraged Spirit slashes at "+attacker_ob->query_name()+".\n"+
  ""+NORM+"\n");
call_other(attacker_ob,"hit_player",random(50)+50);
return;
}

monster_died() {
sword->reset();
return 0;}
