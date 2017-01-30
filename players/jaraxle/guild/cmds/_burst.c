#include "/players/jaraxle/define.h"
object obj;
string att;
main(str) {
   
   if(!str) {
      obj = TP->query_attack();
      if(!obj) return (write("You must be in combat, or specify a target.\n"), 1);
   }
   if(str) {
      obj = present(str,environment(TP));
      att = str;
   }
   
   
   if(TP->query_sp() < 25){
      write("You do not have enough spell points!\n");
      return 1; }
   
   /*
   if(!str){
      obj = this_player()->query_attack();
      att = obj->query_name();
      return 1; }
   */
   if(!obj){
      write("Burst whom?\n");
      return 1; }
   
   if(!living(obj)){
      write("What?\n");
      return 1; }
   
   obj->hit_player(35);
   this_player()->hit_player(0);
   this_player()->add_spell_point(-50);
   write("Spell worked!\n");
   say("Blah.\n");
   return 1; }
