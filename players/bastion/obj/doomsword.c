
/* Sword for /players/bastion/monster/demon6 */

inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
     set_name("sword");
     set_alt_name("longsword");
     set_long("It is a blade of pure blackness, warm to the touch.\n");
     set_short("A black longsword");
     set_class(20);
     set_weight(1);
     set_value(10000); 
     set_save_flag(0);
     set_hit_func(this_object()); }


weapon_hit(attacker) {
     write("The blade screams for blood in your mind!\n");
     say(this_player()->query_name() + " attacks with the fervor of " +
         "a madman!\n");
     return 100;
}
