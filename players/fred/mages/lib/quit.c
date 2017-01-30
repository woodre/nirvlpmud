#include "/players/fred/mages/defs.h"

cmd_quit(){
  msave();
  get_rid_of_it();  
  if(!TP->query_invis() && TP->query_level() < 39)
  cmd_gemote("has left the realm.");
 }

get_rid_of_it(){
 object ob, ghoul, dragon;
 int ghouled, dragoned;
 ob = present("dark_circle", TP);
 ob->set_tele_room("/players/fred/mages/rooms/hall.c");
 ob->ssave();
 ghoul = present("ghoul_obj", ENV(TP));
 dragon = present("dragon_obj", ENV(TP));
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
}
