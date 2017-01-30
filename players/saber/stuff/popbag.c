 inherit "obj/container.c";
 reset(arg) {
    ::reset();
    if (arg) return;
    set_name("bag");
    set_short("A bag of party poppers");
    set_long("A bag full of party poppers.\n"+
        "To use, type <poppers>\n");
    set_weight(0);
    set_value(10);
    set_max_weight(10);
}

init()  {
  ::init();
  add_action("dest_bag","poppers");
        }

dest_bag()  {
object pop;
int number;
  number = random(12);;
  while(number > 0)  {
  pop = clone_object("/players/saber/stuff/popper.c");
  move_object(pop, environment(this_player()));
  number = number - 1;
        }
  write("You reach into the bag and grab a handful of party poppers.\n"+
        "You throw the poppers into the air!\n");
  say(this_player()->query_name()+" reaches into a bag a grabs a handful of party poppers.\n"+
        this_player()->query_name()+" throws the poppers into the air!\n"+
        "It begins to rain party poppers!\n");
  return 1;
        }
