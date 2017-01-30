#define TP this_player()
#define TPN TP->query_name()
inherit "/obj/treasure";
reset(arg) {
  if(arg) return;
  set_id("heal");
  set_alias("scroll");
  set_short("A scroll of full heal");
  set_long("This is a scroll of full healing.  'read' it.\n");
  set_value(300+random(200)); }

init() {
  ::init();
  add_action("cmd_read","read"); }

cmd_read(arg) {
  if(!arg) {
    notify_fail("Read what?\n");
    return 0; }
  if(arg == "scroll") {
    write("You read the scroll of full healing!\n");
    say(TPN+" reads the scroll of full healing!\n");
    TP->heal_self(10000);
    write("Your wounds are fully healed!\n");
    destruct(this_object());
    return 1; }
  }
