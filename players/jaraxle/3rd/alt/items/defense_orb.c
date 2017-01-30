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
   
   set_name("prismatic stronghold");
   set_alias("stronghold");
   set_long("This orb is shaped into a large triangle.  In the center\n"+
      "of the orb a swirling square of "+BLK+BOLD+"solid"+NORM+" and "+HIC+" fortitude"+NORM+"\n"+
      "spins effortlessly.  To use its properties you can\n"+
      HIC+"'"+BLK+"activate"+HIC+"'"+NORM+" and "+HIC+"'"+BLK+"deactivate"+HIC+"'"+NORM+" the orb.\n");
   set_ac(0);
   set_type("orb"); 
   set_weight(0);
   set_value(7000);
}

short(){
   return HIC+"Prismatic "+BLK+BOLD+"Stronghold"+NORM+""+(worn_by?" "+BLK+BOLD+"("+NORM+CYN+"floating nearby"+BLK+BOLD+")"+NORM+"":""); 
}

id(str) {
   return str == "defense orb" || str == "orb" || str == "orb of defense";
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
      tell_room(environment(USER),
         HIC+"Prismatic "+BLK+BOLD+"Stronghold"+NORM+" wraps itself around "+capitalize(USER->query_name())+" shielding some of the blow.\n", ({ USER }));
     tell_object(USER, HIC+"Prismatic "+BLK+BOLD+"Stronghold"+NORM+" wraps itself around you, shielding some of the blow.\n");
      return 2+random(5);}
   return 0; }
