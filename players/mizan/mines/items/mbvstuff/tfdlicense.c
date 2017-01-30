inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(5);
    set_weight(1);
    set_name("license");
    set_alias("card");
    set_short("An Washington State drivers license");
   set_long("This is a driver's license with the name 'FAVID DLEETWOOD' on it.\n");
}
