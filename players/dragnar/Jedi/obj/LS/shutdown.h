shutdown_saber(string str){
  if(!ignited){ write("What?\n"); return 1; }	
  if(!str){ write("collapse what?\n"); return 1; }
  if(str == "lightsaber" || str == "saber"){
    if( ignited == 2 ) {
      tell_object( USER, "You close down the secondary blade of your saber.\n");
      say( USER->query_name()+" closes down the secondary blade on "+USER->query_poessive()+" Lightsaber.\n");
      ignited = 1;
      return 1;
    }
    if(wielded) ::stopwield();
    set_class(3);
    set_light(-1);
    this_object()->set_ignited(0);
    this_object()->set_message_hit(({"massacre"," to small fragments","smashed",
                    " with a bone crushing sound","hit"," very hard","hit"," hard","hit","",
                    "grazed","","tickled"," in the stomach"}));
    this_object()->set_light(0);
    tell_object(USER,
      "You close down your lightsaber.\n");
    say(USER->query_name()+" closes down "+USER->query_possessive()+" lightsaber.\n");
    return 1;
  } 

write("no go.\n");
return 1;
}
