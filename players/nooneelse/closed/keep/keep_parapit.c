/*
  keep_parapit.c - parapit of player's keep
*/

inherit "room/room";
inherit "/players/nooneelse/closed/keep/keep_common";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc="Parapit";
  items =
    ({
      "cannon", "The cannon are facing out through the gun ports",
      "gun ports",
           "The gun ports are openings in the thick stone walls that face\n"+
           "in every conceivable direction.  They are just large enough\n"+
           "to aim the cannon through",
      "gun port",
           "The gun ports are openings in the thick stone walls that face\n"+
           "in every conceivable direction.  They are just large enough\n"+
           "to aim the cannon through",
      "ports",
           "The gun ports are openings in the thick stone walls that face\n"+
           "in every conceivable direction.  They are just large enough\n"+
           "to aim the cannon through",
      "port",
           "The gun ports are openings in the thick stone walls that face\n"+
           "in every conceivable direction.  They are just large enough\n"+
           "to aim the cannon through",
    });
  dest_dir =
    ({
      THRONE_ROOM, "down",
    });
}

long() {
  write(
    "This is the parapit of a keep.  It is high enough for the cannon to\n"+
    "reach any other keep on the mud.  You can 'shoot at <who>' to fire at\n"+
    "<who>'s keep.  Note: If the number of soldiers in your keep falls\n"+
    "below 2, you cannot fire your cannon.  Also, you can only fire on a\n"+
    "keep if it is not occupied.\n"+
    "You can also 'pour boiling oil' on anyone standing outside your keep.\n"+
    describe_damage()+"\n\n");
  write("   The only obvious exit is down.\n");
}

init() {
  ::init();

  add_action("dump_keep","dump");
  add_action("down",     "down", 1);
  add_action("shoot",    "shoot");
  add_action("pour_oil", "pour");
}

down() {
  if (living(query_keep_room())) {
    write("\nSomething's wrong!  You're not supposed to be in here unless\n"+
          "the keep has been placed!  I'm dumping you in the church.\n\n");
    tell_room("/room/church",
              this_player()->query_name()+" appears as if by magic.\n");
    move_object(this_player(), "/room/church");
    command("look", this_player());
    return 1;
  }
  write("You walk down the granite stairs into the throne room.\n");
  tell_room(THRONE_ROOM,
            this_player()->query_name()+
            " walks down the granite stairs into the throne room.\n");
  move_object(this_player(), THRONE_ROOM);
  tell_room(PARAPIT,
            this_player()->query_name()+
            " walks down the granite stairs into the throne room.\n");
  command("look", this_player());
  return 1;
}

shoot(str) {
  string keep_owner, keep_owner_room, str2, str3;
  object keep_owner_obj, deed_obj;
  if (!str) return 0;
  keep_owner=0;
  sscanf(str, "at %s", keep_owner);
  if (!keep_owner) {
    write("Huh?\n");
    return 1;
  }
  if (query_keep_soliders() < 2) {
    write("You have less than 2 soldiers to man the cannon.  "+
          "You cannot shoot.\n");
    return 1;
  }
  keep_owner_obj=0;
  keep_owner_obj=find_player(keep_owner);
  if (!keep_owner_obj) {
    write(capitalize(keep_owner)+" isn't in the mud.\n");
    return 1;
  }
  if (!environment(keep_owner_obj)) {
    write(capitalize(keep_owner)+" isn't in a keep.\n");
    return 1;
  }
  keep_owner_room=0;
  keep_owner_room=file_name(environment(keep_owner_obj));
  if (!keep_owner_room ||
      sscanf(keep_owner_room, "%s/nooneelse/closed/keep/%s", str2, str3)!=2) {
    write("You cannot shoot at "+capitalize(keep_owner)+
          "'s keep when they are not in it.\n");
    return 1;
  }
  deed_obj=0;
  deed_obj=present("keep deed", keep_owner);
  if (!deed_obj) {
    write(capitalize(keep_owner)+" doesn't have a keep to shoot at.\n");
    return 1;
  }
  TELL_KEEP("You hear a deafening BOOM as the cannon fire.\n");
  deed_obj->add_keep_damage(1);
  deed_obj->
    TELL_KEEP("You hear a deafening crash and feel the floor tremble\n"+
              "as cannon fire slams into the keep.\n");
  tell_object(deed_obj->query_keep_obj(),
              "You hear a deafening crash and feel the ground tremble\n"+
              "as cannon fire slams into the keep.\n");
  if (deed_obj->query_keep_damage() > query_max_damage()) {
    write("With a tremendous explosion, you see "+capitalize(keep_owner)+
          "'s keep crumble into a pile of rubble.\n");
  }
  return 1;
}

pour_oil(str) {
  object player_obj, next_obj;
  string who;
  who=0;
  if (!str || str!="boiling oil") return 0;
  player_obj = first_inventory(query_keep_room());
  while(player_obj) {
    next_obj=next_inventory(player_obj);
    if (player_obj->is_player()) {
      tell_object(player_obj,
        "\nSomeone on the parapits pours boiling oil all over you!\n");
      who=who+" "+player_obj->query_name();
    }
    player_obj=next_obj;
  }
  write("You pour boiling oil over the edge of the wall.\n");
  if (who)
    write("It lands on "+who+".\n");
  else
    write("It lands on nobody.\n");
  return 1;
}
