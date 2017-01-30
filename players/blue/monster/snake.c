inherit"obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

   set_name("snake");
   set_short("A slithery snake");
   set_long("It has no limbs, and it moves funny.\n");
   set_level(1);
   set_hp(20);
   set_wc(6);
   set_ac(2);
   }
}
