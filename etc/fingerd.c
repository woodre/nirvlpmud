#pragma strong_types   // Coogan, 19-Oct-2010
#pragma no_shadow      // Coogan, 19-Oct-2010

inherit "/obj/player";

private static mapping loaded = ([]);

void reset(int arg) {
  if (!arg) {
    if (clonep(this_object()))
      set_heart_beat(1);
    else
      set_privilege(1);
  } else if (!clonep())
      loaded -= mkmapping(m_indices(loaded));
       // Sunblood 19-Jun-1999, else loaded is filled
       // with destructed objects
}

void save_me() { /* No fooling around */ }

object load_player(string name) {
  object ob;
  if (!valid_name(name))
    return 0;
  name = to_real_name(name);
  if (ob = find_player(name))
    return ob;
  if (!clonep(this_object())) {
    if (!loaded[name]) {  // Ugh Dec-14-1995
      ob = clone_object(load_name(this_object()));
      return loaded[name] = ob->load_player(name);
    }
    else
      return loaded[name];
  }
  if (unguarded(1,(#'restore_object),save_file(name))) {
    set_heart_beat(1);
    return this_object();
  } else {
    destruct(this_object());
    return 0;
  }
}

mixed modify_player_data(string name, string func, mixed arg1, mixed arg2,
                         mixed arg3) {
  object ob;
  mixed result;
  name = to_real_name(name);
  if (clonep(this_object())) {
    /* The player is not online and a duplicate of fingerd has been cloned */
    if (!check_previous_privilege(1))
      return 0;
    /* make sure we don't destroy .o files */
    if (name != query_real_name()) // took out casting, Coogan, 23-Apr-1998
      return 0;
    result = call_other(this_object(),func,arg1,arg2, arg3);
    unguarded(1,#'save_object,save_file(name));
    return result;
  } else {
    ob = load_player(name);
    if (query_once_interactive(ob)) {
      /* modifying player object. the player object will do the
       * security check itself.
       */
      result = ob->modify_player(func, arg1, arg2, arg3);
      ob->save_me(1);
      return result;
    } else /* go on to the clone and its own security check */
      return ob->modify_player_data(name, func, arg1, arg2, arg3);
  }
}

/*
 * This will simply load the player, change nothing and then save him again.
 * The only changes applied are the ones done by loading the player (e.g.
 * in the various set_defaults() and so on).
 *                                          Alfe 97-Dec-31
 */
void convert_player(string name) {
  modify_player_data(name,"-",0,0, 0);
}

int query_last_login(string name) {
  return (load_player(name) || this_object())->get_last_login();
}

int file_time_of(string name) {
  mixed h;  // Alfe 96-Apr-23
  return (!catch(h=unguarded(1,#'file_time,save_file(name)+".o"))) && h;
}

void heart_beat() {
  destruct(this_object());
}

void notify_destruct () {
  /* so it isn't logged */
}

