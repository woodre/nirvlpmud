/*
 bedroom1.c
*/

inherit "room/room";

object key, vase;

int vase_is_gone;

string str, str2;

init() {
  ::init();

  add_action("vase", "get");
  add_action("vase", "take");
}

vase(str) {
  if (!str) return;
  if (str != "vase" && str != "all") return;
  if (vase_is_gone) return;
  write("It is a very delicate crystal vase and it...\n");
  write("CRASH!  Your clumsiness caused the vase to fall and break!\n");
  say(call_other(this_player(), "query_name")+
      " reaches for the vase and knocks it to the floor.\n");
  key=clone_object("obj/key");
  key->set_key_data("tarnished alchemkey");
  move_object(key, this_object());
  vase_is_gone = 1;
  destruct(vase);
  return 1;
}

reset(arg) {
  if (arg) return;

  short_desc = "master bedroom";
  set_light(1);
  no_castle_flag=1;
  long_desc =
    "This room is luxuriously furnished, with a massive four poster bed,\n"
    + "lush carpeting, and several soft couches and chairs.  Several\n"
    + "flickering lanterns provide dim illumination.  There are some\n"
    + "large, magnificient paintings hanging on each of the walls.\n";
  items =
    ({
      "bed", "A large, comfortable feather bed with ornately carved posts",
      "chair", "You see a large, comfortable chair",
      "chairs", "You see several large, comfortable chairs",
      "couch", "You see a large, comfortable couch",
      "couches", "You see several large, comfortable couches",
      "painting", "It shows a lovely, sundrenched landscape",
      "paintings", "Each shows a different sundrenched landscape",
      "lantern", "It is a large, heavy oil lantern",
      "lanterns", "Large crystal oil lanterns",
    });
  dest_dir =
    ({
      "players/nooneelse/red/dressing", "east",
    });
  if (!present("vase")) {
    vase=clone_object("obj/treasure");
    vase->set_id("vase");
    vase->set_short("A little vase");
    vase->set_long("A beautiful little porcelain vase.\n");
    vase->set_value(25);
    vase->set_weight(3);
    move_object(vase, this_object());
  }
}

id(str) {
  str2=0;
  sscanf(str,"at %s", str2);
  if (str=="vase" || str2=="vase") {
    vase("vase");
    return;
  }
  return (str=="bed" ||
          str=="chair" || str=="chairs" ||
          str=="couch" || str=="couches" ||
          str=="painting" || str=="paintings" ||
          str=="lantern" || str=="lanterns");
}
