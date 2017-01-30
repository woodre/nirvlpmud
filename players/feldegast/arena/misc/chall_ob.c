#include "/players/feldegast/arena/melee/def.h"
object challenger;
int *options;
id(arg) {
  return arg=="challenge_ob";
}

init() {
  add_action("accept_challenge","accept_challenge");
  add_action("refuse","refuse");
  call_out("refused_by_default",60);
}
get(str) { return 0; }
drop() { return 1; }
  
set_options(arg) {
  options=arg;
}
set_opponent(ob) {
  challenger=ob;
}
refuse() {
  write("You refuse "+challenger->query_name()+"'s challenge.\n");
  tell_object(challenger,this_player()->query_name()+" has refused your challenge.\n");
  destruct(this_object());
  return 1;
}
enter_arena() {

  object pob1, pob2, arena;

/* Clones a new arena and sets the variables for it. */
  arena=clone_object("/players/feldegast/arena/rooms/arena");
  arena->set_p1(this_player());
  arena->set_p2(challenger);
  arena->set_options(options);

/* Clones arena objects, sets their variables, and moves */
/* them to the players. */
  pob1=clone_object("/players/feldegast/arena/misc/arena_ob");
  pob2=clone_object("/players/feldegast/arena/misc/arena_ob");

  if(options[1]) 
    options[1]=this_player()->query_mhp() - challenger->query_mhp();

  if(options[1] < 0) pob1->set_heal(-options[1]);
  if(options[1] > 0) pob2->set_heal(options[1]);

  move_object(pob1,this_player());
  move_object(pob2,challenger);  

  move_object(this_player(),arena);
  move_object(challenger,arena);

}
/* Am I above stealing my own code?  Obviously, no. */
enter_feldaria() {
  object map;
  object *players;
  object *room_list;
  int i;

  room_list=ROOMS;
  players=({ challenger, TP });

  map=clone_object(PATH+"map.c");
  map->set_players(players);
  map->set_options(options);
  for(i=0; i < sizeof(players); i++)
  {
    move_object(players[i],(object)map->query_room(PATH+ (room_list[random(sizeof(room_list))]) ));
    tell_object(players[i],"Your vision blurs for a moment.  You blink your eyes to clear them.\nWhen you open them again, you see you are somewhere else.\n");
    tell_object(players[i],"You must kill all opponents and leave through the death gate.\n");
  }
  move_object(map,"/players/feldegast/arena/rooms/inner");
  return 1;
}
accept_challenge(string str) {
  if(!challenger) {
    write("That person has left the game.\n");
    destruct(this_object());
    return 1;
  }
  if(environment(environment())->query_in_use()) {
    write("The arena is in use right now.\n");
    return 1;
  }
  if (!str) {
     write("Accept whose challenge?\n");
    return 1;
  }
  if (!environment(environment())->short()=="The Coliseum's Inner Chamber [s]") {    
    write("You must be in the coliseum's inner chamber to do that.");
    return 1;
  }
  if ( !present(challenger,environment(this_player()) ) ) {
    write("He's not here.\n");
    return 1;
  }
  if(options[3]) {
    if(TP->query_pl_k() < 2) {
      write("You must set your spar flag.  Type 'kill_players spar'.\n");
      return 1;
    }
    if(challenger->query_pl_k() < 2) {
      write(challenger->query_name()+" must set "+challenger->query_possessive()+" spar flag.\n");
      tell_object(challenger,"You must set your spar flag.  Type 'kill_players spar'.\n");
      return 1;
    }
  }
  if( lower_case(str)==lower_case(challenger->query_name()) ) {
    tell_object(challenger,
      capitalize(this_player()->query_name())+" has accepted your challenge.\n");
    write("You have accepted "+str+"'s challenge.\n");

    if(options[0]==0)
      enter_arena();
    if(options[0]==1)
      enter_feldaria();
    return 1;

  }
  return 0;
}
refused_by_default() {
  if(this_object()) {
    tell_object(environment(),"Time has expired on the challenge.\n");
    if(challenger)
      tell_object(challenger,"Time has expired on your challenge.\n");
    destruct(this_object());
  }
}
