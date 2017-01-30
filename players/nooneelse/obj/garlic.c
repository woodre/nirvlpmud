/*
 garlic.c
*/

/*
 * This stuff is good to have when fighting against the vampires in
 * nooneelse's castle.
*/

inherit "obj/food";

string str;

reset(arg) {
     ::reset(arg);
     set_name("garlic");
     set_alias("clove");
     set_short("a clove of garlic");
     set_value(0);
     set_weight(1);
     set_eater_mess("You eat the clove of garlic.  Yech!  That tasted nasty.\n");
     set_eating_mess(" eats a clove of garlic and makes a face.\n");
}

id(str) { return (str=="clove" ||
                  str=="garlic" ||
                  str=="clove of garlic" ||
                  str=="holy item");
}
