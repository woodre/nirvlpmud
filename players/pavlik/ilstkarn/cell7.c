#include <ansi.h>
inherit "room/room";
#define POR "/players/pavlik/ilstkarn/ilstkarn_portal.c"
#define ME capitalize(this_player()->query_name())

int busy;

reset(arg) {
if(arg) {
  return;
}
set_light(0);
short_desc="a cold dark Cell";
long_desc=
"You step into one of the dark prison cells of Arcydia's dungeon.  The\n"+
"cold, damp walls crowd you and you have to supress a feeling of\n"+
"clausterphobia.  The lingering stench of the cell's past victims\n"+
"attacks your senses.  You gaze through the iron bars of the cell's\n"+
"gate and see the relative safety of the dim corridor.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/dungeon13", "west",
});

busy = 0;

}

init() {
  ::init();
  if(this_player()->is_player()) sceptre_check();
  add_action("dont_go","west");
}

/*
 * this function checks for the kings sceptre and if not found
 * it places it in the room.  if the king has already been killed
 * once this reboot the sceptre will not clone again.
 */
sceptre_check() {
  object ob;
  int i, found;

  found = 0;
  if(present("kings_sceptre", this_object())) {
    return 1;
  }
  if(!POR->query_king()) {
    return 1;
  }
  ob = all_inventory(this_object());
  for(i=0; i<sizeof(ob); i++) {
    if(present("kings_sceptre", ob[i])) {
      found = 1;
    }
  }
  if(!found) {
    move_object(clone_object("players/pavlik/items/ilstkarn/kings_sceptre"),
    this_object());
  }
  return 1;
}

/*
 * This function is too long and screwed up to explain.
 */
dont_go() {
  object obj;

  obj = present("kings_ghost", this_object());

  /* If we don't have the sceptre then we can leave */
  if(!present("kings_sceptre", this_player())) {
    this_player()->move_player("west#players/pavlik/ilstkarn/dungeon13");
    return 1;
  }

  /* if the kings ghost is here */
  if(obj) {
    if(this_player()->query_attack() == obj) {
      if(!random(3)) {
        write("You drop the golden sceptre and run for it!!!\n");
        say(ME+" drops the golden sceptre and runs for it!!!\n");
        this_player()->move_player("west#players/pavlik/ilstkarn/dungeon13");
        transfer(present("sceptre", this_player()), this_object());
        return 1;
      }
      else {
        write("You are unable to escape!\n");
        return 1;
      }
    }
    else {
      say(ME+" tries to leave with the golden sceptre.\n");
      tell_room(this_object(),
      "An inhuman scream shakes the walls of the room!\n"+
      "The King's Ghost attacks!\n");
      obj->begin_fight(this_player());
      return 1;
    }
  }
  /*
   * if the kings ghost is not here 
   * make sure the king hasnt already been killed, this can only
   * happen once per reboot
   */
  else if(POR->query_king()) {
    if(busy) {
      say(ME+" tries to leave with the golden sceptre.\n");
      tell_room(this_object(),
      "The King's Ghost reemerges from the darkened cell wall.\n"+
      "His hollow voice intones:\n"+
      "'I warned thee ...now you shall die!!!\n");
      obj = clone_object("players/pavlik/monsters/ilstkarn/kings_ghost");
      move_object(obj, this_object());
      obj->begin_fight(this_player());
      busy = 0;
      return 1;
    }
    else {
      write("You try to leave but the golden sceptre stops you...\n");
      say(ME+" tries to leave but the golden sceptre stops him...\n");
      tell_room(environment(this_player()),
      "You turn towards a powerful white glow in the back of the cell.\n"+
      "A brilliant white light seems to burst through the solid wall.\n"+
      "A ghostly shape steps through the radiance and stands before you.\n");
      tell_room(environment(this_player()),
      "The Ghost of Secezeran lifts an arm slowly and points at "+ME+".\n");
      move_object(clone_object("players/pavlik/monsters/ilstkarn/kings_ghost"),
      this_object());
      call_out("finish", 6);
      return 1;
    }
  }
  /* if king isnt here and has already been killed we can leave */
  else {
    this_player()->move_player("west#players/pavlik/ilstkarn/dungeon13");
    return 1;
  }
}

finish() {
  object obj;

  obj = present("kings_ghost", this_object());

  if(!obj) {
    tell_room(this_object(), "Bug ... no king.\n");
    return 1;
  }

  if(obj->query_attack()) {
    tell_room(this_object(),
    "The King's Ghost intones: You too will rot forever in these dungeons!\n");
    return 1;
  }
  else {
    tell_room(this_object(),
    "The hollow voice of King Secezeran intones:\n"+
    "'You have taken my fortress, which I have built with thy own hands,\n"+
    " but you will not take thine Sceptre.  The Legions of Dead shall haunt\n");
    tell_room(this_object(),
    " thee until the Key of Arcadia is returned to me.  Return all that has\n"+
    " been taken ...return what has been taken...'\n");
    call_out("leave", 10+random(20));
    call_out("unbusy", 100);
    busy = 1;
    return 1;
  }
}

leave() {
  object obj;

  obj = present("kings_ghost", this_object());

  if(!obj || obj->query_attack()) {
    return 1;
  }
  tell_room(this_object(),
  "The Ghost turns away and disappears.\n");
  move_object(obj, "players/pavlik/mages/rooms/master_room");
  destruct(obj);
  return 1;
}

unbusy() {
  busy = 0;
}

query_ilstkarn(){ return "cell7"; }
realm(){ return "NT"; }
query_no_teleport(){ return 1; }
query_nofollow(){ return 1; }

