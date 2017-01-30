inherit "obj/monster";

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("imp");
   set_alias("imp");
set_short("Impoverished");
set_long("This poor guy is just that. Poor as shit. It would be sad\n"+
"to kill this dood. Nahhh go ahead.\n");
   set_level(3);
   set_hp(45);
   set_al(100);
   set_wc(7);
   set_ac(5);
}
