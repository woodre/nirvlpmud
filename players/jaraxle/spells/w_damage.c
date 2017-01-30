inherit "obj/treasure";
#include "defs.h"
#include "/players/jaraxle/ansi.h"
int do_damage;
reset(arg){
   set_weight(0);
   call_out("hurt_me",6);
   call_out("dest_it",60);
}
id(str){ return str == "w_damage" || str == "wind_sigil_damage"; }
set_power(p){ do_damage = p; }

hurt_me()  {
   int chance;
   string chat;
   object ob;
   
   ob = environment(this_object());
   if(!ob) return 1;
   if(!USER->query_attack()){
      tell_room(environment(environment(this_object())), "\t"+HIW+"The winds calm, and whisk through the room."+NORM+"\n");
      destruct(this_object());
      return 1; }
   if(living(ob)) {
      
      
      chance = random(4);
      
      if(chance == 0) chat = "\t"+HIW+"A tornado of winds angrilly choke the life from you!"+NORM+"";
      if(chance == 1) chat = "\t"+HIW+"Winds pummel your body, whipping around you furiously!"+NORM+"";
      if(chance == 2) chat = "\t"+HIW+"An angry gust of wind rips into you!"+NORM+"";
      if(chance == 3) chat = "\t"+HIW+"A gale of wind thrashes around you!"+NORM+"";
      environment(this_object())->add_hit_point(-2+-random(9));
   }
   
   tell_object(ob, chat+".\n");
   tell_room(environment(ob), "Winds angrilly fill the room!\n");
   call_out("hurt_me", 6+random(5));
   return 1;
}
dest_it(){
   tell_room(environment(environment(this_object())), "\t"+HIW+"The winds calm, and whisk through the room."+NORM+"\n");
   destruct(this_object());
   return 1; }
drop(){ return 0; }
get(){ return 0; }
