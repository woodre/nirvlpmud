 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Amster's Brewery";
long_desc = "This is an old building that has been kept up over the years.\n"+
            "There are kegs and kegs of ale stacked up to the ceiling here.\n"+
            "There is a beautiful Halfling checking stock.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail28","west",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("jess")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/jess.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
