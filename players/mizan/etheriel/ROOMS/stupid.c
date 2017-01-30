inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tWispy filamentine structures, made of a semi-solid inflexible\n"+
"  material restrict movement around here. A dazzling and bewildering array\n"+
"  of them drift by, spiraling and weaving randomly. Resembling what you\n"+
"  know as DNA, your head begins to smart just trying to come up with\n"+
"  a logical explanation for what you have just observed.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/spucktrooper.c",
    "players/mizan/etheriel/beasties/feathertone.c",
    "players/mizan/etheriel/beasties/fuzzy.c"
  });
  ::extra_reset();
  if(1==random(100)) {
  move_object(clone_object("players/mizan/etheriel/items/blockbuster.c"), this_object());
  }
}
