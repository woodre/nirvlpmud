#include "/players/jareel/ansi.h"
inherit "obj/monster.c";
#define TO this_object()
     
     int B;
     int C;
     object gold;
     reset(arg)  {
       ::reset(arg);
       if(arg) return;
     no_clean = 1;
     set_name("cooper");
     set_alt_name("moss ranger");
     set_race("draconian");
     set_short(HIW+"The Moss Ranger"+NORM);
     set_level(29);
     set_hp(2000);
     set_al(0);
     set_wc(90);
     set_wc_bonus(80);
     set_ac_bonus(15);
     set_ac(20);
     set_aggressive(0);
     set_heart_beat(1);
     set_dead_ob(this_object());
     set_heal(5,1);
     set_chance(50);
     set_spell_dam(60);
     gold = clone_object("obj/money");
     gold->set_money(23000 + random(4000));
     move_object(gold,this_object());
     message_hit = ({
         BLINK+BOLD+RED+"<<< E V I S C E R A T E D >>>"+NORM," into ashes",
         BLINK+RED+"DISEMBOWELED"+NORM," with hurricane force",
         BOLD+RED+"GORED"+NORM," with deadly precision",
         BLINK+BOLD+RED+"<<< E V I S C E R A T E D >>>"+NORM," into ashes",
         BLINK+RED+"DISEMBOWELED"+NORM," with hurricane force",
         BOLD+RED+"GORED"+NORM," with deadly precision",
         "laid the "+GRN+"Smack"+NORM+" down on"+NORM," ",
         });
     }

     long(){
       write(
         "cooper\n"+
         "\n"+
         "\n"+
         "\n"); 
       return 1;
     }

     heart_beat(){
       ::heart_beat();
         if(attacker_ob) {
         C = random(7);
         B = random(8);
           if(attacker_ob){
             if(C <= 2) C_bracer();       /* 40%  WC - 90 +42  */
             if(B <= 2) C_shockammy();    /* 20%  22  +4    */
             if(B == 3) C_rattleammy();   /* 16%  15  +2    */
             if(B == 4) C_elecammy();     /* 16%  15  +2    */
             if(C == 3) C_suffbless();    /* 16%  15  +2    */
             if(C == 4) C_drwnbless();    /* 16%  15  +2    */
             if(C == 5) C_zappbless();    /* 16%  15  +2    */
             if(C == 6) C_smashbless();   /* 16%  15  +2    */
             else if(B >= 5) C_heal();    /* 62%  25  +15   */
     }
     }
     }

     C_bracer() {
       tell_room(environment(TO),
         ""+BOLD+BLU+"Cooper's form"+NORM+BOLD+" || |  | blurs |  | ||"+BLU+" as her bracers"+YEL+" glow"+NORM+"...\n");
         already_fight=0;
         attack();
       return;
     }

     C_shockammy()  {
       tell_room(environment(TO),
         "Cooper "+BOLD+"SHOCKS"+NORM+" you with a jolt of "+HIY+"lightning"+NORM+"!\n");
         call_other(attacker_ob,"hit_player",random(25)+10);
       return;
     }

     C_heal() {
       tell_room(environment(TO),
         "Cooper takes a bite of "+BOLD+GRN+"Jun"+YEL+"ju"+NORM+" fruit.\n");
         heal_self(random(50));
       return;
     }

     C_rattleammy() {
       tell_room(environment(TO),
         "Cooper "+YEL+"rattles"+NORM+" you with a jolt of "+HIY+"lightning"+NORM+"!\n");
         call_other(attacker_ob,"hit_player",random(20)+5);
       return;
     }

     C_elecammy()  {
       tell_room(environment(TO),
         "Cooper "+HIY+"ELECTRIFIES"+NORM+" you with a jolt of "+HIY+"lightning"+NORM+"!\n");
         call_other(attacker_ob,"hit_player",random(20)+5);
       return;
     }

     C_suffbless() {
       tell_room(environment(TO),
         ""+attacker_ob->query_name()+" is "+BOLD+CYN+"suffocated with a "+CYN+"gust of wind"+NORM+" from "+BOLD+"Natures "+GRN+"Blessing"+NORM+"!\n");
         call_other(attacker_ob,"hit_player",random(20)+5);
       return;
     }

     C_drwnbless()  {
       tell_room(environment(TO),
         ""+attacker_ob->query_name()+" is "+BOLD+BLU+"drowned"+NORM+" with a "+BOLD+BLU+"splash of water"+NORM+" from "+BOLD+"Natures "+GRN+"Blessing"+NORM+"!\n");
         call_other(attacker_ob,"hit_player",random(20)+5);
       return;
     }

     C_zappbless() {
       tell_room(environment(TO),
         ""+attacker_ob->query_name()+" is "+HIY+"zapped"+NORM+" with a "+HIY+"jolt of"+NORM+" electrictity from "+BOLD+"Natures "+GRN+"Blessing"+NORM+"!\n");
         call_other(attacker_ob,"hit_player",random(20)+5);
       return;
     }

     C_smashbless()  {
       tell_room(environment(TO),
         ""+attacker_ob->query_name()+" is "+YEL+"smashed"+NORM+" with a "+BOLD+BLK+"giant bolder"+NORM+" from "+BOLD+"Natures "+GRN+"Blessing"+NORM+"!\n");
         call_other(attacker_ob,"hit_player",random(20)+5);
       return;
     }

     monster_died(){
       return 0;
     }
