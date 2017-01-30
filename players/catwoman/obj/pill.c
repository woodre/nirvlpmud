
#include "/obj/clean.c"

short()
{
      return "A weight-loss pill";
}

query_value()
{
        return 23;
}

  query_weight() {   return 0; }
long()
{
     write("A pill used to lose weight, some side effects are possible.\n");
}

init() {
     add_action("eat","eat");
     add_action("eat","swallow");
}

id(str) {
    return str == "pill" || str == "weight-loss pill";
}

eat(str) {
    if (str && !id(str))
        return 0;
    if (!call_other(this_player(), "eat_food", 2))
        return 1;
say(call_other(this_player(), "query_name") +
    " eats a pill.\n");
     if(random(100)> 1) {
     if(!this_player()->query_pregnancy()) {
       this_player()->add_phys_at(3,-random(15));
write("You eat the pill and lose weight.\n");
say(this_player()->query_name()+" grows smaller.\n");
    } else { 
      if(random(100) < 50) {
      write("The pill has no effect.\n");
     } else {
     write("Something feels wrong.\nYou feel your body expand as you gain weight.\n");
     say(this_player()->query_name()+" grows larger.\n");
     this_player()->add_phys_at(3,random(50));
     }
      }
    }
    else
    {
    this_player()->add_phys_at(3,random(50));
    write("Something feels wrong.\nYou feel your body expand as you gain weight.\n");
say(this_player()->query_name()+" grows larger.\n");
    }
  destruct(this_object());
    return 1;
}

get() {
      write("You pick up the pill.\n");
    return 1;
}
