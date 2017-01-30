
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("scalemail");
   set_type("armor");
   set_short("a suit of scalemail");
   set_long("A suit of scalemail with the emblem of a dragon on the shoulder.\n");
   set_ac(2);
   set_value(300);
   set_weight(2);
}

