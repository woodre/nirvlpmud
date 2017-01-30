/*
 * obj/fading_blindness.c -- an object which informs a player who is
 *                           blinded due to eye sigh adaptation for a
 *                           moment, that he can see again.
 *
 * by Alfe for TubMud 2001-Aug-3
 */

#include <event.h>

inherit "basic/create";

void create() {
  create::create();
  listen_event("move",-500);
  listen_event("look",-500);
}

void notify_move() {
  int tts;
  tts = environment()->time_to_sight(1);
#if 0
  DEBUG_POINT("alfe",({tts,
                       environment()->query_darkness_threshold(),
                       environment()->query_adapting_light_level(),
                       environment()->query_brightness_threshold(),
                       query_light_level(environment(environment()))}));
#endif
  if (tts < 0)
    call_out(#'destruct,1,this_object());
  else {
    message("Your eyes slowly adapt ...\n",environment());
    if (tts > 100)
      call_out("notify_owner", tts / 10, 4);
    if (tts > 30)
      call_out("notify_owner", tts / 3,  3);
    if (tts > 10)
      call_out("notify_owner", tts / 2,  2);
    call_out(  "notify_owner", tts + 2,  1);
  }
}

string cmd;

void set_command(string c) { cmd = c; }

void notify_owner(int level) {
  switch (level) {
  case 1:
    message("Slowly your sight clears.\n",environment());
    if (cmd)
      command(cmd,environment());
    destruct(this_object());
    break;
  case 2:
    message("You still cannot see but it definitely gets better...\n",
            environment()); break;
  case 3:
    message("You still cannot see...\n",environment()); break;
  case 4:
    message("You still cannot see and you doubt that it is getting"
            " better...\n",environment()); break;
  default:
    raise_error("Bad level\n");
  }
}

void receive_event(mapping e,string type) {
  switch (type) {
  case "look":
    if (e[E_AGENT] == environment() &&   // owner looks?
        environment()->test_sight(0,1))  // and can see again?
      destruct(this_object());  // forget everything about us.
    break;
  case "move":
    if (e[E_AGENT] == environment())  // owner moves?
      destruct(this_object());        // annihilate all of us
    break;
  }
}
