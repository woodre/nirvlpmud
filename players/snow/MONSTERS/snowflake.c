inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(100) + 35);
  move_object(gold,this_object());
 
     set_name("snowflake");
     set_short("A small snowflake");
     set_race( "snowflake");
     set_alias("flake");
     set_long(
"A multi-faceted flake of frozen water. Surprisingly, this one is alive.\n");
     set_level(5);
     set_ac(1+ random(2));
     set_wc(5 + random(5));
     set_hp(40 + random(20));
     set_al(-200);
     set_aggressive(0);
   }
}
