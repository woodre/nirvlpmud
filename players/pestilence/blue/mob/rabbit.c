inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("rabbit"); 
  set_alias("rabbit");
  set_short("Rabbit");
  set_long("This is Rabbit.  He is gray and fluffy, and pedaling as fast as he\n"+
           "can so he can try to win the race.\n");
  set_level(4);
  set_wc(8);
  set_ac(5);
  set_hp(60);
  set_ep(1000);
  add_money(0);
  set_aggressive(0);
  set_al(200);
  move_object(clone_object("/players/pestilence/blue/obj/tricycle.c"),
      this_object());
 move_object(clone_object("/players/pestilence/blue/arm/bikehelmet.c"),
        this_object()); }
