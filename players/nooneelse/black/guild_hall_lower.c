reset(arg)
{
  if(!arg) return;
   if(!this_player()) return;
   this_player()->set_home("/players/eurale/Vamp/RMS/vguild_hall.c");
   move_object(this_player(),this_player()->query_home());
}

