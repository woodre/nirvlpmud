#define ME capitalize(this_player()->query_name())

/*
 * This object allows a player to teleport once out and once back
 * into my area.  The entire area is NT, so this is a very useful
 * object to have.
 */

string dest;

reset(arg){
  if(arg) return;
  dest = "none";
}

id(str){
  return str == "disc" || str == "teleport" || str == "teleport disc";
}

long(){
  write(
  "A teleport disc.  This magical device will allow you to teleport\n"+
  "outside the walls of the Fortress and then back.  The disc can\n"+
  "only provide one round-trip before it disappears.  Rub the disc\n"+
  "to activate it.\n");
  return;
}

short(){
  return "A Disc (glowing)";
}

get() {
  return 1;
}

query_weight() {
  return 0;
}

query_value() {
  return 0;
}

query_save_flag() {
  return 1;
}

init() {
  add_action("rub_disc","rub");
}

rub_disc(str) {
  object obj;

  if(id(str)) {
    if(dest == "none") {
      if(!environment(this_player())->query_ilstkarn()) {
        write("The discs magical powers will not work here.\n");
        return 1;
      }

      if(environment(this_player())->query_no_teleport()) {
        write("The discs magical powers will not work here.\n");
        return 1;
      }

      write(
      "You rub the glowing disc and something happens.\n"+
      "You are transported across time and space.\n");
      say(
      ME+" rubs a blue disc and disappears!\n");

      dest = object_name(environment(this_player()));
      obj = environment("players/pavlik/ilstkarn/ilstkarn_portal");

      if(!obj) {
        move_object(this_player(), "room/church");
      }
      else {
        move_object(this_player(), obj);
      }

      say(ME+" appears in a puff of smoke.\n");
      return 1;
    }
    else {
      if(environment(this_player())->realm() == "NT"  &&
      !environment()->query_ilstkarn()) {
        write("The discs magical powers will not work here.\n");
        return 1;
      }

      write(
      "You rub the glowing disc and something happens.\n"+
      "You are transported across time and space.\n");
      say(
      ME+" rubs a blue disc and disappears!\n");

      move_object(this_player(), dest);
      say(ME+" appears in a puff of smoke.\n");

      write("The blue disc turns to smoke and disappears.\n");
      destruct(this_object());
      return 1;
    }
  }
}

