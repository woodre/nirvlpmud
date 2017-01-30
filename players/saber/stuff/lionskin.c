inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("skin");
   set_short("A beautiful lion skin");
    set_long("The skin of a lion.  It looks very soft.\n"+
     "You think that it would be worth a decent price.\n");
   set_weight(3);
   set_value(850);
}

quest_ob()  { return 1; }
