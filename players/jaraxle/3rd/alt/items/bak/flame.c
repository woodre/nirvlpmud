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
   
   set_name("orb of flame");
   set_alias("flame orb");
   set_long("A small red orb with a flickering flame in the center.\n"+
      HIW+"'"+NORM+RED+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+RED+"deactivate"+HIW+"'"+NORM+" the orb.\n");
   set_ac(0);
   set_type("orb");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(4000);
   set_params("other|fire", 2, 30, "do_fire_special");
   /* 2 ac, 30% resistance to other|fire damage, */
}

short(){
   
   return "Orb of "+RED+"Flame"+NORM+""+(worn_by?" (floating nearby)":""); }

id(str) {
   return str == "flame orb" || str == "orb" || str == "orb of flame";
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
      write("You can "+HIW+"'"+NORM+RED+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+RED+"deactivate"+HIW+"'"+NORM+" the orb to use this power.\n");
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
      case 0: cast = ""+RED+"whip of fire"+NORM+"";
      break;
      case 1: cast = ""+HIR+"lick of flame"+NORM+"";
      break;
      case 2: cast = ""+RED+"spark of fire"+NORM+"";
      break;
      case 3: cast = ""+YEL+"spit of flame"+NORM+"";
      break;
      case 4: cast = ""+HIY+"ball of fire"+NORM+"";
      break;
   }
   
   i = random(8);
   if(!ATT) return;
   if(i==1){
/*
      if(ATT->is_npc())
         ATT->heal_self(-(1+random(3)));
*/
       ATT->hit_player(random(2)+1, "other|fire");
       if(ATT)
      tell_room(environment(USER),
         capitalize(USER->query_name())+" burns  "+capitalize(ATT->query_name())+" with a "+cast+".\n", ({ USER }));
     if(ATT)

      tell_object(USER, "You burn "+capitalize(ATT->query_name())+" with a "+cast+".\n");
      return 0;}
   return 0; }
do_fire_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         The Orb of Flame glows a bright red as it absorbs some of the\n"+
         "\tfire damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
