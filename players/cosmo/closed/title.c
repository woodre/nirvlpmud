#include "/players/cosmo/closed/ansi.h"
id(str) { return str == "titlemaker"; }

init() {
  add_action("titler","titler");
  add_action("pretitler","pretitler");
  add_action("guilder","guilder");
}

titler(arg) {
string who,whats;
  sscanf(arg, "%s %s",who,whats);
find_player(who)->set_title(whats);
return 1;}

pretitler(arg) {
string who,whats;
  sscanf(arg, "%s %s",who,whats);
  find_player(who)->set_pretitle(whats);
return 1; }

guilder(arg) {
string who,whats;
  sscanf(arg, "%s %s",who,whats);
  find_player(who)->set_guild_name(whats);
return 1; }
