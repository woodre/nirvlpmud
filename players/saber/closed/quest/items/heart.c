inherit "obj/treasure";

reset(arg)
{  if (arg) return;
   set_id("heart");
   set_short("The heart of a nightmare");
   set_long(
     "The heart of a nightmare.  It still drips with dark blood.\n");
   set_weight(1);
   set_value(50);
}

quest_ob()  { return 1; }
query_save_flag()  { return 1; }
