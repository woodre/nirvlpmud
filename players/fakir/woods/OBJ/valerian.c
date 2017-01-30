inherit "obj/food.c";
reset(arg){
object apple;
set_name("valerian");
set_alias("plant");
set_short("A Valerian Plant");
set_long("A naturaly growing herb in the Whipspering Woods.  It has\n"+
         "fine healing properties when eaten.\n");
set_value(5);
set_strength(20);
set_weight(1);
set_eater_mess("You chew the Valerian and swallow...your wounds heal!\n");
set_eating_mess(" chews the Valerian and is healed considerably.\n");
}


