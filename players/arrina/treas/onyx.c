  inherit "obj/treasure";
  reset(arg)  {
   if(arg) return;
     set_id("onyx");
    set_short("A piece of carved onyx");
    set_long("This is a beatiful piece of onyx, carved into a statue.\n"
 +     "You think that it would be worth a decent price.\n");
    set_weight(2);
    set_value(650);
 }
