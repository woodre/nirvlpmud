int glvl, glvln;
heart_beat() {
  int spell_delay,beats,glvl;
  object me, myenv;
  me = environment();
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
  object me;
  int mystr, mysta;
  glvl = query_guild_rank();
  glvln = me->query_guild_rank();
  me = environment();
  if(!me) return;
  mystr = USER->query_attrib("wil");
  mysta = me->query_attrib("sta");
  if(mystr = 20) {
    TE(me, HIK+"\nDarkness lends you it's willpower.\n"+NORM);
  USER->set_attrib("wil", 26);
    me->save();
    me->reset(); }
  return 1; }
