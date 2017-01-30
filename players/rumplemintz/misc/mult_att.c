inherit "obj/monster";
reset(arg){
   object gold,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("guardian demon");
   set_race("demon");
   set_alias("demon");
   set_short("Guardian Demon");
   set_long("This is the guardian demon of the abyss. You must kill\n"+
      "him to leave this place, or find another way out.\n");
   set_level(22);
   set_hp(600);
   set_al(-1000);
   set_wc(34);
   set_ac(19);
   gold=clone_object("obj/money");
   gold->set_money(random(20)+300);
   move_object(gold,this_object());
   weapon=clone_object("/players/scathe/closed/rod3");
   move_object(weapon,this_object());
   enable_commands();
   set_heart_beat(1);
   set_chance(60);
   set_spell_dam(10+random(30));
   set_spell_mess1("The Guardian demon casts a fireball.");
   set_spell_mess2("The Guardian demon casts a fireball at you.");
}
heart_beat(){
   int dam;
   object attacker,room;
   string attacker_name;
   ::heart_beat();
   room=environment(this_object());
   attacker=this_object()->query_attack();
   if(attacker){
      if(living(attacker)){
         attacker_name=attacker->query_real_name();
         if(present(attacker_name,environment(this_object()))){
            if(attacker->query_ghost() != 1){
               if(1 == random(5)){
                  tell_room(room,"Guardian demon smashed "+capitalize(attacker_name)+" with a bone crushing sound.\n");
                  dam=(20+random(10));
                  attacker->hit_player(dam);
               }
               else {
                  tell_room(room,"Guardian demon missed "+capitalize(attacker_name)+".\n");
               }
            }
            if(attacker->query_ghost() != 1){
               if(1 == random(5)){
                  tell_room(room,"Guardian demon smashed "+capitalize(attacker_name)+" with a bone crushing sound.\n");
                  dam=(20+random(10));
                  attacker->hit_player(dam);
               }
               else {
                  tell_room(room,"Guardian demon missed "+capitalize(attacker_name)+".\n");
               }
            }
            if(attacker->query_ghost() != 1){
               if(1 == random(5)){
                  tell_room(room,"Guardian demon smashed "+capitalize(attacker_name)+" with a bone crushing sound.\n");
                  dam=(20+random(10));
                  attacker->hit_player(dam);
               }
               else {
                  tell_room(room,"Guardian demon missed "+capitalize(attacker_name)+".\n");
               }
            }
            if(attacker->query_ghost() != 1){
               if(1 == random(5)){
                  tell_room(room,"Guardian demon smashed "+capitalize(attacker_name)+" with a bone crushing sound.\n");
                  dam=(20+random(10));
                  attacker->hit_player(dam);
               }
               else {
                  tell_room(room,"Guardian demon missed "+capitalize(attacker_name)+".\n");
               }
            }
            if(attacker->query_ghost() != 1){
              if(1 == random(5)){
                  tell_room(room,"Guardian demon smashed "+capitalize(attacker_name)+" with a bone crushing sound.\n");
                  dam=random(10);
                  attacker->hit_player(dam);
               }
               else {
                  tell_room(room,"Guardian demon missed "+capitalize(attacker_name)+".\n");
               }
            }
         }
      }
   }
}
