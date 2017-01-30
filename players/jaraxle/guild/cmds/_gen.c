#include "/players/jaraxle/define.h"
object obj;
string att, str1, str2;
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
   
   this_player()->hit_player(0);
   this_player()->add_spell_point(-50);
   if(sscanf(environment(TP)->query_long(), "%sgrass%s", str1, str2) == 2)
      {
      write("SPELL WORKED!\n");
      say("GRASSLAND SPELL!\n");
      obj->hit_player(35);
   }
   else {
      write("Spell worked version2!\n");
      say("NO GRASSLANDS SPELL! [generic spell]\n");
      obj->hit_player(35);
   }
   return 1; }
