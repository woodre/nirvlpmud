disperse() {
object corpse;
  if(TP->query_ghost()) return 0;
  corpse = present("corpse", environment(TP));
  if(!corpse) corpse = present("corpse", TP);
  if(!corpse) {
    notify_fail("There is no corpse present.\n"); return 0;
  }
  write(QMI("disperse1")+"\n");
  tell_room(environment(TP),QMI("disperse2")+"\n");
  TP->heal_self(corpse->heal_value());
  destruct(corpse);
  return 1;
}
