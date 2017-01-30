/************************************************************************
*  Dark Ranger Guild Armor.                                           *
*  Created by Beck/Russ Warren for Nirvana                             *
*  Last changed 1/6/97                                                 *
************************************************************************/
static string name, alias, short_desc, long_desc;
static int value, weight;
static string type;
static int size, save_flag, worn, ac;
static object worn_by;
static object next;
static string info;
static int set_ac_flag;
link(ob){ next = ob;}
remove_link(str){
   object ob;
   
   if (str == name) {
      ob = next;
      next = 0;
      return ob;
   }
   if (next)
      next = call_other(next, "remove_link", str);
   return this_object();
}


rec_short()
{
   if(next)
      return name + ", " + call_other(next, "rec_short");
   return name;
}


test_type(str)
{
   if(str == type)
      return this_object();
   if(next)
      return call_other(next, "test_type", str);
   return 0;
}

tot_ac()
{
   if(next)
      return ac + call_other(next, "tot_ac");
   return ac;
}

query_type() { return type; }
query_worn() { return worn; }
query_name() { return name; }
armor_class() { return ac; }
query_weight() { return weight; }
set_weight(w) { weight = w; }
set_ac(a) { ac = a; 
   set_ac_flag = 7; }
set_type(t) {
   if (ac > 0 || !set_ac_flag) {
      if (t !="armor" && t !="helmet" && t != "boots" && t != "ring" && t !="amulet" && t != "shield" && t != "misc") 
         destruct (this_object());
   }
   type = t;
}
set_arm_light(l) { set_light(l); }
query_paladin_shield(){ return 1; }
QMetallicArmor(){
   return MetallicArmor;
}
MetallicArmor(){
   if(!MetallicArmor){
      if(!Morphed){
         write("You can only use your Metallic Armor when Morphed.\n");
         return 1;
      }
      MetallicArmor = 1;
      tell_room(ENVTP, TPNAME+" yells: Metallic Armor, Power Up!\n");
      return 1;
   }
   MetallicArmor = 0;
   write("You Power down your Metallic Armor.\n");
   return 1;
}
QHelmetLamp(){ return HelmetLamp; }
SHelmetLamp(){
   if(!Morphed){
      write("You need to be morphed to use this.\n");
      return 1;
   }
   if(!HelmetLamp){
      HelmetLamp = 1;
      set_arm_light(2);
      tell_room(ENVTP,TPNAME+"'s Helmet begins to emit a bright beacon of light.\n");
      return 1;
   }
   HelmetLamp = 0;
   set_arm_light(-2);
   tell_room(ENVTP,TPNAME+"'s Helmet stops emitting light.\n");
   return 1;
}
shield_bonus(ob){
   mixed *skills;
   string skill, msg, name, attack;
   int prot;
   prot = 4;
   name = capitalize(ENVOB->query_real_name());
   if(ENVOB->query_attack()){
      attack = (ENVOB->query_attack())->query_name();
   }
   else {
      attack = "Enemy";
   }
   if(KarateLevel > random(15)){
      skill = RandomDefense();
      skills = MASTER->UseMartialArts(skill);
      prot += skills[0];
      msg = name+skills[1]+attack+skills[2];
      if(!Spam)
         tell_object(ENVOB, "[ "+BOLD+BLUE+"DEFENSE"+OFF+" ] "+msg+"\n");
      AMartialExp(1);
      if(KarateLevel > random(20)){
         skill = RandomDefense();
         skills = MASTER->UseMartialArts(skill);
         prot += skills[0];
         msg = name+skills[1]+attack+skills[2];
         if(!Spam)
            tell_object(ENVOB, "[ "+BOLD+BLUE+"DEFENSE"+OFF+" ] "+msg+"\n");
         AMartialExp(3);
      }
   }
   if(Morphed){ prot += 2; }
   if(Ninja){ prot += 1; }
   if(MetallicArmor){
      if(MASTER->QPowerPoints() > 2){
         prot += 1;
         ASkillExp(3);
         tell_object(ENVOB, "[ "+BOLD+BLUE+"METALLIC ARMOR"+OFF+" ] "+"Your Armor flashes as it absorbs some damage\n");
         MASTER->APowerPoints(-2);
      }
   }
   ACombatExp(prot);
   prot += random(KarateLevel);
   prot += ((ENVOB->GLEVEL)/10);
/* Temporary until armor is changed -Snow */
  if(prot > 12) prot = 12;  /* Max ac of 12 */
   if(random(10*KarateLevel) < 1){ 
      tell_room(ENV(ENVOB),"\n"+name+" is hit squarely in the chest by "+attack+".\n"+
         "There is a huge explosion as "+name+" is thrown back "+random(300)+" feet.\n\n");
      prot = 0;
   }
   return prot;
}
RandomDefense(){
   int i;
   i = sizeof(Defense);
   i = random(i);
   return Defense[i];
}
