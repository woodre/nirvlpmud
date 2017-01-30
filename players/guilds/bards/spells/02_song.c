#include "/players/guilds/bards/def.h"

status main(string str) {
  if(!str)
    FAIL("Which song do you want to use?\n");
  if (str == "darken") {
    if (spell(-155, 6, 30) == -1)
      return 0;

    if(!creator(environment(TP)))
      FAIL("You cannot darken the main village.\n");

    if (present("bard_darkness_object", environment(this_player())))
      FAIL("This room is already affected by the Canticle of Darkness.\n");
    move_object(clone_object(OBJ+"dark"),
          environment(this_player()));
    write("You sing the Canticle of Darkness.\n");
    say(tp+ " sings a short, disquieting Canticle.\n");
    tell_room(environment(this_player()),
          "A cloud of darkness covers the room.\n");
    call_other(TP, "add_spell_point", -30);
    return 1;
  }
  if (str == "light") {
    if (!GOB->query_is_lit()) {
      if (spell(-100, 2, 10) == -1)
        return 0;
      write(
        "You weave a mixture of prayers and song into the Canticle of Light.\n"
        + "You are surrounded by an aura of light.\n");
      say(tp +
        " weaves a mixture of prayers and song into a canticle.\n" +
        tp + " is surrounded by an aura of light.\n");
      GOB->set_is_lit(1);
      call_other(TP, "add_spell_points", -10);
    } else {
      write("You single a single word, cancelling the Canticle of Light.\n"+
            "The aura of light around you fades away.\n");
      say(tp + " sings a single word.\n"+
            "It gets darker.\n");
      GOB->set_is_lit(0);
      
    }
    return 1;
  }
  FAIL("Which song do you want to use?\n");
}
