reset(arg) {
  if(!find_player("mythos")) destruct(this_object());
  else check();
}

check() {
  object me,ev,wh;
  int h,j;
me = find_player("mythos");
  if(!me) destruct(this_object());
  ev = users();
  for(h=0;h<sizeof(ev);h++) {
   wh = deep_inventory(ev[h]);
   for(j=0;j<sizeof(wh);j++) {
    if(wh[j]->query_value() < 0) {
      tell_object(me,wh[j]->query_value()+"  "+ev[h]->query_real_name()+"\n");
  } 
  }
}
destruct(this_object());
return 1; }
