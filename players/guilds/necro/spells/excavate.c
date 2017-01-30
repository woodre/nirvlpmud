#include "../defs.h"

cmd(str) {

object ob,ob2,ob3;

ob2 = GOB;
ob3 = (present("necro_corpse_check",environment(tp)));

  if(!GOB) return 0;
  if(!GOB->checklev(2,5)) return 1;
  if(str != "corpse"){
    notify_fail("What would you like to excavate?\n");
    return 0;
  }
  if(!present("shovel",tp)){
    notify_fail("You do not have a shovel to dig with.\n");
    return 0;
  }
  if(!(GRAVESITE)){
    notify_fail("You should dig for a corpse in a graveyard.\n");
    return 0;
  }
  if(tp->query_hp() < 5){
    write("You are not healthy enough to excavate.\n");
    return 1;
  }
  tp->add_hit_point(-5);
  if(!random(5)){
    write("You dig but find nothing.\n");
    say(tpn+" digs up some of the dirt.\n");
    return 1;
  }
  if(!ob3){
     ob3 =clone_object(OBJ+"/misc/corpsecheck.c");
     move_object(ob3,environment(tp));
  }
  
  if(ob3->query_corpses() == 0) { 
    write("You dig and conclude there are no more corpses here.\n");
    say(tpn+" digs up some dirt and finds nothing.\n"); 
    return 1;
  }
  write("You dig into the fresh dirt.  As you scoop up a pile you see a dead\n"+
        "hand sticking out of the ground.\n"+
        BOLD+"You've found a corpse!\n"+OFF);
  say(tpn+" digs into the fresh dirt only to discover a dead hand\n"+
      "sticking up from the ground.\n");
  ob = clone_object("obj/corpse.c");
  ob->set_name("an unknown person");
  ob->set_corpse_level(1+random(17));
  ob3->add_corpses(-1);
  move_object(ob,environment(tp));
  tp->add_hit_point(-10);
  if(!random(5)) {
    call_out("raise_spirit",1,tp);  
  }
  return 1; 
} 

raise_spirit(player){
object spirit;
    spirit = clone_object(MON+"/upset_spirit.c");
    spirit->set_stupidplayer(player);
    move_object(spirit,environment(player));
    tell_room(environment(player),"A spirit rises from the ground and wales at its disturber.\n");
}