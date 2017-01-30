 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Cheese Factory";
long_desc = "As you walk in you see a Halfling man swing a broom at some mice\n" +
            "that are running around.  Looks like he needs help.  You see all\n" +
            "kinds of machinery for making cheese laying around.  In the back\n" +
            "you see some white cheese stacked up to the ceiling.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail15","north",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("mouse")) {
while(i<5) {
  monster = clone_object("/players/mouzar/castle/monsters/mouse.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("hofflik")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/hofflik.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
