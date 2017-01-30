/****************************************************************************
      bruise.c -- written by Alfe, Chameloid and Ugh for Tubmud
****************************************************************************/

// ATTENTION: This file is still in work and will probably still change a lot
// in the nearer future. Please don't use it in your code, yet

#include <message.h>

inherit "complex/wound";

static void
bearer_weakened() {
  object bearer,bodypart;
  bearer = query_bearer();
  bodypart = get_compound();
  send_message(({ M_TARGETS,bearer,M_ME_THE," on your ",M_NONE,bodypart,
                  M_ME_VERB,"ache","." }));
}

static void
wound_healed() {
  object bearer,bodypart;
  bearer = query_bearer();
  bodypart = get_compound();
  send_message(({ M_ROOM,environment(bearer),M_ME_THE," on ",M_S,bearer,
                  M_NONE,bodypart,M_ME_VERB,"vanish","." }));
}

static void
wound_healing() {
  object bearer,bodypart;
  bearer = query_bearer();
  bodypart = get_compound();
  send_message(({ M_TARGETS,bearer,"The ache from ",M_ME_THE," on your ",
                  M_NONE,bodypart," lessens." }));
}

static void
wound_inflicted() {
  object bearer,bodypart;
  bearer = query_bearer();
  bodypart = get_compound();
  send_message(({ M_ROOM,environment(bearer),M_THE,bearer,M_VERB,"get",
                  bearer,M_SIMPLE_DESCRIBE,M_ME," on ",M_POSSESSIVE,bearer,
                  M_NONE,bodypart,". ",
                  M_TARGETS,bearer,M_ME_PRONOUN,M_ME_VERB,"start",
                  " to ache." }));
}

static void
wound_stopped() {
  object bearer,bodypart;
  bearer = query_bearer();
  bodypart = get_compound();
  send_message(({ M_TARGETS,bearer,M_ME_THE," on your ",M_NONE,bodypart,
                  M_ME_VERB,"stop"," to ache." }));
}

string
bruise_long() {
  return message2string(({ "A nasty ",M_ME_NONE,". ",M_CAPITALIZE,M_ME_PRONOUN,
                           " sure ",M_ME_VERB,"ache"," a little.\n" }));
}

void
configure() {
  wound::configure();
  set_wound_type("bruise");
  set_id(({ "bruise","wound" }));
  set_long(#'bruise_long);
}  
