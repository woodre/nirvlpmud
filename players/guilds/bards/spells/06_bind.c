#include "/players/guilds/bards/def.h"

status main(string str) {

  object ob;
   object binding;
  int a, b;

  if (!str)
    FAIL("Harper's Song of Spectral Binding requires a target.\n");
  ob = present(str, environment(TP));
  if (attack_spell(-150, 6, 20, ob) == -1) return 0;

  write("You play Harper's Song of Spectral Binding.\n\n");
  say(tp + " begins to play a Song.\n\n");
  tell_room(environment(TP),
    "The room fills with slow, etheral sounding " +
    INST + " music.\n\n" + NAME(ob) +
    " is bound in illusionary chains.\n\n");

  TP->add_spell_point(-20);
  binding = clone_object(OBJ+"binding.c");
  binding->set_time(20 + TP->query_level() + TP->query_extra_level());
  binding->web_person(ob);
  return 1;
}
