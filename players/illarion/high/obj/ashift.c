/* armour (sort of) for high/mon/amanda */

inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("shift");
  set_short("A filmy, clingy shift");
  set_long(
"A scandalously thin piece of cloth in the vague shape of a female torso.\n"+
"Although it more or less covers the areas a shift is generally expected\n"+
"to, it is too thin and too apt to cling to conceal anything the low cut\n"+
"neck and high cut legs do not already reveal.\n");
  set_ac(1);
  set_weight(1);
  set_value(200);
}
