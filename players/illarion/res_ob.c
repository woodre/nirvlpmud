#include "../def.h"
/*
 * Resurrection object for healers
 * Adapted from Rump's dopp res object
 */

object user, targ;
int str;

int id(string str) { return str == "healer_rez_object"; }

extra_look() { 
  if(environment() && environment()->query_ghost()) {
    if(this_player() == environment()) 
      return "You are surrounded by a globe of light"; 
    else
      return "This ghost is surrounded by a globe of light"; 
  }
}

void reset(int arg) {
  if (arg) return;
}

int start_res(object u, object t, int s) {
  if(!u || !t || !s) {
    destruct(this_object());
    return 0;
  }
  user = u;
  targ = t;
  str = s;

  tell_object(targ,
              user->query_name() + " has cast a resurrection spell on you.\n"+
              "To accept, type \"res_accept\" - To decline, type " +
              "\"res_decline\"\n"+
              "You have 30 seconds to decide.\n");
  call_out("no_decision", 30);
}

void init() {
  add_action("rez_func", "res_accept");
  add_action("rez_func", "res_decline");
}

void res_off() {
  tell_object(targ, "The globe of light surrounding you winks out.\n");
  tell_room(environment(targ), 
    "The globe of light around "+capitalize((string)targ->query_real_name())+" winks out.\n", ({targ}));
}

int rez_func() {
  if (query_verb() == "res_accept") {
    if(targ && targ->query_ghost()) {
      if(user)
        tell_object(user, targ->query_name() + " accepted your resurrection.\n");
        tell_object(targ, format("The globe of light surrounding you collapses, then explodes outward in a brilliant, blinding flash!\n"));
        tell_room(environment(targ), format(
"The globe of light surrounding "+capitalize((string)targ->query_real_name())+"'s ghost collapses, then explodes outward in a brilliant, blinding flash!\n"), ({targ}));
      targ->remove_ghost_finish();
      if(str) {
        targ->heal_self(str * 2);
        if(user) {
          call_other(POWER, "add_res_exp", user, str);
        }
      }
    }
  } else if (query_verb() == "res_decline") {
    if(user)
      tell_object(user, targ->query_name() + " declined your resurrection.\n");
    if(targ) {
      tell_object(targ, "Resurrection Declined.\n");
      res_off();
    }
  }
  while(find_call_out("no_decision") != -1)
    remove_call_out("no_decision");
  destruct(this_object());
  return 1;
}

int no_decision() {
  if(targ) {
    res_off();
    if(user)
      tell_object(user, "Resurrection on " + targ->query_name() +
                  " has timed out.\n");
  }
  destruct(this_object());
  return 1;
}

