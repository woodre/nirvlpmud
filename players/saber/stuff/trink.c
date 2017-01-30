inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("trinket");
   set_short("A strange metal trinket");
   set_long("A strange metal trinket.\n"+
       "You have no idea what it is for.\n");
   set_weight(1);
   set_value(75);
}

quest_ob()  { return 1; }
