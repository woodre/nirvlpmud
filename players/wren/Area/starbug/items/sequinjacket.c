	/* Cat's Red Sequin Jacket */

inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("jacket");
   set_alias("sequin jacket");
   set_short("Cat's red sequin jacket");
   set_long("This is one of the Cat's many clothing items. It is a \n"+
            "dazzling bright red sequin jacket. It almost hurts to \n"+
            "look at. The Cat has worn this on at least one of his \n"+
            "attempts to find a female. Maybe you'll have better luck.   \n");
   set_ac(2);
   set_type("misc");
   set_weight(2);
   set_value(600);
}
query_save_flag() {return 1;}
