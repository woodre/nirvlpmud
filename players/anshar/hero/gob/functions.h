/* FUNCTIONS */
hero_reset() {
  object ob;
  save_me();
  ob = clone_object("/players/anshar/hero/gob.c");
  write("Resetting Hero Stats.\n");
  move_object(ob, TP);
  destruct(this_object());
  return 1; }
shelp(str) { GOB->shelp(str); return 1; }
shome() { GOB->shome(); return 1; }
stalk(str) { GOB->stalk(str); return 1; }
semote(str) { GOB->semote(str); return 1; }
stitle() { GOB->stitle(); return 1; }
hero_score() { GOB->hero_score(); return 1; }
