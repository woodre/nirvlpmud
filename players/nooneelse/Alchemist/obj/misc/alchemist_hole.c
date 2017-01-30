/*
  alchemist_hole.c
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

int hidden, covered, i, weight;
string owner_name;

is_castle() { return 1; }

init() {
  add_action("search_item", "search");
}

search_item(str) {
  if(this_player()->query_real_name()==owner_name) {
    write("You remember that you burried something here and uncover a hole.\n");
    hidden=0;
    return 1;
  }
  if(present("guild gloves", this_player()) &&
     present("guild gloves", this_object())) {
    write("You search for a while, but find nothing useful.  You get the\n"+
          "feeling that something might be here, but it's hard to find.\n");
    return 1;
  }
  if(present("Alchemist Pouch", this_player()) && random(100) < 40) {
    write("You discover something that was burried here by someone and\n"+
          "uncover a hole.\n");
    hidden=0;
    return 1;
  }
  if(random(100) < 5) {
    write("You notice that something is buried here and uncover a hole.\n");
    hidden=0;
    return 1;
  }
  write("You search for a while, but find nothing useful.  You get the\n"+
        "feeling that something might be here, but it's hard to find.\n");
  return 1;
}

query_save_flag() { return 1; }

reset(arg) {
  if(!arg) return;
  return;
}

short() {
  if(hidden) return;
  return "A hole in the ground";
}

long() {
  if(hidden) {
    write("What?\n");
    return 1;
  }
  else {
    write("This is little hole in ground.\n");
    if(!first_inventory(this_object()))
      write("It seems to be empty.\n");
    else
      write("There seems to be something in it.\n");

  }
}

get() { return; }

drop() { return 1; }

can_put_and_get() { return 1; }

add_weight(i) {
  weight=weight+i;
  return 1;
}

set_hidden(i) { hidden=i; }

set_owner(str) { owner_name=str; }

query_hidden() { return hidden; }

query_owner() { return owner_name; }

self_destruct_timer(i) { call_out("self_destruct", i); }

self_destruct() {
  if(!first_inventory(this_object())) {
    destruct(this_object());
    return 1;
  }
  call_out("self_destruct", 60);
}

id(str) {
  if(hidden) return str=="alchemist_hole" ||
                    str=="hidden_hole" ||
                    str=="hidden hole" ||
                    str=="guild_hole" ||
                    str=="guild hole" ||
                    str=="hidden_item";
  return str=="hole";
}
