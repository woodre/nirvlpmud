/*
  hunt_list.c - scavenger hunt list
*/

inherit "obj/treasure";

string owner_of_list, *current_dates;
int NBR_ITEMS_PER_LIST; /* this must be changed in hunt_control too! */

set_owner_of_list(arg) { owner_of_list=arg; }
query_owner_of_list() { return owner_of_list; }

reset(arg) {
  name="scavenger hunt list";
  alias_name="list";
  set_value(0);
  set_weight(1);
  owner_of_list="nobody";
  NBR_ITEMS_PER_LIST=10;
  current_dates=allocate(NBR_ITEMS_PER_LIST);
}

id(str) {
  return str=="list" || str=="hunt list" || str=="scavenger hunt list";
}

short() { return capitalize(owner_of_list)+"'s Grand Scavenger Hunt List"; }

/* Adjust a field to display n characters for formatted displays */
ladjust(str, n) {
  return extract(str+
     "                                                                       ",
     0,n-1);
}

long() {
  string item_name, item_date, current_clue, current_item;
  int i, nbr_items_per_list;
  nbr_items_per_list=
    "/players/nooneelse/hunt/hunt_control"->query_nbr_items_per_list();
  write(short()+".\n\n"+
"clue or item name                                  turned in\n"+
"-----------------                                  ---------\n");
  for (i=0; i<nbr_items_per_list; i++) {
    current_clue="/players/nooneelse/hunt/hunt_control"->query_current_clue(i);
    current_item="/players/nooneelse/hunt/hunt_control"->query_current_item(i);
    if (current_item) {
      if (current_dates[i]) {
        write(ladjust(capitalize(current_item),50)+" ");
        write(current_dates[i]+"\n");
      }
      else
        write(ladjust(capitalize(current_clue),70)+"\n");
    }
  }
  write("\nIf you decide that the items on this list are too tough for\n"+
        "someone of your level, type 'burn list' & try in a later hunt.\n"+
        "The items aren't the same in every hunt.\n");
  return 1;
}

init() {
  add_action("quit", "quit");
  add_action("burn", "burn");
  add_action("dump", "dump");
}

quit() {
  burn("list");
  return 0;
}

burn(str) {
  if (!str || str != "list") return 0;
  "/players/nooneelse/hunt/hunt_control"->
    burn_list(this_player()->query_name());
  destruct(this_object());
  write("The list flares in flames and disappears.\n");
  say(this_player()->query_name()+" burns a piece of paper.\n", this_player());
  return 1;
}

mark_item(mark_name) {
  string item_name, item_date, current_item;
  int i, found_it, all_found, nbr_items_per_list;
  all_found=1;
  found_it=0;
  nbr_items_per_list=
    "/players/nooneelse/hunt/hunt_control"->query_nbr_items_per_list();
  for (i=0; i<nbr_items_per_list; i++) {
    current_item="/players/nooneelse/hunt/hunt_control"->query_current_item(i);
    if (current_item==mark_name ||
        (present(mark_name, environment(this_object())) &&
         present(current_item, environment(this_object())))) {
      current_dates[i]=ctime(time());
      found_it=1;
    }
    if (!current_dates[i]) all_found=0;
  }
  if (all_found) return 9;
  return found_it;
}

dump(str) {
  string current_clue, current_item;
  int i, nbr_items_per_list;
  if (this_player()->query_level() < 32) return 0;
  if (!str || str!="list") return 0;
  nbr_items_per_list=
    "/players/nooneelse/hunt/hunt_control"->query_nbr_items_per_list();
  write("\n\nItem numbers selected ("+nbr_items_per_list+")\n");
  for (i=0; i<nbr_items_per_list; i++) {
    current_clue="/players/nooneelse/hunt/hunt_control"->query_current_clue(i);
    current_item="/players/nooneelse/hunt/hunt_control"->query_current_item(i);
    write(current_item+"#"+current_clue+"\n");
  }
  return 1;
}
