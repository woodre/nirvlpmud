#define TP this_player()
#define TPN TP->query_name()
inherit "/obj/treasure";
reset(arg) {
  if(arg) return;
  set_id("heal");
  set_alias("dust");
  set_short("A bag of healing dust");
  set_long("This dust has magical powers of healing. 'sprinkle' the dust to invoke its power.\n");
  set_value(1500+random(200)); }

init() {
  ::init();
  add_action("cmd_sprinkle","sprinkle"); }

cmd_sprinkle(arg) {
  if(!arg) {
    notify_fail("Sprinkle what?\n");
    return 0; }
  if(arg == "dust") {
    write("You sprinkle the dust of full healing!\n");
    say(TPN+" sprinkles the dust of full healing!\n");
    TP->heal_self(10000);
    write("Your wounds are fully healed!\n");
    destruct(this_object());
    return 1; }
  }
