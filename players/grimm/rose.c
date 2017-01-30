inherit "obj/treasure";
reset(arg) {
  if(arg) return;
  set_id("A lovely rose");
  set_short("A lovely rose");
  set_long("This is a lovely rose given to express friendship.  It is clean"
+" cut and has\na wonderfully tantalizing aroma.\n");
  set_alias("rose");
  set_weight(0);
  set_value(50);
}

init() {
add_action("smell","smell");
}

smell(str) {
if(str!="rose") return;
write("The aroma of the rose almost overwelms you with a sense of delight.\nYou lean back to enjoy the scent and almost drift away.\n");
return 1;
}
