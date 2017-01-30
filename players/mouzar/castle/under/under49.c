inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "You are greated by silence here.  You have to choose now which direction\n"+
              "you want to head off in.  The east seems quiet now.  Every now and then\n"+
              "there is a roar that comes from the south.  The westward cave is blocked\n"+
              "by many spiders and their webs.  Looks as though one has entered that cave\n"+
              "in a long time.  Maybe they have their reasons?\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under48","south",
               "/players/mouzar/castle/under/under54","east",
               "/players/mouzar/castle/under/under50","west",
               });
  items=({"cave","As you look deep into the cave you get the feeling that it's\n"+
		 "pretty dangerous inside.\n"});
           }
 
} 
