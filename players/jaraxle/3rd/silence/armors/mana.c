#include "/players/jaraxle/define.h"
#define USER environment(this_object())
#define ATT USER->query_attack()
inherit "obj/armor";
int change_color;

set_type(string str){
   type = str;
}


object ob;
int tmp, num;


reset(arg) {
   ::reset(arg);
   
   set_name("orb of mana");
   set_alias("mana orb");
   set_long(HIW+"Nature's "+HIG+"Blessing"+NORM+" is a powerful orb shaped from the\n"+
      "essence of nature.  You can "+HIW+"'"+HIG+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+HIG+"deactivate"+HIW+"'"+NORM+"\n"+
      "the orb to use this power.\n");
   set_ac(1);
   set_type("orb");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(4000);
}

short(){
   switch(random(3)){
      case 0: change_color = ""+HIC+"";
      break;
      case 1: change_color = ""+HIY+"";
      break;
      case 2: change_color = ""+HIM+"";
      break;
   }
   return "Orb of "+MAG+"Mana"+NORM+""+(worn_by?" "+change_color+"("+NORM+MAG+"floating nearby"+NORM+change_color+")"+NORM+"":""); }

id(str) {
   return str == "mana orb" || str == "orb" || str == "orb of mana";
}

query_worn() { return worn; }
query_type() { return type; }
query_save_flag(){ return 1; }

init(){
   ::init();
   
   add_action("wear_it","wear");
   add_action("wear_it","remove");
   add_action("activate","activate");
   add_action("deactivate","deactivate");
}

wear_it(str){
   if(id(str)){
      write("You can "+HIW+"'"+NORM+MAG+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+MAG+"deactivate"+HIW+"'"+NORM+" the orb to use this power.\n");
      return 1; }
}

activate(str){
   if(environment()->is_kid()){
      object room;
      tell_room(room, "The orb refuses the childs will.\n");
      return 1; }
   
   if(id(str)){
      if(!worn){
         write("The orb slowly floats to your side.\n");
         present(str, this_player())->wear(str);
         return 1; }
      return 0; }
}

deactivate(str){
   if(id(str)){
      if(worn){
         write("The orb slowly sinks back into your hand.\n");
         present(str, this_player())->remove(str);
         return 1; }
      return 0; }
}

do_special(owner) {
   int i, cast, damage;
   
   switch(random(5)){
      case 0: cast = ""+HIB+"splash of water"+NORM+"";
      damage = ""+HIB+"drowned"+NORM+"";
      break;
      case 1: cast = ""+HIR+"lick of flame"+NORM+"";
      damage = ""+HIR+"burned"+NORM+"";
      break;
      case 2: cast = ""+BLK+BOLD+"giant bolder"+NORM+"";
      damage = ""+YEL+"smashed"+NORM+"";
      break;
      case 3: cast = ""+CYN+"gust of wind"+NORM+"";
      damage = ""+HIC+"suffocated"+NORM+"";
      break;
      case 4: cast = ""+HIY+"jolt of "+HIW+"electrictity"+NORM+"";
      damage = ""+HIY+"zapped"+NORM+"";
      break;
   }
   
   i = random(8);
   if(!ATT) return;
   if(i==1){
      if(ATT->is_npc())
         USER->add_spell_point(1+random(5));
         else USER->add_spell_point(random(5));
      tell_room(environment(USER),
         capitalize(USER->query_name())+" is "+damage+" with a "+cast+" from "+HIW+"Natures "+HIG+"Blessing"+NORM+"!\n");
      return 0;}
   return 0; }
