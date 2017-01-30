#define lvl this_player()->query_level()
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("kama");
  set_alias("kama");
  set_short("kama");
  set_long("This is a kama- a small tool used for cutting plants.\n"+
      "A metal blade sticks out at right angles to the wooden\n"+
      "handle.\n");

  set_class(8);

  set_weight(1);
  set_value(100);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W,Y;
W = random(22);
if(W>16)  {
  Y = call_other(this_player(),"query_attrib","luc") ;
  say("The kama slices through the muscles of its foe!\n");
  write("You slice through muscle- shredding flesh.\n");
return (Y/2);

   }
   return;
}

init() {
  ::init();
  if(this_player() == environment(this_object())) {
   if(lvl > 9) set_class(4);
  else if(lvl > 5) set_class(6);
  else if(lvl > 3) set_class(8);
  else set_class(10);
}
}
