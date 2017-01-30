#pragma strong_types

#include <combat.h>
#include <limits.h>
#include <server.h>

#define TIME 0
#define DURATION 1
#define CALL_ID 2
#define CALL 3
#define ABORT 4

private static int new_call_id, current_time;

private static mixed *schedule;

private status query_schedule_empty() {
  return !(schedule && sizeof(schedule));
}

object get_coordinator() {
  object h;

  catch(h = SE_COMBAT->query_combat_coordinator(this_object()));
  if (h)
    h->start_coordinating(this_object());
  return h;
}

public int get_current_time() {
  return current_time;
}

private void set_current_time(int time) {
  current_time = time;
}

private void add_current_time(int time) {
  set_current_time(get_current_time()+time);
}

private void adjust_time(int new_time) {
  int i, t;

  if (t = new_time - get_current_time()) {
    if (!query_schedule_empty())
      for (i = sizeof(schedule); i--; )
        schedule[i][TIME] += t;
    set_current_time(new_time);
  }
}

public void synchronize(object coordinator) {
  int waiting_until;

  if (!coordinator)
    return;
  waiting_until = coordinator->get_waiting_time(this_object());
  if (sizeof(schedule)) {
    if (waiting_until < 0)
      adjust_time(coordinator->get_current_time());
    if (waiting_until != schedule[0][TIME])
      coordinator->wait_until(schedule[0][TIME],this_object());
  } else if (waiting_until >= 0) { // waiting without schedule?
    coordinator->dont_wait(this_object());
  }
}

private void insert_call_in_schedule(mixed *call) {
  int first, mid, last;

  if (!sizeof(schedule)) {
    schedule = ({call});
  } else { // binary search in sorted list
    first = 0;
    last = sizeof(schedule)-1;
    mid = first+(last-first)/2;
    while (first < last) {
      if (schedule[mid][TIME] < call[TIME])
        first = mid+1;
      else 
        last = mid;
      mid = first+(last-first)/2;
    }
    if (schedule[mid][TIME] > call[TIME]) {
      schedule[mid..mid-1] = ({call});
    } else {
      schedule[mid+1..mid] = ({call});
    }
  }
  synchronize(get_coordinator());
}

private int find_call_in_schedule(mixed call_id) {
  int i;

  if (!query_schedule_empty())
    for (i = sizeof(schedule); i--; )
      if (schedule[i][CALL_ID] == call_id)
        return i;
  return -1;
}

private mixed remove_call_in_schedule(int index) {
  mixed h;

  h = schedule[index];
  schedule[index..index] = ({});
  synchronize(get_coordinator());
  return h;
}

mixed current_call;

private mixed execute_first_call() {
  mixed call;

  call = remove_call_in_schedule(0);
  if (call[CALL] && to_object(call[CALL])) {
    current_call = call;
    with_player(this_object(),#'funcall,call[CALL]);
    current_call = 0;
  }
  return call;
}

void abort_current_call() {
  object caller;

  if (current_call && (caller = to_object(current_call[CALL]))) {
    current_call = 0;
    caller->abort_current_call();
  }
}

public void reach_time(int time) {
  set_current_time(time);
  execute_first_call();
}

private mixed abort_call_in_schedule(int index) {
  mixed call;

  call = remove_call_in_schedule(index);
  if (call[ABORT] && to_object(call[ABORT]))
    with_player(this_object(),#'funcall,call[ABORT]);
  return call;
}

// int -> string, Coogan, 09-Sep-2000
private varargs string get_new_call_id() {
  return object_name()+":"+(++new_call_id);
}

private mixed build_call(int time, mixed call, mixed abort) {
  mixed h;

  h = allocate(5);
  h[TIME] = get_current_time()+time;
  h[DURATION] = time;
  h[CALL_ID] = get_new_call_id();
  h[CALL] = call;
  h[ABORT] = abort;
  return h;
}

varargs mixed schedule_call(int time, mixed call, mixed abort) {
  mixed h;
  object c;

  // are we being coordinated
  if (c = get_coordinator())
    // maybe the 'other' time is running faster
    set_current_time(c->get_current_time());
  h = build_call(time,call,abort);
  insert_call_in_schedule(h);
  return h[CALL_ID];
}

mixed remove_call(mixed call_id) {
  int i;

  if (pointerp(call_id))
    filter(call_id,#'remove_call);
  else if ((i = find_call_in_schedule(call_id)) >= 0)
    return remove_call_in_schedule(i);
}

void abort_call(mixed call_id) {
  int i;
  mixed h;

  if (pointerp(call_id))
    filter(call_id,#'abort_call);
  else if ((i = find_call_in_schedule(call_id)) >= 0)
    abort_call_in_schedule(i);
}

status can_abort_call(mixed call_id) {
  int i;

  if (pointerp(call_id))
    return sizeof(filter(call_id,#'can_abort_call)) == sizeof(call_id);
  else if ((i = find_call_in_schedule(call_id)) < 0 || schedule[i][ABORT])
    return 1;
}

status delay_call(int call_id, int delay) {
  int i;
  mixed h;

  if ((i = find_call_in_schedule(call_id)) >= 0) {
    h = remove_call_in_schedule(i);
    h[TIME] = get_current_time()+h[DURATION]+delay;
    insert_call_in_schedule(h);
    return 1;
  }
}

int get_max_calls_per_heart_beat() {
  return MAX_ACTIONS_PER_HB;
}

int get_next_call_time() {
  return schedule[0][TIME];
}

status handle_heart_beat_error(string error,
                               string program,
                               string current,
                               int line) {
  abort_current_call();
  return 1;
}

void heart_beat() {
  int i, t, max;
  mixed h;
  object c;

  if (!(c = get_coordinator())) {
    i = get_max_calls_per_heart_beat();
    max = get_eval_cost();
    while (!query_schedule_empty() && i &&
           max - get_eval_cost() < USED_EVAL_COST_IN_HB &&
           get_eval_cost() > 100000) {
      if (c = get_coordinator()) {
        synchronize(c);
        break;
      }
      t = get_next_call_time();
      if (t - get_current_time() > 2000) { // delay call?
        add_current_time(2000); // advance the clock
        break;
      } else {
        i--; // one less call this heart-beat
        set_current_time(t);
        execute_first_call();
      }
    }
  } else { // let the coordinator handle it then
    synchronize(c);
  }
}
