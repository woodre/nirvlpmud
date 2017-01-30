inherit "/players/mizan/core/vehicle-manual.c";

/*
 * our reset method
 *
 */
reset(arg)
{
    ::reset(arg);

    if (arg) return;

    set_short("The M113 FMT driver manual");
    set_long("This is a solid book made of some fairly thick paper.\nIt covers topics on the operation of the M113 armored personnel carrier.\nYou might want to 'read' it.\n");
    set_manual_root("/players/mizan/opl/vehicles/m113/manual/");

}
/* end function reset(); */
