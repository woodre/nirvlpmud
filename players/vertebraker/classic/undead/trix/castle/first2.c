inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"You have entered the castle's courtyard, only the light of the full\n"+
"moon allows you to see. The courtyard is bare and devoid of any form of\n"+
"life. Out of the corner of your eye you swear you saw a guard still\n"+
"standing post on the battlement but then he is gone.\n"+
"To the north you see the main gates to the castle are open statues\n"+
"guard the passage. To the south is the drawbridge.\n"+
"To the east and west are two staircases leading up to a doorway to\n"+
"each of the towers of the gate house.\n";
    short_desc ="A courtyard";
    dest_dir = ({
                  "/players/trix/closed/guild/castle/first3.c","north",
                  "/players/trix/closed/guild/castle/first1.c","south",
                  "/players/trix/closed/guild/castle/first10","east",
                  "/players/trix/closed/guild/castle/first7.c","west"
                                                        });
}
realm(){return "NT";}
