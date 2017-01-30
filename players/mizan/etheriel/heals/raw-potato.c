inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("potato");
	set_short("A potato");
	set_alias("potato");
	set_long("An ordinary looking potato.\n");
	set_eater_mess("You chomp down on a raw potato.\n");
	set_strength(7);
	}
}
query_value() 
{
  return 1;
}
