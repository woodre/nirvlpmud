inherit "/players/mizan/core/vehicle-manual.c";

/*
 * our reset method
 *
 */
reset(arg)
{
    ::reset(arg);

    if (arg) return;

    set_short("The Tiger 1 MBT driver manual");
    set_long("This is a solid book made of some fairly thick paper.\nIt covers topics on the operation of the Tiger 1 main battle tank.\nYou might want to 'read' it.\n");
    set_manual_root("/players/mizan/samples/vehicles/tiger1/manual/");

}
/* end function reset(); */
