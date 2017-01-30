#include "../DEFS.h"
#define LEVEL  4
#define DRAIN 80

status main(string str) {
  object here;
  string here_realm, where;
  if(!gotrank(TP, LEVEL)) return 0;
  if(!gotsp(TP,   DRAIN)) return 1;
  here       = environment(TP);
  here_realm = (string)here->realm();
  if(here_realm == "NT") {
    write("Matter transfer is too dangerous from your location.\n");
    return 1; }

  /* chance for teleport error */
  if(where = (string)call_other("obj/base_tele", "teleport")) {
    write("You feel the energy wave from a distant solar flare.\n");
    say(TPN+"'s body vaporizes into nothing.\n");
    write("Your body disintegrates into invisible matter particles.\n");
    write("Something went wrong!\n");
    TP->move_player("with an astonished look#"+where);
    return 1;
  }

  say(TPN+"'s body vaporizes into nothing.\n");
  write("Your body disintegrates into invisible matter particles.\n");
  write("A magnetic transfer beam sucks you away...\n\n");
  tell_room(ROOMDIR + "/teleport.c", TPN+" transfers in.\n");
  move_object(TP, ROOMDIR + "/teleport.c");
  call_other(TP, "glance");
  call_other(TP, "add_spell_point", -DRAIN);
  return 1;
}
