#include "/players/mythos/closed/guild/def.h"
simulacrum(str) {
object was_mon, is_mon;
string was, is;
write("This was removed by Boltar's orders.\n");
return 1;
if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 50) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 500) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!str || sscanf(str,"%s %s",was,is) != 2) {
  write("Usage: simulacrum <name of target> <name of person>\n");
  return 1;}
was_mon = present(was,environment(tp));
is_mon = find_player(is);
if(!was_mon) { write("That monster is not here!\n"); return 1;}
if(!is_mon) { write("That player is not on!\n"); return 1;}
if(was_mon->is_pet() || was_mon->is_kid()) {
  write("You may not do pets or kids.\n");
return 1; }
if(is_mon->query_level() > 20) { write("You may not simulcrum wizes.\n"); return 1;}
was_mon->set_short(is_mon->short());
was_mon->set_long(write(is_mon->long()));
was_mon->set_alias(was_mon->query_real_name());
was_mon->set_name(is_mon->query_real_name());
was_mon->set_alt_name(is_mon->query_real_name());
was_mon->set_gender(is_mon->query_gender());
was_mon->set_can_kill(1);
was_mon->set_whimpy();
was_mon->set_move_at_reset();
was_mon->set_wander();
was_mon->set_load_chat(0);
was_mon->set_load_a_chat(0);
write("You have created a simulacrum of "+is+"!\n");
say("Darkness comes and.....  goes.....\n");
tp->add_spell_point(-50);
pp->add_sacrifice(-500);
was_mon->reset(1);
return 1;}
