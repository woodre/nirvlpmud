private mapping commands;
private mapping clones;

static void add_command(string func,string verb) {
  if (!commands)
    commands = ([ ]);
  commands[verb]=func;
}

static void remove_command(string verb) {
  if (!commands)
    return;
  m_delete (commands, verb);
}

nomask mapping get_commands() {
  if (query_once_interactive(previous_object()))
    return commands; // save memory if safe to do so
  else
    // Ugh Jul-06-1995 added the empty mapping
    return commands && copy(commands);
}

static void set_auto_clone() {
  if (!previous_object() || this_object()==previous_object())
    return;
  if (clonep())
    return;
  if (!clones)
    clones = ([ ]);
}

int is_privileged(object user,string func) {
  return 1;
}

object find_instance(object player) {
  string name;
  object clone;
  if (!clones)
    return this_object();
#if 0 // sunblood, 05-jul-1999
  name = player->query_real_name() || object_name(player);
#else
  name = query_once_interactive(player) ? player->query_real_name() 
                                        : object_name(player);
#endif
  clone = clones[name];
  if (!clone) {
    clone = clones[name] = clone_object(load_name(this_object()));
    clone->set_player(name);
  }
  return clone;
}

static void destruct_clone(string ignore,object clone) {
  if (objectp(clone))
    destruct(clone);
}

void notify_destruct() {
  if (clones)
    walk_mapping(clones,#'destruct_clone);
}

int dispatch(string verb,string arg) {
  string func;
  func = commands && commands[verb];
  if (!func)
    return 0;
#if 0 // Alfe 1995-Mar-31
  if (previous_object()!=this_player() || !interactive(this_player()))
#else
  if (previous_object()!=this_player())
#endif
    return 0;
  if (!is_privileged(previous_object(),func))
    return 0;
  return call_other(find_instance(this_player()),func,arg,verb);
}

// introduced by Ugh May-23-1997
object *get_instances() {
  return clones? m_values(clones) : ({});
}

object query_owner() {
  int i;
  if (clonep())
    return find_object(load_name(this_object()))->query_owner();
  if (!clones)
    return 0;
  i = member(m_values(clones),previous_object());
  if (i >= 0)
    return find_player(m_indices(clones)[i]);  // added find_player()
                                               // Alfe 1998-May-22
}
