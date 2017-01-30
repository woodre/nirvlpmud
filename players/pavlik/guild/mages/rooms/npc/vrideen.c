inherit "/obj/monster";

  int BUSY;
reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_name("Vrideen");
 set_alias("vrideen");
 set_short("Vrideen the Dragon Trainer");
 set_long(
 "Vrideen is an old wrinkled lump of flesh.  However you can read\n"+
 "strength and awesome power in his dark blue eyes.  Vrideen the\n"+
 "Dragon Master has been working with dragons since he was a small\n"+
 "child, and he has the scars to prove it.\n");
 set_level(30);
 set_ac(10);
 set_wc(30);
 set_hp(10000);
 set_al(10000);
 set_aggressive(0);
 call_out("rid_this", 60);
   }
}


