inherit "obj/food.c";
reset(arg){
object apple;
set_name("calendula");
set_alias("sprig");
set_short("A sprig of Calendula");
set_long("A naturaly growing herb in the Whispering Woods.  It has\n"+
         "fine healing properties when eaten.\n");
set_value(5);
set_strength(20);
set_weight(1);
set_eater_mess("You place the sprig to your tongue and your wounds close!\n");
set_eating_mess(" eats the Calendula and is healed.\n");
}


