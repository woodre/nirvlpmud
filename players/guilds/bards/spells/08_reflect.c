#include "/players/guilds/bards/def.h"

status main(string str) {
  if (spell(-159, 8, 100) == -1)
    return 0;
  if(present("bard_scrying_pool",environment(TP)))
    FAIL("There is already a scryping pool here.\n");
  write("You play the Canticle of Reflection upon your " + INST +".");
  say(tp + " plays a Canticle upon " + POSS(TP) + " " + INST + ".");
  tell_room(environment(TP),
        "\n\nA small cloud of silver mist comes forth from chaos." +
        "\n\nIt begins to rain." +
        "\n\nA dark pool of water forms upon the ground.\n");
  move_object(clone_object(OBJ+"pool.c"),
        environment(TP));
  call_other(TP, "add_spell_point", -100);
  return 1;
}
