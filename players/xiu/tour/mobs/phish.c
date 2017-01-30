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
 set_name("phish");
  set_race("human");
set_alias("band");
set_short("Phish, the band");
 set_level(12);
 set_hp(2500);
   set_al(-1000);
   set_wc(40);
   set_ac(40);
   gold=clone_object("obj/money");
 gold->set_money(random(6000)+20000);
   move_object(gold,this_object());
   enable_commands();
   
}

long()
{
write("The hippy jam band, Phish. \n Most of the members are present and relaxing.\n"+extra_long());
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
tell_room(room,"Trey throws a punch at "+capitalize(attacker_name)+".\n");
 dam=random(20);
               attacker->hit_player(dam);
            }
            else {
tell_room(room,"Trey missed "+capitalize(attacker_name)+".\n");
            }
if(this_object()->query_hp() < 1500){
               head1 = 1;
tell_room(room,"Trey falls over, dead.\n");
attacker->add_exp(1000);
            }
         }

         if(head2 == 0){
            if(1 == random(3)){
 tell_room(room,"Mike bitchslaps "+capitalize(attacker_name)+".\n");
dam=random(15);
               attacker->hit_player(dam);
            }
            else {
 tell_room(room,"Mike missed "+capitalize(attacker_name)+".\n");
            }
if(this_object()->query_hp() < 800){
               head2 = 1;
tell_room(room,"Mike keels over, clutching his chest.\n");
 attacker->add_exp(1000);
            }
         }

         if(head3 == 0){
            if(1 == random(3)){
tell_room(room,"Jon runs at and kicks "+capitalize(attacker_name)+".\n");
dam=random(20);
               attacker->hit_player(dam);
            }
            else {
tell_room(room,"Jon missed "+capitalize(attacker_name)+".\n");
            }
if(this_object()->query_hp() < 650){
               head3 = 1;
tell_room(room,"Jeff squirts blood all over and crumples to the ground.\n");
attacker->add_exp(1000);
            }
         }

         if(head4 == 0){
            if(1 == random(2)){
 tell_room(room,"Jeff scratches "+capitalize(attacker_name)+".\n");
dam=random(25);
               attacker->hit_player(dam);
            }
            else {
  tell_room(room,"Jeff bats at and misses "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 1000){
               head4 = 1;
tell_room(room,"Jeff spits out blood and slumps down, dead.\n");
attacker->add_exp(1000);
            }
         }

         if(head5 == 0){
            if(1 == random(2)){
     tell_room(room,"Mark aggressively pushes "+capitalize(attacker_name)+".\n");
   dam=random(30);
               attacker->hit_player(dam);
            }
            else {
 tell_room(room,"Mark charges but misses "+capitalize(attacker_name)+".\n");
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
command("south");
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
 if(hp < 2900){desc1 = "slightly hurt.";}
 if(hp < 2500){desc1 = "somewhat hurt.";}
if(hp < 1800){desc1 = "in bad shape.";}
if(hp < 1500){desc1 = "dead."; desc2 = "slightly hurt.";}
if(hp < 1400){desc2 = "somewhat hurt.";}
if(hp < 1200){desc2 = "in bad shape.";}
if(hp < 1000){desc2 = "dead."; desc3 = "slightly hurt.";}
 if(hp < 900){desc3 = "somewhat hurt.";}
if(hp < 800){desc3 = "in bad shape.";}
if(hp < 700){desc3 = "dead."; desc4 = "slightly hurt.";}
if(hp < 675){desc4 = "somewhat hurt.";}
if(hp < 650){desc4 = "in bad shape.";}
if(hp < 600){desc4 = "dead"; desc5 = "slightly hurt.";}
if(hp <  500){desc5 = "somewhat hurt.";}
if(hp <  250){desc5 = "somewhat hurt.";}
if(hp <  100){desc5 = "in very bad shape.";}
return "Trey is "+desc1+"\n"+"Mike is "+desc2+"\n"+
"Jon is "+desc3+"\n"+"Jeff is "+desc4+"\n"+"Marc is "+desc5+"\n";
}
