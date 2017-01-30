	/*Fuzzy dice for the bridge */

inherit "/obj/treasure";

reset(arg)  {
     set_id("dice");
     set_alias("fuzzy dice");
     set_short("a pair of red fuzzy dice");
     set_weight(1);
     set_value(5);
     set_long("You've found the fuzzy dice that used to hang above \n"+
              "the dash. They must have fallen off when the gelf \n"+
              "battle cruiser attacked or maybe it was the Deep  \n"+
              "Space Enforcer pod. They look pretty battered.     \n");
}


