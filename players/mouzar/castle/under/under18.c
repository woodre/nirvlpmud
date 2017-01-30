inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Drow House";
  long_desc = "As you enter through the doors with giant spiders carved into it.  You see\n"+
               "that just about everything in here resemble spiders.  If it isn't carved into\n"+
               "the shape of a spider it has a picture of a spider on it.  There are plenty of\n"+
               "of riches from the surface decorating the house.  You wonder how many surrface\n"+
               "dwellers had to die for this drow matron mother to decorate her house.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under17","south",
               });
           }
if(!present("drow"))
move_object(clone_object("/players/mouzar/castle/under/mon/mdrow"),this_object());
} 
