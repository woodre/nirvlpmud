/*
 * update_actions
 * limited to top 45 objects
 */

varargs void update_actions(object ob) {
  int i;
  object *inv;

  if (!ob) ob = previous_object();
  inv = all_inventory(ob);
  for (i = 0; i < sizeof(inv) && i < 45; i++) {
    if (!inv[i] || !living(inv[i])) continue;
    move_object(inv[i], ob);
  }
  if (environment(ob)) {
    move_object(ob, environment(ob));
  }
}

