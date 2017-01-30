inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
long_desc=
"This is a clean, well kept street.  The pavement looks new here.  There\n"+
"is not a pothole, or even a crack, in sight.  Large trees line each side\n"+
"of the road, growing near the cement sidewalks.  Luxurious homes can\n"+
"be seen on each side of the street.  The lawns look immaculate as well,\n"+
"with freshly cut grass and well kept flower beds.  A small memorial is\n"+
"to the left.\n";
short_desc=(HIB+BOLD+"Downsize Lane"+NORM);
items = ({
"memorial","This is a large copper statue which is shaped like a space shuttle.\n"+
                    "It was erected in honor of the astronauts who died in the space\n"+
                    "shuttle Challenger explosion",          
"street","A well kept residential street.  There are no potholes in sight",
"road","A well kept residential street.  There are no potholes in sight",
"pavement","Grey concrete pavement.  It is new and very smooth",
"trees","Large willow, oak, and maple trees.  They look at least 50\n"+
            "years old",
"sidewalks","There are cement sidewalks on each side of the street.  Trees\n"+
                     "are growing next to them, making the sidewalk a well shaded\n"+
                     "place to take a walk",
"homes","Expensive looking two story homes line each side of the street.  Most\n"+
                "of them are made out of brick, and are very well kept.  They all have\n"+
                "immaculate lawns",
"lawns","These beautifully manicured lawns have freshly cut grass, beautiful trees,\n"+
              "and spectacular flower beds",
"flower beds","Each lawn has a number of spectacular flower beds.  They are all bustling\n"+
                        "with an assortment of flowers, which adds color to the neighborhood",
"grass","Freshly cut green grass.  There does not appear to be a weed in sight",
"flowers","A beautiful blend of red, white, purple, blue, yellow, and orange flowers",
});
dest_dir = ({
 "/players/jenny/80s/rooms/3","north",
 "/players/jenny/80s/rooms/14","south",
});
}
