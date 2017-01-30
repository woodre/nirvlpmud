/************************************************************************
*  The Power Ranger Guild Weapon                                        *
*  Created by Beck/Russ Warren for Nirvana                              * 
*  Last Changed 3/20/2002                                                *
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
static int damagetmp;



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


SPrevWeapon(ob){
   PrevWeapon = ob;
}
PrevWeapon(){
   return PrevWeapon;
}

query_pro_weapon(){ return 1;}

proficiency_hit(ob){
   int enemyhp, enemymhp, enemyper;
   int damage;
   int damage2;
   int temp;
   int i;
   int result;
   string name, attacker;
   string skill; string msg;
   mixed *skills;
   if(!ENVOB || !ENVOB->query_attack()) return; /* checks by verte 6.6.01 */
   hits = 0;misses = 0;

   damage = (1);

   damage2 = 0;

   name = ENVOB->query_name();
   attacker = (ENVOB->query_attack())->query_name();

   if(QMorphed()){
      temp = QuerySkillLevel("morph");
      for(i=1; i < temp; i++){
         damage += 2;
         result += 1;
         temp -= i;
      }
 /*     damage += QuerySkillLevel("morph") / 4; */
   }

   for(i=0; i<sizeof(OffSkills); i++){
       damage += ("/players/"+QuerySkillWiz(OffSkills[i])+"/Rangers/Commands/"+capitalize(OffSkills[i])+".c")->OffSkill(QuerySkillLevel(OffSkills[i]));
   }   

   if(damage < 0) damage = 0;

   if(damage > 100) damage = 90;

   damage2 = damage / 3;
   damage -= damage2;
   damagetmp = damage2;

   ENVOB->set_spell_dam(damage2); 

   if(damage+damage2 > 100){
      damage = 100-damage2;
   }
 /*  
   if(ENVOB->query_real_name() == "jazz"){
      tell_object(ENVOB, "Damage "+BOLD+RED+damage+" "+damage2+" "+result+OFF+"\n");
   }
   
   if(ENVOB->is_kid()){
      if (damage > 20)
         damage = 20;
   }
*/
   return damage;
}

query_message_hit(tmp) {
   string *mess;
   tmp += damagetmp;
   mess = ({" into ashes", BLINK+BOLD+RED+"<<< E V I S C E R A T E D >>>"+OFF });
   if (tmp < 40) { mess = ({" with hurricane force",BLINK+RED+"DISEMBOWELED"+OFF}); }
   if (tmp < 32) { mess = ({" with deadly precision",BOLD+RED+"GORED"+OFF}); }
   if (tmp < 29) { mess = ({" to small fragments","massacre"}); }
   if (tmp < 25) { mess = ({" with a bone crushing sound","smashed"}); }
   if (tmp < 22) { mess = ({"","laid the "+GREEN+"Smack"+OFF+" down on"}); }
   if (tmp < 19) { mess = ({" very hard","hit"}); }
   if (tmp < 16) { mess = ({" with reckless abandon","went off on"}); }
   if (tmp < 13) { 
      mess = ({" with a brilliant display of martial arts","stunned"}); }
   if (tmp < 10) { mess = ({"","hit"}); }
   if (tmp < 5) { mess = ({"","beat up"});}
   if (tmp < 3) { mess = ({" with a weak attack","grazed"}); }
   if (tmp == 1) { mess = ({" in the stomach","tickled"});}
   return mess;
}


check_ranger_kill(str){
   object ob;
    if(!str) return;
    if(!this_player()) return;
    if(!environment(this_player())) return;
   ob = present(str, environment(this_player()));
   if(!ob){ return; }
   if(RangerAlign == "Power Ranger"){
      if(Morphed){
      if(!ob->is_player() && ob->query_alignment() > 10){
            write("You can not bring yourself to attack that riteous being.\n");
            
            return 1;
         }
         
      }
      if(ob->RangerNPC()){
         write("Zordon tells you: You better not kill fellow Power Rangers!!!\n");
         return 1;
      }
   }
   return;
}

