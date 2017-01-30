/*****************************************************************************
 *      File:                   ublood-product.c
 *      Function:               Behold... this item costs 1M coins to make
 *                              and it is completely USELESS.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(50);
    set_weight(1);

    set_name("cartridge");
    set_alias("printer cartridge");

    set_short("An inkjet printer cartridge (" + 
             HBCYN + HIK + "C" +
             HBMAG + HIK + "M" + 
             HBYEL + HIK + "Y" + 
             HBWHT + HIK + "K" + NORM + ")");
    set_long("This is a small printer cartridge for some sort of Canon inkjet\n"+
        "color photo printer.\n");

    set_read("A label on the cartridge reads: 'Genuine Canon Aftermarket Product'.\n");
    set_smell("The label smells like freshly popped plastic.\n");
    set_taste("Miu mook munny mif mee minter martridge min moor mouf.\n");
}

query_save_flag() { return 1; }
