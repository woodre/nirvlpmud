inherit "room/room";
#define POR "/players/pavlik/ilstkarn/ilstkarn_portal.c"
#define REALMSIZE 14

reset(arg) {
if(arg) {
  return;
}
set_light(1);
short_desc="In the Dungeons of Arcydia";
long_desc=
"You have reached the end of the completed section of this area.  This\n"+
"room will take you up into the halls of Arcydia, amongst the most\n"+
"powerful and evil Wizards ever known.  Thank you for your interest\n"+
"in this area, if you have any questions or comments mail Pavlik.\n"+
"The corridor leads southward from here.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/dungeon16", "south",
 "/players/pavlik/ilstkarn/null", "leave",
});

}

init() {
  ::init();
  add_action("leave","leave");
}

leave() {
  write("You leave the dungeons of Arcydia.\n");
  say(capitalize(this_player()->query_real_name())+" leaves the dungeons.\n");
  move_object(this_player(), environment("players/pavlik/ilstkarn/ilstkarn_portal"));
  command("look", this_player());
  return 1;
}

query_ilstkarn(){ return "dungeon17"; }
realm(){ return "NT"; }


okay_follow() { return 1; }
