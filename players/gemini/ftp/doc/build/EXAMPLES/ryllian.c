/*
 *  This is an example of a room based upon the inherit
 *    room/room.c.  It will show light, descrips, items and how to clone
 *    a monster and/or an item.  For more examples, see VALLEY.c
 *					-- Saber
 *
 */


/* This will give you all the stuff from /room/room",
    such as dest_dir (directions), items, ect.            */
inherit "room/room";


/* Don't mess with this just yet.  Just leave it in.     */
reset(arg){


/*  This will clone an object if there is not a scroll already in
    the room.  It will than move the object into this room.  This
    will happen every reset.                         */
if(!present("scroll"))  {
move_object(clone_object("/players/saber/stuff/flier.c"),this_object());  }

if(!present("man")) {
move_object(clone_object("/players/saber/monsters/stoman.c"),this_object());
}


/*  Connected to the reset(arg) above, don't mess with it just yet.  */
 if(!arg){


/*  This will make the room light.  If you want it dark, set_light(0) */
  set_light(1);


/*  This will set the short description, seen when verbose mode is
    used, or when people check a who2, ect.          */
  short_desc="Rift's End";


/*  The long_desc is what people see when they enter a room.   */
long_desc=
 "It is night, and you feel a slight chill in the air as the breeze tugs\n" +
 "softly at your hair.  You stand on a well kept road which runs south to\n" +
 "the city of Ryllian and west towards a green valley.  To the north is\n" +
 "the rift which will return you to the realms of Nirvana.\n";


/*  Items are things which people can look at.  For example, when a
    person types "look at ground", they will get the message
    "The ground is covered with lush green grass."  Note that you do
    NOT need to put a period.               */
items=({
  "road", "A well kept road leading from the Green Valley\n"+
  "to the City of Ryllian",
  "ground","The ground is covered with lush green grass",
  "rift","A rift in time and space",
  "city","The seaport of Ryllian",
 });


/*  dest_dir are directions which will show up just after the long_desc
    When the person types the key word (example, north), they will move
    to room /players/saber/ryllian/mountain.c             */
dest_dir=({
 "/players/saber/ryllian/rift.c","rift",
 "/players/saber/ryllian/mountain1.c","north",
 "/players/saber/ryllian/gv1.c","west",
           });
        }
        }
