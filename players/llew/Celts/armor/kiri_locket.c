inherit "obj/armor";

reset(arg) {
   if(arg) return;
   set_id("locket");
   set_name("locket");
   set_short("A silver locket");
   set_value(500);
   set_weight(0);
   set_ac(1);
   set_long("The small silver locket opens to a picture of a beautiful elven\n"+
            "maiden.  Celtic whorls and spirils adorn the coverings.\n"+
            "On the side opposite the picture is an inscription.\n");
   set_type("amulet");
}
init() {
   ::init();
   add_action("read","read");
}

read(str) {
   if(!str || !id(str)) { return 0; }
   write("For the beautiful Kirlar...\nMay she grace us always.\n");
   return 1;
}
