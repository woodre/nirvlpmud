inherit "obj/food";

reset(arg) {
   if(arg) return;
   set_name("honey pot");
   set_short("A honey pot");
   set_long("A ceramic pot filled with golden honey.\n");
   set_value(300);
   set_weight(1);
   set_strength(30);
   set_eater_mess("You stuff you face into the pot of honey and dig in.\n"+
         "You throw the empty pot away when you're finished.\n");
   set_alias("pooh_honeypot");
}

id(str) {
   return str == "honey pot" || str == "honey" || str == "pot" || str == "pooh_honeypot";
}
