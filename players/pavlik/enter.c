inherit "room/room";

/*
 * Things this room is to do:
 *    Remove ALL items from the player except soul and quicktyper
 *    Put all these items into safety-box
 *    Clone Arena_Soul and move to player
 *    Give player a basic weapon
 *    Move player into one of the 4 entrances
 */

reset(arg) {
if(arg) return;
set_light(1);
short_desc="Entrance";
long_desc=
"The Entrance.\n"+
"Make sure to put LARGE SIGNS here for the players to read.\n";

dest_dir=({
 "/players/pavlik/arena/room1", "enter",
 "/players/pavlik/workroom", "leave",
});

}

init() {
  ::init();
  add_action("read","read");
  add_action("enter","enter");
}

enter() {
  object ob, obj;
  string item;
  int i;

  write(
  "An iron box bound tightly with enormous chains appears before you.\n"+
  "The box's lid opens slowly and ***ALL*** of your worldly possessions\n"+
  "disappear into it.  The heavy lid closes and the lock and chains bind\n"+
  "themselves securely around the chest.\n"+
  "The heavy iron box disappears.\n");

  obj = clone_object("players/pavlik/mon");
  move_object(obj, environment(this_player()));

  this_player()->transfer_all_to(obj);

  ob = all_inventory(this_player());
  for(i=0; i<sizeof(ob); i++) {
    if(ob[i]->id("ND") || ob[i]->id("quicktyper")) {
	continue;
    }
    else {
	item = ob[i]->short();
	if(item) write("Removing: "+item+".\n");
	move_object(ob[i], obj);
    }
  }

  write("Done.\n");
  return 1;
}


