#pragma strong_types

#include <server.h>
#include <imud3.h>

object present(mixed arg1, object arg2) {
  string name, mud, real_mud, nameatmud;
  object ob;

  if (load_name(arg1) != "bin/tools/intermud_soul_d")
    return efun::present(arg1, arg2);
  nameatmud = arg1->query_name();
  if (sscanf(nameatmud, "%s@%s", name, mud) != 2)
    return efun::present(arg1, arg2);
  real_mud = SE_INTERMUD->get_mud_name(mud);
  if (!real_mud)
    return notify_fail("Unknown mud: " + mud + "\n"), 0;
  ob = clone_object("bin/tools/intermud_soul_d");
  ob->set_emoteto(name, real_mud);
#if 0  // don't move it to the player. Coogan, 29-Apr-02
       // if moved, the catch_tell() in 'ob' will receive the 'Emote sent to'
       // message, leading to too-deep-recursion errors.
  move_object(ob, this_player());
#endif
  return ob;
}

varargs object create_sould(string name, string mud) {
  object ob;
  ob = clone_object("bin/tools/intermud_soul_d");
  ob->set_emoteto(name, mud);
#if 0  // Coogan, 07-Mar-02
  ob->set_protocol(SE_INTERMUD->get_mud_protocol(mud));
#endif
#if 0  // Coogan, 26-Mar-02
  move_object(ob, environment(this_player()));
#endif
  return ob;
}

