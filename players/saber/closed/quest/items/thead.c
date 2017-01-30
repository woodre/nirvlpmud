inherit "obj/treasure";

reset(arg)
{  if (arg) return;
   set_id("head");
   set_short("The bloody head of a troll");
   set_long(
    "The head of a troll.  It is covered with blood.\n");
   set_weight(1);
   set_value(50);
}

quest_ob()  { return 1; }
query_save_flag()  { return 1; }
