
#define FILE_NAME       "players/merlyn/closed/guild/typer"
#define ME              environment()

#include "/obj/debug.h"

string  owner;
object  list_ab;
object  list_cmd;

string thingone, thingtwo;

int     refreshing;
int     needs_refresh;
object  ob;

/*
  return som info for the interested
 */
query_info() { return "A type speeder modified by Merlyn"; }

/*
  make it possible to retrieve information from the quicktyper
 */
query_magetyper(arg)
{
  if (arg == 0) return list_ab;
  if (arg == 1) return list_cmd;
  return 0;
}

id(str) { if (str == "magetyper" || str == "ND" || str == "typer" || str == "mt") return 1; }

query_name() { return owner + "'s MageTyper"; }

reset(arg)
{
  if (ME) tell_object(ME,"MageTyper Reset (" + arg + ").\n");
  if (is_debug) {
    write("reset(" + arg + ")\n");
    write("this_object()="); write(this_object()); write("\n");
    write("environment(this_object())="); write(environment(this_object())); write("\n");
    write("this_player()="); write(this_player()); write("\n");
    write("environment(this_player())="); write(environment(this_player())); write("\n");
  }
  if (!refreshing && this_player()) owner = this_player()->query_name();
}

init_alias_list()
{
  object obj;
  if (!list_ab)  list_ab  = allocate(34);
  if (!list_cmd) list_cmd = allocate(34);
}

init(arg)
{
  int i;
  object obj;
  if (is_debug) {
    write("init(" + arg + ")\n");
    write("this_object()="); write(this_object()); write("\n");
    write("environment(this_object())="); write(environment(this_object())); write("\n");
    write("this_player()="); write(this_player()); write("\n");
    write("environment(this_player())="); write(environment(this_player())); write("\n");
  }
  if (this_player()) owner = this_player()->query_name();
  init_alias_list();
  if (environment(this_object()) == this_player()) {
    add_action("alias", "alias");
    add_action("do_cmd", "do");
    add_action("resume", "resume");
    add_action("do_refresh", "refresh");
    add_action("help", "help");
/* let wizards have some additional information commands */
    if (call_other(this_player(), "query_level") >= 20) {
      add_action("version", "ver");
      add_action("debug_toggle", "debug");     /* declared in debug.h */
    }
    i = 0;
    while (i < sizeof(list_ab)) {
      if(list_ab[i] && list_ab[i] != "" && list_cmd[i] && list_cmd[i] != "") {
        add_action("do_it", list_ab[i]);
      }
      i += 1;
    }
    if (!refreshing) {
      write("MageTyper ...\n");
    } else {
      if (is_debug) {
        write("MageTyper Refresh -init \n");
      }
    }
    if (!needs_refresh && !refreshing) {
      if (is_debug) {
        write("MageTyper: Refresh in 30 sec.\n");
        needs_refresh = 1;
      }
      call_out("refresh", 30, this_player());
    }
  }
}

do_refresh()
{
  write("MageTyper: Refreshing ... ");
  refresh(this_player());
  write("Done.\n");
  return 1;
}

refresh(obj)
{
  if (is_debug) {
    tell_object(obj, "MageTyper: Refreshing ... ");
  }
  refreshing = 1;
  move_object(this_object(), "room/storage");
  if (is_debug) tell_object(obj, "moved to storage,");
  move_object(this_object(), obj);
  if (is_debug) tell_object(obj, "back again\n");
  refreshing = 0;
  needs_refresh = 0;
  return 1;
}

short() { return owner + "'s MageTyper"; }

long()
{
  write("This is a modification of the normal QuickTyper that is faster,\n"+
        "has more aliases, and allows a more complicated 'do' command.\n"+
        "For more information, type 'help magetyper'.\n");
}

