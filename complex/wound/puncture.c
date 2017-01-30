/****************************************************************************
      puncture.c -- written by Alfe, Chameloid and Ugh for Tubmud
****************************************************************************/

// ATTENTION: This file is still in work and will probably still change a lot
// in the nearer future. Please don't use it in your code, yet

#include <combat.h>
#include <message.h>

inherit "complex/wound";

static void
bearer_weakened() {
  object bearer,bodypart;
  bearer = query_bearer();
  bodypart = get_compound();
  send_message(({ M_ROOM,environment(bearer),M_ME_THE," on ",M_S,bearer,
                  M_NONE,bodypart,M_ME_VERB,"bleed",". ",M_TARGETS,bearer,
                  "You feel weaker." }));
  move_object(clone_object(BLOOD),bearer);
}

static void
wound_healed() {
  object bearer,bodypart;
  bearer = query_bearer();
  bodypart = get_compound();
  send_message(({ M_ROOM,environment(bearer),M_ME_THE," on ",M_S,bearer,
                  M_NONE,bodypart,M_ME_VERB,"heal","." }));
}

static void
wound_healing() {
  object bearer,bodypart;
  bearer = query_bearer();
  bodypart = get_compound();
  send_message(({ M_TARGETS,bearer,M_ME_THE," on your ",M_NONE,bodypart,
                  M_ME_VERB,"grow"," smaller." }));
}

static void
wound_inflicted() {
  object bearer,bodypart;
  bearer = query_bearer();
  bodypart = get_compound();
  send_message(({ M_ROOM,environment(bearer),M_ME," on ",M_S,bearer,M_NONE,
                  bodypart,M_ME_VERB,"start"," to bleed. ",M_TARGETS,
                  bearer,"You feel weaker." }));
  move_object(clone_object(BLOOD),bearer);
}

static void
wound_stopped() {
  object bearer,bodypart;
  bearer = query_bearer();
  bodypart = get_compound();
  send_message(({ M_ROOM,environment(bearer),M_ME_THE," on ",M_S,bearer,
                  M_NONE,bodypart,M_ME_VERB,"stop"," to bleed." }));
}

string
puncture_long() {
  return message2string(({ M_CAPITALIZE,M_S,query_bearer()," suffered ",
                           M_SIMPLE_DESCRIBE,M_ME,". The flesh is not much "
                           "hurt, still ",M_ME_PRONOUN,M_ME_VERB,"are",
                           " bleeding.\n" }));
}

void
configure() {
  wound::configure();
  set_wound_type("puncture");
  set_id(({ "puncture","wound" }));
  set_long(#'puncture_long);
}  
