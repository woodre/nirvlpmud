inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("Genestealer");
   set_race("Alien");
   set_alias("genestealer");
   set_short("A purestrain Genestealer");
   set_long("As you gaze at it's hypnotic eyes you feel at peace with life.\n");
   set_aggressive(1);
   set_level(15);
   set_hp(225);
   set_al(-1000);
   set_wc(16);
   set_ac(6);
   set_chance(40);
   set_spell_dam(20);
   set_spell_mess1("Hmmm. Why is your friend looking so happy and calm?");
   set_spell_mess2("The gaze of the stealer pulls you in for a wet KISS!\n");
   set_chat_chance(12);
   load_chat("Genestealer mumbles: Gaaaze into my eyes! Joooin the coven, brothers and sisters!\n");
   load_chat("Genestealer moans: Let me give you a big KISSSSSSS\n");
   gold=clone_object("obj/money");
   gold->set_money(random(675)+200);
   move_object(gold,this_object());
   set_heart_beat(1);
}
heart_beat(){
   string attacker_name;
   object attacker;
   ::heart_beat();
   attacker=this_object()->query_attack();
   if(attacker){
      attacker_name=attacker->query_real_name();
      if(present(attacker_name,environment(this_object()))){
         if(random(100)<30) {
         say("With dazziling speed the claws rake impossibly fast.\n");
         attacker->hit_player(random(7));
         }
      }
   }
}
