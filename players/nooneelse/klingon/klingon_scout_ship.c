/*
 klingon_scout_ship.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "obj/treasure";

string str;

init() {
/*@@@@@@@@@@@@
  add_action("microphone"); add_xverb("");
@@@@@@@@@@@@@*/
  enable_commands();
}

microphone(str) {
  object aux_bridge;
  aux_bridge=find_object(KLINGON_AUX_BRIDGE);
  if (!aux_bridge) return;
  tell_room(aux_bridge, "\nThe screen flickers and snaps, but you see:\n\n"+
            str+"\n");
  return;
}

catch_tell(str){
  string action_str;
  object aux_bridge;
  aux_bridge=find_object(KLINGON_AUX_BRIDGE);
  if (!aux_bridge) return;
  if(sscanf(str, "%s", action_str)==1){
    tell_room(aux_bridge, "\nThe screen flickers and snaps, but you see:\n\n"+
              str+"\n");
    return;
  }
}

reset(arg) {
  if (arg) return;

  set_light(1);
  set_short("A dark gray, Klingon scout ship");
  set_long(
    "A dark gray, Klingon scout ship is hovering above you on flickering\n"+
    "anti-grav beams.  The sight of it's gaping torpedo launch tubes and\n"+
    "glaring phaser projectors is fearsome!\n");
  set_weight(999);
}

move_ship(str) {
  object peeker_obj, new_environment, old_environment, aux_bridge, stuff_obj;
  if (!str) return;
  old_environment=environment(this_object());
  peeker_obj=clone_object("players/nooneelse/obj/peeker");
  move_object(peeker_obj, old_environment);
  peeker_obj->init_command(str);
  new_environment=environment(peeker_obj);
  destruct(peeker_obj);
  aux_bridge=find_object(KLINGON_AUX_BRIDGE);
  if (!aux_bridge) return;
  if (new_environment==old_environment) {
    tell_room(aux_bridge,
              "The computer beeps and says:\n"+
              "   Helm not responding!  The ship cannot fly "+str+
              ", First Officer.\n");
    return 1;
  }
  tell_room(new_environment,
            "Dust and debris fly around as the braking jets of a\n"+
            "Klingon scout ship flare and the ship hovers above you.\n");
  move_object(this_object(), new_environment);
  tell_room(old_environment,
            "Dust and debris fly around as the manuvering jets of the\n"+
            "Klingon scout ship flare and the ship flys away.\n");
  tell_room(aux_bridge,
            "The computer beeps and says:\n"+
            "   Helm responding.  Setting course "+str+", First Officer.\n\n"+
            "The screen flickers and snaps, but you see:\n\n");
  tell_room(aux_bridge, new_environment->long()+"\n");
  stuff_obj = first_inventory(new_environment);
  while(stuff_obj) {
    if (stuff_obj && stuff_obj->short() && stuff_obj != this_object()) {
      tell_room(aux_bridge, capitalize(stuff_obj->short())+"\n");
    }
    stuff_obj = next_inventory(stuff_obj);
  }
  return 1;
}

self_destruct() {
  tell_room(environment(this_object()),
            "You hear a high pitched whine, that seems to be comming\n"+
            "from the Klingon ship.  All of a sudden, claxxons start\n"+
            "blaring and sirens scream!\n\n");
  tell_room(environment(this_object()),
            "Suddenly, the ship explodes!  The heat was so intense,\n"+
            "that not a scrap remains!\n\n");
  return 1;
}

id(str) { return (str=="klingon scout ship" ||
                  str=="klingon ship" ||
                  str=="scout ship" ||
                  str=="ship"); }
