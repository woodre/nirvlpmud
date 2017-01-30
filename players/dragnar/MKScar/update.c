#define TLIST "players/dragnar/MKScar/daemons/MKRank"
#include "scar.h"

inherit "obj/treasure";

mapping warr;
void
reset(int arg) {
   if (arg) return;
   set_id("tester");
   set_short("Tester");
   set_long(
"A tester for top killer list.\n");
   set_weight(0);
   set_value(1200);
   set_save_flag();
   warr = WARRIORS;
}

void init() {
  if(this_player()->query_level() > 39) {
    add_action("do_test","test");
    add_action("Begin","del");
	add_action("llist","llist");
  }
}

status
do_test(string str) {
  string winner,loser;

  if( !str) return 1;
  if( str == "reset" ) {
    TLIST->ResetList();
    write(TLIST->list());
    return 1;
  }
  if( str == "list" ) {
    write(TLIST->list());
    return 1;
  }
  sscanf(str, "%s %s",winner,loser);
  TLIST->Insert(winner, loser);
  write(TLIST->list());
   return 1;
}
Begin(str) {
  int x;
  string who;
  if(!str) return 0;
  sscanf(str, "%d", x);
  TLIST->Delete(x);
  return 1;
}

llist() {
  write(RANK->tail());
}
