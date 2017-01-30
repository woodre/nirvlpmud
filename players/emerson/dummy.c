inherit "obj/monster";
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("dummy");
   set_race("dummy");
   set_alias("spell dummy");
   set_short("Dummy");
   set_long("This is a battle dummy that will tell you how hard you hit it. Attacking it\nwith any command that initiates a fight will let you get in two combat turns\nbefore it tells you the accumulated damage and stops the fight.\n");
   set_level(1);
   set_hp(1000);
   set_al(0);
   set_wc(0);
   set_ac(0);
   enable_commands();
   set_heart_beat(1);
}

heart_beat(){
   int hps;
   object attacker;
   hps=this_object()->query_hp();
   attacker= this_object()->query_attack();
    attacker->stop_fight();
   attacker->stop_fight();
   if(attacker){
      say("You just did "+(1000 - hps)+" points of damage.\n");
      say("Your averaged "+((1000 - hps)/2)+" points of damage per attack round.\n");
      }
   this_object()->heal_self(1000);
   attacker->stop_fight();
      this_object()->stop_fight();
   attacker->stop_fight();
   this_object()->stop_fight();
   this_object()->stop_fight();
   attacker->stop_fight();
   attacker->stop_fight();
     this_object()->stop_fight();
   this_object()->stop_fight();
   attacker->stop_fight();
   attacker->stop_fight();
}
