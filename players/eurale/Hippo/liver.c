inherit "room/room";
object sign;

reset(arg){
  if(arg) return;
set_light(0);

short_desc = "The liver";
long_desc =
  "  A pulsing red organ surrounds you.  It seems to be filtering out all the\n"+
  "things your body doesn't want in its blood.  The warmth is comforting.\n";

items = ({
  "organ","This is the body's liver, dark red and healthy looking",
});

dest_dir = ({
   "/players/eurale/Hippo/ratrium.c","heart",
   "/players/eurale/Hippo/liver2.c","cancer",
   "/players/eurale/Hippo/pancreas.c","pancreas",
	});
}
