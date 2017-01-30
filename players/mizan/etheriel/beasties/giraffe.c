inherit "/players/mizan/core/monster.c";

int head1,head2,head3;
int hps;

reset(arg)
{
   object weapon;
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("three headed giraffe");
   set_race("giraffe");
   set_alias("three headed");
   set_short("A three headed giraffe");
   set_level(10);
   set_hp(150);
   set_al(-100);
   set_wc(14);
   set_ac(8);
   set_aggressive(0);
   gold=clone_object("obj/money");
   gold->set_money(random(30)+100);
   move_object(gold,this_object());
   weapon=clone_object("players/mizan/etheriel/heals/carbo-blast.c");
   move_object(weapon,this_object());
   enable_commands();
}
long(){write("This is a three headed giraffe. It's a really scary looking thing.\n"+extra_long());
}
heart_beat(){
   int dam;
   object attacker,room;
   string attacker_name;
   ::heart_beat();
   hps=this_object()->query_hp();
   room=environment(this_object());
   attacker=this_object()->query_attack();
   if(attacker){
      attacker_name=attacker->query_real_name();
      if(present(attacker_name,environment(this_object()))){
         if(head1 == 0){
            if(1 == random(2)){
               tell_room(room,"The ugly head spits on "+capitalize(attacker_name)+".\n");
               dam=random(7);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The ugly head missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 120){
               head1 = 1;
               tell_room(room,"The ugly head explodes!\n");
               attacker->add_exp(90);
            }
         }
         if(head2 == 0){
            if(1 == random(2)){
               tell_room(room,"The goofy-looking head licks "+capitalize(attacker_name)+".\n");
               dam=random(5);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The goofy-looking head missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 80){
               head2 = 1;
               tell_room(room,"The goofy-looking head is destroyed.\n");
               attacker->add_exp(90);
            }
         }
         if(head3 == 0){
            if(1 == random(2)){
               tell_room(room,"The smelly head bonks "+capitalize(attacker_name)+".\n");
               dam=random(5);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The smelly head missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 40){
               head3 = 1;
               tell_room(room,"The smelly head explodes.\n");
               attacker->add_exp(90);
            }
         }
      }
   }
}
extra_long(){
   string desc1,desc2,desc3,desc4;
   int hp;
   hp=this_object()->query_hp();
   desc1 = "in good shape.";
   desc2 = "in good shape.";
   desc3 = "in good shape.";
   desc4 = "in good shape.";
   if(hp < 150){desc1 = "slightly hurt.";}
   if(hp < 138){desc1 = "somewhat hurt.";}
   if(hp < 125){desc1 = "in bad shape.";}
   if(hp < 120){desc1 = "dead."; desc2 = "slightly hurt.";}
   if(hp < 100){desc2 = "somewhat hurt.";}
   if(hp < 85){desc2 = "in bad shape.";}
   if(hp < 80){desc2 = "dead."; desc3 = "slightly hurt.";}
   if(hp < 60){desc3 = "somewhat hurt.";}
   if(hp < 45){desc3 = "in bad shape.";}
   if(hp < 40){desc3 = "dead."; desc4 = "slightly hurt.";}
   if(hp < 20){desc4 = "somewhat hurt.";}
   if(hp < 8){desc4 = "in bad shape.";}
   if(hp < 5){desc4 = "in very bad shape.";}
   return "The ugly head is "+desc1+"\n"+"The goofy-looking head is "+desc2+"\n"+
"The smelly head is "+desc3+"\n"+"The giraffe's body is "+desc4+"\n";
}
