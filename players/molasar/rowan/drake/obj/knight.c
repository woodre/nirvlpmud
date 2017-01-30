
/*
 * DEATH KNIGHT (4/30/94)
 */

inherit "obj/monster";

reset(arg) {
   if(arg)
     return;
   set_name("knight");
   set_alias("evil_guard");
   set_short("A death knight");
   set_long("Standing before you is one of the cursed knights in the\n"+
   "service of Lord Ariand. They are doomed to spend the rest of eternity\n"+
   "guarding these halls. Clad in black platemail and wielding great\n"+
   "broadswords these are very imposing enemies.\n");
   set_level(16);
   set_wc(25);
   set_ac(10);
   set_hp(450);
   set_aggressive(1);
   set_al(-750);
   ::reset();
}


