inherit "obj/weapon.c";

reset(arg) 
{
  ::reset(arg);
  if (arg) return;
  set_name("Iphone4");
  set_alias("phone");
  set_short("An Apple Iphone4");
  set_long("A cell phone made from Apple Inc.\n");
  set_class(20);
  set_weight(3);
  set_value(7500);
  set_hit_func(this_object());
}

weapon_hit(attacker)
{
  int W;
  W = random(100);

  if(W > 50 && W < 90)
  {
    say("The Iphone4 zaps its foe with a powerful volt of electricity.\n");
    write("Your Iphone zapped your target with a bolt of electricty.\n");
    return 3;
  }

  if(W > 98)
  { 
    say(environment()->query_name()+"'s Iphone is destroyed!\n"); 
    write("Your Iphone is damaged and breaks.\n");
    this_object()->weapon_break();
    return 1;
  }
}

