/*****************************************************************************
        /basic/exit.c rewritten by Ugh with mappings and the possibility
        to use closures for destinations, move hooks and exit flags
******************************************************************************/
#include <orientation.h>
#include <exits.h>
#include <libs.h>
#include <termcol.h>    // Coogan, 02-Jun-2003, 25-Nov-2003

inherit "basic/orientation";

// Carador, 24-Jul-1997: removed all break_string() calls in query_exit_long()

private mapping exits; // a mapping that maps the exits onto destinations, 
                       // move hooks and some flags

private string *command_list; // this is needed for the set_move_hooks()
                              // call *sigh*

private status show_exits=1; // Arkon, 05-Jan-1995

private mixed used_exit; // a variable for the used exit (Ugh Aug-05-1996)


void init() {
  int i;
  add_action("default_exit_command","",1);
  if (exits) 
    for (i=0;i<sizeof(command_list);i++)
      add_action("exit_command",command_list[i]);
}

private string query_dest(string dir) {
  mixed dest;
  dest=exits && funcall(exits[dir,EXIT_DEST]);
  if (objectp(dest))
    return object_name(dest);
  else if (stringp(dest))
    return implode(explode(dest,"/")-({""}),"/");
  return 0;  // Coogan, 27-Mar-2011
}

// private function that evaluates the move hook, Ugh, Aug-05-1996
// made it public, Carador, 09-Sep-1997

varargs public status test_move_hook(string dir,string str,status silently) {
  mixed hook;
  if (hook=exits[dir,EXIT_HOOK])
    if ((closurep(hook) && funcall(hook,str,silently)) ||
        (stringp(hook) && call_other(this_object(),hook,str,silently)) ||
        (intp(hook) && hook))
      return 1;
  return 0;  // Coogan, 27-Mar-2011
}

static status use_exit_prevented;

public status prevent_use_exit(string dir_str) {
  mixed hook,h;
  string dir,str;
  if (!used_exit) 
    return 0;
  if (stringp(used_exit[0]) &&  // stringp-check by Coogan, 05-Apr-1999
      dir_str != used_exit[0])
    return 0;
  dir=used_exit[1];
  str=used_exit[2];
  used_exit=0; // to avoid too deep recursions
#if 0  // Alfe 2006-Apr-4
  h=test_move_hook(dir, str, 1);  // added silently, Coogan, 17-Sep-2001
#else
  h=test_move_hook(dir, str, 0);  // and removed it again, Alfe 2006-Apr-4
  // Why was the silently added?  With it, the barring hellhound in
  // ~darkstar/rooms/grove made no message "the hellhound is barring
  // your way."  Well, he could have made that message _despite_ the
  // silent flag, but that is no good solution either.
  // Any good reason for adding the silent flag here?
#endif
  use_exit_prevented=h;
  return h;
}

// completely rewritten, Ugh, Aug-05-1996

public status use_exit(string dir,string str) {
  mixed h;
  int f,old_use_exit_prevented;
  mixed hook;
  mixed old_used_exit;
  object old_environment;
  if (!exits || member(command_list, dir)<0) return 0;
  f=funcall(exits[dir,EXIT_FLAGS]);
  if (str && !(f & EXIT_LONGER_THAN_VERB)) 
    return notify_fail(capitalize(dir)+" "+str+"?\n"), 0;
  if ((f & EXIT_VISIBLE_IF_OPEN) && test_move_hook(dir,str,1)) return 0;
  old_used_exit=used_exit;
  old_use_exit_prevented=use_exit_prevented;
  used_exit=({exits[dir,EXIT_DIR]||dir,dir,str});
  use_exit_prevented=0;
  old_environment=environment(this_player());
#if 0  // Alfe 1999-Feb-03
  this_player()->move_living(funcall(exits[dir,EXIT_DIR]) || dir,
                             query_dest(dir) || environment(this_player()));
#else
  h = funcall(exits[dir,EXIT_DIR]) || dir;
  if (stringp(h))
    this_player()->move_living(h,(query_dest(dir) ||
                                  environment(this_player())));
  else if (mappingp(h))
    this_player()->move_living(dir,(query_dest(dir) ||
                                    environment(this_player())),
                               h["out"],h["in"]);
  else if (pointerp(h))
    this_player()->move_living(dir,(query_dest(dir) ||
                                    environment(this_player())),h);
  else
    raise_error("Bad direction in use\n");
#endif
  used_exit=old_used_exit;
  f=use_exit_prevented;
  use_exit_prevented=old_use_exit_prevented;
  return notify_fail("",-1), !f; // changed && to ',', Alfe 96-Oct-10
}

