/*
 * Rumplemintz
 * Security and Permissions. Most of these functions guard critical
 * efuns. See also creator_file(), valid_read(), and valid_write()
 */

//---------------------------------------------------------------------------
int query_player_level (string what)

// There are several occasions when the game driver wants to check if
// a player has permission to specific things
//
// These types are implemented so far:
//    "error messages" : If the player is allowed to see runtime error
//                       messages
//    "trace"          : If the player is allowed to use tracing
//    "wizard"         : If the player is considered at least a 'minimal'
//                       wizard
//    "create domain"  : If the player is allowed to create new domains
//    "snoop"          : It the player is allowed to 'snoop'
{
  int security_level;

  if (!this_player()) return 0;

  security_level = (int)this_player()->query_security_level();

  switch(what) {
    case "wizard"        : return (security_level >= SEC1);
    case "error messages": return (security_level >= SEC1);
    case "trace"         : return (security_level >= SEC4);
    case "create domain" : return (security_level >= SEC8);
    case "snoop"         : return (security_level >= SEC5);
  }
  return 0;
}


//---------------------------------------------------------------------------
int privilege_violation (string op, mixed who, mixed arg, mixed arg2)

// Validate the execution of a privileged operation.
//
// Arguments:
//   op   : the requested operation (see below)
//   who  : the object requesting the operation (filename of object pointer)
//   arg  : additional argument, depending on <op>.
//   arg2 : additional argument, depending on <op>.
//
// Result:
//     >0 : The caller is allowed for this operation
//      0 : The caller was probably mislead; try to fix the error
//    else: A real privilege violation; handle it as error
//
// Privileged operations are:
//   attach_erq_demon  : Attach the erq demon to object <arg> with flag <arg2>
//   bind_lambda       : Bind a lambda-closure to object <arg>
//   call_out_info     : Return an array with all call_out information
//   erq               : The request <arg4> is to be sent to the erq-demon
//                       by the object <who>
//   execute_command   : Execute command string <arg2> for object <arg>
//   input_to          : Object <who> issues an 'ignore-bang'-input_to() for
//                       command giver <arg3>; the exact flags are <arg4>
//   nomask simul_efun : Attempt to get an efun <arg> via efun:: when it
//                       is shadowed by a 'nomask'-type simul_efun
//   rename_object     : The current object <who> renames object <arg> to
//                       name <arg2>
//   send_imp          : Send UDP-data to host arg3 <deprecated>
//   send_udp          : Send UDP-data to host <arg>
//   set_auto_include_string : Set the string automatically included by the
//                       the compiler (deprecated)
//   get_extra_wizinfo : Get the additional wiz-list info for wizard <arg>
//   set_extra_wizinfo : Set the additional wiz-list info for wizard <arg>
//   set_extra_wizinfo_size : Set the size of the additional wizard info in
//                       the wiz-list to <arg>
//   set_driver_hook   : Set hook <arg> to <arg2>
//   limited           : Execute <arg> with reduced/changed limits
//   set_limits        : Set limits to <arg>
//   set_this_object   : Set this_object() to <arg>
//   shadow_add_action : Add an action to function <arg4> of object <arg3>
//                       from the shadow <who> which is shadowing <arg3>
//   symbol_variable   : Attempt to create symbol of a hidden variable
//                       of object <arg> with index <arg2> in the objects'
//                       variable table
//   wizlist_info      : Return an array with all wiz-list information
//
// call_out_info can return the arguments to functions and lambda closures
// to be called by call_out; you should consider that read access to
// closures, mappings and pointers means write access and/or other privileges
// wizlist_info() will return an array which holds, among others, the extra
// wizlist field. While a toplevel array, if found, will be copied, this does
// not apply to nested arrays or to any mappings. You might also have some
// sensitive closures there
// send_udp() should be watched as it could be abused to mess up the IMP
// The xxx_extra_wizinfo operations are necessary for a proper wizlist and
// should therefore be restricted to admins
// All other operations are potential sources for direct security breaches -
// any use of them should be scrutinized closely
{
  /* This object and the simul_efun objects may do everything */
  if (who == this_object() || who == find_object(SIMUL_EFUN)) return 1;

  switch(op) {
    case "nomask simul_efun":
      if (objectp(who)) {
        who = object_name(who);
      }
      if (who[0..6] == "/secure") {
        return 1;
      }
      else {
        return -1;
      }
    case "call_out_info": return 1;
    case "limited":       return 1;
    case "set_auto_include_tring":
    case "add_worth":
    case "bind_lambda":
    case "rename_object":
    case "input_to":
    case "set_extra_wizinfo_size":
    case "set_this_object":
    case "shadow_add_action":
      return (valid_master_call(who)) ? 1 : -1;
    case "erq":
      if (objectp(who)) {
        who = object_name(who);
      }
      if (who[0..6] == "/secure") {
        return 1;
      }
    switch(arg) {
      case ERQ_RLOOKUP: return 1;
      case ERQ_EXECUTE:
      case ERQ_FORK:
      case ERQ_AUTH:
      case ERQ_SPAWN:
      case ERQ_KILL:
      default:
        return -1;
    }
    default:
      return -1; /* Make this violation an error */
  }
}


