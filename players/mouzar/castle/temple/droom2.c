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
            "showing the dragon in his full glory.  The door that leads out of this\n"+
            "room is to the north of you.\n";
  dest_dir=({"players/mouzar/quest/droom5","south",
             "players/mouzar/quest/droom1","west",
             "players/mouzar/quest/droom3","east",});
 }
}
init(){
  ::init();
     add_action("north","north");
     add_action("open","open");
}

open(str) {
    notify_fail("open what?\n");
    if (!str)
        return 0;
    if (str == "door") {
    write("The door opens with a squeak.\n");
    say(RN + " open the door slowly.\n");
    open="yes";
   return 1;
   }
    return 1;
}
north() {
  if(open == "yes"){
    write("The door closes behind you!\n\n");
    ME->move_player("north#/players/mouzar/quest/hall6");
    say("The door closes behind "+RN+"!\n");
    open == "no";
    return 1;
  }
  write("You run into the door!    OUCH!!\n");
  say(RN +" walks into a door!\n");
  return 1;
}
