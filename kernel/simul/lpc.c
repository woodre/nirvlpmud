/*
 * kernel/simul/lpc.c
 * simul_efuns that are just to complete the efun list because the driver
 * does not support them (yet)
 * Rumplemintz
 */

#include <timed_flag.h>
#include <rtlimits.h>
#include <kernel.h>
#include <prop/player.h>

#include "/kernel/simul/array.h"

static mapping alloc_wl_entry(string name) {
  closure call;
  mapping m;

  call = bind_lambda(#'efun::call_other, load_object("/etc/shared"));
  if (m = funcall(call, "/etc/shared", "query_global", name))
    return m;
  funcall(call, "/etc/shared", "set_global", name, m = ([ ]));
  return m;
}

#define TIMED_FLAG(x) ("-"+(x))

varargs int test_timed_flag(string flag) {
  return funcall(bind_lambda(#'find_call_out, previous_object()),
                 TIMED_FLAG(flag))+1;
}

int clear_timed_flag(string flag) {
  return funcall(bind_lambda(#'remove_call_out, previous_object()),
                 TIMED_FLAG(flag))+1;
}

varargs void set_timed_flag(string flag, int delay, int mode) {
  switch (mode) {
  case TF_MAXIMUM:
    if (test_timed_flag(flag) > delay)
      return;
    // fall through
  case TF_OVERRIDE:
    clear_timed_flag(flag);
    break;
  case TF_ADDING:
    delay += clear_timed_flag(flag);
    break;
  }
  funcall(bind_lambda(#'call_out, previous_object()), TIMED_FLAG(flag),
          delay-1);
}

varargs mixed sort_args(closure original, int *order) {
  int i;
  symbol *args;

  if (!order)
    order = ({ 1,0 });
  i = find_extreme(order, #'>) + 1;
  args = allocate(i);
  while (i--)
    args[i] = quote(to_string(i));
  /*
   * the following is the same as this:
   * return lambda(args,({ #'funcall,original }) +
   *               map(map(order,#'to_string),#'quote));
   * but it is secure, because the calls are bound to the caller of us.
   */
  return bind_lambda(unbound_lambda(args,
                                    ({ bind_lambda(#'funcall,
                                                   previous_object()),
                                       original }) +
                                    map(map(order,#'to_string),
                                              (#'quote))),previous_object());
}

// this function is for objects which overload efuns/simul_efuns and still
// want to use them
// It is necessary because simul_efun::<function>(<args>)) does not work.
// Now instead, simul_efun_call("<function>",<args>) can be used
varargs mixed simul_efun_call(string fun, varargs mixed vargs) {
  return apply(bind_lambda(symbol_function(fun), previous_object()), vargs);
}

varargs mixed apply_function(mixed func, varargs mixed extra) {
  if (closurep(func))
    return apply(func, extra);
  if (stringp(func))
    func = ({ previous_object(), func });
  if (pointerp(func) && sizeof(func) > 1 && stringp(func[1]) &&
      (objectp(func[0]) || stringp(func[0]))) {
    func += extra;
    if (pointerp(func[<1])) // is the last an array?
      func[<1..<1] = func[<1];
    return apply(#'call_other, func);
  }
  return func;
}

void check_arguments(mixed args, closure *tests, string func) {
  int i;

  if (sizeof(args) != sizeof(tests))
    raise_error("Size mismatch of arguments to check_arguments()\n");
  for (i=0; i<sizeof(args); i++)
    if (!funcall(tests[i], args[i]))
      raise_error("Bad arguemtn " + (i+1) + " to " + func + "()\n");
}

#if !__EFUN_DEFINED__(extract)
string extract(varargs mixed* args) {
  switch (sizeof(args)) {
  case 0: raise_error("Too few arguments to extract!\n");
    break;
  case 1: return args[0];
  case 2: return args[0][>args[1]..];
  case 3: return args[0][>args[1]..>args[2]];
  }
}
#endif

#if !__EFUN_DEFINED__(member_array)
int member_array(mixed item, mixed arr) {
  return member(arr, item);
}
#endif

private int last_log_file_size;

#define LOG_FILE "/"__HOST_NAME__".debug.log"

mixed try(mixed closure_or_result, varargs mixed *args) {
  mixed err;

  last_log_file_size = file_size(LOG_FILE);
  if (referencep(&closure_or_result))
    err = catch(closure_or_result = apply(args[0],args[1..]));
  else
    err = catch(apply(closure_or_result, args));
  return err;
}

string query_last_trace() {
  return read_bytes(LOG_FILE, last_log_file_size, 10000);
}

private mapping caught_errors = ([]);

private void report_caught_errors() {
  if (this_player() &&
      (SECURITY->query_is_wizard(this_player()->query_real_name()) ||
       this_player()->query_property(P_TESTPLAYER)))
    printf("There have errors been caught:\n"
           "%s\n",implode(explode(sprintf("%O",caught_errors),"\n")[1..<2],
                          "\n"));
  else {
    if (this_player())
      write("Your sensitive mind notices a wrongness in the fabric of"
            " space.\n");
    if (find_object("lib/channels"))
      "lib/channels"->channel_shout("wrongness",
                                    (this_player() &&
                                     this_player()->query_real_name()) +
                                    " got caught error(s) while standing"
                                    " in " +
                                    (this_player() &&
                                     object_name(environment(this_player()))) +
                                    " and typing " +
                                    (this_player() &&
                                     this_player()->query_commandline()) +
                                    " (" +
                                    implode(explode(sprintf("%O",
                                                            caught_errors),
                                                    "\n")[1..<2],"")[2..<2] +
                                    ")",
                                    "simul_efun:wrongness");
  }
  caught_errors = ([]);
}

mixed handle_catch(string slot, mixed info, mixed closure_or_result,
                   varargs mixed *args) {
  mixed result, err;
  string s, call;

  if (referencep(&closure_or_result))
    err = apply(#'try, &closure_or_result, args);
  else
    err = apply(#'try, closure_or_result, args);
  if (err) {
    if (referencep(&closure_or_result))
      args = args[1..]; // cut off closure at beginning of args
    s = ("---------------------------------------------------------\n" +
         (stringp(err) ? "%s" : "%O\n") +  // error
         (info ? "%O\n" : "") +            // info (maybe)
         (sizeof(args) ? "%O\n" : "") +    // args (maybe)
         "%s\n");                          // trace
    if (info)
      if (sizeof(args))
        s = sprintf(s, err, info, args, query_last_trace());
      else // info bu no args
        s = sprintf(s, err, info, query_last_trace());
    else // no info
      if (sizeof(args))
        s = sprintf(s, err, args, query_last_trace());
      else // no info, no args
        s = sprintf(s, err, query_last_trace());
    "etc/filer"->log_file("/syslog/CATCH/" + slot, s);
    caught_errors[slot]++;
    remove_call_out(#'report_caught_errors);
    call_out(#'report_caught_errors, 1);
  }
  return err;
}

private mixed cheap(closure code, varargs mixed args) {
  return limited(lambda(0, ({ (#'apply), (#'limited), code, quote(args) })),
                 LIMIT_EVAL, LIMIT_UNLIMITED);
}

mixed handle_catch_limited(string slot, mixed info, int eval_limit,
                           mixed closure_or_result, varargs mixed *args) {
  mixed result, err;
  string s, call;
  if (referencep(&closure_or_result)) { // is result?
    err = try(&closure_or_result, (#'cheap),
              lambda(0, ({ #'apply, args[0], quote(args[1..]) })),
              LIMIT_EVAL, eval_limit);
  }
  else { // is closure
    err = try((#'cheap),
              lambda(0, ({ #'apply, closure_or_result, quote(args) })),
              LIMIT_EVAL, eval_limit);
  }
  if (err) {
    if (referencep(&closure_or_result))
      args = args[1..];  // cut off closure at beginning of args
    s = ("---------------------------------------------------------\n" +
         (stringp(err) ? "%s" : "%O\n") + // error
         (info ? "%O\n" : "") +           // info (maybe)
         (0 &&                            // diabled
          sizeof(args) ? "%O\n" : "") +   // args (maybe)
         "%s\n");                         // trace
    if (info)
      if (0 && sizeof(args))
        s = sprintf(s, err, info, args, query_last_trace());
      else // info but no args
        s = sprintf(s, err, info, query_last_trace());
    else // no info
      if (0 &&  // disabled
          sizeof(args))
        s = sprintf(s, err, args, query_last_trace());
      else // no info, no args
        s = sprintf(s, err, query_last_trace());
    "etc/filer"->log_filel("/syslog/CATCH/" + slot, s);
    caught_errors[slot]++;
    remove_call_out(#'report_caught_errors);
    call_out(#'report_caught_errors, 1);
  }
  return err;
}

#if !__EFUN_DEFINED__(m_add)
mapping m_add(mapping m, varargs mixed *key_and_values) {
  m += apply(#'mkmapping, transpose_array(({ key_and_values })));
  return m;
}
#endif

