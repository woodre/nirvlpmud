inherit "/players/jaraxle/closed/monster.c";
#include "/players/jareel/define.h"

reset(arg){
   
     object gold,helmet,armor,sword;
       ::reset(arg);
       if(arg) return;
     set_wander(15, 0,);
     set_name("guardian");
     set_alias("legend");
     set_alt_name("guard");
     set_short(BOLD+"A Legend Guardian"+NORM);
     set_long(
       "The imposing figure standing before you bears the task of\n"+
       "keeping the legends area intact.  The guardians of the hall\n"+
       "are hand picked for their attention to detail, and their grace\n"+
       "with a weapon.\n" );
     if(!random(2)) set_gender("male"); else set_gender("female");
     set_al((1000-random(2000)));
     set_race("human");
     set_level(20);
     set_hp(500);
       MOCO("/players/jareel/weapons/legends/guardian_dagger.c"),this_object());
         init_command("wield dagger");
     set_wc(30);
     set_ac(17);
     set_aggressive(0);
     add_money(4000);
     set_dead_ob(this_object());
     set_chance(20);
     set_spell_dam(20);
     set_spell_mess1(
       "The Guardian yell: Infidels feel my wrath!\n");
     set_spell_mess2(BOLD+
       "A wave of power smashes into you!!!!\n"+NORM);
}

heart_beat(){
     
     object ob;
     object att;
     object next;
     
     if(!environment()) return;
     if(ob = present("guardian", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
       ::heart_beat();
}
