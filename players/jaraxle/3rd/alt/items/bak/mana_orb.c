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
   set_long("This orb is shaped into a small square.  Upon further examination\n"+
            "you see a small creature, motionless and inprisoned forever in the\n"+
            "center of the orb.  To use its properties you can "+HIW+"'"+NORM+MAG+"activate"+HIW+"'"+NORM+" and\n"+
            ""+HIW+"'"+NORM+MAG+"deactivate"+HIW+"'"+NORM+" the orb.\n");
   set_ac(0);
   set_type("orb"); 
   set_weight(0);
   set_value(7000);
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
   return ""+MAG+"Breath"+HIW+" of"+NORM+MAG+" Souls"+NORM+""+(worn_by?" "+change_color+"("+NORM+MAG+"floating nearby"+NORM+change_color+")"+NORM+"":""); }

id(str) {
   return str == "breath of souls" || str == "orb" || str == "souls";
}

query_worn() { return worn; }
query_type() { return type; }
query_save_flag(){ return 0; }

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
   
 
   
   i = random(8);
   if(!ATT) return;
   if(i==1){
/*
      if(ATT->is_npc())
         USER->add_spell_point(1+random(5));
*/
            USER->add_spell_point(random(3));
     tell_room(environment(USER),
         capitalize(USER->query_name())+" is surrounded by an "+HIM+"aura"+NORM+" of magic.\n", ({ USER }));
     tell_object(USER, "A "+HIM+"magical aura"+NORM+" spills from the Orb over your body.\n");
      return 0;}
   return 0; }
