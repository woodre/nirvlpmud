/*
  keep_repair.c - place to get keeps repaired
*/

inherit "room/room";
inherit "/players/nooneelse/closed/keep/keep_common";

int repairing_keep;

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc="Stonecutter's Guild";
  dest_dir=
    ({
      THRONE_ROOM, "west",
    });
}

long() {
  write("Local branch of the Stonecutter's Guild.  We specialzie in\n"+
        "the repair of keeps.  The cost depends on the extent\n"+
        "of the damage.  Use:  'estimate' or 'repair keep'\n"+
    describe_damage()+"\n\n");
  write("   The only obvious exit is west.\n");
}

init() {
  ::init();

  add_action("dump_keep","dump");
  add_action("west",     "west", 1);
  add_action("estimate", "estimate");
  add_action("repair",   "repair");
}

west() {
  if (living(query_keep_room())) {
    write("\nSomething's wrong!  You're not supposed to be in here unless\n"+
          "the keep has been placed!  I'm dumping you in the church.\n\n");
    tell_room("/room/church",
              this_player()->query_name()+" appears as if by magic.\n");
    move_object(this_player(), "/room/church");
    command("look", this_player());
    return 1;
  }
  write("You walk through the archway into the throne room.\n");
  tell_room(THRONE_ROOM,
            this_player()->query_name()+
            " walks through the archway into the throne room.\n");
  move_object(this_player(), THRONE_ROOM);
  tell_room(REPAIR_ROOM,
            this_player()->query_name()+
            " walks through the archway into the throne room.\n");
  command("look", this_player());
  return 1;
}

estimate() {
  int cost_estimate, time_estimate;
  if (keep_damage<=0) {
    write("The foreman says:\n"+
          "   Eh?  The place is as good as new now!  Whatcha want done?\n");
    return 1;
  }
  cost_estimate=keep_damage*3000;
  time_estimate=keep_damage*3;
  write("The foreman says:\n"+
        "   Well, it looks like it'll take "+cost_estimate+" gold and\n"+
        "   "+time_estimate+" minutes to make 'er good as new.\n");
  return 1;
}

repair(str) {
  int cost_estimate;
  if (keep_damage<=0) {
    write("The foreman says:\n"+
          "   Eh?  The place is as good as new now!  Whatcha want done?\n");
    return 1;
  }
  if (repairing_keep) {
    write("The foreman says:\n"+
          "   Eh?  We already got a crew working in your place.\n");
    return 1;
  }
  cost_estimate=keep_damage*3000;
  if (this_player()->query_money("gold")<cost_estimate) {
    write("The foreman says:\n"+
          "   Eh?  Whatcha tryan ta do, cheat me?  You ain't got that\n"+
          "   kind of dough!\n");
    return 1;
  }
  repairing_keep=1;
  call_out("repair_damage", 3);
  return 1;
}

repair_damage() {
  add_keep_damage(- 1);
  TELL_KEEP("Some stonemasons rush into the room, make some quick repairs\n"+
            "and leave.\n");
  if (keep_damage<=0) {
    keep_damage=0;
    repairing_keep=0;
  }
  else
    call_out("repair_damage", 3);
}
