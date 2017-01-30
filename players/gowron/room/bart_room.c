inherit "room/room";

get_bart() {
      return clone_object("players/gowron/room/obj/bart");
}

reset (arg) {
      if (arg) {
	 if (!present("bart")) {
            move_object(get_bart(), this_object());
	 }
	 return;
      }
      set_light(1);
      short_desc = "Bart's Bedroom";
      long_desc = "You have entered the bedroom of Bart Simpson.  It is "+
	          "littered with paraphenalia bearing the photo of Bart's "+
		  "hero, Krusty the Klown.  Apparently, Bart is 'sick' "+
		  "today, so he stayed home from school.  He has the TV "+
		  "wheeled up here and is staring into it.\n";
      dest_dir = ({ "players/gowron/room/shall", "north", });
      move_object(get_bart(), this_object());
}
	
