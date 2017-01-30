/*
  portable_keep.c - portable entry to players personal keep
*/

inherit "obj/treasure";
inherit "/players/nooneelse/closed/keep/keep_common";


int soldiers_placed;

reset(arg) {
  if (arg) return;

  set_id("keep");
  set_alias("portable keep");
  set_short("Portable Keep");
  set_value(0);
  set_weight(1);
}

short() {
  string return_str;
  if (living(query_keep_room())) return "Portable keep";
  if (query_gates()) {
    return_str=capitalize(query_owner_name())+"'s keep.\n"+
               "     The gates are open.\n"+
               describe_damage();
  }
  else {
    return_str=capitalize(query_owner_name())+"'s keep.\n"+
               "     The gates are closed.\n"+
               describe_damage();
  }
  return return_str;
}

long(str) {
  string gate_msg;
  if (query_gates())
    gate_msg="open";
  else
    gate_msg="closed";
  if (living(query_keep_room())) {
    write("This is a portable keep.  You can take it whereever you can\n"+
          "travel.  When you find a suitable location, 'place keep' will\n"+
          "plant it in the ground.  There are certain places on the mud\n"+
          "from which you cannot teleport.  The keep cannot be placed in\n"+
          "any of them.  When you pick the keep up again, all players in\n"+
          "it will be booted out & all other items in it will be destroyed.\n");
    write(describe_damage()+".\n");
  }
  else {
    write("You see a keep constructed of huge, dark gray stones.\n"+
          "Over the "+gate_msg+" gates, you see a large banner saying '"+
          capitalize(query_owner_name())+"'s Keep'.\n");
    write(describe_damage()+".\n");
  }
}

init() {
  ::init();

  add_action("dump_keep",     "dump");
  add_action("enter_keep",    "enter");
  add_action("get",           "get");
  add_action("get",           "take");
}

enter_keep(str) {
  int i;
  if (!str || str!="keep") return 0;
  if (living(query_keep_room())) {
    write("Huh?  You can't enter the keep until it's been placed.\n");
    return 1;
  }
  write("You stroll through the gates into the throne room.\n");
  tell_room(THRONE_ROOM,
            this_player()->query_name()+
            " strolls through the gates into the keep.\n");
  move_object(this_player(), THRONE_ROOM);

  /* put the soldiers in the keep as they enter the 1st time */
  for (i=0; i<query_keep_soldiers(); i++)
    move_object(clone_object("players/nooneelse/closed/keep/keep_soldier"),
                THRONE_ROOM());
  soldiers_placed=1;

  tell_room(query_keep_room(),
            this_player()->query_name()+
            " strolls through the gates into the keep.\n");
  command("look", this_player());
  return 1;
}

destruct_keep_room(arg) {
  object player_obj, next_obj;
  player_obj = first_inventory(arg);
  while(player_obj) {
    next_obj=next_inventory(player_obj);
    if (player_obj->is_player()) {
      move_object(player_obj, environment(query_keep_obj()));
      tell_object(player_obj,
                  "\nThe keep begins to shrink.  Fortunately, you manage to\n"+
                  "get out in time to keep from being crushed.\n");
      command("look", player_obj);
    }
    player_obj=next_obj;
  }
  destruct(arg);
}

get(str) {
/*
  if (!str || !id(str)) return 0;
*/
  if (this_player()->query_real_name()!=query_owner_name()) return 0;
  if (str=="all" && lower_case(this_player()->query_name())!=query_owner_name())
    return 0;
  if (THRONE_ROOM) destruct_keep_room(THRONE_ROOM);
  if (PARAPIT) destruct_keep_room(PARAPIT);
  if (REPAIR_ROOM) destruct_keep_room(REPAIR_ROOM);
  write("As you reach to pick up the keep, it begins to shrink to a\n"+
        "more manageable size.\n");
  say("As "+this_player()->query_name()+" reaches to pick up the keep,\n"+
      "it begins to shrink.\n", this_player());
  call_out("destruct_this", 1);
  return 1;
}

destruct_this() { destruct(this_object()); }
