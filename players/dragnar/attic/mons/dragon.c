inherit "obj/monster";

#define LOG "/players/dragnar/logs/MONS_DEATH"

int head1,head2,head3;
int hps;
 
reset(arg){
   object weapon;
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("shardik");
   set_race("dragon");
   set_gender("creature");
   set_alias("shardik");
	set_short("Shardik, Keeper of the portal");
   set_level(20);
	set_hp(random(200)+1300);
   set_al(-100);
   set_wc(45);
   set_ac(17);
   set_dead_ob(this_object());
   gold=clone_object("obj/money");
   gold->set_money(random(4000)+190);
   move_object(gold,this_object());
   enable_commands();
   set_heart_beat(1);
}
long() {
	write("Shardik is a black, three headed dragon.  He is the biggest creature\n"+
"you have ever seen.  Even in his deep slumber he looks dangerous.\n");
}

monster_died() {
    say("The portal pulses with a deep blue light.\n");
    write_file(LOG, ctime(time())+" "+
    query_attack()->query_real_name()+" killed Shardik.\n");
}
heart_beat(){
   int dam;
	object attacker,room,dragon,ob;
	string idstr;
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
               tell_room(room,"The head of electricity shoots some static at "+capitalize(attacker_name)+".\n");
               dam=random(10);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The head of electricity missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 1000){
               head1 = 1;
               tell_room(room,"The head of electricity screams and dies!\n");
               attacker->add_exp(70);
            }
         }
         if(head2 == 0){
            if(1 == random(2)){
               tell_room(room,"The head of frost shoots a ball of ice at "+capitalize(attacker_name)+".\n");
               dam=random(10);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The head of frost missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 600){
               head2 = 1;
               tell_room(room,"The head of frost whines piteously and dies.\n");
               attacker->add_exp(50);
            }
         }
         if(head3 == 0){
            if(1 == random(2)){
               tell_room(room,"The head of fire shoots flames at "+capitalize(attacker_name)+".\n");
               dam=random(10);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"The head of fire missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 200){
               head3 = 1;
               tell_room(room,"The head of fire smoulders and dies!\n");
               attacker->add_exp(80);
            }
         }
      }
   }
}
