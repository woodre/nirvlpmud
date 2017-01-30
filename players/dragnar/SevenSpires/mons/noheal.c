inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Mob");
  set_alias("mob");
  set_short("Incomplete Mob");
  set_long(
        "A very sad mob that is not very interesting.\n");
  set_level(22);
  set_ac(60);
  set_wc(80);
  set_hp(2500);
  set_al(100);
  set_aggressive(0);

  add_spell("stomp",
    "#MN# pulls up his huge $G$foot$N$ and S C R E A M S as he $G$S T O M P S$N$ on you!\n",
    "#MN# pulls up his huge $G$foot$N$ and S C R E A M S as he $G$S T O M P S$N$ on #TN#!\n",
    25,"10-50","physical" );
}
