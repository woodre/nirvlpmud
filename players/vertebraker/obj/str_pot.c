inherit "/obj/treasure";

reset(arg)
{
  if(arg) return;
  set_id("potion of strength");
  set_alias("potion");
  set_short("A potion of strength");
  set_long("\
Drink me.\n");
  set_weight(1);
}

init()
{
  ::init();
  add_action("cmd_drink","drink");
}

cmd_drink(str)
{
  if(!str){
    notify_fail("Drink what?\n");
  }
  else if(!id(str)){
    notify_fail("You can only drink "+query_name()+".\n");
  }
  else {
    object mod;
    
    write("You gulp down the potion.\n");
    say(this_player()->query_name() + " gulps down a potion.\n");
    
    mod = clone_object("/obj/attrib_mod");
    mod->set_dest_msg("The effects of the potion of strength wear off.\n");
    move_object(mod, this_player());
    mod->start_it("str", 5, 600);
    destruct(this_object());
    return 1;
  }
}