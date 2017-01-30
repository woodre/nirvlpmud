

#include "/players/guilds/warriors/sdefine.h"

main(string str, object gob, object player)
{ 
object woo;
if(USER->query_ghost()) return 1;

if(!str){
  tell_object(USER, "Study who?\n");
  return 1;
  }
if(GOB->query_assassin() && !USER->query_pl_k()){
      tell_object(USER, "You must be pk.\n");
      return 1;
      }
if(GOB->query_end() < 5){ 
      tell_object(USER, "Your endurance is too low.\n");
      return 1;
      }
if(USER->query_sp() < 20){
   tell_object(USER,
   "You are too weak to concentrate.\n");
   return 1;
   }

woo = present(str, environment(USER));
if(!woo){
  tell_object(USER, "You do not see them present.\n");
  return 1;
  }
if(!living(woo)){
  tell_object(USER, "You can study it, but what good would it do?\n");
  return 1;
  }
if(GOB->query_studied() == woo){
   tell_object(USER, "You are already studying "+str+".\n");
   return 1;
   }

if(random(100) + (GOB->query_skills(101) * 10) + (USER->query_attrib("wil") * 2) <
   woo->query_level() + random(100)){
   tell_object(USER,
   "You fail to find anything significant about "+woo->query_name()+".\n");
   USER->add_spell_point(-20);
   return 1;
   }
GOB->add_end(-5);
USER->add_spell_point(-20);
GOB->set_studied(woo);
tell_object(USER,
"You watch "+capitalize(str)+" very carefully...\n"+
"After a small amount of time, you figure out "+woo->query_possessive()+""+
" strengths\n"+
"and weaknesses.\n");   
return 1;
}

