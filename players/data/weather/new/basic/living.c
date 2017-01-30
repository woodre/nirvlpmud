#pragma strong_types                     // Coogan, 08-Jan-1999

#include <event.h>

inherit "basic/filter";
inherit "basic/inventory";
inherit "basic/link";
inherit "basic/property";
nosave variables inherit "basic/cache";  // Alfe 2001-Aug-01
inherit "basic/living/accept";           // Ugh Mar-31-1998
inherit "basic/living/appearance";
inherit "basic/living/carry";            // Carador Aug-1996
inherit "basic/living/colour";           // Coogan, 15-Feb-2001
inherit "basic/living/combat";
inherit "basic/living/concentration";    // Ugh Apr-21-1998
inherit "basic/living/experience";       // Coogan, 07-Dec-1998
inherit "basic/living/extern";           // Ugh Jul-07-1995
inherit "basic/living/flags";            // Coogan, 04-Dec-1998
inherit "basic/living/heart";
inherit "basic/living/magic";            // Mentar 27-Nov-1994
inherit "basic/living/money";
inherit "basic/living/move";             // added by Ugh Jun-14-1995
inherit "basic/living/nutrition";        // Coogan, 16-Jun-1998
inherit "basic/living/offer";            // Alfe 1997-Jul-23
#if 0  // too specialized to be global, Chameloid, 22-Jan-1999
inherit "basic/living/reaction";
#endif
inherit "basic/living/resistance";       // Coogan, 17-May-2001
inherit "basic/living/senses";           // Ugh Mar-30-1996
inherit "basic/living/skill_test";       // Ugh Aug-16-1995
#if 0  // moved to b/l/nutrition, Coogan, 01-Apr-2003
inherit "basic/living/stats";            // Coogan, 07-Dec-1998
#endif
inherit "basic/living/tongue";           // Ugh Feb-21-1996
inherit "basic/living/reference";        // Alfe 2002-Feb-4
virtual inherit "basic/living/skills";  // virtual again, Coogan, 18-Feb-1999

virtual inherit "basic/living/command";  // Ugh Jun-03-1997

void reset(status refresh) {
#ifdef NEW_COMBAT
  combat::reset(refresh);
#endif
  cache::reset(refresh);
}

void create() {
  offer::create();
  senses::create();  // Alfe 2001-Aug-3
  enable_commands();
#ifdef NEW_SKILLS
  skills::initialize_skills();
#endif
}

void configure() {
  appearance::configure();
  command::configure();
#if 0 // Chameloid, 22-Jan-1999
  reaction::configure();
#endif
}

private closure heart_beat_interceptor;

void set_heart_beat_interceptor(closure c) { heart_beat_interceptor = c; }
closure query_heart_beat_interceptor() { return heart_beat_interceptor; }

void original_heart_beat() {
  heart::heart_beat();
  nutrition::heart_beat();    // Coogan, 16-Jun-1998
  combat::heart_beat();
  command::heart_beat();      // Coogan, 08-Jan-1999
  senses::heart_beat();       // Alfe 2001-Sep-11
}

void heart_beat() {
  if (heart_beat_interceptor)
    funcall(heart_beat_interceptor, #'original_heart_beat);
  else
    original_heart_beat();
}

#if 0 // Chameloid, 22-Jan-1999
void init() {
  reaction::init();
}
#endif

status query_busy() {
  return heart::query_busy();
}

//*************** functions for basic/link *******************************

status resists_force(mapping e) {
  /* cheap heuristic */
  if (query_str() > e[E_AGENT]->query_str())
    return 1;
  if (query_dex()/2 > e[E_AGENT]->query_dex())
    return 1;
}

status wont_follow_linked(mapping e) {
  if (query_following(e[E_AGENT]))
    return 0;
  return resists_force(e);
}

void react_move_linked(mapping e) {
  if (wont_follow_linked(e))
    return;
  // This is in case the moving object wants to handle the move of the
  // linked objects, e.g. a horse moves the rider without commanding them
  if (e[E_AGENT]->handle_move_linked(copy(e), this_object()))
    return;

  // default behaviour, command the living to the same command the
  // linked object used
  if (living(this_object()))
    command(e[E_COMMAND], this_object(), 1);
  else
    link::react_move_linked(e);
}

// **************** functions for basic/living/combat *********************

object *get_inventory(string which, string preposition) {
  object *result;

  result = ({ });
  result +=
    inventory::get_inventory(which,preposition) || ({ });
  result +=
    combat::get_inventory(which,preposition) || ({ });
  return result;
}
