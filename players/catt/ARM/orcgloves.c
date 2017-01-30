inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
   set_name("orc gauntlets");
   set_alias("gauntlets");
   set_short("Orc gauntlets");
   set_long("The gauntlets are made of rough leather with small overlapping plates\n"+
            "of steel sewn over the top. They look at little rough but still serviceable.\n");
   set_value(35+random(15));
set_weight(1);
set_ac(1);
set_type("ring");
}
