inherit "/obj/monster";
#include "/players/jareel/define.h"

int H;
int shield;
int sword;
reset(arg)
{
   ::reset(arg);
   if (arg) return;

set_alias("rune lord");
set_alt_name("lord");
set_name("henrik");
set_race("human");
set_al(0);
set_level(21);
set_aggressive(0);
set_hp(600);
MOCO("/players/jareel/weapons/sword.c"),this_object());
sword = present("sword",this_object());
sword->set_short(HIK+"Bastard Sword. "+NORM+BOLD+"( "+BLU+"Lightning charged"+NORM+BOLD+" )"+NORM);
init_command("wield sword");
MOCO("/players/jareel/armor/orlanthi_wind_lord_shield.c"),this_object());
shield = present("shield",this_object());
shield->set_short(BLU+"Wind Shield"+NORM+". "+BOLD+"( "+BLU+"Swirling Wind"+NORM+BOLD+" )"+NORM);
init_command("wear shield");
    set_ac(20);
    set_wc(34);
    set_wc_bonus(32);
    set_gender("male");
    add_money(2000+random(1000));
    set_dead_ob(this_object());
set_short(
     "Henrik - "+BLU+"Rune Lord"+NORM+" of Orlanth Rex. (neutral)");
set_long(
   "Henrik is an older man.  Having seen many years of\n"+
   "battle, his far-away stare makes you believe he has\n"+
   "one too many fights.  You get the sense that a dark\n"+
   "trauma lies behind his eyes and only death will\n"+
   "free his poor soul.\n");
set_chance(30);
set_spell_mess1(
     "Henrik shoots out a bolt of energy.\n");
set_spell_mess2(
     "Henrik casts a disruption at you.\n"+
     "\n"+
     "                     Your skin"+RED+" B O I L S!\n"+
     ""+NORM+"\n");
set_spell_dam(50);
set_chat_chance(2);
load_chat("Henrik says: 'The cr..ims...on    b..a.....t...'\n");
load_chat("Henrik rocks back and forth'\n");
}

init() {
  ::init();
add_action("nogo","east");
}

nogo() {
write("Henrik wont let you pass.\n");
return 1;}

heart_beat(){
  ::heart_beat();
  if(!this_object()) return;
  if(attacker_ob) {
    already_fight=0;
 
H = random(5);
if(attacker_ob && present(attacker_ob, environment(this_object()))) {
  if(H <= 1) H_parry();
  if(H == 2) H_fistsmash();
  else if(H >= 3) H_bladesharp();
}
}
}

H_parry() {
tell_room(environment(TO),
 "Hendrik parries the feeble attack.\n"+
 "             "+BOLD+" E L E C T R I C I T Y "+NORM+"runs along his blade.\n");
call_other(attacker_ob,"hit_player",random(40)+5);
return;
}

H_fistsmash()  {
tell_room(environment(TO),
  "Hendrik smashes you with a shield bash.\n");
call_other(attacker_ob,"hit_player",random(25)+10);
return;
}

H_bladesharp() {
tell_room(environment(TO),
 "Hendrik unleashes lightning\n"+
 "\n"+
 ""+BLINK+BOLD+" L I G H T N I N G "+NORM+" leaps from the blade.\n"+
 "\n");
call_other(attacker_ob,"hit_player",random(60)+5);
return;
}
monster_died() {
shield->reset();
sword->reset();
return 0;}
