inherit "obj/treasure";
#define ME capitalize(this_player()->query_name())
#define PO this_player()->query_possessive()

reset(arg) {
  if(arg) return;
  set_short("A red Potion");
  set_alias("potion");
  set_long("A tiny vial filled with red liquid.\n");
  set_weight(1);
  set_value(700);
}

id(str) {
  return str == "vial" || str == "potion" || str == "red" ||
  str == "red potion";
}

init() {
 ::init();
  add_action("drink","drink");
}

drink(str) {
  if(id(str)) {
    write(
    "You tip the vial to your lips and down the red liquid.\n"+
    "It burns as it slides down your throat, but once the red\n"+
    "fluid hits your stomach you feel much better!\n");
    say(ME+" drinks a red potion.\n");
    this_player()->add_spell_point(300);
    this_player()->add_weight(-1);

    write_file("/players/pavlik/ilstkarn/ITEM_LOG",
        ctime()+"\t"+capitalize(this_player()->query_name())+" used a Red Potion.\n");

    destruct(this_object());
    return 1;
  }
}