private int update_actions_flag;

void remove_exit(mixed command) {
  if (!exits)
    return;
  if (pointerp(command)) {
    update_actions_flag=1;
    map(command,#'remove_exit);
    update_actions_flag=0;
    update_actions();
  }
  else {
    m_delete(exits,command);
    command_list-=({ command });
    if (!update_actions_flag)
      update_actions();
  }
}

varargs void add_exit(mixed dest, string dir, mixed hook, mixed flags,
                      mixed vis_dir) {
  if (stringp(dest) && dest[0..1]=="./")
    dest=implode(explode(object_name(this_object()),"/")[0..<2],"/")+dest[1..];
  else if (stringp(dest) && dest[0..2]=="../")  // Alfe 1999-Feb-03
    dest=implode(explode(object_name(this_object()),"/")[0..<3],"/")+dest[2..];
  // next two lines by sunblood 25-sep-1999
  if (stringp(dest))
    dest = make_shared_string(dest);
  if (exits) {
    exits+=([ dir:dest;hook;flags;vis_dir ]);
    command_list=command_list-({ dir })+({ dir });
  }
  else {
    exits=([ dir:dest;hook;flags;vis_dir ]);
    command_list=({ dir });
  }
  if (!update_actions_flag)
    update_actions();
}

varargs mixed query_exit(mixed command) {
  string *commands;
  int i;
  mixed result,tmp;
  if (!command) {
    commands=exits && command_list[0..];
    if (!commands || !sizeof(commands)) return 0;
    result=allocate(5);
    result[0]=commands;
    for (i=1;i<sizeof(result);i++)
      result[i]=allocate(sizeof(commands));
    for (i=0;i<sizeof(commands);i++) {
      result[1][i]=query_dest(commands[i]);
      result[2][i]=exits[commands[i],EXIT_HOOK];
      result[3][i]=funcall(exits[commands[i],EXIT_FLAGS]);
      result[4][i]=funcall(exits[commands[i],EXIT_DIR]);
    }
    return result;
  }
  if (exits)
    if (result=query_dest(command))
      return result;
    else {
      if (objectp(command))
        command=object_name(command);
      else if (stringp(command)) 
        command=implode(explode(command,"/")-({""}),"/");
#if 0 // Chameloid, 11-Dec-1997
      for (i=0;i<sizeof(tmp=m_indices(exits));i++)
#else
      for (i=sizeof(tmp=m_indices(exits));i--;)
#endif
        if (query_dest(result=tmp[i])==command)
          return result;
    }
  return 0;  // Coogan, 24-Mar-2011
}

mixed * query_dest_dir() {
  mixed *result;
  string *commands;
  int i;
  if (!exits) return 0;
  result=allocate(sizeof(commands=command_list)*2);
  for (i=0;i<sizeof(commands);i++) {
    result[2*i]=query_dest(commands[i]);
    result[2*i+1]=commands[i];
  }
  return result;
}

string * query_command_list() {
  return command_list && command_list[0..];
}

// made varargs, Coogan, 26-Sep-2010
varargs void set_exits(mixed *dests, string *commands, mixed *hooks,
                       int *flags, mixed *dirs) {
  int i;
  exits=0;
  command_list=0;
  update_actions_flag=1; // no further call of update_actions() by add_exit()
  if (dests && pointerp(dests) && sizeof(dests) && pointerp(dests[0])) {
    for (i=0;i<sizeof(dests);i++) {
      switch (sizeof(dests[i])) {
      case 2: 
        add_exit(dests[i][0],dests[i][1]);
        break;
      case 3:
        add_exit(dests[i][0],dests[i][1],dests[i][2]);
        break;
      case 4:
        add_exit(dests[i][0],dests[i][1],dests[i][2],dests[i][3]);
        break;
      case 5:
        add_exit(dests[i][0],dests[i][1],dests[i][2],dests[i][3],dests[i][4]);
        break;
      }
    }
  }
  else 
    for (i=0;i<sizeof(dests);i++)
      add_exit(dests[i],commands[i],
               (i<sizeof(hooks)? hooks[i]:0),
               (i<sizeof(flags)? flags[i]:0),
               (i<sizeof(dirs)? dirs[i]:0));
  update_actions_flag=0; // we still want to be able to add exits :)
  update_actions(); // let's not forget it afterwards
}

void set_move_hooks(mixed *hooks) {  /* this for the sake of compatibility */
  int i;
  if (!exits || !pointerp(hooks))
    return;
  for (i=0;i<sizeof(command_list) && i<sizeof(hooks);i++)
    exits[command_list[i],EXIT_HOOK]=hooks[i];
}

status exit_command(string str) {
  return use_exit(query_verb(),str);
}

private mixed default_exit_hook;

static status no_exit_hook(string direction) {
#if 1  // Alfe 2001-Sep-3
  notify_fail("There's no exit in that direction.\n");
  return 0;
#else
  write("There's no exit in that direction.\n");
  return 1;
#endif
}

void set_default_exit_hook(mixed hook) {
  default_exit_hook = hook;
}

mixed query_default_exit_hook() {
  return default_exit_hook || #'no_exit_hook;
}

status default_exit_command(string str) {
  mixed hook;
  string direction;
  if (!str &&
      (direction = orientation_long(query_verb())) &&
      (!query_exit(direction) ||
       // added funcall() below as described in the manpage, Coogan, 03-Aug-1998
       ((funcall(exits[direction,EXIT_FLAGS]) & EXIT_VISIBLE_IF_OPEN) &&
        test_move_hook(direction,str,1)))) {
    if (hook = query_default_exit_hook()) {
      if (closurep(hook))
#if 1  // Alfe 2001-Sep-3
        return
#endif
          funcall(hook,direction);
      else if (stringp(hook))
#if 1  // Alfe 2001-Sep-3
        return
#endif
          call_other(this_object(),hook,direction);
      return 1;
    }
  }
  return 0;  // Coogan, 27-Mar-2011
}

status set_show_exits(status flag) {  // Arkon, 05-Jan-1995
  return show_exits=!!flag;
}

status query_show_exits() {  // Arkon, 05-Jan-1995
  return show_exits;
}

// this can be overridden by inheriters to get something else but the
// string 'obvious exit' (e.g. 'possible landing place').
string obvious_exit_description(status plural) {
  return plural? "obvious exits" : "obvious exit";
}

// so it can be overridden in case some exits are not to be mentioned
// (maybe because they are obvious anyway as all eight directions while
// swimming on the sea or while flying)
string *query_exit_long_commands() {
  return command_list[0..];
}

// 'brief' flag added by Carador, Feb-1995
// the second argument passed to the move hook means 'silently', thus
// no messages should be given, Ugh Jun-14-1995 

varargs string query_exit_long(status brief) {
  string *obvious,*not_obvious;
  int i,flags;
  mixed hook;

  if (!show_exits)
    return ""; // Arkon, 05-Jan-1995
  if (!command_list || !sizeof(obvious=query_exit_long_commands()))
    return (brief? 0 : "There are no " + obvious_exit_description(1) + ".\n");
  not_obvious=({}); // none not obvious yet
  for (i=0;i<sizeof(obvious);i++) {
    flags=funcall(exits[obvious[i],EXIT_FLAGS]);
    if (flags & EXIT_INVISIBLE)
      not_obvious+=({ obvious[i] });
    else
      if ((flags & EXIT_VISIBLE_IF_OPEN) && test_move_hook(obvious[i],0,1))
        not_obvious+=({ obvious[i] });
  }
  obvious -= not_obvious;
  switch (sizeof(obvious)) {
  case 0:
    return brief? 0 : "There are no " + obvious_exit_description(1) + ".\n";
  case 1:
    if (!brief)
      return ("There is one " + obvious_exit_description(0) + ": " +
      // TERMCOL_DESC_* tokens added by Coogan, 02-Jun-2003, 20-Jun-2003
              TERMCOL_DESC_EXIT + obvious[0] + TERMCOL_DESC_NORMAL + ".\n");
    return "Exit: " + TERMCOL_DESC_EXIT + obvious[0] + TERMCOL_DESC_NORMAL;
  default:
    if (!brief)
      return ("There are " + (LIB_PARSE->get_numeral(sizeof(obvious))) + " " +
              obvious_exit_description(1) + ": " +
              make_list(map(obvious,
                            (: TERMCOL_DESC_EXIT + $1 + TERMCOL_DESC_NORMAL :)))
              + ".\n");
    return "Exits: " +
           implode(map(obvious,(: TERMCOL_DESC_EXIT+$1+TERMCOL_DESC_NORMAL :)),
                   ", ");
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

string long(string str) {
  return query_exit_long();
}

string query_long(string str) {  // *sigh*
  return query_exit_long();
}

void move_create_room(string str) {
  mixed err;
  if (err=catch(call_other(str,"???")))
    log_file("LOAD_ERR","Load failed for '"+str+"' "+ctime(time())+"\n");
}

void remove() {
  int i;
  object *inv;
  inv=all_inventory(this_object());
  for(i=0;i<sizeof(inv);i++) {
    /* move them to a safe place */
    inv[i]->move("/room/void");
    move_object(inv[i],"/room/void"); /* just to be sure */
  }
  destruct(this_object());
}

// next four functions added by Ugh for blocking handling, Jun-20-1996

private static mapping blocking;

void set_blocking(object who,string exit,closure condition) {
  if(exit) {
    if (!query_exit(exit))
      return;
    if (!blocking)
      blocking=([]);
    blocking+=([who:exit;condition||1]);
  }
  else if (blocking)
    m_delete(blocking,who);
}

object * query_blocked(string exit,object who) {
  mixed h;
  if (!blocking || !query_exit(exit))
    return 0;
  blocking=filter_indices(m_delete(blocking,0),#'present,this_object());
  h=filter_indices(blocking,
                     lambda(({'x}),
                            ({#'&&,
                              ({#'==,({#'[,blocking,'x}),exit}),
                              ({#'!=,'x,who}), // don't block yourself
                              ({#'funcall,({#'[,blocking,'x,1}),who})
                            })));
  return sizeof(h) && m_indices(h);
}

varargs mixed query_blocking(object who) {
  if (blocking)
    blocking=filter_indices(m_delete(blocking,0),#'present,this_object());
  if (who)
    return blocking && blocking[who];
  else
    return blocking? copy(blocking):([]);
}

void notify_leave(object who,object where) {
  if (blocking)
    m_delete(blocking,who);
}

string get_orientation(string direction, int mode) {
  switch (mode) {
  case OM_REVERSE:
    return orientation_reverse(direction);
  case OM_RIGHT:
    return orientation_right(direction);
  case OM_LEFT:
    return orientation_left(direction);
  case OM_AHEAD:  // Coogan, 24-Mar-2011
    return 0;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

