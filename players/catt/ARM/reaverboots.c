/* 8.7.01 - Vertebraker changed ac to 2.  we could use some more good boots.
    might increase play in the area */
inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("leather merc boots");
set_alias("boots");
set_short("Leather mercenary boots");
set_long(
"These are the boots used by the mercenaries. They may be magical.\n" +
"If they are or not, they still look very comfortable.\n");
set_weight(1);
set_value(200);
set_ac(2);
set_type("boots");
}
