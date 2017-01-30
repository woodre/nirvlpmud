/*
  keep_deed.c - autoloading deed to a keep
*/

inherit "obj/treasure";
inherit "/players/nooneelse/closed/keep/keep_common";

object deed_keep_obj;

query_auto_load() {
  return "/players/nooneelse/closed/keep/keep_deed:";
}

set_it_up(obj) {
  string keep_entry;
  object keep_obj;
  if (!obj) return 0;
  move_object(this_object(), obj);
  keep_entry=find_object("/players/nooneelse/closed/keep/keep_sales_office.c")->
                         owns_a_keep(lower_case(this_player()->query_name()));
  owner_name=0;
  keep_soldiers=0;
  keep_damage=0;
  if (keep_entry!=" ") {
    sscanf(keep_entry, "%s (%d:%d)\n", owner_name, keep_soldiers, keep_damage);
    keep_obj=clone_object("/players/nooneelse/closed/keep/portable_keep");
    keep_obj->set_owner_id(owner_name+" keep");
    move_object(keep_obj, this_player());
    write("Here's your magic portable keep.\n"+
          "NOTE: Do not drop the keep until you have examined it to see how\n"+
          "      to use it properly.\n");
  }
}

reset(arg) {
  if (arg) return;

  set_id("deed");
  set_alias("keep deed");
  set_short("The deed to a keep");
  set_long("This deed indicates that you are the proud owner of a keep\n"+
           "with "+query_keep_soldiers()+" soldiers to defend it.\n\n"+
           "You can take it where ever you can travel.  When you find a\n"+
           "suitable location, 'place keep' will plant it in the ground.\n"+
           "(There are certain places on the mud from which you cannot\n"+
           " teleport.  The keep cannot be placed in any of them.)\n"+
           "When you pick the keep up again, all players in it (if any)\n"+
           "will be booted out & all other items in it will be destroyed.\n"+
           "\n[If you have problems with it, go to the sales office and\n"+
           " 'renew deed'.\n");
  set_value(0);
  set_weight(0);
  set_it_up();
  deed_keep_obj=0;
}

id(str) { return str=="deed" || str=="keep deed" || str==owner_id; }

get() { return 1; }

drop() { return 1; }

init() {
  ::init();

  add_action("dump_deed",     "dump");
  add_action("place_keep",    "place");
}

dump_deed(str) {
  if (this_player()->query_level() < 32) return 0;
  if (!str || str!="deed") return 0;
  dump_keep("keep");
  return 1;
}

place_keep(str) {
  int i;
  if (!str || str!="keep") return 0;
  if (deed_keep_obj) {
    write("You've already placed your keep at:\n"+
          "     "+environment(deed_keep_obj)->short()+"\n");
    return 1;
  }
  if (environment(this_player())->realm("NT")) {
    write("Sorry, you cannot place the keep in this location.\n");
    return 1;
  }
  deed_keep_obj=clone_object("/players/nooneelse/closed/keep/portable_keep");
  deed_keep_obj->set_keep_room(environment(this_player()));
  deed_keep_obj->set_owner_name(lower_case(this_player()->query_real_name()));
  deed_keep_obj->set_owner_id(owner_name+" keep");
  deed_keep_obj->set_keep_obj(deed_keep_obj);
  deed_keep_obj->set_gates(1);
  deed_keep_obj->set_keep_soldiers(query_keep_soldiers());
  set_owner_name(lower_case(this_player()->query_real_name()));
  set_owner_id(owner_name+" keep");
  set_keep_obj(deed_keep_obj);
  set_keep_room(environment(this_player()));
  set_gates(1);
  /* clone some unique rooms for each keep */
  set_GENERIC_THRONE_ROOM();
  set_GENERIC_PARAPIT();
  set_GENERIC_REPAIR_ROOM();
  THRONE_ROOM=clone_object(GENERIC_THRONE_ROOM);
  PARAPIT=clone_object(GENERIC_PARAPIT);
  REPAIR_ROOM=clone_object(GENERIC_REPAIR_ROOM);
  /* now set the rooms up */
  deed_keep_obj->set_THRONE_ROOM(THRONE_ROOM);
  deed_keep_obj->set_PARAPIT(PARAPIT);
  deed_keep_obj->set_REPAIR_ROOM(REPAIR_ROOM);
  THRONE_ROOM->set_keep_room(environment(this_player()));
  THRONE_ROOM->set_owner_name(lower_case(this_player()->query_real_name()));
  THRONE_ROOM->set_keep_obj(deed_keep_obj);
  THRONE_ROOM->set_gates(1);
  THRONE_ROOM->set_keep_soldiers(query_keep_soldiers());
  THRONE_ROOM->set_THRONE_ROOM(THRONE_ROOM);
  THRONE_ROOM->set_PARAPIT(PARAPIT);
  THRONE_ROOM->set_REPAIR_ROOM(REPAIR_ROOM);
  THRONE_ROOM->set_owner_id(owner_name+" keep");
  PARAPIT->set_keep_room(environment(this_player()));
  PARAPIT->set_owner_name(lower_case(this_player()->query_real_name()));
  PARAPIT->set_keep_obj(deed_keep_obj);
  PARAPIT->set_THRONE_ROOM(THRONE_ROOM);
  PARAPIT->set_PARAPIT(PARAPIT);
  PARAPIT->set_REPAIR_ROOM(REPAIR_ROOM);
  PARAPIT->set_owner_id(owner_name+" keep");
  PARAPIT->set_keep_soldiers(query_keep_soldiers());
  REPAIR_ROOM->set_keep_room(environment(this_player()));
  REPAIR_ROOM->set_owner_name(lower_case(this_player()->query_real_name()));
  REPAIR_ROOM->set_keep_obj(deed_keep_obj);
  REPAIR_ROOM->set_THRONE_ROOM(THRONE_ROOM);
  REPAIR_ROOM->set_PARAPIT(PARAPIT);
  REPAIR_ROOM->set_REPAIR_ROOM(REPAIR_ROOM);
  REPAIR_ROOM->set_owner_id(owner_name+" keep");
  REPAIR_ROOM->set_keep_soldiers(query_keep_soldiers());

  move_object(deed_keep_obj, environment(this_player()));
  write("You place your portable keep on the ground and stand back as\n"+
        "it grows into a tall stone tower.\n");
  say(this_player()->query_name()+" places a tiny replica of a keep on the\n"+
      "ground and stands back.  You are amazed to see it grow until it is\n"+
      "a full sized tower.\n");
  return 1;
}
