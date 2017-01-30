	/*Cat's comb, he wouldn't go anywhere without it*/

inherit "/obj/treasure";

reset(arg)  {
     set_id("comb");
     set_alias("hair pick");
     set_alias("pick");
     set_short("the cat's hair pick");
     set_weight(1);
     set_value(500);
     set_long("This is one of the Cat's prize hair care devices. It's  \n"+
              "hard to keep looking so good without constant attention.\n"+
              "Cat uses this often for grooming even in odd environments\n"+
              "like during an ion storm.\n");

}
