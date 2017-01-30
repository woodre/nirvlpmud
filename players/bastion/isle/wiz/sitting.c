inherit	"room/room";

object table;

reset(arg) { 
  if(!table) {
       table=clone_object("players/bastion/obj/static");
       table->set_name("table");
       table->set_short("table");
       table->set_object(this_object());
       table->set_summon("summon_damian");
       table->set_beat(4);
       move_object(table, this_object());
       call_other(table, "start_check"); }
  table->load_summon();
  if(!arg) {
  string service_stat;
  if(!present("tea service"))
      service_stat="is empty.\n";
  else
      service_stat="holds a silver tea service.\n";
  set_light(1);
  short_desc = "Sitting Room";
  long_desc = 
   "A sofa and chairs, with a low, rectangular table as their focus,\n"+
   "occupy this room. A table next to the west door "+
   service_stat +
   "The curtains are drawn on the windows offering a view of the island\n"+
   "and surrounding sea. Another door opens south.\n";
  items = ({"window",
           "You can see the sparse shrubbery and grasses that habitate the island\nbelow",
            "windows",
            "You can see the sparse shrubbery and grasses that habitate the island\nbelow"});
  dest_dir = ({"players/bastion/isle/wiz/e_hall2", "south",
               "players/bastion/isle/wiz/dining", "west"});
  }
}

summon_damian() {
     object damian;
     if(present("damian")) {
          table->unload_summon();
          return 1; }
     if(!find_living("damian the sorcerer")) {
          damian=clone_object("players/bastion/monster/damian");
          tell_room(this_object(), "Damian arrives in a puff of smoke.\n");
          move_object(damian, this_object());
          table->unload_summon();
          call_out("dest_damian", 20); 
          return 1; }
}

dest_damian() {
     if(!present("damian")) return;
     present("damian")->self_destruct();
}
