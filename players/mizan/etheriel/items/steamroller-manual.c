inherit "/players/mizan/core/vehicle-manual.c";

/*
 * our reset method
 *
 */
reset(arg)
{
    ::reset(arg);

    if(arg) return;

    set_short("A steamroller vehicle operations manual");
    set_long("This is a solid book made of some fairly thick paper.\nIt covers topics on the operation of a steamroller.\nYou might want to 'read' it.\n");
    set_manual_root("/players/mizan/core/vehicle_manual/");

}
/* end function reset(); */
