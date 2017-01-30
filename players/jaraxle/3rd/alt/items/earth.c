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
   
   set_name("orb of earth");
   set_alias("earth orb");
   set_long("A small orb made of rock and dirt.\n"+
      HIW+"'"+NORM+HIG+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+HIG+"deactivate"+HIW+"'"+NORM+" the orb.\n");
   set_ac(0);
   set_type("orb");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(4000);
   set_params("other|earth", 2, 30, "do_earth_special");
   /* 2 ac, 30% resistance to other|earth damage, */
}

short(){
   
   return "Orb of "+GRN+"Earth"+NORM+""+(worn_by?" (floating nearby)":""); }

id(str) {
   return str == "earth orb" || str == "orb" || str == "orb of earth";
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
      case 0: cast = ""+GRN+"handful of pebbles"+NORM+"";
      break;
      case 1: cast = ""+YEL+"gust of sand"+NORM+"";
      break;
      case 2: cast = ""+HIG+"heavy rock"+NORM+"";
      break;
      case 3: cast = ""+HIY+"anvil of stone"+NORM+"";
      break;
      case 4: cast = ""+GRN+"collapse of boulders"+NORM+"";
      break;
   }
   
   i = random(8);
   if(!ATT) return;
   if(i==1){
       ATT->hit_player(random(2)+1, "other|earth");
     {
      if(USER && environment(USER) && ATT)
      tell_room(environment(USER),
         capitalize(USER->query_name())+" hits "+capitalize(ATT->query_name())+" with a "+cast+".\n", ({ USER }));
      tell_object(USER, "You hit "+capitalize(ATT->query_name())+" with a "+cast+".\n");
     }
      return 0;}
   return 0; }
do_earth_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         The Orb of Earth glows a dirty brown as it absorbs some of the\n"+
         "\tearth damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
