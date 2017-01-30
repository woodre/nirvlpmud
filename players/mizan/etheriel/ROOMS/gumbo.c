inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tUncontrollable and utterly wacko thoughts seem to force\n"+
"  their way into your mind for some reason... You begin thinking about\n"+
"  things like stainless steel watermelons and dirt-flavored ice cream...\n"+
"  Not just that, but the Principles of Painless Distraction which you\n"+
"  have been completely ignorant about previously- all become clear...\n"+
"  Wow. 'This is really cool' you say in a hushed voice.\n";

}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/gumby.c",
    "players/mizan/etheriel/beasties/pokey.c",
    "players/mizan/etheriel/beasties/fungoid.c",
    "players/mizan/etheriel/beasties/spuckball.c",
  });
  ::extra_reset();
  if(1==random(200)) {
  move_object(clone_object("players/mizan/etheriel/heals/dirtbag.c"), this_object());
  }
}

