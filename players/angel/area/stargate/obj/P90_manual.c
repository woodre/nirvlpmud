#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/treasure";

reset(arg)
{
	::reset(arg);
	if (arg) return;
    set_id("manual");
    set_alias("p90 manual");
    set_short("P90 Manual");
    set_long(
    "A P90 Manual\n");
    set_read(
    "         P90 MANUAL\n\
    This manual expains how the P90 works and all of its parts.\n\
    This machine gun combines the automatic fire of\n\
    a large machine gun with the cartridge of a pistol, and is\n\
    between the two in weight and size. \n");
    set_weight(0);
    set_value(0);
}