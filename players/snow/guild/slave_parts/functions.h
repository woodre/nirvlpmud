/* FUNCTIONS */
cyborg_reset() {
  object ob;
  ob = clone_object("/players/snow/guild/slave.c");
  write("Resetting cyborg status.\n");
  move_object(ob, TP);
  destruct(this_object());
  return 1; }
query_flash_time() { return flash_time; }
cyborg_flash() {
  if(TP->query_sp() < 25) { write("You lack the energy.\n"); return 1; }
  if(flash_time) { write("You are already flashing light!\n"); return 1; }
  write("Your eyes flash with a brilliant light!\n");
  say(TPN+"'s eyes flash with a brilliant light!\n");
  flash_time = 10;
  set_light(10);
  TP->add_spell_point(-25);
  return 1; }
cyborg_look(string str) { GOB->cyborg_look(str); return 1; }
cyborg_get(string str) { GOB->cyborg_get(str); return 1; }
cyborg_put(string str) { GOB->cyborg_put(str); return 1; }
run(string str) { GOB->run(str); return 1; }
