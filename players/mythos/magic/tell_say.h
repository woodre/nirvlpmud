tell_say(object ob,string what) {
object where, who;
int h;
  if(!ob) return 1;
  where = environment(ob);
  if(!where) return 1;
  who = all_inventory(where);
  for(h=0;h<sizeof(who);h++) {
    if(living(who[h])) if(who[h] != ob) tell_object(who[h],what);
  }
}