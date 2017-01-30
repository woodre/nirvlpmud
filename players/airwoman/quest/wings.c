inherit "obj/armor";
reset(arg) {
   if(arg) return;
   set_name("wings");
   set_short("Icarus's Wings");
   set_long("Your wings to fly to the mountain tops\n"+
            "to retrieve the tears from heaven.\n"+
            "You must wear them first.\n");
   set_weight(1);
   set_value(1000);
   set_type("misc");
 
}
wear(arg) {
   int x;
   x = worn;
   if (!::wear(arg))
      return 0;
   if (worn && !x) {
     write("You are ready for flight now.  type fly.\n");
   }
   return 1;
}
  
init ()
{
add_action("fly", "fly");
::init();
}
 
fly () {     
 
    write("The wings begin to flap taking you higher and higher\n"+
        "towards the sky. You feel free and light...\n");
    write("\n\n\n\n\n\n\n");
    write("Higher and higher you go....\n");    
    write("\n\n\n\n\n\n\n"); 
    write("Oh no your wings melt as you get to close to the sun!\n");  
    write("\n\n\n\n\n\n\n");
    write("Fortunately, unlike Icarus you fall on the highest\n"+
        "point of the mountain....\n");         
     write("\n\n\n\n\n");
    say("You watch as "+this_player()->query_name()+" flies high "+
        "into the sky....\n");
    this_player()->move_player("flies to the the mountain "+
        "tops#/players/airwoman/quest/heaven"); 
 
 
        destruct(this_object());
        return 1;            
       write("You must wear the wings first before flying!\n");
}
