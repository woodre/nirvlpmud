	/* MT DEW marketable version 2.0 */

#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("dew");
    add_alias("can");
    add_alias("soda");
    add_alias("pop");
    add_alias("MTDew");
    set_short("a can of"+GRN+" MT Dew"+NORM+".");
    set_long("The greatest substance ever made by modern man. "+HIG+"MT.Dew"+NORM+". \n"+
             "You crave the caffinated goodness. Wren is your new god.\n");
    set_type("slams");
    set_type_single("slam");
    set_msg("You slam a "+GRN+"DEW"+NORM+". You feel invigorated.\n");
    set_msg2(" does the "+GRN+"DEW"+NORM+". \n");
    set_empty_msg("You finish off the "+GRN+"Mt Dew"+ NORM+" and spin the can into the trash.\n");
    add_cmd("slam");
    add_cmd("drink");
    set_heal(50,50);
    set_charges(3);
    set_soak(10);
    set_value(800);
}

