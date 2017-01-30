/*
 follower.c - make code to cause following a player
              this is cloned & placed in the player
              it is destroyed when you stop following.
              also, it is invisible. :)
*/

inherit "obj/armor";

string owner_name, who2, who3, who, str, where, msg, s1, s2;
int following;
object follow_who, me;

reset(arg) {
  :: reset(arg);
  if (arg) return;

  set_value(5);
  set_weight(0);
  set_ac(1);
  set_type("ring");
  enable_commands();
  set_long("It is transparent.\n");
}

drop() {
  if (!name) return;
  sscanf(name, "%sfollower", str);
  if (!str) return;
  command("shadow",find_living(str));
  return 1;
}

query_weight() { return 0; }  

set_short(str) { short_desc = str; }

id(str) { return (str==name || "xfollower"); }

catch_tell(str) {
  if (!str) return;
  if (sscanf(str,"%s leaves %s.",who2, where) == 2) {
    who3=lower_case(environment(this_object())->query_name());
    follow_who=environment(this_object());
    sscanf(name, "%sfollower", owner_name);
    me=find_living(owner_name);
    msg="Shadowing "+who3+" "+where+".\n";
    tell_object(me,msg);
    if (where == "north") where="n";
    else
    if (where == "northeast") where="ne";
    else
    if (where == "east") where="e";
    else
    if (where == "southeast") where="se";
    else
    if (where == "south") where="s";
    else
    if (where == "southwest") where="sw";
    else
    if (where == "west") where="w";
    else
    if (where == "northwest") where="nw";
    else
    if (where == "up") where="u";
    else
    if (where == "down") where="d";
    else
    if (where == "exit") where="exit";

/* turn it off if not in the same room as target */
    if (!name) return;
    sscanf(name, "%sfollower", str);
    if (!str) return;
    if (environment(follow_who) != environment(find_living(str)))
      {
      command("shadow",find_living(str));
      return 1;
    }

/* chase 'em */
    command(where, me);
  }
  return 1;
}
