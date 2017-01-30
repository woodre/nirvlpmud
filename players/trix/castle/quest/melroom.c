inherit "room/room";
object melko;
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"  This is the hall of Melko, a semi-darkened room filled with a strange mist\n"+
"that hides the true features of the room from your sight.  You can only see\n"+
"Melko's huge golden throne coming up out of the fog.\n";
    short_desc="The Hall of Melko";
    dest_dir = ({
                  "/room/church","church"});
    melko=clone_object("/players/trix/castle/quest/monst/melko");
    move_object(melko,this_object());
}
init(){
 ::init();
   add_action("church","church");
}
church()
{ if(melko&&call_other(melko,"query_attack")) {
    write("Melko says: You can't escape now!  You should have thought twice before\n"+
       "            daring to attack me!\n");
                 return 1;}
  if(present("melkoring",this_player())) {
    write("You can't leave this place with Melko's ring.\n");
    return 1;
  }
}
realm(){return "NT";}
