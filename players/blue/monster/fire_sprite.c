inherit"obj/monster";

reset(arg) {
   object coins;
  ::reset(arg);
   if(!arg) {

   set_name("sprite");
   set_short("Fire sprite");
set_long(
"This is a thin creature with slitty eyes.  It stands only a few feet off\n"+
"the ground.  There are flames dancing on his clothes.\n");
   set_level(5);
   set_hp(75);
   set_ac(5);
   set_wc(11);
   set_al(-200);
   coins=clone_object("obj/money");
/* Changed from 400 to 200 (lev.5 monster) */
   coins->set_money(200);
   move_object(coins, this_object());
}
}
