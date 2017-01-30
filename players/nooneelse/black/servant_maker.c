/*
  servant_maker.c - test the new servants out
*/

inherit "obj/treasure";

#include "defs.h"

init() {
  add_action("make_one", "makeservant");
}

/* -------- Make a servant from a corpse ---------- */
make_one(str) {
  object target_obj, servant_obj;
  int i;
  str="renfield";
  if (present("nooneelse vampire fangs", this_player())->query_servant_obj()) {
    write("You can only make one servant at a time.\n");
    return 1;
  }
  servant_obj = clone_object("/players/nooneelse/black/servant_new");
  present("nooneelse vampire fangs", this_player())->set_servant_obj(servant_obj);
  servant_obj->set_name(lower_case(str));
  servant_obj->set_master_name(this_player()->query_real_name());
  servant_obj->set_servant_name(lower_case(str));
  /*NOTE: both set_name & set_servant_name are overridden in the servant's
          set_servant_name to name it renfield */
  i = 19;
  servant_obj->set_level(i);
/* No. 130hp as in servant file. -Bp.
  servant_obj->set_hp(666666);
*/
  servant_obj->set_hp(130);
  servant_obj->set_ac(99);
  if (i < 10) i = 4;
  servant_obj->set_wc(i);
  move_object(servant_obj, environment(this_player()));
  command("fix servant", this_player());
  write("The corpse raises as a servant and says: 'My name is "+
        capitalize(servant_obj->query_name())+"'.\n");
  say("The corpse raises and says: 'My name is "+
      capitalize(servant_obj->query_name())+"'.");
  str = "bow "+capitalize(this_player()->query_real_name());
  command(str, servant_obj);
  return 1;
}

reset(arg) {
  short_desc="a servant maker (Use: makeservant)";
}

id(str) { return str=="servant maker"; }
