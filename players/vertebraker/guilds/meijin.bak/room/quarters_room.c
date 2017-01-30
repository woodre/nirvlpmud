inherit "room/room";

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="Quarters Room";
  long_desc=
	"This room holds all the personal quarters.  If you are\n"+
	"in this room and do not have a signed permission slip\n"+
	"you are in big trouble!\n";

  }
}

clean_up() { return 1; }

