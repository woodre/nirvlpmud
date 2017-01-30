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

new_fangs = clone_object(EFANGS);
old_fangs = present("vampire fangs",TP);
new_fangs->set_call_time(old_fangs->query_call_time());
new_fangs->set_last_time(old_fangs->query_last_time());
new_fangs->set_form_description(old_fangs->query_form_description());
new_fangs->set_new_form_description(old_fangs->query_new_form_description());
new_fangs->set_form_owner_name(old_fangs->query_form_owner_name());
new_fangs->set_following_name(old_fangs->query_following_name());
new_fangs->set_guild_name(old_fangs->query_guild_name());
new_fangs->set_guild_display(old_fangs->query_guild_display());
new_fangs->set_target_name(old_fangs->query_target_name());
new_fangs->set_alarm_bat_obj(old_fangs->query_alarm_bat_obj());
new_fangs->set_wolf_obj(old_fangs->query_wolf_obj());
new_fangs->set_new_form_obj(old_fangs->query_new_form_obj());
new_fangs->set_form_obj(old_fangs->query_form_obj());
new_fangs->set_following_obj(old_fangs->query_following_obj());
if(old_fangs->query_servant_obj()) {
  old_fangs->query_servant_obj()->set_master_name(TPRN);
  new_fangs->set_servant_obj(old_fangs->query_servant_obj()); }
new_fangs->set_old_room(old_fangs->query_old_room());
new_fangs->set_hell_fire_pause(old_fangs->query_hell_fire_pause());
new_fangs->set_in_a_form(old_fangs->query_in_a_form());
new_fangs->set_demon_wrath_pause(old_fangs->query_demon_wrath_pause());
new_fangs->set_glowing_eyes(old_fangs->query_glowing_eyes());
new_fangs->set_telepathy(old_fangs->query_telepathy());
new_fangs->set_sanctuary_on(old_fangs->query_sanctuary_on());
new_fangs->set_sanctuary_hp(old_fangs->query_sanctuary_hp());
new_fangs->set_old_hp(old_fangs->query_old_hp());
new_fangs->set_old_sp(old_fangs->query_old_sp());
new_fangs->set_old_intox(old_fangs->query_old_intox());
new_fangs->set_old_stuffed(old_fangs->query_old_stuffed());
new_fangs->set_sneak_seconds(old_fangs->query_sneak_seconds());
new_fangs->set_told_em_i_died(old_fangs->query_told_em_i_died());
new_fangs->set_call_time(old_fangs->query_call_time());
  /* now get rid of any extra fangs they have */
for (n=0; n<10; n++) {
  old_fangs = present("vampire fangs",TP);
  if(old_fangs) destruct(old_fangs);
  }
move_object(new_fangs,TP);
write(HIR+"Done sharpening your fangs!"+NORM+"\n");
return 1;
}
