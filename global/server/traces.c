/*
 * This is the trace server which manages all traces which are currently
 * in the mud.
 * It offers the possibility to find a trace given a part (e.g. a
 * participant) of the trace.
 *
 * Written by Alfe for Tubmud 98-Jan-1
 */

#include <kernel.h>
#include <traces.h>  // changed to traces, Coogan, 20-Nov-00

inherit ACCESS;

mixed *traces = ({ ({}),({}) });

object create_trace(mixed event,int delay) {
  object trace;
  if (!check_previous_privilege("@traces"))
    raise_error("Illegal creation of a trace\n");
  trace = clone_object(TRACE_OBJECT);
  trace->set_event(event);
  trace->set_delay(delay);
  return trace;
}

varargs void place_trace(object trace,object room,int delay) {
  mixed h;
  int fade_time;
  if (!check_previous_privilege("@traces"))
    raise_error("Illegal placement of a trace\n");
  move_object(trace,room);
  fade_time = time() + (delay || trace->query_delay());
  h = insert_alist(fade_time,traces[0]);
  traces[0][h..h-1] = ({ fade_time });
  traces[1][h..h-1] = ({ trace });
  remove_call_out("remove_old_traces");
  call_out("remove_old_traces",traces[0][0] - time());
}

void remove_old_traces() {
  int i;
  for (i=0; i<sizeof(traces[0]) && traces[0][i]<=time(); i++)
    if (traces[1][i])  // trace still existent?
      traces[1][i]->fade_away();
  traces = ({ traces[0][i..],traces[1][i..] });
  remove_call_out("remove_old_traces");
  if (sizeof(traces[0]))
    call_out("remove_old_traces",traces[0][0] - time());
}

object *find_trace(mixed part) {
  return filter_objects(traces[1],"trace_matches",part);
}
