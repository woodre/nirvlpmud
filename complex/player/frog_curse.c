#include <filter.h>
#include <event.h>
#include <describe.h>
#include <wizlevels.h>
#include <kernel.h>
#include <message.h>
#include <filters.h>  // Coogan, 18-Aug-98

inherit "complex/player/reshape";

string modify_shout_message(string msg) {
  return " Hriibit! Hrriiibit!";
}

string modify_say_in_messages(string verb) {
  return "croak";
}

void react_on_feeling(mapping e) {
  if (e[E_FEELING] == "kiss" &&  // kissing?
      member(e[E_PERSONS], environment()) >= 0) {  // kissing us?
    // next checks by Coogan, 18-Aug-98
    // changed all call_out()s of 0 to 1 sec, Coogan, 19-Aug-98
    if (environment(e[E_AGENT]) != environment(environment())) {
      // the player tries a remote kiss and turns into a frog
      call_out(#'move_object, 1, clone_object(FROG_MARK), e[E_AGENT]);
    }
    else if (environment()->query_always_frog()) {
      call_out(#'move_object, 1, clone_object(FROG_MARK), e[E_AGENT]);
    }
    else {
      call_out(#'move_object, 1, this_object(), e[E_AGENT]);
      e[E_AGENT]->add_visit(); /* replaced this_player() by e[E_AGENT],
                                  Coogan, 18-Aug-98 */
    }
  }
}

string query_stay_invisible_msg(status on_apply) {
  if (on_apply)
    return "You suddenly feel like a big frog but you are still invisible.\n";
  else  // on unapply
    return ("You suddenly don't feel like a big frog anymore but"
            " you are still invisible.\n");
}

void turn_into_frog(object who) {   apply_reshape(who); }  // compat
void         defrog(object who) { unapply_reshape(who); }  // compat

string query_shape_short(string original_short) { return "a big frog"; }
string query_shape_name( string original_name)  { return   "big frog"; }

string *query_shape_id(string *original_id) {
  return original_id + ({ "frog", "big frog" });
}

private static string *prince = 
  ({ "royal person", "prince", "princess", "lot of princes or princesses" });

string query_shape_long(string original_long) {
  return ("A strange looking frog you imagine being a really nice " +
          prince[environment()->query_gender()] + ".\n"
          "Maybe you should try and kiss it ...\n");
}

int query_shape_gender(int original_gender) {
  return 0;  // frogs are neuter. Coogan, 07-Aug-2002
}

mixed query_shape_mmout(mixed original_mmout) {
  return ({ M_THE, M_ARG, E_AGENT, M_VERB, "croak", E_AGENT,
            " in surprise and ", M_VERB, "disappear", E_AGENT,
            " in a puff of legs." });
}

mixed query_shape_mmin( mixed original_mmin ) {
  return ({ M_ARG, E_AGENT, M_VERB, "appear", E_AGENT,
            " in a puff of legs." });
}

mixed query_shape_mout( mixed original_mout ) {
  return ({ M_THE, M_ARG, E_AGENT, M_VERB, "hop", E_AGENT, " ", M_ARG,
            E_DIR, "." });
}

mixed query_shape_min(  mixed original_min  ) {
  return ({ M_ARG, E_AGENT, M_VERB, "hop", E_AGENT, " in." });
}

mixed do_shape_filter(string func, mixed arg) {
  switch (func) {
  case F_STR: 
    return -8;   // 9->8, Carador, 14-Dec-97, as money weighs something
  case F_NO_ARTICLE:
  case F_TITLE:
  case F_PRETITLE:
  case F_AL_TITLE:
    return 0;
  default:
    return reshape::do_shape_filter(func, arg);
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

