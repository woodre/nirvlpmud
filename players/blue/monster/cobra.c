inherit"obj/monster";

reset(arg) {
   ::reset(arg);
   if(!arg) {

   set_name("cobra");
   set_short("A nasty cobra");
   set_long("It's got LOOOOONNNNNGGGGGG fangs...\n");
   set_level(3);
   set_hp(50);
   set_wc(9);
   set_ac(6);
}
}
