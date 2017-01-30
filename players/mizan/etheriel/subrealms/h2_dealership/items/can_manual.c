inherit "/players/mizan/core/vehicle-manual.c";

/*
 * our reset method
 *
 */
reset(arg)
{
    ::reset(arg);

    if(arg) return;

    set_short("The Canyonero's driver manual");
    set_long("This is a gigantic book made with redwood paper.\nIt covers topics on the operation of the Canyonero SUV.\nYou might want to 'read' it.\n");
    set_manual_root("/players/mizan/closed/stuff/vehicles/canyonero/manual/");

}
/* end function reset(); */
