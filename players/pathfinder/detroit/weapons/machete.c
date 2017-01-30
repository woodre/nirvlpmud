inherit "obj/weapon.c";

reset(arg) 
{
  ::reset(arg);

  if (arg) return;

  set_name("machete");
  set_alias("machete");
  set_alias("machete");
  set_short("A deadly looking machete");
  set_long("You look at a viscious looking machete dripping with the \n" +
           "blood from its latest victim.\n");
  set_class(17);
  set_weight(5);
  set_value(5000);
  set_hit_func(this_object());
}
 
weapon_hit(attacker) 
{
  int W;

  W = random(25);

  if((W < 9) && (W > 4)) 
  {
    if(this_player()->query_alignment() < -500) 
    {
      call_other(this_player(), "add_hit_point", -W);
      say("The machete chops it opponent in half with its mighty blade!\n");
      write("Your machete chops its opponent in half!\n");
      return (random(6));
    } 
    else 
      return; 
 
  }
}
