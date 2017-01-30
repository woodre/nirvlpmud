inherit"obj/weapon";
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("crowned mace");
  set_alias("mace");
  set_short("Crowned Mace");
  set_long(
  "This weapon was forged with king lang's crown when mortici\n"+
  "the bloody usurped the throne. It is a dull grey weapon\n"+
  "with very little embellishment except for the crown emerald\n"+
  "which is set in the shaft of the weapon.\n");
  set_value(4000);
  set_weight(3);
  set_class(14);
  set_hit_func(this_object());
}
weapon_hit(attacker) {
  if(random(100) < 30) {
    write("Lang's ghost is summoned by the mace\n"+
          "Lang blasts "+attacker->query_name()+" with death stare\n");
   say("Lang's ghost is summoned by the mace\n"+
       "Lang blasts "+attacker->query_name()+" with death stare\n");
   return 3;
  }
return 0;
  }
