inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="In the Lake";
  long_desc=
  "You are underwater!  You have sunk to the bottom of the underground\n"+
  "lake.  All types of bizzare sea life swim past you, their numerous\n"+
  "shapes and colors are a spectacle to behold.  It would be wonderful\n"+
  "to stay here and watch but unless you sprout some gills, you had better\n"+
  "find a place with some air.\n";
  dest_dir=({
	"/players/pavlik/ilstkarn/lake6", "west",
	"/players/pavlik/ilstkarn/lake1", "east",
	"/players/pavlik/ilstkarn/null", "up",
  });
  move_object(clone_object("players/pavlik/ilstkarn/monsters/sealife"),
  this_object());
}

query_ilstkarn(){ return "lake2"; }
realm(){ return "NT"; }
/* query_nofollow(){ return 1; } */
query_no_teleport(){ return 1; }
query_underwater(){ return 1; }

init() {
  ::init();
  if(this_player()->id("ilstkarn_monster")) {
	return;
  }
  if(!present("hold_breath", this_player())) {
	object hb;
	hb = clone_object("players/pavlik/ilstkarn/obj/hold_breath");
	move_object(hb, this_player());
	hb->add_breath(10);
  }
  add_action("go_up","up");
}

go_up() {
  if(get_player_weight(this_player()) >= 40) {
	write("You are to heavy to swim!\n");
	return 1;
  }
  write("You swim up to the lake's surface.\n");
  say(capitalize(this_player()->query_name())+" swims up.\n");
  move_object(this_player(), "players/pavlik/ilstkarn/lake_surface");
  command("look", this_player());
  return 1;
}

/*
 * This function gets the % of total possible weight being
 * carried by the player.
 */
get_player_weight(ob) {
  int weight_carried, player_max;
  object obj;

  obj = first_inventory(ob);
  weight_carried = 0;

  while (obj) {
    weight_carried += obj->query_weight();
    obj = next_inventory(obj);
  }
  player_max = ob->query_level() + 6 + ob->query_attrib("str") / 5;
  if (ob->query_frog()) player_max = player_max / 2;

  return (100 * weight_carried) / player_max;
}


okay_follow() { return 1; }
