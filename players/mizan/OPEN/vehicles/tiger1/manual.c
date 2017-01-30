inherit "/players/mizan/closed/stuff/vehicles/manual.c";

/*
 * our reset method
 *
 */
reset(arg)
{
    ::reset(arg);

    if(arg) return;

    set_short_desc("The Tiger 1 MBT driver manual");
    set_long_desc("This is a solid book made of some fairly thick paper.\nIt covers topics on the operation of the Tiger 1 main battle tank.\nYou might want to 'read' it.\n");
    set_manual_root("/players/mizan/closed/stuff/vehicles/tiger1/manual/");

}
/* end function reset(); */
