object RealAttack;
status InFight;
string Fatality;
int time;
int hp_new;
int hp_old;
int WC, AC, RES;

query_player_shell(){ return 1; }
Target(){ return this_object(); }

heart_beat() {

   if(!environment(this_object())) return;

   set_hbflag("hbstayon");

   ::heart_beat();

   if(this_object()->query_attack()){
      if(!hp_old)
         hp_old = hit_point;
      hp_new = this_object()->query_hp() - hp_old;
      hp_old = this_object()->query_hp();


      if((this_object()->query_attack())->query_hp() < 50) {
         InFight = 0;
         return 1;
      }
   }
}

Reset(){
   set_level(25);
   set_hp(1000);
   set_al(0);
   set_wc(35);
   RegisterArmor(this_object(),({"physical",0,0,"armor_special_physical"}));
   InFight = 0;
   move_object(clone_object("/players/dragnar/MKScar/scar.c"),this_object());
   set_dead_ob(this_object());
}

set_ac(){
   return;
}

armor_special_physical(){
   int total_ac;

   if(hp_new > -10)
      heal_self(10);

   RES = 10 + (hp_new/10);

   if(random(7) == 5)
      RES += random(70);

   if(RES < 0)
      RES = 0;
   total_ac = RES*100;
   
   AC = hit_point/50;
   AC += 20 + (hp_new/10);

   total_ac += AC; 
   return total_ac; 
  
}

monster_died(){
   destruct(present("corpse",environment(this_object())));
   return 0;
}

heal_self(amt){
   if(amt < 0){
      amt = amt/2;
      say(name+" takes a hard blow, licks the blood, and smiles.\n");
   }
   ::heal_self(amt);
}


