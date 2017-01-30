#define DISP "/players/earwax/obj/dispenser"

void reset(status arg) {
  object ob;

  if (arg)
    return;

  ob = find_object("/players/earwax/obj/dispenser");

  if (!ob)
    ob = clone_object("/players/earwax/obj/dispenser.c");

  ob->reset(0);
}

void load_it(object where) { move_object(clone_object(DISP), where); }
