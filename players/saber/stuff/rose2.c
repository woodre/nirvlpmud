inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("rose");
   set_short("A small silver rose");
   set_long("This small silver rose is very beautiful to look at.\n");
   set_weight(1);
   set_value(10);
}
init()
{  add_action("smell_rose", "smell");   }
smell_rose(str)
{  if ((!str) || !id(str)) return 0;
   write("You smell the sweet fragrance of the silver rose.\n");
    return 1;   }

quest_ob()  { return 1; }
