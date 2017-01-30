	/*Red Light Bulb for Red Alert */

inherit "/obj/treasure";

reset(arg)  {
     set_id("bulb");
     set_alias("red bulb");
     set_short("the red bulb for the alert light");
     set_weight(1);
     set_value(5);
     set_long("This is the red bulb that needed to be swapped in to \n"+
              "change to red alert.  Kryten must have forgotten about\n"+
              "where it was during the mocking of Rimmer that followed \n"+
	      "the request for upgrading alert status and for saying \n"+
              "'Shrove Tuesday' instead of mayday.\n");
}
