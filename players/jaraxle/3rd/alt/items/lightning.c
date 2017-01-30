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
   
   set_name("orb of lightning");
   set_alias("lightning orb");
   set_long("A small blue orb which is full of static electricity in the center.\n"+
      HIW+"'"+NORM+HIY+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+HIY+"deactivate"+HIW+"'"+NORM+" the orb.\n");
   set_ac(0);
   set_type("orb");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(4000);
set_params("other|electricity", 2, 30, "do_electricity_special");
   /* 2 ac, 30% resistance to other|electricity damage, */
}

short(){
   
   return "Orb of "+HIY+"Lightning"+NORM+""+(worn_by?" (floating nearby)":""); }

id(str) {
   return str == "lightning orb" || str == "orb" || str == "orb of lightningr";
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
      write("You can "+HIW+"'"+NORM+HIY+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+HIY+"deactivate"+HIW+"'"+NORM+" the orb to use this power.\n");
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
      case 0: cast = ""+HIY+"jolt of electricity"+NORM+"";
      break;
      case 1: cast = ""+YEL+"bolt of lightning"+NORM+"";
      break;
      case 2: cast = ""+HIY+"shock of lightning"+NORM+"";
      break;
      case 3: cast = ""+YEL+"spark of electricity"+NORM+"";
      break;
      case 4: cast = ""+HIW+"ball of static"+NORM+"";
      break;
   }
   
   i = random(8);
   if(!ATT) return;
   if(i==1){
         ATT->hit_player(random(2)+1, "other|electricity");
     if(USER && ATT && environment(USER))
    {
      tell_room(environment(USER),
         capitalize(USER->query_name())+" zaps "+capitalize(ATT->query_name())+" with a "+cast+".\n", ({ USER }));
      tell_object(USER, "You zap "+capitalize(ATT->query_name())+" with a "+cast+".\n");
     }
      return 0;}
   return 0; }

do_electricity_special(object owner)
{
   if(!random(8))
      {
      tell_object(owner, "\
         The Orb of Lightning glows a bright yellow as it absorbs some of the\n"+
         "\telectricity damage.\n");
      return 1504;
      /* 
      15% [15] resistance boost
      4  [04] ac boost 
      */
   }
}
