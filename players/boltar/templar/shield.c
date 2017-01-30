/* Orginal code from Bern's Clerics, 
Modified to become The Knight's Templar by Boltar.
   */
inherit "obj/armor.c";
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("templar shield");
   set_short(this_player()->query_name()+"'s Templar Shield");
   set_long("The shield more Knights choose.\n");
   set_ac(1);
   set_type("shield");
   set_value(0);
}

init() {
   ::init();
   add_action("wear","wear");
   add_action("remove","remove");
}

wear(str) {
   if (!id(str)) return 0;
   if (present("KnightTemplar", this_player())) {
     ::wear(str);
      if(!worn) destruct(this_object());
      call_out("done",1300);
      return 1;
   }
   write("Only Knights Templar can wear this.\n");
   return 1;
}

remove(str){
   if (!id(str)) return 0;
   ::drop();
   destruct(this_object());
   return 1; }
drop() {
   write("The Templar Shield destructs as it hits the ground.\n");
   ::drop();
   destruct(this_object());
   return 1;
}


done() {
   object bbh;
   bbh = environment(this_object());
   if(bbh) {
      if(bbh->is_player())
         command("remove shield",bbh);
      tell_object(bbh, "Your Templar Shield shimmers and fades away.\n");
      ::drop();
      destruct(this_object());
      return 1;
   }
}
