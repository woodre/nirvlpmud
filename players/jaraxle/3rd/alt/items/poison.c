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
   
   set_name("orb of poison");
   set_alias("poison orb");
   set_long("A small, rotting, slime covered orb.\n"+
      HIW+"'"+NORM+HIG+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+HIG+"deactivate"+HIW+"'"+NORM+" the orb.\n");
   set_ac(0);
   set_type("orb");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(4000);
}

short(){
   
   return "Orb of "+HIG+"Poison"+NORM+""+(worn_by?" (floating nearby)":""); }

id(str) {
   return str == "poison orb" || str == "orb" || str == "orb of poison";
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
      write("You can "+HIW+"'"+NORM+HIG+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+HIG+"deactivate"+HIW+"'"+NORM+" the orb to use this power.\n");
      return 1; }
}

activate(str){
   if(environment()->is_kid()){
      object room;
      tell_room(room, "The orb refuses the childs will.\n");
      return 1; }
   
   if(id(str)){
      if(!worn){
         write("The orb begins to slowly float to your side.\n");
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
   int i, cast;
   
   switch(random(5)){
      case 0: cast = ""+HIG+"ball of bacteria"+NORM+"";
      break;
      case 1: cast = ""+MAG+"venomous strike"+NORM+"";
      break;
      case 2: cast = ""+HIG+"ball of contamination"+NORM+"";
      break;
      case 3: cast = ""+MAG+"touch of contagion"+NORM+"";
      break;
      case 4: cast = ""+HIG+"septic ball of sludge"+NORM+"";
      break;
   }
   
   i = random(8);
   if(!ATT) return;
   if(i==1){
/*
      if(ATT->is_npc())
         ATT->heal_self(-(1+random(3)));
*/
         ATT->hit_player(random(2)+1, "other|poison");
     if(environment(USER))
     if(ATT && USER) {
      tell_room(environment(USER),
         capitalize(USER->query_name())+" defiles "+capitalize(ATT->query_name())+" with a "+cast+".\n", ({ USER }));
   }
   if(ATT)
      tell_object(USER, "You defile "+capitalize(ATT->query_name())+" with a "+cast+".\n");
      return 0;}
   return 0; }
