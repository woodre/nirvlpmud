/*
 show_bat.c -   This is a showoff bat.
*/

#include "lib/defs.h"

object player_obj, users_list;

string msg, help_str, this_verb;

int i;

inherit "obj/treasure";

init() {
  add_action("show_bats", "show");
  add_action("show_bats", "showa");
  add_action("show_bat",  "show1");
}

show_bats(arg) {
  this_verb = query_verb();
  if (arg=="bat") arg=arg+" .";
  if (sscanf(arg, "bat %s", msg) != 1) return;
  users_list=users();
  for (i=0; i < sizeof(users_list); i++) {
    player_obj=users_list[i];
    if (this_verb=="showa")
      show_it();
    else
    if (present("noonelse@vampire@fangs", player_obj) ||
          present("vampirebite", player_obj))
      show_it();
  }
  return 1;
}

show_bat(arg) {
  if (!arg) {
    write("Give the name of the player to show the bat to.\n");
    return 1;
  }
  player_obj=find_living(arg);
  if (!player_obj) {
    write("That player can't be found right now.\n");
    return 1;
  }
  msg=".";
  show_it();
  return 1;
}

show_it() {
  string who_msg;
  if (!player_obj) return;
  if (in_editor(player_obj)) {
    write("That player is in the editor right now.  Not showing bat.\n");
    return;
  }

  write("Now showing bat to "+player_obj->query_real_name()+"\n");
  tell_object(player_obj,
"\n\n\n\n\n"+HIR+
"                            -.                       .-\n"+
"                        _..-'(                       )`-.._\n"+
"                     ./'. '||\\\\.      |\\___/|      .//||` .`\\.\n"+
"                  ./'.|'.'||||\\\\|..   \\ -v- /   ..|//||||`.`|.`\\.\n"+
"               ./'..|'.|| |||||\\``````=(___)=''''''/||||| ||.`|..`\\.\n"+
"             ./'.||'.|||| ||||||||||||. V-V .|||||||||||| ||||.`||.`\\.\n"+
"            /'|||'.|||||| |||||||||||||     ||||||||||||| ||||||.`|||`\\\n"+
"          '.||| ||||||||| |/'   ``\\||``     ''||/''   "+
"`\\| ||||||||| |||.`\n"+
"          '.||| ||||||||| |/'   ``\\||``     ''||/''   `\\| ||||||||| |||.`\n"+
"          |/' \\./'     `\\./         \\!|\\   /|!/         \\./'     `\\."+
"/ `\\|\n"+
"          V    V         V          }' `\\ /' `{          V         V    V\n"+
"          `    `         `               V               '         '    '\n"+
"\n"+
"                                 I want your blood!\n\n"+NORM);
  who_msg=capitalize(this_player()->query_real_name());
  if (msg=="leave")
    msg=HIR+"                  "+who_msg+" is leaving the mud!"+NORM;
  if (msg=="enter" || msg=="arrive")
    msg=HIR+"                  "+who_msg+" is entering the mud!"+NORM;
  if (msg != ".")   tell_object(player_obj, HIR+"          "+msg+NORM+"\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  help_str="A showoff bat.  (normally shows only members. <a>=all)\n"+
           "                Use: show<a> bat\n"+
           "                     show<a> bat <msg>\n"+
           "                     show<a> bat leave\n"+
           "                     show<a> bat enter\n"+
           "                     show1 <who> (to show one player)\n";
  set_short(help_str);
  set_long(help_str+"\n");
  set_value(0);
  set_weight(0);
}

id(str) { return (str=="showbat" || str=="bat"); }
