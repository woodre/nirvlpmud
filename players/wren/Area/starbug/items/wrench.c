	/*spanner or wrench, heh you're call*/

inherit "/obj/treasure";

reset(arg)  {
     set_id("wrench");
     set_alias("pipe wrench");
     set_short("small pipe wrench");
     set_weight(1);
     set_value(500);
     set_long("Kochanski was attempting to quiet the noisy pipes by\n"+
              "pounding on them with this. It didn't help. It's    \n"+
              "slightly battered but might be worth something.     \n");
}
