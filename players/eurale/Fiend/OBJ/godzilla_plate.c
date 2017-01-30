#define ETP environment(this_player())
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
set_id("plate");
set_short("godzilla plate");
set_long(
  "This solid plate off the back of Godzilla is valued by treasure\n"+
  "hunters the world over.  You could probably 'barter' it to one who\n"+
  "mixes magical potions and the like.\n");

set_weight(3);
set_value(3000);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!present("rue",ETP)) return 0;
if(str == "plate") {
  num = 4900 + random(100);
  write("Rue takes the plate and licks it.  She exclaims, 'Aha, a fine\n"+
        "specimen from godzilla.'  She quickly hides it away and pays\n"+
        "you "+num+" coins for it.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1;}
}
