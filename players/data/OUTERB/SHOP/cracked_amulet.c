inherit "obj/armor";


reset(arg) {
if(arg) return;
::reset(arg);

set_name("amulet");
set_alias("amulet");
set_short("A Cracked Amulet");
set_long(

      "This amulet belonged to some long dead person, you hope you don't visit his fate.\n"

);

set_ac(1);
set_type("amulet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(100);

}



