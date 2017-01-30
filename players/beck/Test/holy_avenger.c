inherit "/players/beck/updates/weapon.c";
#include "/players/beck/Lib/Resource.c"
int die, attacker, pain;
object ob;

/*
data:

date approved,
date last touched,
approval,
stats approved,

sig

This doesnt fit the standard PGP sig format yet. because
its the first one i made

-----BEGIN PGP MESSAGE-----
Version: 2.6.2

hIwDSrLZYb6nRr0BBADP/iBuWVOXK0if1jxODVXOXS1s4LlSYl96gzZYAc1Sj8vV
   FxFVZtyJ5ipkOdJ54USegPLb4W7jWR3HuYhnONcrt3zmTakZqrOnPubsjIUpnT7t
sJ35g54H+y95943mGxvcdq0zigW3QGGYF+Pf2JoEKcSRH66qzG+3FdiX/jfj66YA
AACjtIPu0KFRSBTBi3LMkBSDD74WM1M3Wc5aMUvlbja0n7F2xU1b/ESj2K7B0S75
H7OwpdcGPPy52pppLXpzvksP/YH/WYXuRic34hxW6k8HjD63RNY8bukyuxj+uZld
RTRwtmnUoyxv3+vMkvTg6xKqa/ZaQtafv+tPD+iJj0Y3TNHVCUxN5wij1N4Vt9gA
xclfI9Q1N1kbYx7F8AMOhR1TXTAeqw==
=nf65
-----END PGP MESSAGE-----

*/



reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name("avenger");
      set_alt_name("quest_holy_avenger");
      set_class(19);
      set_value(80000);
      set_weight(3);
      set_type("sword");
      set_alias("holy avenger");
      set_short("The Holy Avenger");
      set_long(
         "This sword shines with a glowing white blade.\n"+
         "There are runes on its jeweled hilt which translate to:\n"+
         "Only those who are extremely rightious shall be able to grasp this sword.\n"+
         "***** This sword is meant to slay (only) the minions of EVIL!*****\n"+
         "***** The possessor shall not be able to harm the good *****\n"+
         "The sword may act violently if you break any of these rules.\n"+
         "");
      set_hit_func(this_object());
      set_params("other|good", 1, "holy_hit");
      AResource(({"jewel|ruby",3,"jewel|emerald",2,"metal|platinum",5}));
   }
}
holy_hit(attacker)
{
   if(!random(3))
      if(attacker->query_alignment() < -500) {
      hits = 0;
      write("You raise the sword toward the heavens calling on the holy power.\n"+
         "In a brilliant flash the blade rips through the minion of evil\n"+
         "with the wrath of God.\n");
      say("The Holy Avenger becomes a brilliant white and sends the evil\n"+
         "minion back to the gates of hell.\n");
      return 10;
   }
   return 0;
}
query_save_flag() { return 1; }
wield(arg){
   if(arg=="avenger"){
      if(this_player()->query_alignment() < 1299 && this_player()->query_name() != "Protege"){
         write("You are not worthy of this honor.\n");
         return 1;
      }
      if(::wield(arg));
      write("You are blessed by the heavens as the Holy Avenger is grasped.\n");
      say("The Holy light shines on "+capitalize(this_player()->query_real_name())+" as the Holy Avenger is grasped.\n");
      return 1;
   }
   if(arg != "avenger"){
      return;
   }
}
init(){
   ::init();
   add_action("check_kill","kill");
}
check_kill(str){
   if(!present("avenger", this_player())){
      return;  
   }
   ob = present(str,environment(environment(this_object())));
   if(!ob){
      return;
   }
   if(ob->query_alignment() > 100){
      call_other(this_player(),"heal_self", -40 );
      write("The sword quivers in your hand.  Then begins to glow bright white.\n"+
         "In a sudden flash the sword seems to explode.  You feel as if\n"+
         "something has just bitten you and you feel weaker.  The sword\n"+
         "quivers once more, then returns to normal as if nothing happened.\n");
      return 1;}
}
