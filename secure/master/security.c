/*
 * security.c
 * 
 * For each object in the mud exists a stirng attribute which
 * determines the objects rights in security-sensitive matters.
 *
 * Rumplemintz
 */


/* this states that nobody is allowed to shadow the master */
status query_prevent_shadow() {
  return true;
}


/* file security */
static mixed valid_file_access(string path,
                               object caller,
                               string call_fun,
                               string access) {
  mixed file;
  object ob;

  if (path[0] != '/') path = "/" + path;

  ob = (object)SECURITY_FILE;
  file = call_other(ob, "valid_" + access, path, caller, call_fun);
  if (!file) {
    if (query_player_level("error messages")) {
      write("Invalid " + access + " Access:\t " + path
            +"\n\t\tCaller:\t " + FILE_NAME(caller)
            +"\n\t\tEfun:\t " + call_fun + "\n");
    }
    else {
      write("Bad file name.\n");
    }
  }
  return file;
}

mixed valid_write(string path,
                  string eff_user,
                  string call_fun,
                  object caller) {
  if (!objectp(caller)) caller = previous_object();
  return valid_file_access(path, caller, call_fun, "write");
}

mixed valid_read(string path,
                 string eff_user,
                 string call_fun,
                 object caller) {
  if (!objectp(caller)) caller = previous_object();
  if (object_name(caller)[0..13] == "secure/master")
    return path[1..];
  if (object_name(caller)[0..10] == "obj/master")
    return path[1..];
  return valid_file_access(path, caller, call_fun, "read");
}

/* Some functions ask if it is valid for an object to make the call,
 * These functions say yes or no, they make up the basis for security
 */

nomask status valid_master_call(object ob) {
  return ((status)SECURITY_FILE->valid_master_object(ob));
}

nomask status valid_player_call(object ob) {
  if (valid_master_call(ob)) return 1;
  return ((status)SECURITY_FILE->restricted_path_object(ob));
}

/*
 * This function is called for a wizard that has dropped a castle.
 * The argument is the file name of the object that called create_wizard().
 * Verify that this object is allowed to do this call.
 */
int verify_create_wizard(object ob) {
  int dummy;

  if (sscanf(object_name(ob), "room/port_castle#%d", dummy) == 1
   || sscanf(object_name(ob), "global/port_castle#%d", dummy) == 1)
    return 1;
  return 0;
}

