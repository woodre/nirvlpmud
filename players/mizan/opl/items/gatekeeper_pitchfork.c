/*****************************************************************************
 *      File:                   gatekeeper-pitchfork.c
 *      Function:               Used by the gatekeeper
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

inherit "obj/weapon";

reset(arg)
{
    ::reset(arg);
    if (!arg)
    {
        set_name("pitchfork");
        set_long("This is a small, ceremonial red pitchfork. There's nothing spectacular about it.\n");
        set_short("A small red pitchfork");
        set_class(8);
        set_value(250);
        set_alias("pitchfork");
        set_weight(2);
    }
}
