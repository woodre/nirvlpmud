/* HEART BEAT */
heart_beat() {
  object me, myenv;
  me = environment();
  if(!me || !me->is_player()) return;
  myenv = environment(me);
  if(!myenv) return;
  return 1;
  }

