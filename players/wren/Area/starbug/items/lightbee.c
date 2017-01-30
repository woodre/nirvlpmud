	/*Rimmer's Hardlight lightbee*/

inherit "/obj/treasure";

reset(arg)  {
     set_id("object");
     set_alias("light bee");
     set_short("a strange object called a 'light bee'");
     set_alias("bee");
     set_weight(1);
     set_value(random(500)+1500);
     set_long("This is the moble projector for the Rimmer Hologram. \n"+
              "Legion improved it to a 'hardlight' form allowing him \n"+
              "to act much as a human can. It's capable of taking a \n"+
              "fair amount of damage as was proven by the number of \n"+
              "times its been beat around and that Lister 'passed\n"+
              "it' heh.\n");

}


