#include "/players/guilds/bards/def.h"

status main() {
  object ob;
  string where;
  ob = this_player();
  if (spell(-200, 1, 80) == -1)
  return 0;

  write("The runes on your "+INST+" glow bright silver.\n"
       +"Your surroundings start to waver.\n");
  say("The runes on " + tp + "'s " + INST + " glow a bright silver.\n"
     +tp + " starts to waver and fade from sight.\n");

  if((string)REALM == "NT") {
    write("Some kind of magic blocks your spell!\n"
         +"Your surroundings solidify again.\n");
    say("The fading abrubtly reverses, leaving "+ tp +" solid again.\n");
    return 1;
  }


  where = (string)call_other("obj/base_tele", "teleport");
  if(where) {
    write("Something went wrong!\n");
    say(tp + " suddenly looks startled!\n");
  } else {
    where = "/players/guilds/bards/bardrooms/teleport.c";
  }
  say(tp + " vanishes completely.\n");
  move_object(ob,where);
  command("look", this_player());
  say(tp + " fades into view.\n");
  call_other(this_player(), "add_spell_point", -80);
  return 1;
}
