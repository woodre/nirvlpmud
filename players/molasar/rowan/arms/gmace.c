
/*
 * Generic mace for use with /players/molasar/rowan/obj/tr_gen
 */
inherit "obj/weapon";
inherit "players/sandman/paladin/obj/weapon";

reset(arg) {
   if(arg) return;
   set_name("mace");
   set_short("A small wooden mace");
   set_long("A small mace made of oak.\n");
   set_weight(2);
   set_value(100);
   set_class(10);
}

