#include <ansi.h>

int occupied;
object origin, bwm, opp;
string ori;
inherit "room/room";
reset(arg){
  if(arg){ return; }
  set_light(-10);
  set_short(HIK+"[ "+HIC+"Showdown in the Shadow Plane"+HIK+" ]"+NORM);
  set_long(HIK+"This is an intangable pocket of space within the Elemental Plane of Shadow\n"+
                "The Black Willow Order uses these extra-dimensional spaces to battle to the\n"+
                "death. The darkness goes on forever in all directions, yet movement is limited\n"+
                "to a ten foot radius. Two will enter this space, but only one will be leaving.\n");
}

init() {
  ::init();
  occupied = 0;
  set_heart_beat(1);
}  

int query_occupied() {
  return occupied;
}

void set_occupied() {
  occupied = 1;
  return;
}

void set_origin(string obj) {
  origin = find_object(obj);
  if(!origin) origin = clone_object(obj);
  return;
}

void set_combatants(object com1, object com2) {
  bwm = com1;
  opp = com2;
  return;
}

object query_origin() {
  return origin;
}

object * query_combatants() {
  return ({bwm, opp});
}

heart_beat() {
  object corpse;
  if(!present(bwm,this_object()) && !present(opp, this_object())) {
    return;
  }
  else {
    tell_room(this_object(),
	  "BWM = "+bwm->query_name()+"\nOPP = "+opp->query_name()+"\nORIGIN = "+file_name(origin)+"\n");
  }
  if(bwm && opp && !bwm->query_attack() && !bwm->query_ghost() && !opp->query_ghost()) {
    tell_room(this_object(),
	  "A loud voice booms: "+BOLD+"'THE BATTLE MUST CONTINUE!'"+NORM+"\n");
	bwm->attacked_by(opp);
  }
  if(bwm->query_ghost() || opp->query_ghost()) {
    corpse = present("corpse", this_object());
	move_object(bwm, origin);
	move_object(opp, origin);
	if(corpse) {
	  move_object(corpse, origin);
	}
	tell_room(origin,
	  "A large portal of shadows opens!\nA loud voice booms: 'The Showdown is OVER!'\nThe portal closes suddenly!\n");
	destruct(this_object());
	return;
  }
  if(present(bwm, this_object()) && !present(opp, this_object())) {
    move_object(bwm, origin);
    corpse = present("corpse", this_object());
	if(corpse) {
	  move_object(corpse, origin);
	}
	tell_room(origin,
	  "A large portal of shadows opens!\nA loud voice booms: 'The Showdown is OVER!'\nThe portal closes suddenly!\n");
	destruct(this_object());
	return;
  }
  return;
}