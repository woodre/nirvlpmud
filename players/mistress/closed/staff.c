inherit "obj/weapon";

reset(arg) {
   if(!arg) {
      ::reset(arg);
      set_name("staff");
      set_short("A Golden Staff");
      set_class(10000);
      set_weight(0);
      set_value(10000); }
   }

get() {
   if(call_other(this_player(),"query_name") != "Mistress") {
      write("A strong force stops you from taking the staff.\n");
      return 0; }
   return (::get()); }
