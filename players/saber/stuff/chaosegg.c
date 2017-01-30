inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("chaos egg");
   set_alias("egg");
   set_short("A Chaos Egg");
   set_long("A chaos egg.  Legend has it that the chaos egg\n"+
       "contains the very essence of chaos.  If you type\n"+
       "<hatch egg>, something may happen.\n");
   set_weight(1);
   set_value(1000);
}
init()
{  add_action("hatch_egg", "hatch");   }

hatch_egg(str)
{  if ((!str) || !id(str)) return 0;
  write("The egg cracks and is gone.\n"+
        "A message appears.\n"+
        "\n\n        \"\We're sorry, but the egg is currently out of order.\"\n"+
        "\n            \"\Try again later for better results.\"\n"+
        "\n                                             -- the management.\n\n");
   destruct(this_object());
    return 1;   }

