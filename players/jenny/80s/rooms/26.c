inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
long_desc=
"This is a quiet residential street in an affluent neighborhood.\n"+
"The street is new, and devoid of any cracks or potholes.  Huge\n"+
"oak trees provide shade for the sidewalks.  Large homes, mansions\n"+
"really, are on both sides of the street.  The manicured lawns are\n"+
"beautifully landscaped, and a pleasure to look at.\n";
short_desc=(YEL+"Brat Pack Boulevard"+NORM);
items = ({
"street","The street has been recently paved.  There is not a crack or pothole in sight",
"flower beds","Well maintained flower beds, with flowers in an assortment of colors",
"flowers","They are not close enough to carefully inspect.  They blend together into\n"+
                  "a beautiful symphony of colors",
"hills","Small rolling hills, which enhance the beauty of these manicured lawns",
"trees","These huge oak trees must be close to 100 years old.  They provide\n"+
             "lots of shade for the sidewalks",
"sidewalks","Both sides of the street are lined with cement sidewalks.  Huge\n"+
              "oak trees keep them well shaded",
"homes","Huge, eccentric mansions line both sides of the street.  Many of\n"+
               "these homes are owned by people in the television industry",
"lawns","These lawns are beautifully landscaped with plush green grass, flower\n"+
               "beds, small hills, etc",
});
dest_dir = ({
 "/players/jenny/80s/rooms/23","north",
 "/players/jenny/80s/rooms/25","west",
 "/players/jenny/80s/rooms/27","east",
});
}
