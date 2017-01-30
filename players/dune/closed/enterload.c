inherit "obj/clean";


status id(string str)
{
  str = lower_case(str);
  return str == "enterload";
}


long()  { write("Castle Load Object.\n"); return 1; }
short() { return "The Enterload"; }
get()   { return 1; }
query_weight() { return 0; }
drop()  { return 1; }


init()
{
  add_action("prepare", "prepare");
  add_action("loadups", "loadups");
}


status loadups()
{
  object ob;
  string room;
  room = "/room/plane8.c";
  call_other(room, "reset");
  ob = find_object(room);
  if (!present("pavilion", ob))
  {
  if (find_player("dune"))
    tell_object(find_player("dune"), "placing RoboMech Pavilion...\n");
    move_object(clone_object(
      "/players/dune/closed/pavilion/pavilion.c"), 
      ob);
  }

  if (find_player("dune"))
    tell_object(find_player("dune"), "loading CyberNinja implants...\n");
  call_other("/players/dune/closed/guild/implants",      "get");

  if (find_player("dune"))
    tell_object(find_player("dune"), "loading CyberNinja computer...\n");
  call_other("/players/dune/closed/guild/objects/cpu.c", "get");

  return 1;
}


status prepare(string str)
{
  object ob;
  string room;
  room = "/players/dune/workroom.c";
  call_other(room, "reset");
  ob = find_object(room);
  if (!present("polls", ob))
  {
    write("placing Nirvana Polls...\n");
    move_object(clone_object("/players/dune/voting/polls.c"), ob);
  }

  call_other("/players/dune/voting/votedaem.c", "loadCheck", 0);

  if (str && str == "now") loadups();
  else                     call_out("loadups", 5);
  return 1;
}
