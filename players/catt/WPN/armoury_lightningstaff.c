inherit"obj/weapon";
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("lightning staff");
  set_alias("staff");
  set_short("lightning staff");
  set_long(
    "This staff is not for the faint of heart for it is made of\n"+
    "a harnessed lightning bolt of blindingly powerful energy.\n");
  set_value(8000);
  set_weight(3);
  set_class(3);
  set_params("other|electric",12,0);
  set_hit_func(this_object());
}
weapon_hit(attacker) {
  if(random(100) < 80) {
  write("Lightning cascades around "+attacker->query_name()+"\n");
  write(attacker->query_name()+" is rocked to the ground\n");
  say("Lightning cascades around "+attacker->query_name()+"\n");
  say(attacker->query_name()+" is rocked to the ground\n");
   return 3;
  }
return 0;
}
