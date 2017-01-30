inherit "room/room";

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="-----";
  long_desc=
	"This is the storage room for the Meijin guild objects.  If you\n"+
	"are in here and you don't have a signed permission slip you are\n"+
	"in big trouble!\n";
  }
}

short() { return "-----"; }
clean_up() { return 0; }