alias(str)
{
  int i;
  string ab, cmd;
  owner = call_other(this_player(), "query_name");
  if (!str || str == "") {
    write("The aliases in your quicktyper are:\n");
    i = 0;
    while (i < sizeof(list_ab)) {
      if (list_ab[i]) {
        write(extract(list_ab[i] + "         ", 0, 9) + list_cmd[i] + "\n");
      }
      i += 1;
    }
    return 1;
  }
  if (sscanf(str, "%s %s", ab, cmd) == 2) {
    if (sscanf(cmd, "%s^%s", thingone, thingtwo) == 2 || sscanf(ab, "%s^%s", thingone, thingtwo) == 2) {
      write(" ^ is not a valid alias/command character.\n");
      log_file("BAD_PLAYER", ctime(time()) + " " + this_player()->query_real_name() + " with quicktyper autoload, file " + ab + " " + cmd + "\n");
      return 1;
    }
    if (ab == cmd) {
      write("That is not a valid alias/command pair.\n");
      return 1;
    }
    i=0;
    while (i < sizeof(list_ab)) {
      if (ab == list_cmd[i] || cmd == list_ab[i]) {
        write("That's not a valid alias/command pair.\n");
        return 1;
      }
      i = i + 1;
    }
    i = 0;
    while (i < sizeof(list_ab)) {
      if (list_ab[i] == ab) {
        list_cmd[i] = cmd;
        write("Ok.\n");
        return 1;
      }
      i += 1;
    }
    i = 0;
    while (i < sizeof(list_ab)) {
      if (!list_ab[i]) {
        list_ab[i] = ab;
        list_cmd[i] = cmd;
        add_action("do_it", list_ab[i]);
        write("Ok.\n");
        return 1;
      }
      i += 1;
    }
    write("Sorry the quicktyper is full!\n");
    return 1;
  }
  if(sscanf(str, "%s", ab) == 1) {
    i = 0;
    while(i < sizeof(list_ab)) {
      if(list_ab[i] && list_ab[i] == ab) {
        list_ab[i] = 0;
        list_cmd[i] = 0;
        write("Removed alias for " + ab + ".\n");
        return 1;
      }
      i += 1;
    }
    write(ab + " didn't have an alias!\n");
    return 1;
  }
  write("This can't happen!\n");
  return 0;
}

help(str)
{
  if (!str || !id(str)) return 0;
  write("The MageTyper allows you to perform rapid movements and extends your normal\n"+
        "quicktyper abilities.  You can do the following:\n\n"+
        "alias - Works the same as the normal quicktyper, except that you can have\n"+
        "        more aliases than normal.\n"+
        "do - Similar to the regular quicktyper 'do', except that it works as a\n"+
        "     macro movement.  Each command can be in the format:\n"+
        "       <repetitions><command>,<repetitions><command>\n"+
        "     The commands will be executed immediately.  Unfortunately, doing\n"+
        "     too many commands at once may cause you to be disconnected.  If you\n"+
        "     want to do a great number of commands, put a semicolon (;) instead\n"+
        "     of a comma.  This will insert a pause between the commands.  A\n"+
        "     typical command might be : do s,4w,3n,e;touch,kill guard,fireball\n\n");
  write("Have fun with your MageTyper!\n");
  owner = call_other(this_player(), "query_name");
  return 1;
}

get()
{
  object oldtyper;
  if (present("magetyper", this_player())) return;
  if (present("quicktyper",this_player())) {
    write("You pick up the MageTyper and toss away your old quicktyper.\n");
    destruct(present("quicktyper",this_player()));
    return(1);
  }
  if (present("speedster",this_player())) {
    write("You pick up the MageTyper and toss away your old speedster.\n");
    destruct(present("speedster",this_player()));
    return(1);
  }
  return 1;
}

drop() { return 1; }

query_value() { return 0; }

query_auto_load()
{
  string temp;
  int i, count;
  while (i < sizeof(list_ab)) {
    if (list_ab[i] && list_cmd[i]) count += 1;
    i += 1;
  }
  temp = FILE_NAME + ":"  + count + ";";
  i = 0;
  while (i < sizeof(list_ab)) {
    if (list_ab[i] && list_cmd[i]) temp += list_ab[i] + " " + list_cmd[i] + ";.X.Z;";
    i += 1;
  }
  return temp;
}

do_it(str)
{
  int i;
  string verb;
  
  if (is_debug) {
    write("query_verb=" + query_verb() + "\n");
    write("str=" + str + "\n");
  }
  verb = query_verb();
  if (verb == 0) return 0;
  i = 0;
  while (i < sizeof(list_ab)) {
    if (list_ab[i] == verb) {
      if (list_cmd[i] == 0) {
        list_ab[i] = 0;
      } else {
        if (str && str != "") {
          if (is_debug) write(list_cmd[i] + " " + str + "\n");
          command(list_cmd[i] + " " + str, this_player());
        } else {
          if (is_debug) write(list_cmd[i] + "\n");
          command(list_cmd[i], this_player());
        }
        return 1;
      }
    }
    i += 1;
  }
  return 0;
}

