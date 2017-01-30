/************************************************************************
*  The Dark Ranger Guild Weapon                                        *
*  Created by Beck/Russ Warren for Nirvana                              * 
*  Last Changed 8/13/98                                                 *
*************************************************************************/
static status wielded;
static object wielded_by;
static int broke;
static int eff_wc;
static int misses,hits;
static int save_flag,class_of_weapon;
static object hit_func;
static string type;
static string *message_hit;
static object PrevWeapon;
weapon_class() {
   return class_of_weapon;
}
hit(attacker)
{
   if (hit_func)
      return call_other(hit_func,"weapon_hit",attacker);
   return 0;
}
set_class(c) { class_of_weapon = c; }

un_wield(){
   if(Weapon){
      PrevWeapon = Weapon;
      if(!Weapon->query_wielded())
         Weapon = 0;
   }
   call_out("re_wield",2);
}
re_wield(){
   PrevWeapon = 0;
   ENVOB->wield(TO,1);
}
weapon_breaks(){
   if(broke) return 1;
   return 1;
}
count_misses() {
   misses += 1;
   return 1;
}
count_hit_made(w) {
   hits += 1;
   eff_wc=((hits-1)*eff_wc + w)/hits;
   return 1;
}
query_wear() {
   return 0;
}
add_wear(arg) {
   misses = 0;
   hits = 0;
}
fix_weapon() {
   if (!broke) {
      return 0;
   }
   broke = 0;
   return 1;
}
re_break() { 
   broke = 1;
   return 1;
}

query_broke(){return broke;}

SWeapon(ob){
   Weapon = ob;
}
Weapon(){
   return Weapon;
}
SPrevWeapon(ob){
   PrevWeapon = ob;
}
PrevWeapon(){
   return PrevWeapon;
}
QPowerWeapon(){
   return PowerWeapon;
}
PowerWeapon(){
   if(!PowerWeapon){
      if(Weapon){
         write("You are already wielding "+Weapon->query_name()+"\n");
         return 1;
      }
      if(!Morphed){
         write("You can only use your Power Weapon when Morphed.\n");
         return 1;
      }
      PowerWeapon = 1;
      tell_room(ENVTP, TPNAME+" yells: Power "+RangerWeapon+"!\n");
      return 1;
   }
   PowerWeapon = 0;
   write("You put away your Power "+RangerWeapon+".\n");
   return 1;
}
query_pro_weapon(){ return 1;}
proficiency_hit(ob){
   int enemyhp, enemymhp, enemyper;
   int damage;
   int damage2;
   string name, attacker;
   string skill; string msg;
   mixed *skills;
   hits = 0;misses = 0;damage = 5;
   damage2 = 0;
   name = ENVOB->query_name();
   attacker = (ENVOB->query_attack())->query_name();
   if(Morphed){ damage += 7; }
   if(Ninja){ damage += 3; }
   if(PowerWeapon){
      if(MASTER->QPowerPoints() > 2*KarateLevel){
         tell_object(ENVOB, "[ "+BOLD+RED+"WEAPON"+OFF+" ] You strike "+attacker+" with your Power "+RangerWeapon+"\n");
         damage += KarateLevel;
         if(!(ENVOB->query_attack())->is_player())
            damage2 += KarateLevel;
         MASTER->APowerPoints(-2*KarateLevel);
         ASkillExp(2);
      }
   }
   if(Weapon){
      Weapon->weapon_hit(ENVOB->query_attack());
   }
   if(!Weapon){
      if(KarateLevel > random(15)){
         skill = RandomOffense();
         skills = MASTER->UseMartialArts(skill);
         damage += skills[0];
         msg = name+skills[1]+attacker+skills[2];
         if(!Spam)
            tell_object(ENVOB, "[ "+RED+"OFFENSE"+OFF+" ] "+msg+"\n");
         AMartialExp(1);
         if(KarateLevel > random(20)){
            skill = RandomOffense();
            skills = MASTER->UseMartialArts(skill);
            damage += skills[0];
            msg = name+skills[1]+attacker+skills[2];
            if(!Spam)
               tell_object(ENVOB, "[ "+RED+"OFFENSE"+OFF+" ] "+msg+"\n");
            AMartialExp(3);
            if(KarateLevel > random(25)){
               enemyhp = (ENVOB->query_attack())->query_hp();
               enemymhp = (ENVOB->query_attack())->query_mhp();
               enemyper = (enemyhp * 100)/enemymhp;
               if(enemyper < 15 && enemyhp < 40){
                  damage2 += enemyhp;
                  tell_object(ENVOB, "[ "+BOLD+RED+"FATAL"+OFF+" ] You finish "+attacker+" off with a deadly blow\n");
                  AMartialExp(5);
               }
               else {damage -=2; }
            }
         }
      }
   }
   ACombatExp(damage);
   damage += KarateLevel;
   damage2 += (KarateExtraLevel/2);
   damage += ((ENVOB->GLEVEL)/5);
   ENVOB->set_spell_dam(damage2);
   if(damage > 40) damage = 40;
   if(damage+damage2 > 50){
      damage = 50 - damage2;
   }
   if(damage > 30) damage = 20+random(15);
   return damage;
}

RandomOffense(){
   int i;
   i = sizeof(Offense);
   i = random(i);
   return Offense[i];
}
query_message_hit(tmp) {
   string *mess;
   mess = ({" with hurricane force",BLINK+RED+"DISEMBOWELED"+OFF});
   if (tmp < 35) { mess = ({" with deadly precision",BOLD+RED+"GORED"+OFF}); }
   if (tmp < 32) { mess = ({" to small fragments","massacre"}); }
   if (tmp < 28) { mess = ({" with a bone crushing sound","smashed"}); }
   if (tmp < 25) { mess = ({"","laid the "+GREEN+"Smack"+OFF+" down on"}); }
   if (tmp < 20) { mess = ({" very hard","hit"}); }
   if (tmp < 18) { mess = ({" with reckless abandon","went off on"}); }
   if (tmp < 15) { 
      mess = ({" with a brilliant display of martial arts","stunned"}); }
   if (tmp < 10) { mess = ({"","hit"}); }
   if (tmp < 5) { mess = ({"","beat up"});}
   if (tmp < 3) { mess = ({" with a weak attack","grazed"}); }
   if (tmp == 1) { mess = ({" in the stomach","tickled"});}
   return mess;
}
check_ranger_kill(str){
   object ob;
   ob = present(str, environment(this_player()));
   if(!ob){ return; }
   if(Morphed){
      if(ob->query_alignment() < -750){
         write("You should be ridding the forces of good instead.\n");
         ASkillExp(-20);
         ACombatExp(-20);
         return 1;
      }
   }
   if(ob->DarkRangerNPC()){
      write("Zordon tells you: You better not kill fellow Dark Rangers!!!\n");
      return 1;
   }
   return;
}

