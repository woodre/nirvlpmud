/*
  coffin.c
*/

inherit "obj/treasure";

int coffin_unlocked;

reset(arg) {
  set_id("coffin");
  set_alias("box");
  set_short("A coffin the size of a door");
  set_long("The ironwood box is strangly shaped and has a top that is hinged "+
           "like a door.\n"+
           "It is large enough for a human to lay down in.\n");
  set_value(50);
  set_weight(6666);
}

get() { return 0; } /* no taking the coffin */

id(str) { return str=="coffin" || str=="nooneelsecoffin" ||
                 str=="box" || str=="ironwood box" || str=="ironwood coffin" ||
                 str=="door"; }

init() {
  ::init();

  add_action("open_box", "open");
}

open_box(str) {
  object obj;
  if (!str) return 0;
  if (str!="box" && str!="coffin") return 0;
  if (!coffin_unlocked) {
    write("It seems to be locked tight as a door.\n");
    return 1;
  }
  if (present("bubble pipe", this_player())) {
    write(
      "You strain your muscles to the limit!  Finally, it opens enough\n"+
      "for you to see something inside.  As you grab for it, the lid\n"+
      "slams shut again.  It slammed shut too fast for you to get whatever\n"+
      "it was that's in there.\n");
  }
  else {
    write("You strain your muscles to the limit!  Finally, it opens enough\n"+
          "for you to see something inside.  As you grab for it, the lid\n"+
          "slams shut again.  You see something interesting laying on the\n"+
          "ground next to the coffin.\n");
    obj=clone_object("/players/nooneelse/obj/bubbles");
    move_object(obj, environment(this_object()));
  }
  coffin_unlocked=0;
  return 1;
}

/* use function name from door.c so the telekenetics ability can unlock it */
set_locked(arg) { coffin_unlocked=1; }

query_coffin_locked() { return coffin_unlocked; }
