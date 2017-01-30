/* FUNCTIONS */
dervish_reset() {
  object ob;
  if(!environment()) return;
  if(offwep) offwep->stop_wep_shadow();
  save_me();
  ob = clone_object("/players/snow/dervish/gob.c");
  write("Resetting Dervish whirlwind.\n");
  move_object(ob, environment());
  destruct(this_object());
  return 1; }
dhelp(str) { GOB->dhelp(str); return 1; }
dhome() { GOB->dhome(); return 1; }
dtalk(str) { GOB->dtalk(str); return 1; }
demote(str) { GOB->demote(str); return 1; }
dtitle() { GOB->dtitle(); return 1; }
offwield(string str) { GOB->offwield(str); return 1; }
run(string str) { GOB->run(str); return 1; }
sand_transfer() { GOB->sand_transfer(); return 1; }
dervish_chant() { GOB->dervish_chant(); return 1; }
dervish_invis(str) { GOB->dinvis(str); return 1; }
dervish_pray() { GOB->dervish_pray(); return 1; }
dervish_heal() { GOB->dervish_heal(); return 1; }
confuse(str) { GOB->confuse(str); return 1; }
scatter(str) { GOB->scatter(str); return 1; }
sandblast(str) { GOB->sandblast(str); return 1; }
dervish_score() { GOB->dervish_score(); return 1; }
lead_toggle() { GOB->lead_toggle(); return 1; }
dervish_cleanse() { GOB->dervish_cleanse(); return 1; }
dervish_whirlwind() { GOB->dervish_whirlwind(); return 1; }
dervish_sandstorm() { GOB->dervish_sandstorm(); return 1; }
cmd_ready() { return GOB->cmd_ready(); return 1; }
dervish_train(str) { GOB->dervish_train(str); return 1; }
dervish_set_percent(str) { GOB->dervish_set_percent(str); return 1; }
dervish_oasis() { GOB->dervish_oasis(); return 1; }
dervish_sharpen(str) { GOB->dervish_sharpen(str); return 1; }
dervish_idea(str) { GOB->dervish_idea(str); return 1; }
dervish_fatal() { GOB->dervish_fatal(); return 1; }
dervish_sandcheck() { GOB->dervish_sandcheck(); return 1; }


dervish_resett(){
  object ob;
  if(!environment()) return;
  save_me();
  return 1;
}
