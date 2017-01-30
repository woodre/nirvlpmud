inherit "/players/mizan/core/vehicle-manual.c";

/*
 * our reset method
 *
 */
reset(arg)
{
    ::reset(arg);

    if(arg) return;

    set_short("The GM Hummer H2 owner's manual");
    set_long("This is a solid book made of some fairly thick paper.\nIt covers topics on the operation of the Hummer H2 SUV.\nYou might want to 'read' it.\n");
    set_manual_root("/players/mizan/etheriel/subrealms/h2_dealership/environs/h2_manual/");

}
/* end function reset(); */
