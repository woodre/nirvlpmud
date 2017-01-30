inherit "/players/mizan/closed/stuff/vehicles/manual.c";

/*
 * our reset method
 *
 */
reset(arg)
{
    ::reset(arg);

    if(arg) return;

    set_short_desc("The Canyonero's driver manual");
    set_long_desc("This is a gigantic book made with redwood paper.\nIt covers topics on the operation of the Canyonero SUV.\nYou might want to 'read' it.\n");
    set_manual_root("/players/mizan/closed/stuff/vehicles/canyonero/manual/");

}
/* end function reset(); */
