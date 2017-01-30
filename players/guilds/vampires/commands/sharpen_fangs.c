/*
  TP->add_guild_exp(666); }

*/

#include "/players/eurale/defs.h"

/* --------------- update fangs --------------- */
sharpen_fangs(str) {
  object new_fangs, old_fangs, next_obj;
  int i, n;

if(!str || !str == "fangs") {
  write("Usage: sharpen fangs\n");
  return 1; }

write("Sharpening your "+HIR+"Vampire Fangs"+NORM+".\n");
TP->set_guild_name("vampire");
if(TPGEXP < 666 || TPGEXP > 672) {
  TP->add_guild_exp(-TPGEXP);
  TP->add_guild_exp(666); }

new_fangs = clone_object(FANGS);
old_fangs = present("vampire fangs",TP);
new_fangs->set_form_description(old_fangs->query_form_description());
new_fangs->set_new_form_description(old_fangs->query_new_form_description());
new_fangs->set_form_owner_name(old_fangs->query_form_owner_name());
new_fangs->set_target_name(old_fangs->query_target_name());
new_fangs->set_littlebat_obj(old_fangs->query_littlebat_obj());
new_fangs->set_wolf_obj(old_fangs->query_wolf_obj());
new_fangs->set_new_form_obj(old_fangs->query_new_form_obj());
new_fangs->set_form_obj(old_fangs->query_form_obj());
new_fangs->set_in_a_form(old_fangs->query_in_a_form());
new_fangs->set_telepathy(old_fangs->query_telepathy());
  /* now get rid of any extra fangs they have */
for (n=0; n<10; n++) {
  if(old_fangs) destruct(old_fangs);
  }
move_object(new_fangs,TP);
write(HIR+"Done sharpening your fangs!"+NORM+"\n");
return 1;
}
