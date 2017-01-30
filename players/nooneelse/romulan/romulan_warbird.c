/*
 romulan_warbird.c
*/

#include "/players/nooneelse/romulan/romulan_warbird.h"

inherit "obj/treasure";

string str;

init() {
/*@@@@@@@@@@@@
  add_action("microphone"); add_xverb("");
@@@@@@@@@@@@*/
  enable_commands();
}

microphone(str) {
  object bridge;
  bridge=find_object(ROMULAN_BRIDGE);
  if (!bridge) return;
  tell_room(bridge, "\nOn the screen you see:\n\n"+str+"\n");
  return;
}

catch_tell(str){
  string action_str;
  object bridge;
  bridge=find_object(ROMULAN_BRIDGE);
  if (!bridge) return;
  if(sscanf(str, "%s", action_str)==1){
    tell_room(bridge, "\nOn the screen you see:\n\n"+str+"\n");
    return;
  }
}

reset(arg) {
  if (arg) return;

  set_light(1);
  set_short("A dark gray, Romulan Warbird");
  set_long(
    "A dark gray, Romulan Warbird is hovering above you on flickering\n"+
    "anti-grav beams.  The sight of it's gaping torpedo launch tubes and\n"+
    "glaring phaser projectors is fearsome!\n");
  set_weight(999);
}

move_ship(str) {
  object peeker_obj, new_environment, old_environment, bridge, stuff_obj;
  if (!str) return;
  old_environment=environment(this_object());
  peeker_obj=clone_object("players/nooneelse/obj/peeker");
  move_object(peeker_obj, old_environment);
  peeker_obj->init_command(str);
  new_environment=environment(peeker_obj);
  destruct(peeker_obj);
  bridge=find_object(ROMULAN_BRIDGE);
  if (!bridge) return;
  if (new_environment==old_environment) {
    tell_room(bridge,
              "The computer beeps and says:\n"+
              "   Helm not responding!  The Warbird cannot fly "+str+
              ", First Officer.\n");
    return 1;
  }
  tell_room(new_environment,
            "Dust and debris fly around as the braking jets of a\n"+
            "Romulan Warbird flare and the ship hovers above you.\n");
  move_object(this_object(), new_environment);
  tell_room(old_environment,
            "Dust and debris fly around as the manuvering jets of the\n"+
            "Romulan Warbird flare and the ship flys away.\n");
  tell_room(bridge,
            "The computer beeps and says:\n"+
            "   Helm responding.  Setting course "+str+", First Officer.\n\n"+
            "On the screen you see:\n\n");
  tell_room(bridge, new_environment->long()+"\n");
  stuff_obj = first_inventory(new_environment);
  while(stuff_obj) {
    if (stuff_obj && stuff_obj->short() && stuff_obj != this_object()) {
      tell_room(bridge, capitalize(stuff_obj->short())+"\n");
    }
    stuff_obj = next_inventory(stuff_obj);
  }
  return 1;
}

self_destruct() {
  tell_room(environment(this_object()),
            "You hear a high pitched whine, that seems to be comming\n"+
            "from the Romulan Warbird.  All of a sudden, claxxons start\n"+
            "blaring and sirens scream!\n\n");
  tell_room(environment(this_object()),
            "Suddenly, the Warbird explodes!  The heat was so intense,\n"+
            "that not a scrap remains!\n\n");
  return 1;
}

id(str) { return (str=="romulan warbird" ||
                  str=="romulan ship" ||
                  str=="warbird" ||
                  str=="ship"); }
