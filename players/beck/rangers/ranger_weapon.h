/************************************************************************
*  The Power Ranger Guild Weapon                                        *
*  Created by Beck/Russ Warren for Nirvana                              * 
*  Last Changed 2/15/97                                                 *
*************************************************************************/
status wielded;
object wielded_by;
int broke;
int eff_wc;
int misses,hits;
int save_flag,class_of_weapon;
object hit_func;
string type;
string *message_hit;
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
   int wear;
   wear = 3*misses/2 + 4*hits/9;
  return wear;
}
add_wear(arg) {
   misses += 2*arg/3;
   hits += 9*arg/4;
}
fix_weapon() {
   if (!broke) {
     return 0;
   }
  broke = 0;
  misses = misses/2;
  set_class(3*class_of_weapon);
  hits = hits/3;
  write("The weapon has been fixed.\n");
  return 1;
  }
re_break() { 
   broke = 1;
   set_class(class_of_weapon/3);
  return 1;
 }

query_broke(){return broke;}

void metal_weapon_on(){ metal_weapon = 1;}
void metal_weapon_off(){ metal_weapon = 0; }
int query_metal_weapon(){ return metal_weapon;}
query_pro_weapon(){ return 1;}
 proficiency_hit(ob){
   int weapon_strength,damage,final;
   string name, attacker;
   string skill; string msg;
   hits = 0;misses = 0;damage = 0;final = 0;
   name = capitalize(ENV->query_real_name());
   attacker = (ENV->query_attack())->query_name();
   if(morphed){
      damage += 8;
      if(metal_weapon){
         if(MASTER->query_power_points() > 2){
            damage += 3;
            MASTER->add_power_points(-2);
            tell_object(ENV, "[ "+RED+"OFFENSE"+OFF+" ] "+"Your Power "+ranger_weapon+" glows as you strike your enemy"+"\n");
            add_skill_practice(2);
         }
      }
   }
   if(karate_level > random(15)){
      add_skill_practice(1);
      skill = query_offense();
      damage += MASTER->use_offense(skill);
      msg = MASTER->show_offense(skill,name,attacker);
      tell_object(ENV, "[ "+RED+"OFFENSE"+OFF+" ] "+msg+"\n");
      if(karate_level > random(20)){
         add_skill_practice(2);
         skill = query_offense();
         damage += MASTER->use_offense(skill);
         msg = MASTER->show_offense(skill,name,attacker);
         tell_object(ENV, "[ "+RED+"OFFENSE"+OFF+" ] "+msg+"\n");
         if(karate_level > random(25)){
            add_skill_practice(3);
            skill = query_offense();
            damage += MASTER->use_offense(skill);
            msg = MASTER->show_offense(skill,name,attacker);
            tell_object(ENV, "[ "+RED+"OFFENSE"+OFF+" ] "+msg+"\n");
         }
      }
   }
   weapon_strength = random(strength);
   final =weapon_strength+karate_level+damage;
   if(ENV->query_real_name() == "jazz"){
      tell_object(ENV,"OFFENSE BONUS: "+final+"\n");
   }
   return final;
}

query_message_hit(tmp) {
   string *mess;
   mess = ({message_hit[1],message_hit[0]});
   if (tmp < 30) { mess = ({message_hit[3],message_hit[2]}); }
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
   if(morphed){
      object ob;
      ob = present(str, environment(this_player()));
      if(!ob){ return; }
      if(ob->query_alignment() > 0){
         write("You can not bring yourself to attack that riteous being.\n");
         add_skill_practice(-50);
         return 1;
      }
   }
   return;
} 
