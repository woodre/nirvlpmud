/*
 * basic/decay.c  -  a class for decaying items by Coogan, April 98.
 * some mechanisms changed by Alfe 98-Jun-12
 *
 */

#include <prop/room.h>
#include <temperature.h>

private int decay_rate;
private int decay_stamp;
private int decay_factor;
private int decay_stages;
private string *decay_descriptions = ({ });

status query_decaying() {
  return !!decay_stamp;
}

mixed query_decay_state() {
#if 1 // Coogan, 19-Jun-1999: the items should not decay while the player
      // is absent.
  return ({ decay_rate, time() - decay_stamp, decay_factor });
#else
  return ({ decay_rate, decay_stamp, decay_factor });
#endif
}

void set_decay_state(mixed m) {
#if 1  // Coogan, 19-Jun-1999
  decay_rate   = m[0];
  decay_stamp  = time() - m[1];
  decay_factor = m[2];
#else
  decay_rate   = m[0];
  decay_stamp  = m[1];
  decay_factor = m[2];
#endif
}

static string* query_persistent_variables() {
  return ({ "decay_state", "decay_stages", "decay_descriptions" });
}

int query_decay_rate() {
  return decay_rate;
}

int query_decay_stages() {
  return decay_stages;
}

string* query_decay_descriptions() {
  return decay_descriptions[0..];
}

/*
 * returns the date of the current end of the decaying. this may change
 * of course if the object changes its surroundings.
 */
int query_current_decay_end() {
  if (!decay_stamp)  // Coogan, 13-Jan-2001, added this if()
    return 0x7fffffff;
  else
    return decay_stamp + decay_rate * decay_factor / 1000;
}

/*
 * returns the current decay level as a value 0 .. decay_stages-1
 * (very old .. brand new). returns -1 if no decay rate has been set.
 */
int query_decay_level() {
  mixed h;
  int ds;
  if (query_decay_rate() == 0)
    return -1;
  if (!decay_stamp)  // Coogan, 24-Sep-2003
    return query_decay_stages() - 1;
  ds = query_decay_stages();
  h = to_int((to_float(ds) *
              (time()                    - decay_stamp) /
              (query_current_decay_end() - decay_stamp))) + 1; // subtract at least 1
  if (h > ds)  // Coogan, 23-Jul-1998
    h = ds;
  return ds - h;
}

string query_decay_state_description(status in_output) {
  int s, l;
  l = query_decay_level();
  if (l < 0)  // we don't decay
    return 0;
  if (!(s=sizeof(decay_descriptions)))
    raise_error("No decay descriptions defined\n");
  return decay_descriptions[l];
}

/*
 * returns for any given original value (e.g. the healing rate of a food)
 * the current value, lowered as is appropriate due to decaying process.
 */
static int query_age_factorized(int f) {
  if (query_decay_rate() == 0)
    return f;
  return f * query_decay_level() / (query_decay_stages() - 1);
}

void set_decay_stages(int d) {
  if (d > 1)  // changed 0 to 1, Coogan, 16-Jun-1998
    decay_stages = d;
  else
    raise_error("Bad argument 1 to set_decay_stages()\n");
}

void set_decay_descriptions(string *d) {
  if (sizeof(d) > 1)
    decay_descriptions = d[0..];
}

/*
 * this returns the factor (*1000) created by the current surroundings of
 * this obj which delays or quickens the decaying. *1000 means it returns
 * 1000 as a default. a value of 500 will make the item decay in half the
 * time it normally needs.
 *
 * the implementation in this base class just takes the temperature of the
 * room and returns a factor depending on it. suitable for food, not for
 * everything. overload this function in such a case.
 */
int compute_decay_factor() {
  int t;
  if (t=get_room(this_object())->query_property(P_TEMPERATURE))
    switch (t) {
    case 0..CELSIUS(-10):
      return 100000;  // factor 100 for frozen things
    case CELSIUS(-9)..CELSIUS(0):
      return 10000;  // factor 10 for lightly frozen things
    case CELSIUS(1)..CELSIUS(10):
      return 3000;  // factor 3 for cooled things
    case CELSIUS(11)..CELSIUS(25):
      return 1000;  // this is a normal temperature, factor 1
    case CELSIUS(26)..CELSIUS(40):
      return 500;  // things are rotting twice as fast in the heat
    case CELSIUS(41)..CELSIUS(80):
      return 100;  // ten times as fast if it is really hot
    default:  // nearly boiling or even beyond
      return 1000;  // factor 1 to avoid sudden decay just by putting an
                    // egg into boiling water which is not intended
    }
  else  // no temperature given
    return 1000;  // default
}

/*
 * sets the decay rate anew (a value naming the seconds the object normally
 * has until it is decayed) and refreshes the object to brand new state.
 * it also computes and stores the current decay factor which depends on
 * its surroundings.
 */
void set_decay_rate(int d) {
  if (!clonep() && !environment())  // unused blueprints shouldn't decay
    return;
  if (d > 0)
    decay_rate = d;
  else
    decay_rate = 0;
#if 0  // Coogan, 19-Aug-1998
  decay_stamp = time();
#endif
  decay_factor = compute_decay_factor();
}

/*
 * this is to be called if the any of the influences change and the decay
 * factor must be recalculated.
 */
void update_decay_factor() {
  int new_factor;
  new_factor = compute_decay_factor();
  if (new_factor == decay_factor)  // no change?
    return;
  // We now set the decay_stamp to a different value. With faking a different
  // start time we achieve a correct handling of the decay.
  decay_stamp = time() - (time() - decay_stamp) * decay_factor / new_factor;
  decay_factor = new_factor;
}

/*
 * returns whether the object is decayed or not. if with_destruct is 1,
 * it initiates a destruct in the near future in case the object is
 * decayed.
 */
varargs status query_decayed(status with_destruct) {
  if (!query_decay_rate())  // Coogan, 11-Aug-1998
    return 0;
  if (!query_decaying())  // Coogan, 19-Aug-1998
    return 0;
  if (query_current_decay_end() < time()) {
    if (with_destruct)
      call_out(#'destruct, 0, this_object());
    return 1;
  }
  return 0;
}

status start_decaying(object from, mixed to) {  // Coogan, 19-Aug-1998
  if (!decay_stamp && (from || objectp(to) && find_living_environment(to))) {
    decay_stamp = time();
    return 1;
  }
#if 1  // 0, Coogan, 16-Nov-1998, 1 again, Coogan, 13-Jan-2001
  if (decay_stamp && !from)  // added this part, Coogan, 12-Nov-1998
    decay_stamp = time();
#endif
  return 0;
}

