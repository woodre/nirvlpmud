inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("punk");
set_short("A Punk");
set_long("This is an outcast punk with a pink striped orange mohawk.  With"
+" those\nlooks, he SHOULD be put out of his misery.\n");
set_al(-50);
set_level(3);
set_wc(3);
set_hp(15);
set_ac(0);
set_aggressive(0);
}