//---------------------------------------------------------------------------
int query_allow_shadow (object ob) {
  string file;

#ifdef SHADOW_DIR
  file = file_name(previous_object());
  if (file[0] != '/') file = "/" + file;
  if (sscanf(file, SHADOW_DIR, file) != 1) {
    return 0; /* only shadows that have been inspected can be used */
  }
#endif
  /* do not allow shadows with our security functions in them */
  if (function_exists("valid_read", previous_object()) ||
      function_exists("valid_write", previous_object())) {
    return 0;
  }

  if (object_info(ob, OINFO_MEMORY)[OIM_NO_SHADOW]) return 0;

  return !ob->query_prevent_shadow(previous_object());
}


//---------------------------------------------------------------------------
int valid_trace (string what, mixed arg)

// Check if the player is allowed to use tracing
//
// Argument:
//   what : The actual action (see below)
//   arg  : The argument given to the trace-ing efun
//
// Result:
//   Return 0 to disallow, any other value to allow it
//
// Actions asked for so far are:
//   "trace"      : Is the user allowed to use tracing? <arg> is the tracelevel
//                  argument given
//   "traceprefix": Is the user allowed to set a traceprefix? <arg> is the
//                  prefix given
{
  if (this_player() == 0) return 0;

  switch(what) {
    case "trace":
    case "traceprefix":
      return query_player_level("trace");
  }
}


//---------------------------------------------------------------------------
int valid_exec (string name, object ob, object obfrom)

// Validate the rebinding of an IP connection by usage of efun exec()
//
// Arguments:
//   name   : The name of the _program_ attempting to rebind the connection
//            This is not the file_name() of the object, and has no leading
//            slash
//   ob     : The object to receive the connection
//   obfrom : The object giving the connection away
//
// Result:
//   Return a non-zero number to allow the action, any other value to disallow
{
  string tmp;

  if (name && name != "" && name[0] == '/') {
    name = name[1..(strlen(name)-1)];
  }

/*
  if (sscanf(name, RACE_DIR + "/%s.c", tmp) == 1) return 1;
*/
  switch(name) {
    case PLAYER + ".c":
      return 1;
    break;
  }
  write("Invalid Exec() call by object: " + name + "\n");
  return 0;
}


//---------------------------------------------------------------------------
int valid_query_snoop (object obj)

// Validate if the snoopers of an object may be revealed by usage of the
// efun query_snoop
//
// Arguments:
//   previous_object() : the asking object
//   obj               : the object which snoopers are to be revealed
//
// Result:
//   Return a non-zero number to allow the action, any other value to disallow
{
  return query_player_level("snoop");
}


//---------------------------------------------------------------------------
int valid_snoop (object snoopee, object snooper)

// Validate the start/stop of a snoop
//
// Arguments:
//   snoopee : The victim of the snoop
//   snooper : The wannabe snooper, or 0 when stopping a snoop
//
// Result:
//   Return a non-zero number to allow the action, any other value to disallow
{
  if (object_name(previous_object()) == get_simul_efun())
    return 1;
}

