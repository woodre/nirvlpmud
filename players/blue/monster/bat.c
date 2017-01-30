inherit"obj/monster";

reset(arg) {
   ::reset(arg);
   if(!arg) {

   set_name("bat");
   set_short("A big ol bat");
   set_long("It swoops on you!\n");
   set_level(1);
   set_hp(20);
   set_ac(3);
   set_wc(5);
}
}
