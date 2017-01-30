inherit"obj/weapon";
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("thorn");
  set_alias("sword");
  set_short("The legendary sword Thorn");
  set_long(
    "This rather plain black sword is the very weapon used by\n"+
    "Sir Camaris, Prestor Johns greatest knight. This weapon\n"+
    "was rumored to be lost in the great north.\n"+
    "This is an excellent weapon, but a little unpredictable.\n");
/* Changed value from 6000 to 300 -Snow */
/* uh... how about 3k - verte */
  set_value(3000);
  set_weight(3);
  set_class(random(8)+15);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(10) > 8) {
  write("Thorn feels warm in your hands.\n");
   return 0;
   }
   return 0;
}
