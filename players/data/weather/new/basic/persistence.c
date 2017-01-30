#include <libs.h>
#include <message.h>
#include <persistence.h>

static private mapping persistent_variables;
static private string persistence;

private void eval_query_func(string var, mixed set_func, string query_func)
{
  if (stringp(query_func))
    query_func = call_other(this_object(),query_func);
  else if (closurep(query_func))
    query_func = funcall(query_func);
  else if (pointerp(query_func))
    query_func = apply(#'call_other,query_func);
  else if (!query_func) {
    query_func = call_other(this_object(),"query_"+var) ||
#if 0 // Coogan, 05-Sep-1997
                 call_other(this_object(),var) ||
#endif
                 funcall(symbol_variable(var));
  }
}

void use_set_func(string var, mixed set_func, mixed value)
{
  call_other(this_object(),set_func || ("set_"+var),value);
}

void remove_persistent_variable(mixed var)
{
  if (persistent_variables)
  {
    if (stringp(var))
      var = ({ var });
    persistent_variables -= mkmapping(var);
  }
}

private status is_permanent_variable(string key)
{
  return !strstr(key, PER_PERM_VAR);
}


varargs void add_persistent_variable(string var, string set_func, 
                                     mixed query_func)
{
  if (!stringp(var)) return; // Chameloid, 04-Apr-1998

  if (!persistent_variables)
    persistent_variables = ([]);

  if (is_permanent_variable(var)) {
    if (!set_func) set_func = "set_" + var[6..];
    if (!query_func) query_func = "query_" + var[6..];
  }
  if (member(persistent_variables, var)) {
    persistent_variables[var,0] = set_func;
    persistent_variables[var,1] = query_func;
  }
  else persistent_variables += ([ var : set_func; query_func ]);
}


void add_persistent_variables(mixed *vars)
{
  filter(vars,lambda(({'v}),({#'apply,#'add_persistent_variable,'v})));
}


void set_persistent_variables(mixed *vars)
{
#if 0
  persistent_variables = 0;
#else
  if (persistent_variables) persistent_variables =
    filter_indices(persistent_variables, #'is_permanent_variable);
#endif
  add_persistent_variables(vars);
}

status  // Coogan, 29-Apr-1998
query_is_persistent() {
  if (!persistence || persistence == PER_MISS_PERSISTENCE ||
      persistence == PER_NO_PERSISTENCE)
    return 0;
  return 1;
}

// Carador, 21-Aug-1997
mixed get_state()
{
  mapping h;
#if 1  // Coogan, 15-Apr-1998
  if (persistence == PER_MISS_PERSISTENCE)
#else
  if (!persistence || persistence == PER_MISS_PERSISTENCE)
#endif
    return 0;
  // 'if' split up into two parts by Coogan, 23-Sep-1997,
  // also added PER_MISS_PERSISTENCE macro
  if (persistence == PER_NO_PERSISTENCE)
    return -1; // return value changed to -1, Coogan, 23-Sep-1997
  if (persistent_variables)
  {
    if (persistence == "without_vars") {
      h = filter_indices(persistent_variables, #'is_permanent_variable);
      if (!sizeof(h)) return 1;
    }
    else h = copy(persistent_variables);
    walk_mapping(h,#'eval_query_func);
    if (LIB_TYPES->saveable(h))
      return h;
    log_file("persistence",ctime() + ": " + to_string(this_object()) +
             " isn't persistent.\n");
    send_message(({ M_TARGETS,M_PL,M_ME_THE,M_ME_VERB,"are",
                    " not persistent!" }));
    return 0;
  }
  return 1;
}

void set_state(mapping state)
{
  walk_mapping(copy(state),#'use_set_func);
}

varargs void set_persistence(mixed a, mixed b, mixed c)
{
  mixed h;
  int i;

//debug("coogan",a);
  a = ({ a, b, c }) - ({ 0 });
  b = 0;
  c = 0;
//debug("coogan",a);

  if (!sizeof(a)) {  // set_persistence(); ohne argumente
#if 1  // Coogan, 19-May-1998
    persistence = PER_MISS_PERSISTENCE;
#else
    persistence = "without_vars";
#endif
    return;
  }

  persistence = 0;

  for (i=sizeof(a); i--;) {
    if (stringp(a[i])) {
      switch (a[i]) {
        case PER_NO_PERSISTENCE :
        case PER_KEEP_VARS :
          persistence = a[i];
          break;

        default :
          h = load_name(this_object());
          if (      h        != a[i] &&
              "/" + h + ".c" != a[i] && // Alfe 1997-Sep-12
                    h + ".c" != a[i] && // Carador, 02-Jan-1998
              "/" + h        != a[i])   // Carador, 02-Jan-1998
            c = PER_MISS_PERSISTENCE;  // Coogan, 23-Sep-1997: _NO_ -> _MISS_
          else
            c = "without_vars";
      }
      continue;
    }
    if (pointerp(a[i])) {
      b = a[i];
      continue;
    }
  }

  if (b) {    // variablen wurden uebergeben
    if (persistence == PER_KEEP_VARS)
      add_persistent_variables(b);
    else
      set_persistent_variables(b);
#if 1  // Alfe 1998-Feb-22
    // i think that the else-part is a better solution since otherwise objects
    // which simply inherit complex/item for instance and do not call
    // set_persistence() from their own configure() or similar are persistent
    // by this which obviously leads to errors if they have own global
    // variables.  Alfe 1998-Feb-22
    persistence = PER_KEEP_VARS;
#else
    if (persistence != PER_MISS_PERSISTENCE)
      persistence = PER_KEEP_VARS;
#endif
  }

  if ( c == PER_NO_PERSISTENCE ||
       (c && !persistence)
     ) persistence = c;

#if 1 // to save memory, sunblood 14-oct-1999
  if (persistence == PER_NO_PERSISTENCE)
      persistent_variables = 0;
  else if (persistence == "without_vars") {
      if (persistent_variables) {
	persistent_variables = filter_indices(persistent_variables, 
						#'is_permanent_variable);
	if (!sizeof(persistent_variables))
	    persistent_variables = 0;
      }
  }
#endif
}

void remove_persistence(mixed set_func) {
  mixed h;
  if (pointerp(set_func))
    map(set_func,#'remove_persistence);
  else {
    h = m_values(persistent_variables);
    h = member(h,set_func);
    if (h >= 0)
      m_delete(persistent_variables,m_indices(persistent_variables)[h]);
    else if (set_func[0..3] == "set_")
      m_delete(persistent_variables,set_func[4..]);
  }
}

