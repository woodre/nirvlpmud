/*
 * kernel/simul/debug.c
 *
 * simul_efuns that are just for debugging purposes, do not use these
 * permanently in your files!
 * Rumplemintz
 */

#include "/kernel/defs.h"
#include "/kernel/simul/game.h"
#include "/kernel/simul/file.h"
#include "/kernel/simul/for_master.h"

varargs void dump_array(mixed a, string tab, int dw) {
  printf("%O\n", a);
}

varargs void debug(string player_name, mixed m, string s) {
  object player_object;

  if (player_object = find_player(player_name))
    tell_object(player_object, sprintf(s || "%O\n", m));
}

/*
 * get_variable() gets a string which is a variable name and an object in
 * which a global variable of this name exists. It returns a closure to
 * the variable which can be evaluated with funcall()
 * Since this is for debugging purposes only and could be abused, the
 * function is restricted to privilege 1
 */
mixed get_variable(string variable_name, object o) {
  if (!this_interactive() || !check_privilege(1))
    return 0;
  log_file("VARIABLE", sprintf("%s: %s queried %O's variable %O\n", ctime(),
                               this_interactive()->query_vis_name(), o,
                               variable_name));
  return funcall(bind_lambda(#'symbol_variable, o), variable_name);
}

/*
 * set_variable() gets a string which is a variable name, a value this
 * variable shall be set to and an object in which a global variable of this
 * name exists. It sets the variable to the given value and returns whether
 * this variable really exists.
 * PLEASE NOTE that this might lead very easily to corrupted data structures
 * in the modified object, so please do not use this function lightly!
 */
status set_variable(string variable_name, mixed value, object o) {
  mixed h;

  if (!this_interactive() || !check_privilege(1))
    return 0;
  log_file("VARIABLE", sprintf("%s: %s set %O's variable %O\n", ctime(),
                               this_interactive()->query_vis_name(), o,
                               variable_name));
  if (!(h=funcall(bind_lambda(#'symbol_variable, o), variable_name)))
    return 0;
  funcall(funcall(bind_lambda(unbound_lambda(0, ({ (#'lambda),
                                                   0,
                                                   quote(({ (#'=),
                                                            h, value })) })),
                              o)));
  return 1;
}

/*
 * call_function() calls a function in a given object even if this function
 * is static. private functions cannot be called this way, though.
 * give the name of the function to be called as first argument, the object
 * in which this function exists, as second and arguments to the function
 * as third to last argument
 * Calling static functions in an object is ia ticklish matter. Do it only
 * if you know exactly what you are doing!
 */
mixed call_function(string function_name, object o, varargs mixed args) {
  if (!this_interactive() || !check_privilege(1))
    return 0;
  log_file("VARIABLE", sprintf("%s: %s called %O->%s%O\n", ctime(),
                               this_interactive()->query_vis_name(), o,
                               function_name, args));
  return apply(funcall(bind_lambda(#'symbol_function, o), function_name, o),
               args);
}

/*
 * This is a more flexible version of save_object() that may get as second
 * argument the object which's variables are to be stored. Thus it can be
 * used to view an object's variables and to store them.
 */
void save_other_object(object o, string file) {
  if (!this_interactive() || !check_privilege(1))
    return 0;
  log_file("VARIABLE", sprintf("%s: %s saved %O into %O\n", ctime(),
                               this_interactive()->query_vis_name(), o, file));
  funcall(bind_lambda(#'save_object, o), file);
}

/*
 * This correlates with the above function and allows the restoring of a
 * given object from a given file. Thus it is possible to use the (with
 * save_object) stored values and store them in another object.
 */
int restore_other_object(object o, string file) {
  if (!this_interactive() || !check_privilege(1))
    return 0;
  log_file("VARIABLE", sprintf("%s: %s restore %O from %O\n", ctime(),
                               this_interactive()->query_vis_name(), o, file));
  return funcall(bind_lambda(#'restore_object, o), file);
}

private int     call_trace_level = 0;
private string *call_trace = ({});

string *query_call_trace() {
  return call_trace;
}

void reset_call_trace() {
  call_trace_level = 0;
  call_trace = ({});
}

void add_call_trace_enter(object caller, mixed called, string func,
                          mixed *args) {
  call_trace += ({ ({ ++call_trace_level, get_eval_cost(),
                      caller, called, func, args }) });
}

void add_call_trace_leave(mixed *args) {
  call_trace += ({ ({ call_trace_level--, get_eval_cost(), args }) });
}

private status call_other_trace_flag = 0;

void set_call_other_trace(status enable) {
  call_other_trace_flag = enable;
  if (enable)
    reset_call_trace();
}

/*
 * This version of call_other() fulfills the actual call and returns the
 * proper value. If call_other_trace_flag is set, it also logs the event
 * and the eval_times consumed by this into call_other_trace
 */
mixed call_other(mixed called, string func, varargs mixed *args) {
  mixed result;
  mixed h;
  closure co;

  if (previous_object(1) == find_object(SECURITY)) // might be unguarded call?
    co = (#'efun::call_other);
  else  /* no unguarded: caller might be one of those who check us via
         * previous_object(), so we better push our caller in front of
         * us on the caller_Stack.
         */
    co = bind_lambda(#'efun::call_other, previous_object());
  // put the loading of another object into its own eval cost scope
  if (stringp(called) && !find_object(called)) {
    called = limited(#'load_object, ({ 1000000 }), called);
  }
  if (!call_other_trace_flag)
    return apply(co, called, func, args);
  // ok, tracing
  add_call_trace_enter(previous_object(), called, func, args);
  result = apply(co, called, func, args);
  add_call_trace_leave(args);
  return result;
}

// Same here, just for the parser cases which like to pass references
mixed call_other_2ref(mixed called, string func, mixed ref1, mixed ref2,
                      varargs mixed *args) {
  mixed result;

  if (!call_other_trace_flag)
    return apply(bind_lambda(#'efun::call_other, previous_object()),
                 called, func, &ref1, &ref2, args);
  // ok, tracing
  add_call_trace_enter(previous_object(),
                       called, func, ({ ref1, ref2 }) + args);
  result = apply(bind_lambda(#'efun::call_other, previous_object()),
                 called, func, &ref1, &ref2, args);
  add_call_trace_leave(({ ref1, ref2 }) + args);
  return result;
}

