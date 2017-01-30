

/*
 * Example sword using paladin/obj/weapon.c
 */

inherit "players/sandman/paladin/obj/weapon";

reset() {
   set_name("broadsword");
   set_alias("sword");
   set_short("A broadsword");
   set_long("A broadsword of the finest metalwork you have seen in many\n"+
            "years.  The pommel is jewel-encrusted and the hilt surrounded\n"+
            "in gold.\n");
   set_class(18);
   set_weight(4);
   set_value(650);
   set_weapon_type("sword");
}

