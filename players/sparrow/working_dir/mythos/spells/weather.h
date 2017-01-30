#include "/players/mythos/closed/guild/def.h"
weather(str) {
int sm;
object ob, ob2;
string name;
write("This spell has been removed due to abuse - Mythos <11-26-1998>\n");
return 1;
if(!str) { write("Usage: weather <type>\n");
write("Types:  storm  blizzard  clear\n"); return 1;}
name = str;
if(qtf < 19) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 150) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 1000) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(name != "storm" && name != "blizzard" && name != "clear") { write("What?\n"); return 1;}
if(name == "storm") {
if(present("storm_ob",environment(tp))) {  
  present("storm_ob",environment(tp))->set_time(qtf); 
  tell_room(environment(tp),"Suddenly, the storm's fury increases!\n");}
  else {
  ob = clone_object("/players/mythos/closed/guild/spells/storm.c");
  ob->set_time(qtf*2);
  ob->set_pcheck(dpp);
  ob->set_growth(3);
  move_object(ob,environment(tp)); 
  tell_room(environment(tp),capitalize(tpn)+" claps "+tp->query_possessive()+
                 " hands together and....."+HIB+
                 "\n\n                   B   O   O   M\n\n"+NORM+
                 "Lightning flashes and thunder booms!\n");}
}
if(name == "blizzard") {
if(present("blizzard",environment(tp))) {  
  present("blizzard",environment(tp))->set_time(qtf); 
  tell_room(environment(tp),"Suddenly, the blizzard's fury increases!\n");
  } else {
  ob = clone_object("/players/mythos/closed/guild/spells/blizzard.c");
  ob->set_time(qtf*3);
  ob->set_pcheck(dpp);
  ob->set_growth(3);
  move_object(ob,environment(tp)); 
  tell_room(environment(tp),capitalize(tpn)+" screams!\n"+
                 "Suddenly....."+HIB+
                 "\n\n                   F  L  A  S  H\n\n"+NORM+
                 "The air is filled with coldfire!\n"+
                 "The wind blows into a fury and ice/snow smashes down upon you!\n"); }
  ob2 = all_inventory(environment(tp));
  for(sm=0;sm<sizeof(ob2);sm++) {
    if(living(ob2[sm])) { 
    move_object(clone_object("/players/mythos/closed/guild/spells/find.c"),ob2[sm]); }
    }
}
if(name == "clear") {
  if(present("weather",environment(tp))) {
  destruct(present("weather",environment(tp))); }
  else {write("The weather is already clear!\n"); return 1;}
  tell_room(environment(tp),capitalize(tpn)+" raises a hand.\n"+
            "A "+CYN+"FLASH"+NORM+" of coldfire and the weather clears!\n");
}
tp->add_spell_point(-150);
pp->add_sacrifice(-1000);
return 1;}
