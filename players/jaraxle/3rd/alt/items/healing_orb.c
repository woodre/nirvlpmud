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
   
   set_name("hand of asclepius");
   set_alias("hand");
set_long("A triangular shaped box radiates with an enchanted glow.\n"+
         "This is the Hand of "+BLU+"Asclepius"+NORM+", a special orb forged from\n"+
"the mithril of Third Earth.  To use it's properties\n"+
HIW+"'"+NORM+BLU+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+BLU+"deactivate"+HIW+"'"+NORM+" the orb.\n");
   set_ac(0);
   set_type("orb");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(7000);
}

short(){
   switch(random(3)){
      case 0: change_color = ""+HIC+"";
      break;
      case 1: change_color = ""+HIY+"";
      break;
      case 2: change_color = ""+HIW+"";
      break;
   }
   return "Hand of "+BLU+"Asclepius"+NORM+""+(worn_by?" "+change_color+"("+NORM+HIB+"floating nearby"+NORM+change_color+")"+NORM+"":""); }

id(str) {
   return str == "healing orb" || str == "orb" || str == "orb of healing"
   || str == "hand of asclepius" || str == "hand";
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
   int i, cast, damage;
   
   i = random(8);
   if(!ATT) return;
   if(i==1){
/*
     WTF????

      if(ATT->is_npc())
         USER->heal_self(1+random(5));
      else USER->add_hp(random(5));
*/
    USER->add_hp(random(3));
      tell_room(environment(USER),
         capitalize(USER->query_name())+" is surrounded by a healing "+HIM+"aura"+NORM+".\n", ({ USER }));
      tell_object(USER, "A "+HIM+"purple haze"+NORM+" washes over you momentarily.\n");
      return 0;}
   return 0; }
