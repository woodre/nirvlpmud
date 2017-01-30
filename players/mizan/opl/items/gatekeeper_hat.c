/*****************************************************************************
 *      File:                   gatekeeper-hat.c
 *      Function:               Worn by the gatekeeper
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

inherit "/obj/armor.c";

reset(arg) 
{

    ::reset(arg);
    if(arg) return;
    set_name("helmet");
    set_short("A red helmet shaped like a giant key");

    set_long("This is a rather goofy looking helmet which is shaped like a giant key.\n"+
             "It is covered in a fine, fuzzy red velvet and appears to be more ornamental\n"+
             "than functional.\n");

    set_value(1500);
    set_ac(0);
    set_type("helmet");
    set_alias("helm");

    set_weight(1);
    set_size(1);
}

