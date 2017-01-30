/*
 guild_bag.c
*/

#include "/players/nooneelse/ansi.h"
inherit "obj/container";

string str;

init() {
  add_action("put_in_bag",    "put");
  add_action("take_from_bag", "take");
  add_action("take_from_bag", "get");
}

put_in_bag(str) {
  string item;
  if (!str) return;
  sscanf(str, "in guild bag %s", item);
  if (!item) sscanf(str, "in black bag %s", item);
  if (!item) return;
  if (!present(item, this_player())) return;
  command("put "+item+" in guild bag", this_player());
  return 1;
}

take_from_bag(str) {
  string item;
  if (!str) return;
  sscanf(str, "from guild bag %s", item);
  if (!item) sscanf(str, "from black bag %s", item);
  if (!item) return;
  command("get "+item+" from guild bag", this_player());
  return 1;
}

query_save_flag() { return 1; }

reset(arg) {
  ::reset(arg);

short_desc = GRY+"a grey silk bag"+NORM;
long_desc=
    "A g. ey bag.  (Use: put <item> in guild bag or get <item> from guild bag\n"+
    "               You can 'alias pb put in guild bag' & use commands\n"+
    "               like 'pb crown' to put a crown in the bag\n"+
    "               You can also 'alias gb get from guild bag' & use commands\n"+
    "               like 'gb crown' to get a crown from the bag\n";
value=5;
max_weight=45;
local_weight=0;
set_weight(1);
}

prevent_insert() {
  write("You don't really want to hide your guild's bag do you?\n");
  return 1;
}

id(str) { return (
		str == "bag" ||
		str == "guild bag" ||
		str == "silk bag" ||
		str == "grey bag");
}
