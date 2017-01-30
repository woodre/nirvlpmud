#define me environment()
int glvl, glvln;
heart_beat() {
  int spell_delay,beats,glvl;
  object myenv;
  if(!me || !me->is_player()) return;
  if(me->query_level() < 20) test_stats();
  myenv = environment(me);
  if(!myenv) return;
  if(spell_delay) {
 spell_delay -=1;
    if(!spell_delay) TE(me,
      HIK+"Darkness within your soul is useable again.\n"+NORM); }
  beats++;
 return;
  }
test_stats() {
  int mystr, mysta;
  glvl = query_guild_rank();
  glvln = me->query_guild_rank();
  if(!me) return;
  mystr = me->query_attrib("wil");
  mysta = me->query_attrib("sta");
  if(mystr = 20 && glvln > 0) {
    TE(me, HIK+"\nDarkness lends you it's willpower.\n"+NORM);
  me->set_attrib("wil",26 + glvln);
    me->save();
    me->reset(); }
  return 1; }
