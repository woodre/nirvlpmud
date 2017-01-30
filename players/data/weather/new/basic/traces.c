/*
 * basic/traces  by Alfe for Tubmud 2002-Mar-13
 *
 * this class provides functionality for e.g. rooms which like to have
 * an array of places which might contain a trace for an event.
 * this is basic functionality to enable trace-reading.
 */

private mixed *traces;

void set_traces_count(int count) {
  traces = allocate(count);
}

mixed *query_traces() { return traces; }  // be careful! returned by reference!

varargs void lay_trace(mixed trace, int power, int t) {
  if (!power)
    power = sizeof(traces) / 10;
  if (!t)
    t = time();
  trace += ({ t });  // unique item
  while (power-->0)
    /* we simply choose a given number of places and put the trace there;
     * this way traces get overwritten, which is intended.
     */
    traces[random(sizeof(traces))] = trace;  /* we place references
                                              * to the same array
                                              */
}

varargs mixed find_trace(closure condition, int start) {
  for (int i=start; i<sizeof(traces); i++)
    if (traces[i] &&  // is there a trace at all?
        funcall(condition, traces[i]))
      return traces[i];  // found one?  return it
  return 0;
}
