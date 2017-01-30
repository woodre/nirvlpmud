
//===========================================================================
//  Hooks
//
// These functions are set as driver hooks to perform low-level functions
// for the mud.
//===========================================================================

#define ADD_SLASH(p) "/"+p
#define GETUID(p) getuid(p)

string file_name(object ob)
{
    string rc;

    rc = efun::object_name(ob);
    return stringp(rc) ? rc[1..] : 0;
}


//---------------------------------------------------------------------------
static string _include_dirs_hook (string include_name, string current_file)

// Return the full pathname of an include file.
//
// Argument:
//   include_name: the name given in the #include <...> directive.
//   current_file: the filename of the file compiled.
//
// Result:
//   The full pathname of the include file.
//   0 if no such file exists.
//
{
  string name, part;
  int pos;

  if (file_size(ADD_SLASH(include_name)) >= 0)
    return include_name;
  name = "include/sys/"+include_name;
  if (file_size(ADD_SLASH(name)) >= 0)
    return name;
  name = "include/"+include_name;
  if (file_size(ADD_SLASH(name)) >= 0)
    return name;
  name = "sys/"+include_name;
  if (file_size(ADD_SLASH(name)) >= 0)
    return name;
  name = "room/"+include_name;
  if (file_size(ADD_SLASH(name)) >= 0)
    return name;
  name = "include/cfg/"+include_name;
  if (file_size(ADD_SLASH(name)) >= 0)
    return name;
  name = "include/fn/"+include_name;
  if (file_size(ADD_SLASH(name)) >= 0)
    return name;
  name = "include/skills/"+include_name;
  if (file_size(ADD_SLASH(name)) >= 0)
    return name;
  name = "include/fn_specs/"+include_name;
  if (file_size(ADD_SLASH(name)) >= 0)
    return name;
  name = "secure/include/"+include_name;
  if (file_size(ADD_SLASH(name)) >= 0)
    return name;
  name = "include/creators/"+include_name;
  if (file_size(ADD_SLASH(name)) >= 0)
    return name;
  return 0;
}


//---------------------------------------------------------------------------
static void _move_hook_fun (object item, object dest)

// Move object <item> into object <dest>.
//
// Argument:
//   item: the object to be moved.
//   dest: the destination for the object.
//
// The function performs all the checks for a valid move (item exists,
// destination exists, destination is not current environment, etc).
// In addition, it implements the init() protocol needed for add_action()
// to work.

{
  object *others;
  int i;

/*
  if (item != this_object())
    raise_error("Illegal to move other object than this_object()\n");
*/

  /* PLAIN: the call to exit() is needed in compat mode only */
  if (living(item) && environment(item))
  {
      efun::set_this_player(item);
//    environment(item)->exit(item);
  }

  efun::set_environment(item, dest);
  if (living(item)) {
    efun::set_this_player(item);
    dest->init();
    if (!item)
      raise_error(sprintf("%O->init() destructed moved item\n", dest));
    if (environment(item) != dest)
      return;
  }
  others = all_inventory(dest);
  others[member(others, item)] = 0;
  for (i = 0; i < sizeof(others); i++)
  {
    if (living(others[i])) {
      efun::set_this_player(others[i]);
      item->init();
    }
    if (!item)
      raise_error(sprintf("item->init() for %O (#%d) destructed moved item\n", others[i], i));
  }
  if (living(item)) {
    efun::set_this_player(item);
    filter_objects(others, "init");
  }
  if (living(dest) && item) {
    efun::set_this_player(dest);
    item->init();
  }
}



//---------------------------------------------------------------------------
/*
 * Used in driver_hook H_CLONE_UID to retrieve the clone uid
 */
static mixed clone_uid(object blueprint) {
    return GETUID(blueprint) || GETUID(previous_object()) || 1;
}

//---------------------------------------------------------------------------
/* validates whether an object can be loaded  */
static mixed master_creator_file(string object_name) {
  string wiz_name, trailer;

  if(sscanf("/"+object_name,WIZARD_DIR+"%s/%s",wiz_name,trailer)) {
    return wiz_name;
  }

  /* directories that should not have objects in them */
  if(sscanf(object_name,"doc/%s", trailer))                       return 0;
  if(sscanf(object_name,"info/%s", trailer))                      return 0;
  if(sscanf(object_name,"help/%s", trailer))                      return 0;
  if(sscanf(object_name,"manuals/%s", trailer))                   return 0;
  if(sscanf("/"+object_name,WIZARD_DIR+"%s",trailer))             return 0;
  if(sscanf(object_name,"open/%s", trailer))                      return 0;
  if(sscanf(object_name,"log/%s", trailer))                       return 0;
  return 1;  /* else legal */
}

mixed creator_file(string object_name) {
  mixed creator_status;

  if((creator_status = master_creator_file(object_name))) {
    return creator_status;
  }
  return 0;
}

