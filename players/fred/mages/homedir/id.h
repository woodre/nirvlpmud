/* duplicating...
   -Bp
#include "/players/fred/mages/defs.h"
*/

id(str){
  if(str=="GI") return 1;
    return (str == "dark_circle" || str == "guild_ob" ||
            str == "dark_sight_object" || str == "robes" ||
            str == "black robes" || str == "generic_wc_bonus");
      }

/*
query_auto_load() {return "/players/fred/mages/gob.c:"; }
*/

drop(){ return 1; }

get(){ return 1; }

short(){
  if(present(ROBES, USER)){
   return BOLD+BLK+"Black Robes"+HIY+" (Spectral) "+NORM+"(worn)"; }
   return BOLD+BLK+"Black Robes"+NORM+" (worn)"; }

long(){
  write("You are wearing the robes of an aspiring Black Circle Adept.\n"+
        "Do 'info' for help on guild abilities.\n"); }

remove_object(){
  get_rid_of();
 }

get_rid_of(){
 object ob, ghoul, dragon;
 object pet;
 int ghouled, dragoned;
 ob = present("dark_circle", TP);
 ob->set_tele_room("/players/fred/mages/rooms/hall.c");
 ob->ssave();
 ghoul = present("ghoul_obj", ENV(TP));
 dragon = present("dragon_obj", ENV(TP));
 pet = present("drakyr", ENV(TP));
 ghouled = query_has_ghoul();
 dragoned = query_has_dragon();
 if(ghouled != 0){
   ob->set_has_ghoul(0);
   ob->ssave();
 }
 if(dragoned != 0){
   ob->set_has_dragon(0);
   ob->ssave();
 }
 if(ghoul && ghoul->query_owner() == TP){
   say("Ghoul digs a grave.\n");
   say("Ghoul jumps in.\n");
   say("Ghoul pulls the dirt in on top of itself.\n");
   destruct(ghoul);
 }
 if(dragon && dragon->query_owner() == TP){
   say("Shadow Dragon says: I return to the Plane of Shadows.\n");
   say("Shadow Dragon flies away into an enveloping cloud of darkness.\n");
   destruct(dragon);
 }
 if(pet && pet->query_summoner() == TP){
   say("The winged Drakyr screeches and flies off into the clouds.\n");
   move_object(pet, "room/void.c");
   destruct(pet);
 }
}
