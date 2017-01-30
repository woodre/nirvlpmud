#include "/players/mythos/closed/ansi.h"

string alias, short_desc, long_desc;

id(str) { return str == "post" || str == alias; }

drop() { return 1; }

get() { return 0; }

short() { return short_desc; }

long() { write(long_desc); }

set_short(str) { short_desc = str; }

set_alias(str) { alias = str; }

set_long(str) { long_desc = str; }

init() {
  add_action("chip","chip");
}

chip(str) {
object ob; 
  if(!str) return 0;
  if(id(str)) {
    write("You chip off a piece of the "+short_desc+".\n");
    ob = clone_object("/players/mythos/closed/guild/task/horlach/chip.c");
    ob->set_id(alias);
    ob->set_short("Chip of "+short_desc);
    move_object(ob,this_player());
  return 1; }
return 0;}