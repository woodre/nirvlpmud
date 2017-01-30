//===========================================================================
//   Runtime support
//
// Various functions used to implement advanced runtime features
//===========================================================================


//---------------------------------------------------------------------------
object compile_object (string filename)

// Compile a virtual object
//
// Arguments:
//   previous_object() : The object requesting the virtual object
//   filename          : The requested filename for the virtual object
//
// Result:
//   The object to serve as the requested virtual object, or 0.
//
// This function is called if the compiler can't find the filename for an
// object to compile. The master now has the opportunity to return another
// which will then server as if it was compiled from <filename>.
// If the master returns 0, the usual 'Could not load' - error will occur.
{
  object obj, room;
  string filepath;

  if (filename[0] != '/') filename = "/" + filename;
  filepath = implode(explode(filename, "/")[0..<2], "/");
  if (!room && 0 <= file_size(filepath + ".c"))
    room = (object)filepath->compile_object(explode(filename, "/")[<1]);
  return room;
}


//---------------------------------------------------------------------------
string get_wiz_name (string file)

// Return the name of the creator of the file, or 0
{
  string name, rest;

  if (file[0] != '/') file = "/" + file;
  if (sscanf(file, WIZARD_DIR + "%s/%s", name, rest) == 2) {
    return name;
  }
  return 0;
}


//---------------------------------------------------------------------------
void destruct_environment_of(object ob) {
  if (!interactive(ob)) return;
  tell_object(ob,
              "Everything you see is dissolved.\n" +
              "Luckily, you are transported somewhere...\n");
  ob->move_player("is transferred#" + VOID, 0, 1); /* domain safe move */
}


//---------------------------------------------------------------------------
void move_or_destruct(object what, object to)

// Move <what> into <to>, or destruct <what> if that is not possible
//
// An error in this function can be very nasty. Note that unlimited recursion
// is likely to cause errors when environments are deeply nested
{
  int res;

  do {
    if (catch(res = TRANSFER(what, to))) res = 5;
    if (!(res && what)) return;
  } while ((res == 1 || res == 4 || res == 5) && (to = environment(to)));

  // Failed to move the object, then destroy it
  destruct(what);
}


//---------------------------------------------------------------------------
private int handle_super_compat (object super, object ob)

// Handle the weight handling in the environment for prepare_destruct()
// Return non-0 if an error occurred, and 0 if not
{
  if (super) {
    mixed error, weight;

    set_this_object(ob);
    if (living(ob)) {
      if (error = catch(super->exit(ob), 0))
        write("exit" + ": " + error);
    }
    if (error = catch((weight = ob->query_weight()), 0)) {
      write("query_weight" + ": " + error);
      return 1;
    }
    if (weight && intp(weight)) {
      if (error = catch(super->add_weight(-weight), 0)) {
        write("add_weight" + ": " + error);
        return 1;
      }
    }
  }
  return 0;
}


//---------------------------------------------------------------------------
mixed prepare_destruct (object ob)

// Prepare the destruction of the given object
//
// Argument:
//   obj : The object to destruct
//
// Result:
//   Return 0 if the object is ready for destruction, any other value will
//   abort the attempt. If a string is returned, an error with the string
//   as message will be issues.
//
// The gamedriver calls this function whenever an object shall be destructed
// It expects that this function cleans the inventory of the object, or
// the destruct will fail
// Furthermore, the fuction could notify the former inventory objects that
// their holder is under destruction (useful to move players out of rooms
// which are updated); and it could announce mudwide the destruction(quitting)
// of players
{
  object super;
  int i;
  object sh, next;

  /* Remove all pending shadows */
  if (!query_shadowing(ob))
    for (sh = shadow(ob, 0); sh; sh = next) {
      next = shadow(sh, 0);
      funcall(bind_lambda(#'unshadow, sh)); /* avoid deep recursion */
      destruct(sh);
    }
  super = environment(ob);
  if (super) {
    if (funcall(#'handle_super_compat, super, ob))
      return;
  }
  if (!super) {
    object item;

    while (item = first_inventory(ob)) {
      destruct_environment_of(item);
      if (item && environment(item) == ob)
        destruct(item);
    }
  } else {
    while (first_inventory(ob))
      move_or_destruct(first_inventory(ob), super);
  }
  if (interactive(ob))
    disconnect(ob);

  return 0; /* success */
}


//---------------------------------------------------------------------------
//void quota_demon (void)

// Handle quotas in times of memory shortage
//
// This function is called during the final phase of a garbage collection if
// the reserved user area couldn't be reallocated. This function (or a called
// demon) now has the opportunity to remove some (still active) objects from
// the game. If this does not free enough memory to reallocate the user
// reserver, slow_shut_down() will be called to start Armageddon
//
// Note: Up to now, the wizlist lacks various invormation needed to detect
//       the memory-hungriest wizards
// {}


//---------------------------------------------------------------------------
//void receive_udp (string host, string msg, int port)
//void receive_imp (string host, string msg, int port) // deprecated

// Handle a received UDP message
//
// Arguments:
//   host : Name of the host the message comes from
//   msg  : The received message
//   port : The port number from which the message was sent
//
// This function is called for every message received on the UDP port
//
// The driver first calls receive_udp(). If that method doesn't exist
// and if the driver is compiled with USE_DEPRECATED, it will then
// call receive_imp()
// {}


//---------------------------------------------------------------------------
nomask void slow_shut_down (int minutes)

// Schedule a shutdown for the near future
//
// Argument:
//   minutes : The desired time in minutes till the shutdown
//             6, if just the user reserve has been put into use
//             1, if the (smaller) system or even the master reserve has
//                been put into use as well
{
  if (previous_object() && previous_object() != this_object()) {
    return;
  }
  filter(users(), lambda(({'u}),
                         ({#'&&,
                           ({#'environment, 'u}),
                           ({#'!=, 'u,
                             ({#'this_player}),
                           }),
                           ({#'tell_object, 'u, "The Gamedriver shouts: " +
                                                "We are out of memory!\n"})
                         })));
  "/obj/shut"->shut(minutes);
}


//---------------------------------------------------------------------------
varargs void notify_shutdown (string crash_reason)

// Notify the master about an immediate shutdown. If <crash_reason> is 0,
// it is a normal shutdown, otherwise it is a crash and <crash_reason>
// gives a hint at the reason
//
// This function has the opportunity to perform any cleanup operation, like
// informing the mudwho server that the mud is down. This can not be done
// when remove_player() is called because the udp connectivity is already
// gone then.
//
// If the gamedriver shuts down normally, this is the last function called
// before the mud shuts down the udp connections and the accepting socket
// for new players
//
// If the gamedriver crashes, this is the last function called before the
// mud attempts to dump core and exit. WARNING: Since the driver is in an
// unstable state, this function may not be able to run to completion!
// The following crash reasons are defined:
//    "Fatal Error": an internal sanity check failed.
{
  if (previous_object() && previous_object() != this_object()) return;
  if (!crash_reason)
    filter(users(), #'tell_object,
           "Game driver shouts: LPmud shutting down immediately.\n");
  else
    filter(users(), #'tell_object,
           "Game driver shouts: Mud is CRASHING: " + crash_reason + "!\n");
}


//---------------------------------------------------------------------------
int master_file_size(string file) {
  return file_size(file);
}


