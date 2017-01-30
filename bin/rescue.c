/*
 * /bin/rescue.c by Alfe for Tubmud 1996-Nov-28
 *
 * This is a daemon made for rescue cases. To use it you have to add it
 * to your daemon list with a high priority (number below zero). Read
 * 'man daemon' to find out how to do this.
 * After this you have three more commands: sec_list, sec_des and sec_move.
 * sec_list X      gives you a list of the inventory of object X. See below
 *                 to find out what X can be.
 * sec_dest X      destructs X without calling X's notify_destruct to avoid
 *                 it cloning another one of itself.
 * sec_move X Y    moves X into Y without calling any notify_- or prevent_-
 *                 function. The init()-functions will be called.
 * What can X and Y be?
 * "#4"    means the 4th object of the last use of sec_list.
 * "me"    means this_player() which will be you.
 * "here"  means environment(this_player()) which will be the room you are in.
 * Or anything in you, in your environment (both found via present()), a
 * player (find_player()), a living (find_living()) or an object
 * (find_object()).
 */

#pragma strong_types

inherit "basic/tools/lpc";

private object *list;

private status list(string s) {
  int i;
  object o;
  o = get_object(s,list);
  list = all_inventory(o);
  for (i=0; i<sizeof(list); i++)
    printf("#%-2d: %O\n",i,list[i]);
  return 1;
}

private void make_des(object o) {
#if 0  // Alfe 2001-Oct-5
  while (get_eval_cost() > 0x9000)
    ;
#endif
  destruct(o);
}

private status des(string s) {
  mixed h;
  if (!(h=get_object(s,list)))
    return notify_fail("No such object.\n"), 0;
  log_file("DESTRUCT",ctime() + " " + this_interactive()->query_vis_name() +
           " destructed " + h->query_name() + " (" + object_name(h) +
           ") with bin/rescue.\n");
  tell_object(this_interactive(),
              "PLEASE NOTE THAT DESTRUCTING OBJECTS WITH bin/rescue\n"
              "SHOULD BE DONE ONLY IN EMERGENCY CASES AND ALL USE OF IT\n"
              "WILL BE LOGGED!\n"
              "Please use the normal 'destruct' command for normal cases.\n");
  return catch(make_des(h); nolog), 1;
}

private status move(string s) {
  mixed h;
  h = explode(s," ");
  efun::move_object(get_object(h[0],list),get_object(h[1],list));
  return 1;
}

private status help(string s) {
  mixed h;
  h = read_file("/"+load_name(this_object())+".c");
  this_player()->tell_more(h[0..strstr(h,"\n\n")]);
  return 1;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//   The following makes this object a daemon
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

mapping get_commands() {
  return ([ "sec_list":"", "sec_des":"", "sec_dest":"", "sec_move":"",
            "sec_help":"" ]);
}

object find_instance() { return this_object(); }

status dispatch(string verb,string s) {
  switch (verb) {
  case "sec_list":
    return list(s);
  case "sec_des":
  case "sec_dest":
    return des(s);
  case "sec_move":
    return move(s);
  case "sec_help":
    return help(s);
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

