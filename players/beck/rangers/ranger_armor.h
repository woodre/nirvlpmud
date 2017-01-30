/************************************************************************
*  Power Ranger Guild Armor.                                           *
*  Created by Beck/Russ Warren for Nirvana                             *
*  Last changed 1/6/97                                                 *
************************************************************************/
string name, alias, short_desc, long_desc;
int value, weight;
string type;
int size, save_flag, worn, ac;
object worn_by;
object next;
string info;
int set_ac_flag;
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
void metal_armor_on(){ metal_armor = 1; }
void metal_armor_off(){ metal_armor = 0; }
query_metal_armor(){ return metal_armor; }
 set_ranger_lamp(arg){ ranger_lamp = arg; }
 query_ranger_lamp(){ return ranger_lamp; }
 shield_bonus(ob){
    int prot;
   string name;
   int armor_karate, final;
   string skill, msg;
   object attack;
   attack = (ENV->query_attack())->query_name();
   prot = 0;
   name = capitalize(ENV->query_real_name());
   if(karate_level > random(15)){
      add_skill_practice(1);
      skill = query_defense();
      prot += MASTER->use_defense(skill);
      msg = MASTER->show_defense(skill,name,attack,"");
      tell_object(ENV, "[ "+BOLD+BLUE+"DEFENSE"+OFF+" ] "+msg+"\n");
      if(karate_level > random(20)){
	 add_skill_practice(2);
	 skill = query_defense();
	 msg = MASTER->show_defense(skill,name,attack,"");
	 prot += MASTER->use_defense(skill);
	 tell_object(ENV, "[ "+BOLD+BLUE+"DEFENSE"+OFF+" ] "+msg+"\n");
	 if(karate_level > random(25)){
	    add_skill_practice(3);
	    skill = query_defense();
	    msg = MASTER->show_defense(skill,name,attack,"");
	    prot += MASTER->use_defense(skill);
	    tell_object(ENV, "[ "+BOLD+BLUE+"DEFENSE"+OFF+" ] "+msg+"\n");
	 }
      }
   }
   if(morphed){ prot += 4; }
   if(metal_armor){
      if(MASTER->query_power_points() > 2){
	 add_skill_practice(2);
	 tell_object(ENV, "[ "+BOLD+BLUE+"DEFENSE"+OFF+" ] "+"Your Armor flashes as it absorbs some damage."+"\n");
	 MASTER->add_power_points(-2);
	 prot += 2;
      }
   }
   if(endurance > random(30)){
      tell_object(ENV, "[ "+BOLD+BLUE+"DEFENSE"+OFF+" ] "+"Your whole body seems to feel a little better."+"\n");
      ENV->add_hit_point(endurance);
   }
   armor_karate = random(karate_level);
   final = speed+armor_karate+prot;
   if(ENV->query_real_name() == "jazz"){
    tell_object(ENV,"DEFENSE BONUS: "+final+"\n");
   }
   return final;
}
