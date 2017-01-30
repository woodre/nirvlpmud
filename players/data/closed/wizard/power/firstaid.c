

#include "/players/maledicta/closed/w/sdefine.h"

main(string str, object gob, object player)
{ 

int hlvl,cost,bonus;

if(USER->query_ghost()) return 0;


hlvl = GOB->get_skill(50);
cost = hlvl * 8;
 if(!GOB->get_skill(70)){
    if(USER->test_dark()){
      return 1;
      }
     } 
if(USER->query_sp() < cost){
  tell_object(USER, "You are too weak to tend to your wounds.\n");
  return 1;
  }
if(ATT){
  tell_object(USER, "You are too busy fighting!\n");
  return 1;
  }
if(GOB->query_healing()){
   tell_object(USER, "You are already mending your wounds.\n");
   return 1;
   }
if(present("first_aid_kit_prof", USER)){
   tell_object(USER, "You open your FirstAid kit and begin dressing your wounds.\n");
   present("first_aid_kit_prof", USER)->used();
   bonus += hlvl * 4 + random(hlvl * 3);
   }
else if(present("first_aid_bandages_prof", USER)){
   tell_object(USER, "You unroll some fresh bandages and begin dressing your wounds.\n");
   present("first_aid_bandages_prof", USER)->used();
   bonus += hlvl * 2 + random(hlvl * 2);
   }
else{
tell_object(USER,
"\nYou begin tending to your wounds the best you can...\n\n");
}
tell_room(environment(USER),
USERN+" sits down for a moment and begins wrapping "+USER->POS+" wounds.\n", ({USER}));
 GOB->ast(50);
 GOB->ast(50);
 GOB->ast(50);
 GOB->ast(50);
GOB->set_healing(hlvl * 4 + bonus);
GOB->set_heal_room(file_name(environment(USER)));
USER->add_spell_point(-cost);
return 1;
}
