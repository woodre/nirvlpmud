#include "/players/francesco/univ/ansi.h"

inherit "obj/monster";

int a;

reset(arg){
  object snowhoe;
  ::reset();
  if(arg) return;
   set_name("Bjorn");
   set_race("human");
   set_alias("bjorn");
   set_gender("male");
     set_short("Bjorn Daehlie");
     set_long("Bjorn Daehlie is the most medallist in the history of the Winter\n"+
              "Olympics, totalling eight gold, two silver and two bronze medals\n"+
              "from 1992 to 1998 in cross-country skiing.  The most winning \n"+
              "sportsman of Norway, he even wrote a book 'Hunting for gold'\n"+
              "which immediately became a best-seller.\n");
   set_level(20);
   set_hp(620+random(100));
   set_wc(30+random(7));
   set_wc_bonus(30);
   set_ac(17+random(7));
   set_chat_chance(10);
   set_heal(2,2);
   set_chance(25);
   set_spell_dam(25);
   set_spell_mess2("");
   set_spell_mess1("");
   snowhoe= clone_object("/players/francesco/hall/items/snowhoe.c");
   move_object(snowhoe,this_object());
   init_command("wield snowhoe");
}

id(str) {return str=="bjorn" || str=="daehlie" || str=="bjorn daehlie" ;}


heart_beat() {
   ::heart_beat();
   if(attacker_ob){
     if(attacker_ob->query_int() >= random(40))
        attacker_ob->heal_self(-10); 
     if(attacker_ob->query_pie() >= random(40))
        attacker_ob->heal_self(-10); 
     if(attacker_ob->query_luc() >= random(40))
        attacker_ob->heal_self(-10); 
        if(!random(5)){
        say("Bjorn waves his snowhoe like a sword to give massive damage.\n");
        return 1;}
        if(!random(9)){
        say("Bjorn impaled "+attacker_ob->query_name()+" with both his snowhoes.\n");
        return 1;}
       /* 
        wc_bonus calculation:
        50% chance of doing 10 damage, 3 times per round, both hps and sps
        1/2 * 10 * 3 * 2 = 30
       */
      }
  } 



