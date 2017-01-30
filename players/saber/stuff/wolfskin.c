inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("pelt");
    set_short("A beautiful wolf pelt");
    set_long("The pelt of a wolf.  It looks very soft.\n"+
     "You think that it would be worth a decent price.\n");
   set_weight(3);
   set_value(200);
}

quest_ob()  { return 1; }
