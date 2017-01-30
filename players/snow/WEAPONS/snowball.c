inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("snowball");
    set_alias("ball");
    set_short("A deadly snowball");
   set_type("mace");
    set_long("This is a mashed up ball of snow. It looks dangerous. \n");
    set_class(16);
    set_weight(1);
    set_value(150);
    set_hit_func(this_object());
call_out("melt_ball",1000);
}
weapon_hit() {
int W;
    W = random(100);
if (W > 70) {
  say(this_player()->query_name()+" smashes "+this_player()->query_gender()+
   " enemy with a snowball!\n");
  write("You smash your enemy with the snowball!\n");
return 6;
    }
if (W < 5)  {
  say("The snowball flies out of "+this_player()->query_name()+"'s hand!\n"+
     "\n"+"The snowball smashes into "+this_player()->query_attacker()+
    " with a THWOMP!\n");
  write("The snowball flies out of your hand!\n"+
       "The dirty ball of snow devastates your foe!\n"+
       "\n"+
       "You are wielding air!\n");
  if(this_player()->query_attack()->query_npc()) {
  call_other(this_player()->query_attack(),"heal_self",-40);
  }
  drop(1);
destruct(this_object());
   }
return 1;
}

melt_ball() {
  if(wielded) {
    say("Your snowball melts from your grasp!\n");
  command("unwield snowball",environment(this_object()));
destruct(this_object());
return 1;
    }
else
  say("The snowball melts away, leaving your clothes wet...\n");
destruct(this_object());
return 1;
}
