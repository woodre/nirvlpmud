#include "/players/guilds/bards/def.h"

status main(string str) {
  int heal;
  object corpse;
  string verb;
  verb=query_verb();
  if(str) corpse=present(str,environment(TP));
  else corpse=present("corpse",environment(TP));
  if(!corpse) {
    if(str) corpse=present(str,TP);
    else corpse=present("corpse",TP);
  }
  if(!str && !corpse) FAIL("You find no corpses here.\n");
  if(!corpse) FAIL("You find no "+str+" here.\n");
  if(!corpse->is_corpse()) FAIL("That is not a corpse.\n");
  heal=(int)corpse->heal_value();
  if(!heal) FAIL("This corpse is devoid of energy.\n");
  transfer(corpse,environment(TP));
  destruct(corpse);
  if(verb=="pyre") {
    write("You build a funeral "+HIR+"pyre"+NORM+" and burn the corpse.\nYou feel good.\n");
    say(tp+" builds a funeral "+HIR+"pyre"+NORM+" and burns a corpse.\n");
    TP->add_spell_point(heal*2);
  }
  if(verb=="bury") {
    write("You murmur a brief prayer and bury the corpse.\nYou feel good.\n");
    say(tp+" murmurs a brief prayer and burys a corpse.\n");
    corpse = clone_object("/players/guilds/bards/obj/marker");
    if(transfer(corpse,environment(TP))) destruct(corpse);
    TP->add_hit_point(heal*2);
  }
  return 1;
}
