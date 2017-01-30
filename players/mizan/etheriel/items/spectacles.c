inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
	set_name("spectacles");
	set_short("A funky pair of spectacles");
        set_long("'Genuinely antiquish', these metal-framed spectacles are\n"+
	"a relic from pre-industrialized Europe. Boggling!\n");
	set_value(350);
	set_ac(1);
	set_type("misc");
  set_weight(1);
}
