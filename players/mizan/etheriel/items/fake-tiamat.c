id(str) { return str == "tiamat"; }
short() { return "Tiamat, Guardian of the Gate"; }
long() {
write("Ha! Fooled ya! This is just a scaled-down, inflatable replica of\n"+
  "the infamous nine headed beast. Most people hate her so much they\n"+
  "would just love to 'pop' Tiamat.\n");
}

init() { add_action("popme","pop"); }

popme(str) {
  if(!str || str != "tiamat") return 0;
  write("POP! Tiamat deflates into a helpless ball of vinyl before you.\n");
  say((this_player()->query_name()) + " POPS an inflatable Tiamat!\n");
  say("Zzzzzzzzz.....\n");
  say("It is now just a worthless pile of colored vinyl.\n");
  destruct(this_object());
  return 1;
}

get() { return 1; }
