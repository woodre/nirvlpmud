inherit "obj/monster";
int head1,head2,head3,head4,head5;
int hps;

/* Based pretty much on Sweetness' code.
 * Pretty much all of it, that is.
 *
 * This stuff is credited elsewhere though.
 */

reset(arg){
   object weapon;
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("hydra");
   set_race("dragon");
   set_alias("hydra");
   set_short("Hydra");
   set_level(29);
   set_hp(5000);
   set_al(-1000);
   set_wc(44);
   set_ac(40);
   set_aggressive(1);
   gold=clone_object("obj/money");
   gold->set_money(random(6000)+1000);
   move_object(gold,this_object());
   enable_commands();
   
   remove_call_out("make_random_move");
   call_out("make_random_move", 1);
}

long()
{
write("This is a five-headed Hydra.\nOkay. You really should just leave right now.\n"+extra_long());
}

heart_beat()
{
   int dam;
   object attacker,room;
   string attacker_name;

   hps=this_object()->query_hp();
   room=environment(this_object());
   attacker=this_object()->query_attack();

   ::heart_beat();

   if(attacker){
      attacker_name=attacker->query_real_name();
      if(present(attacker_name,environment(this_object()))){
         if(head1 == 0){
            if(1 == random(2)){
               tell_room(room,"The head of electricity slams a lightning bolt at "+capitalize(attacker_name)+".\n");
               dam=random(40);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The head of electricity missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 4000){
               head1 = 1;
               tell_room(room,"The head of electricity is destroyed!\n");
               attacker->add_exp(3000);
            }
         }

         if(head2 == 0){
            if(1 == random(3)){
               tell_room(room,"The head of frost shoots a freezing blast at "+capitalize(attacker_name)+".\n");
               dam=random(40);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The head of frost missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 3000){
               head2 = 1;
               tell_room(room,"The head of frost is destroyed!\n");
               attacker->add_exp(4000);
            }
         }

         if(head3 == 0){
            if(1 == random(3)){
               tell_room(room,"The head of acid belches boiling acid at "+capitalize(attacker_name)+".\n");
               dam=random(45);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The head of acid missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 2000){
               head3 = 1;
               tell_room(room,"The head of acid is destroyed!\n");
               attacker->add_exp(5000);
            }
         }

         if(head4 == 0){
            if(1 == random(2)){
               tell_room(room,"The head of fire blows a blast of flame at "+capitalize(attacker_name)+".\n");
               dam=random(40);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The head of fire missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 1000){
               head4 = 1;
               tell_room(room,"The head of fire is destroyed!\n");
               attacker->add_exp(5000);
            }
         }

         if(head5 == 0){
            if(1 == random(2)){
               tell_room(room,"The head of death spews forth rotten corpses at "+capitalize(attacker_name)+".\n");
               dam=random(45);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The head of death missed "+capitalize(attacker_name)+".\n");
            }
         }
      }
   }
}

hit_player(arg)
{
   if(arg && arg > 60)
      ::hit_player(60);
   else ::hit_player(arg);
}

make_random_move()
{
   int n;

   if(!this_object()->query_attack())
   {
      n = random(6);
      if (n == 0)
      command("up");
      if (n == 1)
      command("down");
      if (n == 2)
      command("south");
      if (n == 3)
      command("north");
      if (n == 4)
      command("west");
      if (n == 5)
      command("east");
   }
   
   remove_call_out("make_random_move");
   call_out("make_random_move", 1);

}


extra_long(){
   string desc1,desc2,desc3,desc4,desc5;
   int hp;
   hp=this_object()->query_hp();
   desc1 = "in good shape.";
   desc2 = "in good shape.";
   desc3 = "in good shape.";
   desc4 = "in good shape.";
   desc5 = "in good shape.";
   if(hp < 5000){desc1 = "slightly hurt.";}
   if(hp < 4500){desc1 = "somewhat hurt.";}
   if(hp < 4250){desc1 = "in bad shape.";}
   if(hp < 4000){desc1 = "dead."; desc2 = "slightly hurt.";}
   if(hp < 3500){desc2 = "somewhat hurt.";}
   if(hp < 3250){desc2 = "in bad shape.";}
   if(hp < 3000){desc2 = "dead."; desc3 = "slightly hurt.";}
   if(hp < 2500){desc3 = "somewhat hurt.";}
   if(hp < 2250){desc3 = "in bad shape.";}
   if(hp < 2000){desc3 = "dead."; desc4 = "slightly hurt.";}
   if(hp < 1500){desc4 = "somewhat hurt.";}
   if(hp < 1250){desc4 = "in bad shape.";}
   if(hp < 1000){desc4 = "dead"; desc5 = "slightly hurt.";}
   if(hp <  500){desc5 = "somewhat hurt.";}
   if(hp <  250){desc5 = "somewhat hurt.";}
   if(hp <  100){desc5 = "in very bad shape.";}
   return "The head of electricity is "+desc1+"\n"+"The head of frost is "+desc2+"\n"+
"The head of acid is "+desc3+"\n"+"The head of fire is "+desc4+"\n"+"The head of death is "+desc5+"\n";
}
