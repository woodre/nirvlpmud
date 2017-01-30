/* 
 * surg_saw.c
 * Surgeon's bone-saw
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("bone-saw");
  set_alt_name("saw");
  set_short("A bone-saw");
  set_long("This is a sw of a type used to cut bones.\n");
  set_class(8);
  set_value(100);
  set_weight(2);
}
