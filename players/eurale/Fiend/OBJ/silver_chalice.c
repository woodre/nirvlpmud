#define tp this_player()
#define ETP environment(this_player())
inherit "obj/treasure";
reset(arg) {
  if(arg) return;

set_id("chalice");
set_alias("silver chalice");
set_short("An ornate silver chalice");
set_long(
  "This ornate silver chalice must have belonged to royalty.  Its\n"+
  "slender stem and rolled base add a distinct touch of class.  All\n"+
  "one has to do is 'barter' it.\n");

set_weight(1);
set_value(2750);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!present("sedjak",ETP)) return 0;
if(str == "chalice" || str == "silver chalice") {
  num = 4900 + random(600);
  write("You haggle over the value of the chalice with Sedjak and\n"+
        "eventually settle on "+num+" coins as a fair price.\n");
  tp->add_money(num);
  destruct(this_object());
  return 1; }
}
