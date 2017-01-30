/************************************************************************
*  The Power Ranger Guild Weapon                                        *
*  Created by Beck/Russ Warren for Nirvana                              * 
*  Last Changed 12/15/97                                                 *
*************************************************************************/
static status wielded;
static object wielded_by;
static int broke;
static int eff_wc;
static int misses,hits;
static int class_of_weapon;
static object hit_func;
/* Duplicate with rangerarmor, isn't used here, ld not like -Bp
static string type;
static int save_flag;
*/
static string *message_hit;
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

QPowerWeapon(){
   return PowerWeapon;
}
PowerWeapon(){
   if(!PowerWeapon){
      if(!Morphed){
         write("You can only use your Power Weapon when Morphed.\n");
         return 1;
      }
      PowerWeapon = 1;
      tell_room(ENVTP, CAPNAME+" yells: Power "+RangerWeapon+"!\n");
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
   string name, attacker;
   string skill; string msg;
   hits = 0;misses = 0;damage = 6;
   name = capitalize(ENVOB->query_real_name());
   attacker = (ENVOB->query_attack())->query_name();
   if(Morphed){ damage += 7; }
   if(Ninja){ damage += 3; }
   if(PowerWeapon){
      if(MASTER->QPowerPoints() > 2){
         tell_object(ENVOB, "[ "+BOLD+RED+"WEAPON"+OFF+" ] You strike "+attacker+" with your Power "+RangerWeapon+"\n");
         damage +=2;
         MASTER->APowerPoints(-2);
         ASkillExp(2);
      }
   }
   if(KarateLevel > random(15)){
      skill = RandomOffense();
      damage += MASTER->use_offense(skill);
      msg = MASTER->show_offense(skill,name,attacker);
      tell_object(ENVOB, "[ "+RED+"OFFENSE"+OFF+" ] "+msg+"\n");
      AMartialExp(1);
      if(KarateLevel > random(20)){
         skill = RandomOffense();
         damage += MASTER->use_offense(skill);
         msg = MASTER->show_offense(skill,name,attacker);
         tell_object(ENVOB, "[ "+RED+"OFFENSE"+OFF+" ] "+msg+"\n");
         AMartialExp(3);
         if(KarateLevel > random(25)){
            enemyhp = (ENVOB->query_attack())->query_hp();
            enemymhp = (ENVOB->query_attack())->query_mhp();
            enemyper = (enemyhp * 100)/enemymhp;
            if(enemyper < 15 && enemyhp < 40){
               damage += enemyhp;
               tell_object(ENVOB, "[ "+BOLD+RED+"FATAL"+OFF+" ] You finish "+attacker+" off with a deadly blow\n");
               AMartialExp(5);
            }
            else {damage -=2; }
         }
      }
   }
   ACombatExp(damage);
   damage += KarateLevel;
   damage += ((ENVOB->GLEVEL)/5);
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
   if(tmp < 35) { mess = ({message_hit[1], message_hit[0]}); }
   if (tmp < 30) { mess = ({message_hit[3],message_hit[2]}); }
   if (tmp < 25) { mess = ({"","laid the "+GREEN+"Smack"+OFF+" down on"}); }
   if (tmp < 20) { mess = ({message_hit[5],message_hit[4]}); }
   if (tmp < 15) { 
      mess = ({" with a brilliant display of martial arts","stunned"}); }
   if (tmp < 10) { mess = ({message_hit[7],message_hit[6]}); }
   if (tmp < 5) { mess = ({"","beat up"});}
   if (tmp < 3) { mess = ({" with a weak attack","grazed"}); }
   if (tmp == 1) { mess = ({message_hit[13],message_hit[12]});}
   return mess;
}
check_ranger_kill(str){
   object ob;
   ob = present(str, environment(this_player()));
   if(!ob){ return; }
   if(Morphed){
      if(ob->query_alignment() > 10){
         write("You can not bring yourself to attack that riteous being.\n");
         ASkillExp(-20);
         ACombatExp(-20);
         return 1;
      }
   }
   if(ob->RangerNPC()){
      write("Zordon tells you: You better not kill fellow Power Rangers!!!\n");
      return 1;
   }
   return;
}

