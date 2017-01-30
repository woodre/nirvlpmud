inherit "obj/weapon.c";
reset(arg) {
    ::reset();
    if (arg) return;
    set_name("cleaver");
    set_alias("sword");
    set_short("A Meat Cleaver");
    set_long("A mean looking meat cleaver is looks like it could do\n" +
             "some very serious damage\n\n");
    set_class(18);
    set_save_flag(0);
    set_weight(3);
    set_value(5000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   if(call_other(this_player(), "query_attrib", "pie") > random(40)) { 
      write("You cleave through the bones of your opponent.\n");
      say ("You hear the crunching of bones.\n");
      return 7;
   }
   return;
}
