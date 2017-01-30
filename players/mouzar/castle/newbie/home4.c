 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Tuck's Home";
long_desc = "This is a nice looking home.  Looks like an average home with the\n"+
            "average stuff in it.  You can see the average wife siting down in\n"+
            "a rocking chair wondering where her husband is.  She is worried\n"+
            "because he is late from gathering wood from the forest.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail33","south",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("turk")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/turkwife.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
