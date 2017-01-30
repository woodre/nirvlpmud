wraithform() {
int g_level, sp_val;
object ac_ob, ob;
ob = present("necro_ob",tp);
  g_level = tp->query_guild_rank();
  if(g_level > 10) g_level = 10;
if(tp->query_sp() < (g_level * 10)) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_blood()) < g_level) {
write("You do not have the spell components available for the spell.\n");
return 1; }
if(tp->query_attack()) {
  write("You can not cast this during combat!\n"); return 1; }
if(present("ac_ob",tp)) {
  write("You are already in wraithform.\n");
return 1; }
  ac_ob=clone_object("/players/daranath/guild/obj/misc/ac_ob.c");
  ac_ob->set_ac(g_level);
  move_object(ac_ob,tp);
  write("\nWraithform takes hold and you take on a misty form.\n\n");
  say(tp->query_name()+" concentrates for a second and releases a dark spell.\n");
  say(tp->query_name()+" fades into an insubstaintial, ghostly form.\n");
  tp->add_spell_point(-10*g_level);
  ob->add_blood(-g_level);
  ob->save_me();
return 1; }

