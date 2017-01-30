heart_beat() {
  object me, myenv;
  me = environment();
  if(!me || !me->is_player()) return;
  myenv = environment(me);
  if(!myenv) return;
  if(me->query_level() < 20) test_stats();
  return 1;
  }

test_stats() {

  object me;
  int mystr, mysta;
  me = environment();
  if(!me) return;
  mysta = me->query_attrib("mag");
  if(mysta > 20) {
    TE(me, HIR+"\nThe ancients powers of Darkness rids you of your extra magic.\n"+NORM);
  me->set_attrib("mag",20);
    me->save();
    me->reset(); }
  return 1; }
