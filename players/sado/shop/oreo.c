#define tpname this_player()->query_name()

inherit "/obj/treasure.c";

int cookies;

reset(arg)
{
   if(!arg)
      {
      set_id("box");
      set_alias("oreos");
      cookies=10;
      set_weight(1);
      set_value(250);
      set_short("A box of oreo cookies");
      set_long("A box of oreos.\nNumber of cookies left: ");
   }
}

init()
{
   ::init();
   add_action("devour","eat");
}

query_price() { return 250; }

long()
{
   write(long_desc+cookies+"\n");
}

devour(str)
{
   if(!(str=="oreo" || str=="cookie"))
      return 0;
   if(random(3)==1)
      write("You bite into the cookie, and enjoy the combination of rich and light flavors.\n");
   else if(random(3)==1)
      write("You pull the sandwich apart, and lick the cream off each biscuit, then eat them.\n");
   else
      write("You put the whole cookie into your mouth, and chomp it down. It tastes delicious!\n");
   say(tpname+" eats an oreo cookie.\n");
   if(--cookies==0) {
      write("You finish off the packet, crumple it up, and through it in a trashcan which\n" +
         "appears magically from nowhere, then disappears with the packaging.\n");
      say(tpname+" finishes the pack of cookies, and throws the box away.\n");
      destruct(this_object());
   } else {
      write("There are now "+cookies+" left.\n");
      set_value(25*cookies);
   }
   return 1;
}
