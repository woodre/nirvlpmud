inherit "obj/monster";

reset(arg) {
   set_name("tarrasque");
   set_level(25);
   /* Changed from 30 to 25 per monster.guide rules */
   set_hp(1000+random(501));
   /* Changed from 1500 to 1000+r501 per monster.guide rules (plus extra)*/
   set_wc(45);
   set_al(0);
   set_short("An INCREDIBLY vicious tarrasque...very dangerous.");
   set_long("Don't mess with this unless you're REALLY serious!\n");
   set_aggressive(1);
   set_ac(27);
   add_money(4000+random(1001));
   set_can_kill(1);
   ::reset(0);
}
