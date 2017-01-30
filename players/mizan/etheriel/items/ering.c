inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
	set_name("Ring of Ephidrena");
	set_short("Ring of Ephidrena");
	set_long("This is a stunningly beautiful ring... upon closer inspection,\n"+
	"you realize it is a replica of the real ring of Ephidrena, which was\n"+
	"carved from a solid chunk of ruby.\n");
	set_value(1000);
	set_ac(1);
  set_weight(1);
	set_type("ring");
	set_alias("ring");
	}
