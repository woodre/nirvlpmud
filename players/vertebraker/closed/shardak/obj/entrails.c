inherit "/obj/treasure";

void
init()
{
    ::init();
    add_action("cmd_eat", "eat");
}

status cmd_eat(string str){
    if(!str) return (notify_fail("Eat what?\n"), 0);
    if(!id(str)) return (notify_fail("You may only eat the entrails.\n"), 0);
    write("Greedily, you eat " + (string)this_object()->short() + ".\n");
    say(this_player()->query_name() + " eats " + (string)this_object()->short() + ".\n");
    this_player()->heal_self(value/4);
    destruct(this_object());
    return 1;
}

void reset(int x)
{
     if(!x) call_out("ollyollyolly", 300 + random(300));
}

ollyollyolly() {
     object x;
    if(x=environment()) { 
      if(x->is_player()) tell_object(x, "The entrails shrivel and decompose.\n");
      transfer(this_object(), "/room/void");
       destruct(this_object());
       return;
     }
}
