/*
  vampire_fangs.c - this closes down the vampire guild
*/

string msg;

init_arg() {
  write(msg);
  return 0;
}

reset(arg) {
  msg =  "\n\n"+
    "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n"+
    "<>                                                                      <>\n"+
    "<>  I've gotten entirely too sick and tired of this mud.  As a result,  <>\n"+
    "<>  I've removed all my stuff from this mud. Sorry guys. Good luck.     <>\n"+
    "<>                                                                      <>\n"+
    "<>  Type 'break fangs' to destroy this item & release yourself from     <>\n"+
    "<>  the guild.                                                          <>\n"+
    "<>                                                                      <>\n"+
    "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n\n";
}

short() {
  return msg;
}

long() {
  write(msg);
}

query_auto_load() { return "/players/nooneelse/black/vampire_fangs.c:"; }

get() { return 1; }

drop() { return 1; }

id(str) { return (str=="nooneelse vampire fangs" ||
                  str=="vampirefangs" || str=="vampire fangs" || str=="fangs" ||
                  str=="guild item" || str=="guild_item" ||
                  str=="guild_obj" || str=="guild obj" ||
                  str=="guild item: fangs"); }

init() {
  add_action("break_fangs", "break");
}

break_fangs(arg) {
  int i;

  if (arg!="fangs") return 0;
  this_player()->set_title("-->former member of the vampire guild");
  i = this_player()->query_guild_exp();
  this_player()->add_guild_exp(-i);
  this_player()->set_guild_name(0);
  this_player()->set_guild_file(0);
  destruct(this_object());
  return 1;
}

