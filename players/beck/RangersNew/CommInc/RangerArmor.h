/************************************************************************
*  Power Ranger Guild Armor.                                           *
*  Created by Beck/Russ Warren for Nirvana                             *
*  Last changed 6/13/99                                                 *
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
armor_class() { return ac; }
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



shield_bonus(ob){
   mixed *skills;
   string skill, msg, name, attack;
   int i;
   int prot;
   prot = 2;  /* AC of 2 for everyone */
   name = capitalize(ENVOB->query_real_name());
   if(ENVOB->query_attack()){
      attack = (ENVOB->query_attack())->query_name();
   }
   else {
      attack = "Enemy";
   }
   
   if(Morphed){ prot += 2; }  /* AC 2 for being morphed.  */

   for(i=0; i<sizeof(DefSkills); i++){
       prot += ("/players/"+QuerySkillWiz(DefSkills[i])+"/Rangers/Commands/"+capitalize(DefSkills[i])+".c")->DefSkill(QuerySkillLevel(DefSkills[i]));
   } 

   

   prot += (1*(ENVOB->GLEVEL)/15);
   if(prot < 0) prot = 0;
   if(prot > 24) prot = 24; /* Changed 6/13/99 -Ap by Snow */

   
   return prot;
}

