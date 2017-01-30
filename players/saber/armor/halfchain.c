inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("half chain");
   set_short("A suit of magical half chain");
   set_alias("chain");
   set_long("A suit of magical fine steel half chain.\n");
   set_ac(3);
   /* magical armor should protect from magic, at least a little */
   set_params("magical",1);
   set_weight(2);
   set_value(500);
}
