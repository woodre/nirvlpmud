inherit "/obj/treasure";

#include "/include/cfg/levels.h"

void reset(status arg) {
  if (arg) return;
  set_name("promoter");
  set_short("Promoter");
  set_long("A Promoter tester.\n");
  set_value(0);
  set_weight(0);
}

void init() {
  if ((string)this_player()->query_name(1) != "rumplemintz") return 0;
  add_action("rumppromote", "rumppromote");
}

status rumppromote(string str) {
  object ob;
  int new_level;
  string level_name;

  if (!str ||
      (sscanf(str, "%s %d", str, new_level) != 2 &&
       sscanf(str, "%s %s", str, level_name) != 2)) {
    write("Usage: promote <who> <level|level name>\n");
    write("Notes: promotes a player to security level, <level> or " +
          "<level name>.\n" +
          "       level names: asp, app, creator, sage, lord, sen, elder, " +
          " arch, or admin.\n" +
          "       see also 'domain' command.\n");
    return 1;
  }
  if (!(ob = find_player(str, environment()))) {
    write(capitalize(str) + " is not playing.\n");
    return 1;
  }
  if (level_name) {
    switch(level_name) {
      case "admin": case "administrator": new_level = SEC9; break;
      case "arch"                       : new_level = SEC8; break;
      case "elder"                      : new_level = SEC7; break;
      case "sen": case "senior"         : new_level = SEC6; break;
      case "lord"                       : new_level = SEC5; break;
      case "sage"                       : new_level = SEC4; break;
      case "creator"                    : new_level = SEC3; break;
      case "app": case "apprentice"     : new_level = SEC2; break;
      case "asp": case "aspirant"       : new_level = SEC1; break;
      default                           : rumppromote(0); return 1; break;
    }
  }
  ob->set_security_level(new_level);
  return 1;
}