init_arg(arg)
{
  int temp;
  int count, place;
  string ab, cmd;
  string the_rest;
  if (is_debug) write("init_arg(" + arg + ")\n");
  if (arg) {
    the_rest = "";
    if (sscanf(arg, "%d;%s", count, the_rest) == 2) {
      if (is_debug) write("count=" + count + "\n");
      init_alias_list();
      while(the_rest && the_rest != "" && place < sizeof(list_ab)) {
        arg = the_rest;
        if (sscanf(arg, "%s %s;.X.Z;%s", ab, cmd, the_rest) >= 2) {
          if(ab && ab != "" && cmd && cmd != "") {
            list_ab[place] = ab;
            list_cmd[place] = cmd;
            place += 1;
          }
        }
      }
    }
  }
}


/* do one ore more commands */

string  org_cmds;
string  more_cmds;
int     first_call;
int     paused;

do_cmd(str)
{
  if (!str || str == "") {
    if (more_cmds) {
      set_heart_beat(0);
      write("Paused. Use \"resume\" to continue.\n");
      paused = 1;
    } else {
      write("usage: do cmd1,cmd2, cmd3,...\n");
    }
    return 1;
  }
  if (more_cmds && !paused) {
    write("Busy doing your commands:\n" + more_cmds + "\n");
    return 1;
  }
  if (paused) {
    write("Skipping paused commands:\n" + more_cmds + "\n");
    paused = 0;
  }
  more_cmds = str;
  ob = this_player();
  first_call = 1;
  heart_beat();
  first_call = 0;
  set_heart_beat(1);
  return 1;
}

resume()
{
  if (paused && ob && more_cmds && more_cmds != "") {
    paused = 0;
    first_call = 1;
    heart_beat();
    first_call = 0;
    set_heart_beat(1);
    return 1;
  }
  write("Nothing to resume.\n");
  return 1;
}

parse_path(str)
{
  string rest;
  int num, cnt, rep, kickout;
  while (str && !kickout) {
    num = sscanf(str,"%s,%s",str,rest);
    if (num == 2) {
      if (sscanf(str,"%d%s",rep,str) == 2) {
        cnt = 0;
        while (cnt < rep && !kickout) {
          cnt++;
          kickout = !command(adjust_path(str),ME);
        }
      } else {
        kickout = !command(adjust_path(str),ME);
      }
      str = rest;
    } else {
      if (sscanf(str,"%d%s",rep,str) == 2) {
        cnt = 0;
        while (cnt < rep && !kickout) {
          cnt++;
          kickout = !command(adjust_path(str),ME);
        }
      } else {
        kickout = !command(adjust_path(str),ME);
      }
      str = 0;
    }
  }
  if (kickout) write("Kickout.\n");
}

heart_beat()
{
  string the_rest;
  string cmd;
  if (ob && more_cmds && more_cmds != "") {
    if (sscanf(more_cmds, "%s;%s", cmd, the_rest) == 2) {
      tell_object(ob, "doing: " + cmd + "\n");
      parse_path(cmd, ob);
      more_cmds = the_rest;
    } else {
      cmd = more_cmds;
      tell_object(ob, "doing: " + cmd + "\n");
      parse_path(cmd, ob);
      more_cmds = 0;
      if (!first_call) set_heart_beat(0);
      tell_object(ob, "Done.\n");
    }
  } else {
    ob = 0;
    more_cmds = 0;
    if (!first_call) set_heart_beat(0);
  }
}

adjust_path(str)
{
  string mod;
  switch (str) {
    case "n": mod = "north"; break;
    case "s": mod = "south"; break;
    case "e": mod = "east"; break;
    case "w": mod = "west"; break;
    case "u": mod = "up"; break;
    case "d": mod = "down"; break;
   case "sw": mod = "southwest"; break;
   case "se": mod = "southeast"; break;
   case "nw": mod = "northwest"; break;
   case "ne": mod = "northeast"; break;
     default: mod = str; break;
  }
  return(mod);
}


