inherit "obj/armor";

reset(arg) {
   if(!arg) {
      ::reset(arg);
      set_name("cloak");
      set_short("A Cloak of Mist");
      set_type("misc");
      set_alias("cloak");
      set_ac(500);
      set_weight(0);
      set_value(10000); }
   }

get() {
   if(call_other(this_player(),"query_name") != "Mistress") {
      write("A strong force stops you from taking the cloak.\n");
      return 0; }
   return (::get()); }
