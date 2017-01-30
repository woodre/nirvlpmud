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
   
   set_name("orb of honor");
   set_alias("honor orb");
   set_long("A small diamond shaped orb with a holy glow around it.\n"+
      HIW+"'"+NORM+WHT+BOLD+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+WHT+BOLD+"deactivate"+HIW+"'"+NORM+" the orb.\n");
   set_ac(0);
   set_type("orb");  
   set_weight(0);
   set_value(4000);
   set_params("other|good", 2, 30, "do_good_special");
   /* 2 ac, 30% resistance to other|good damage, */
}

short(){
   
   return "Orb of "+WHT+BOLD+"Honor"+NORM+""+(worn_by?" (floating nearby)":""); }

id(str) {
   return str == "honor orb" || str == "orb" || str == "orb of honor";
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
      write("You can "+HIW+"'"+NORM+WHT+BOLD+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+WHT+BOLD+"deactivate"+HIW+"'"+NORM+" the orb to use this power.\n");
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
      case 0: cast = ""+WHT+BOLD+"beam of faith"+NORM+"";
      break;
      case 1: cast = ""+BOLD+"divine ball of good"+NORM+"";
      break;
      case 2: cast = ""+WHT+BOLD+"will of good"+NORM+"";
      break;
      case 3: cast = ""+BOLD+"strike of good"+NORM+"";
      break;
      case 4: cast = ""+WHT+BOLD+"force of righteousness"+NORM+"";
      break;
   }
   
   i = random(8);
   if(!ATT) return;
   if(i==1){
       ATT->hit_player(random(2)+1, "other|good");
      tell_room(environment(USER),
         capitalize(USER->query_name())+" blesses "+capitalize(ATT->query_name())+" with a "+cast+".\n", ({ USER }));
      tell_object(USER, "You bless "+capitalize(ATT->query_name())+" with a "+cast+".\n");
      return 0;}
   return 0; }
do_good_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         The Orb of Good glows a bright white as it absorbs some of the\n"+
         "\tgood damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
