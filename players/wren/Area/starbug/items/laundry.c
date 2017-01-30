	/*Lister's dirty laundry...heh shop should charge players to be rid of this*/

inherit "/obj/treasure";

reset(arg)  {
     set_id("laundry");
     set_alias("dirty laundry");
     set_short("Lister's dirty laundry");
     set_weight(1);
     set_value(200);
     set_long("Gah, you don't know how Kryten can touch this stuff. \n"+
              "Well his lack of nose probably helps a lot. Some of \n"+
              "this stuff looks like it should be moving. Eww.\n"+
	      "you'll probably want to dispose of this quickly before \n"+
              "the scent gets to you.\n");
}


