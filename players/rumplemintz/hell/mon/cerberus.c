#include "path.h"
inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name( ({"cerberus","cereberus","cerebrus"}) );
  set_aggressive(0);
  set_long("Cerberus is a three-headed black dog.\n"
           +"On each head is a spiked black collar.\n"
           +"Cerberus is blocking the entrance into hell.\n");
  set_level(LEVHELL);
  set_chance(40);
  set_spell_dam(60);
  set_spell_mess1("Cerberus rips you with his teeth");
  set_spell_mess2("Cerberus bites you");
  load_a_chat(10,
    ({"Cerberus growls at $it.\n",
      "Cerberus scratches at $it.\n"}) );
}
