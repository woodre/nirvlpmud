inherit "/obj/monster";
#include "/players/jareel/define.h"

     int H;

     int sword;

     reset(arg){
      ::reset(arg);
        if (arg) return;

     set_alias("rune lord");
     set_alt_name("lord");
     set_name("jemdar");
     set_race("human");
     set_al(0);
     set_level(21);
     set_aggressive(0);
     set_hp(600);

     MOCO("/players/jareel/weapons/jsword.c"),this_object());
       sword = present("sword",this_object());
       sword->set_short(HIK+"Wind Sword. "+NORM+BOLD+"( "+BLU+"Lightning charged"+NORM+BOLD+" )"+NORM);
         init_command("wield sword");
     MOCO("/players/jareel/armor/orlanth/ring_of_power.c"),this_object());
         init_command("wear ring");

     set_ac(20);
     set_wc(34);
     set_wc_bonus(32);
     set_gender("male");
     add_money(2000+random(1000));
     set_dead_ob(TO);

     set_short(
       "Jemdar - "+BLU+"Rune Lord"+NORM+" of Orlanth Thunderouse. (neutral)");
     set_long(
       "Jemdar is an older man.  Having seen many years of\n"+
       "battle, his far-away stare makes you believe he has\n"+
       "one too many fights.  You get the sense that a dark\n"+
       "trauma lies behind his eyes and only death will\n"+
       "free his poor soul.\n");

     set_chance(30);
     set_spell_mess1(
       "Jemdar shoots out a bolt of energy.\n");
set_spell_mess2(
     "Jemdar casts a disruption at you.\n"+
     "\n"+
     "                     Your skin"+RED+" B O I L S!\n"+
     ""+NORM+"\n");
set_spell_dam(50);
set_chat_chance(2);
load_chat("Jemdar says: 'I need to find Mondar, I have seen the Crimson Bat.'\n");
load_chat("Jemdar says: 'This realm has the stench of chaos abound'\n");
}

init() {
  ::init();
add_action("nogo","east");
}

nogo() {
write("Jemdar wont let you pass.\n");
return 1;}

heart_beat(){
  ::heart_beat();
  if(attacker_ob) {
    already_fight=0;
 
H = random(5);
if(attacker_ob){
  if(H <= 1) H_parry();
  if(H == 2) H_fistsmash();
  else if(H >= 3) H_bladesharp();
}
}
}

H_parry() {
tell_room(environment(TO),
 "Jemdar parries the feeble attack.\n"+
 "             "+BOLD+" E L E C T R I C I T Y "+NORM+"runs along his blade.\n");
call_other(attacker_ob,"hit_player",random(40)+5);
return;
}

H_fistsmash()  {
tell_room(environment(TO),

""+BOLD+"                      zeeeeee-\n"+
"                     z$$$$$$'\n"+
"                    d$$$$$$'\n"+
"                   d$$$$$P\n");
tell_room(environment(TO),
"                  d$$$$$P\n"+
"                 $$$$$$'\n"+
"               .$$$$$$'\n"+
"              .$$$$$$'\n");
tell_room(environment(TO),
"             4$$$$$$$$$$$$$'\n"+
"            z$$$$$$$$$$$$$'\n"+
"            '''''''3$$$$$'\n"+
"                  z$$$$P\n");
tell_room(environment(TO),
"                 d$$$$'\n"+
"               .$$$$$'\n"+
"              z$$$$$'\n"+
"             z$$$$P'\n");
tell_room(environment(TO),
"            d$$$$$$$$$$'\n"+
"           *******$$$'\n"+
"                .$$$'\n"+
"               .$$'\n"+
"              4$P'\n");
tell_room(environment(TO),
"             z$'\n"+
"            zP\n"+
"           z'\n");
tell_room(environment(TO),
"          /  \n"+
"         ^\n"+
"\n"+NORM);
     attacker_ob->hit_player(random(70)+50, "other|electricity");
     return;
}

H_bladesharp() {
     tell_room(environment(TO),
      "Hendrik unleashes lightning\n"+
      "\n"+
      ""+BLINK+BOLD+" L I G H T N I N G "+NORM+" leaps from the blade.\n"+
      "\n");
      attacker_ob->hit_player(random(50)+50, "other|electricity");
      return;
}

monster_died() {
  if(objectp(sword)) sword->reset();
  return 0;}
