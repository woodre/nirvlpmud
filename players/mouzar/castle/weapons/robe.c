inherit "obj/armor";
reset(arg) {
   if (arg) return;
   set_name("robe");
   set_short("Monkey's Robes");
   set_type("armor");
   set_alias("robes");
/* changed from -200[?!?!?!] to 1.  Vertebraker[6.2.01] */
   set_ac(1);
   set_weight(1);
   set_value(10000);
   set_long("Very fancy robes.  They are white with gold trimming.  As you look closer\n"+
           "you see that the gold is very much real.  It doesn't look like it would\n"+
           "provide much protection.\n");
}
