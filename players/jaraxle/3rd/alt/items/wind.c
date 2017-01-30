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
   
   set_name("orb of wind");
   set_alias("wind orb");
   set_long("A small cyan orb with a spinning tornado in the center.\n"+
      HIW+"'"+NORM+CYN+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+CYN+"deactivate"+HIW+"'"+NORM+" the orb.\n");
   set_ac(0);
   set_type("orb");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(4000);
}

short(){
   
   return "Orb of "+CYN+"Wind"+NORM+""+(worn_by?" (floating nearby)":""); }

id(str) {
   return str == "wind orb" || str == "orb" || str == "orb of wind";
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
      write("You can "+HIW+"'"+NORM+CYN+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+CYN+"deactivate"+HIW+"'"+NORM+" the orb to use this power.\n");
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
      case 0: cast = ""+CYN+"gust of wind"+NORM+"";
      break;
      case 1: cast = ""+HIC+"torrent of air"+NORM+"";
      break;
      case 2: cast = ""+BLU+"maddly spinning tornado"+NORM+"";
      break;
      case 3: cast = ""+HIB+"light breeze of air"+NORM+"";
      break;
      case 4: cast = ""+HIW+"hard push of wind"+NORM+"";
      break;
   }
   
   i = random(8);
   if(!ATT) return;
   if(i==1){
      if(ATT->is_npc())
         ATT->heal_self(-(1+random(3)));
      else ATT->hit_player(random(2)+1, "other|wind");
      tell_room(environment(USER),
         capitalize(USER->query_name())+" hits "+capitalize(ATT->query_name())+" with a "+cast+".\n", ({ USER }));
      tell_object(USER, "You hit "+capitalize(ATT->query_name())+" with a "+cast+".\n");
      return 0;}
   return 0; }
