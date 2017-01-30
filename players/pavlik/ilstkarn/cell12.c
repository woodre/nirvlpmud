#include <ansi.h>
inherit "room/room";

object owner;

reset(arg) {
if(arg) return;
set_light(1);
short_desc="a cold dark Cell";
long_desc=
"You step into one of the dark prison cells of Arcydia's dungeon.  The\n"+
"cold, damp walls crowd you and you have to supress a feeling of\n"+
"clausterphobia.  The lingering stench of the cell's past victims\n"+
"attacks your senses.  You gaze through the iron bars of the cell's\n"+
"gate and see the relative safety of the dim corridor.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/null", "west",
});

}

query_ilstkarn(){ return "doppleroom"; }
query_nofollow() { return 1; }
query_no_teleport(){ return 1; }
realm(){ return "NT"; }

set_owner(ob) { owner = ob; }
query_owner() {
  if(!owner || !present(owner, this_object())) {
     owner = 0;
     return 0;
  }
  if(!present(owner, this_object())) {
     move_object(owner, this_object());
  }
  return owner;
}

init() {
  ::init();
  if(this_player()->is_dopple()) {
    return;
  }
  if(!this_player()->is_player()) {
    tell_room(this_object(),
    capitalize(this_player()->query_name())+" disappears.\n");
    move_object(this_player(), "/players/pavlik/waste_room");
    destruct(this_player());
    return;
  }
  if(query_owner() && this_player() != query_owner()) {
    tell_room(this_object(),
    capitalize(this_player()->query_real_name())+" disappears.\n");
    move_object(this_player(), "players/pavlik/ilstkarn/dungeon16");
    return;
  }
  owner = this_player();
  if(present("doppleganger", this_object())) {
     present("doppleganger", this_object())->init_dopple(this_player());
  }
  else {
     move_object(clone_object("players/pavlik/monsters/ilstkarn/dopple"),
     this_object());
     present("doppleganger", this_object())->init_dopple(this_player());
  }
  add_action("west","west");
}

west() {
  if(present("doppleganger", this_object())) {
    write("You cannot leave!\n");
    return 1;
  }
  else {
    this_player()->move_player("west#players/pavlik/ilstkarn/dungeon16");
    owner = 0;
    return 1;
  }
}

