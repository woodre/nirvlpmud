inherit "/players/mizan/core/monster.c";
int head1,head2,head3;
int hps;

reset(arg)
{
    object weapon;
    object gold;
    ::reset(arg);
    if(arg) return;
    set_name("baby hydra");
    set_race("dragon");
    set_alias("hydra");
    set_short("A baby hydra");
    set_level(7);
    set_hp(100);
    set_al(-100);
    set_wc(11);
    set_ac(6);
    set_aggressive(0);
    gold=clone_object("obj/money");
    gold->set_money(random(230)+190);
    move_object(gold,this_object());
    enable_commands();
}

long()
{
    write("This is a baby hydra. It's cute, but damn, can it fight!\n" + extra_long());
}

heart_beat()
{
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
               tell_room(room,"The head of electricity spews some static at "+capitalize(attacker_name)+".\n");
               dam=random(5);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The head of electricity missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 75){
               head1 = 1;
               tell_room(room,"The head of electricity screams and dies!\n");
               attacker->add_exp(70);
            }
         }
         if(head2 == 0){
            if(1 == random(2)){
               tell_room(room,"The head of frost shoots an ice cube at "+capitalize(attacker_name)+".\n");
               dam=random(3);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The head of frost missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 50){
               head2 = 1;
               tell_room(room,"The head of frost whines piteously and dies.\n");
               attacker->add_exp(50);
            }
         }
         if(head3 == 0){
            if(1 == random(2)){
               tell_room(room,"The head of fire blows a smoke ring at "+capitalize(attacker_name)+".\n");
               dam=random(4);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The head of fire missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 25){
               head3 = 1;
               tell_room(room,"The head of fire smoulders and dies!\n");
               attacker->add_exp(80);
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
   if(hp < 100){desc1 = "slightly hurt.";}
   if(hp < 92){desc1 = "somewhat hurt.";}
   if(hp < 80){desc1 = "in bad shape.";}
   if(hp < 75){desc1 = "dead."; desc2 = "slightly hurt.";}
   if(hp < 62){desc2 = "somewhat hurt.";}
   if(hp < 55){desc2 = "in bad shape.";}
   if(hp < 50){desc2 = "dead."; desc3 = "slightly hurt.";}
   if(hp < 42){desc3 = "somewhat hurt.";}
   if(hp < 30){desc3 = "in bad shape.";}
   if(hp < 25){desc3 = "dead."; desc4 = "slightly hurt.";}
   if(hp < 15){desc4 = "somewhat hurt.";}
   if(hp < 9){desc4 = "in bad shape.";}
   if(hp < 5){desc4 = "in very bad shape.";}
   return "The head of electricity is "+desc1+"\n"+"The head of frost is "+desc2+"\n"+
"The head of fire is "+desc3+"\n"+"The hydra's body is "+desc4+"\n";
}
