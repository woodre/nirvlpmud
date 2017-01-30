#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/treasure";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("key3");
	set_alias("key");
	set_short("Key3");
	set_long("A key.\n");
	set_weight(1);
}

init() {
	::init();
	if(present("key1") && present("key2") && present("key3")) {
		write("Key3: all here!\n");
	}
}
