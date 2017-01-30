id(str) { return str == "puddle"; }
init()
{
   object o;
   print("Dammit!  You just stepped in a dark puddle of muck and now your feet are covered in gook and you're leaving a trail behind you as you walk.");
   for(o = first_inventory(environment(this_object())); o; o = next_inventory(o)) if(o->query_whose() == this_player()) return;
   o = clone_object("/players/sado/roamer/footprint.c");
   move_object(o,environment(this_object()));
   o->set_whose(this_player());
}
