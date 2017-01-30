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
   
   set_name("orb of steel");
   set_alias("armor orb");
   set_long("This looks like a very simple orb.  A high polished aluminum \n"+
            "sphere that reflects your face in a warped shape as you gaze\n"+
            "studiously into it.  To use its properties you may "+HIW+"'"+NORM+BOLD+"activate"+HIW+"'"+NORM+"\n"+
            "and "+HIW+"'"+NORM+BOLD+"deactivate"+HIW+"'"+NORM+" the orb.\n");
   set_ac(1);
   set_type("orb"); 
   set_weight(0);
   set_value(7000);
}

short(){
 
   return "Orb of "+BOLD+"Steel"+NORM+""+(worn_by?" "+HIW+"("+NORM+"floating nearby"+HIW+")"+NORM+"":""); }

id(str) {
   return str == "armor orb" || str == "orb" || str == "orb of steel";
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
      write("You can "+HIW+"'"+NORM+BOLD+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+BOLD+"deactivate"+HIW+"'"+NORM+" the orb to use this power.\n");
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

