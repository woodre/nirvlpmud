/* FUNCTIONS */
sage_reset() {
  object ob;
  save_me();
  ob = clone_object("/players/anshar/sage/gob.c");
  write("Resetting sage Stats.\n");
  move_object(ob, TP);
  destruct(this_object());
  return 1; }
shelp(str) { GOB->shelp(str); return 1; }
shome() { GOB->shome(); return 1; }
stalk(str) { GOB->stalk(str); return 1; }
semote(str) { GOB->semote(str); return 1; }
stitle() { GOB->stitle(); return 1; }
sage_score() { GOB->sage_score(); return 1; }
