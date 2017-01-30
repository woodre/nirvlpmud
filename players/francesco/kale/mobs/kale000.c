#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

int a;

reset(arg){
  ::reset();
  if(arg) return;
   set_name(""+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"");
   set_race("unknown");
   set_alias("kale");
   set_gender("neuter");
     set_short(""+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"");
     set_long("to be done \n");
/*   set_dead_ob(this_object());*/
   set_level(20);
   set_hp(500);
   set_wc(31);
   set_ac(17);
   set_chat_chance(10);
   set_heal(2,2);
   set_chance(25);
   set_spell_mess2("");
   set_spell_mess1("");
   set_spell_dam(25);}

id(str) {return str=="kaleidoscope" || str=="kale" || str=="kaleido" ;}

heart_beat() {
   ::heart_beat();
   if(attacker_ob){  
    a = random(5) ;
   if(a == 1) {
     say(""+HIR+"@@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"@@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"@@                 @@"+NORM+"\n"+
         ""+HIR+"@@                 @@"+NORM+"\n");
     say(""+HIR+"@@                 @@"+NORM+"\n"+
         ""+HIR+"@@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
         ""+HIR+"@@@@@@@@@@@@@@@@@@@@@"+NORM+"\n");
   return 1;}
   if(a == 2) {
     say(""+HIB+""+NORM+"\n"+
         ""+HIB+""+NORM+"\n"+
         ""+HIB+""+NORM+"\n"+
         ""+HIB+""+NORM+"\n"+
     say(""+NORM+"\n"+
         ""+HIB+""+NORM+"\n"+
         ""+HIB+""+NORM+"\n");
   return 1;}
   if(a == 3) {
     say(""+HIY+""+NORM+"\n"+
         ""+HIY+""+NORM+"\n"+
         ""+HIY+""+NORM+"\n"+
         ""+HIY+""+NORM+"\n");
     say(""+HIY+""+NORM+"\n"+
         ""+HIY+""+NORM+"\n"+
         ""+HIY+""+NORM+"\n");
   return 1;}
   if(a == 4) {
     say(""+HIC+""+NORM+"\n"+
         ""+HIC+""+NORM+"\n"+
         ""+HIC+""+NORM+"\n"+
         ""+HIC+""+NORM+"\n");
     say(""+HIC+""+NORM+"\n"+
         ""+HIC+""+NORM+"\n"+
         ""+HIC+""+NORM+"\n");
   return 1;}
   if(a == 0) {
     say(""+HIM+""+NORM+"\n"+
         ""+HIM+""+NORM+"\n"+
         ""+HIM+""+NORM+"\n"+
         ""+HIM+""+NORM+"\n");
     say(""+HIM+""+NORM+"\n"+
         ""+HIM+""+NORM+"\n"+
         ""+HIM+""+NORM+"\n");
   return 1;}
}
}



