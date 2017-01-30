#include "/players/guilds/bards/def.h"
#define PLANT "/players/guilds/bards/obj/bardplant.c"
#define COST_DIV 3

/* Creates an item that does poison damage to the target
   every round until the spell ends.
   the cost tops out at 200sp for 30 hits of 1-5 damage
   (30-150, average 90)  
   Only one plant can be present in the room at one time
   
   A storm from "cantrip storm" must be present 
   
   The caster has to remain present and in combat with
   the target or the spell ends.
*/
   

status main(string str) {
  int cost;
  object opp,room,caster,plant;
  int power;
  if(TP->query_spell_dam()) {
    FAIL("You have already cast a spell.\n");
  }
  caster=this_player();
  room=environment(caster); 

  if(!(opp=(object)caster->query_attack()) || !present(opp,room) ) {
    write("You must be fighting to summon the Devil's Snare.\n");
    return 1;
  }

  power=((int)caster->query_level()+1)*((int)caster->query_attrib("wil"))/2;
  power+=((int)caster->query_extra_level())*3;
  cost=power/COST_DIV;
  
  if (attack_spell(-50, 10, cost, opp) == -1)
    return 0;
  if(!present("bard_storm_obj",room))
    FAIL("The Devil's Snare requires a storm to grow.\n");
  if(present("bard_plant_obj",room))
    FAIL("There is already a Devil's Snare plant here.\n");


  write("You play the Song of Growth in harmony with the song of the storm.\n");
  tell_room(room,format(
  NAME(TP)+" plays a tune on "+POSS(TP)+" "+INST+" that harmonizes with "+
  "the song of the storm.\n"),({TP,opp}));
  tell_room(room,format(
  "A thorny green plant grows from the ground almost instantly and twines "+
  "itself around "+NAME(opp)+"!"));

  plant=clone_object(PLANT);
  move_object(plant,room);
  plant->start(opp,caster,power);
  caster->add_spell_point(-cost);

  return 1;
}
