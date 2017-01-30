inherit"obj/monster";

reset(arg) {

   ::reset(arg);

   if(!arg) {

   set_name("lavaman");
   set_alias("man");
   set_alt_name("lava");
   set_level(7);
   set_hp(105);
   set_ac(7);
   set_wc(12);
   set_short("A Lava Man");
   set_long(
"Steam pours off his 500 degree body.  The lava man appears to be made of..."+
"\n....lava.\n");

   }
}
