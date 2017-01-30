#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
id(str) { return str == "titlemaker"; }

init() {
  add_action("set_title","set_title");
}

set_title() {
find_player("soundgarden")->set_guild_name("rangers");
return 1;}
