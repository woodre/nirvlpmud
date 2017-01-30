inherit"obj/monster";

reset(arg) {
   ::reset();
   if(arg) return;

   set_name("clerk");
   set_alias("clerk_ob");
   set_wc(20);
   set_hp(2000);
   set_ac(10);
   set_level(15);   
   call_out("correct_busy",3);   
}

correct_busy() {
   object desk;
   desk = present("desk", environment(this_object()));
   if(desk) {
      desk->no_busy();
      call_out("correct_busy",3);
   }
}

short() {
   if(this_object()->query_attack()) return "Dread Clerk";
   return 0;
}
