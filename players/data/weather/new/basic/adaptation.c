/*
 * /basic/adaptation.c
 *
 * a generic basic class for a value which adapts with the time to a given
 * value (which also can change, e.g. due to changes in the environment).
 * made for the light system.
 *
 * written by Alfe 1999-Jun-06 for Tubmud.
 */

#include <limits.h>
#include <adaptation.h>

inherit "basic/math";

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////  variables  ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*
 * values which define the behaviour of the system, i.e. which are e.g.
 * depending on the race of the living which light-adaptation is modelled.
 */
// time in seconds after which the difference between the current and the
// adaptation value halves:
private float half_life = 1.0;

// the lowest and highest reachable value, due to physical contraints:
private int lower_limit = INT_MIN;
private int upper_limit = INT_MAX;

/*
 * the values to be set by the environment
 */
// the value which "shall" be reached, given enough time:
private int adaptation_goal;

/*
 * internally used changing values
 */
private int value_at_time;
private int time_of_value;

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////  functions  ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*
 * bureaucracy
 */

void set_adaptation_lower_limit(int i) { lower_limit = i; }
void set_adaptation_upper_limit(int i) { upper_limit = i; }

varargs int query_adapting_value(status force_update);

void set_adaptation_half_life(int i) {
  value_at_time = query_adapting_value();
  time_of_value = time();
  half_life = to_float(i);
}

int query_adaptation_lower_limit() { return lower_limit; }
int query_adaptation_upper_limit() { return upper_limit; }
int query_adaptation_half_life()   { return to_int(half_life); }

/*
 * functionality
 */

// we cache the value since its computation is relatively costly (due to the
// floats we use :-( ).  All in a range of +-3 seconds of the last call will
// just query the cache
private static int adapting_value_cache_time;
private static int adapting_value_cache_value;

// this returns the current value of the adapting value.
varargs int query_adapting_value(status force_update) {
  int g;
  if (0 &&  // no, we don't cache.  just ran into problems with it.
      !force_update &&
      time() < adapting_value_cache_time+3 &&
      time() > adapting_value_cache_time-3)
    return adapting_value_cache_value;
  g = adaptation_goal;
  return (adapting_value_cache_value=
          g + to_int((value_at_time - g) *
                     (to_int(half_life) &&
                      pow(0.5,
                          to_float((adapting_value_cache_time=time())-
                                   time_of_value) / half_life))));
}

// call this function each time the goal
// value changes towards which we adapt.
void set_adaptation_goal(int g) {
  g = (g > upper_limit? upper_limit :
       g < lower_limit? lower_limit :
       g);
  if (adaptation_goal == g)  // no change: don't do anything.
    return;
  if (!time_of_value)  // never been set before?
    value_at_time = g;
  else
    value_at_time = query_adapting_value();
  time_of_value = time();
  adaptation_goal = g;
}

// returns the time in seconds you still have to wait until
// the adapting value reaches the given threshold value.
// throws ADAPT_THRESHOLD_NEVER_REACHABLE if the threshold is
// beyond the adaptation_goal.
// CHANGE: ADAPT_THRESHOLD_NEVER_REACHABLE is now returned instead of thrown
//         in this case.  Alfe 2001-Aug-14
mixed get_adaptation_threshold(int th) {
  mixed h;
  int g,result;
  g = adaptation_goal;
#if 1  // Alfe 2001-Aug-14
  h = value_at_time - g;
  if (!h)  // value currently is at its goal?
    if (th == g)  // threshold is current value?
      return 0;  /* we could return _any_ value, but 0 seems reasonable
                  * because it will be interpreted as 'now' which seems
                  * quite ok.
                  */
    else  // different threshold; no change in sight --> never reachable
      return ADAPT_THRESHOLD_NEVER_REACHABLE;
  h = to_float(th-g) / h;
  if (h <= 0)
    return ADAPT_THRESHOLD_NEVER_REACHABLE;
  return time_of_value - time() + to_int(half_life * log(h) / log(0.5));
#else
  if (catch(result = to_int(half_life * log(to_float(th-g) /
                                            (value_at_time-g)) /
                            log(0.5)) + time_of_value - time()))
    throw(ADAPT_THRESHOLD_NEVER_REACHABLE);
  else
    return result;
#endif
}
