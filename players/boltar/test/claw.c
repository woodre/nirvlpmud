inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("claws");
  set_alias("claws");
  set_short("claws");
  set_long("The claws are slightly curved and and are razor edged.\n"+
    "They gleam in the light.\n"+"\nYou  T R E M B L E  as you behold them.\n\n");
  set_class(15);
  set_weight(1);
  set_value(300);
  set_buy_value(500);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(22);
if(W>16)  {
  say("The CLAWS tear into the flesh of its foe.\n"+
    "\nBlood spurts everywhere.\n\n");

  write("You slice into your foe's flesh, tearing chunks of meat out.\n"+
    "Blood from your foe spurts everywhere.\n"+"\n        Feels GOOD doesn't it?\n\n");
return 4;

   }
   return;
}
