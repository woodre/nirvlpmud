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
   
   set_name("orb of water");
   set_alias("water orb");
   set_long("A small blue orb with a droplet of water in the center.\n"+
      HIW+"'"+NORM+BLU+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+BLU+"deactivate"+HIW+"'"+NORM+" the orb.\n");
   set_ac(0);
   set_type("orb");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(4000);
}

short(){
   
   return "Orb of "+BLU+"Water"+NORM+""+(worn_by?" (floating nearby)":""); }

id(str) {
   return str == "water orb" || str == "orb" || str == "orb of water";
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
      write("You can "+HIW+"'"+NORM+BLU+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+BLU+"deactivate"+HIW+"'"+NORM+" the orb to use this power.\n");
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
      case 0: cast = ""+CYN+"spray of water"+NORM+"";
      break;
      case 1: cast = ""+HIC+"splash of water"+NORM+"";
      break;
      case 2: cast = ""+BLU+"wave of water"+NORM+"";
      break;
      case 3: cast = ""+HIB+"shower of rain"+NORM+"";
      break;
      case 4: cast = ""+HIW+"ball of water"+NORM+"";
      break;
   }
   
   i = random(8);
   if(!ATT) return;
   if(i==1){
      tell_room(environment(USER),
         capitalize(USER->query_name())+" wets  "+capitalize(ATT->query_name())+" with a "+cast+".\n", ({ USER }));
      tell_object(USER, "You wet "+capitalize(ATT->query_name())+" with a "+cast+".\n");
/* moved damage to after emote so no error would be caused by target death
  - illarion 5 dec 2004 */
      if(ATT->is_npc())
         ATT->heal_self(-(1+random(3)));
      else ATT->hit_player(random(2)+1, "other|water");
      return 0;}
   return 0; }
