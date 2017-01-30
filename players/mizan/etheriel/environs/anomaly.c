inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(0);
   set_short("A disruptive anomaly");
   set_long("There is a hole in the continuum of the ether-muck here...\n"+
	"It appears to be a portal of some sort, and it has been plugged.\n"+
	"Inspecting it further, you conclude that a force of near-biblical\n"+
	"proportions was required to plug the hole, and whatever is on the\n"+
	"other end is certainly eager to get through...\n");

   set_name("anomaly");

}


