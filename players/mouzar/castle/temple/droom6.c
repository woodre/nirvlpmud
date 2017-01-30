inherit "room/room";
reset(arg){
 if(!arg){
  set_light(1);
  short_desc="Main Praying Room";
  long_desc="This is the main praying room for the priest.  There is a big stone\n"+
            "statue of Maldraedior the Great Wyrm Blue Dragon.  It stands 15 feet\n"+
            "into the air and it is 70 feet long.  The statue is in a half-crouched\n"+
            "position as if ready to spring.  The ceiling in here is a good 35 feet\n"+
            "high.  The walls are decorated with murals of Maldraedior tapestries\n"+
            "showing the dragon in his full glory.\n";
  dest_dir=({"players/mouzar/quest/groom3","north",
             "players/mouzar/quest/groom9","south",
             "players/mouzar/quest/groom5","west",});
 }
}
