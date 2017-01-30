inherit "room/room";

reset(arg) {
    int cont;
    if(arg) return;
    set_light(1);
   long_desc=
"  You are in a huge disco lit only by the flashes of some psychedelic\n"+
"lamps.  You feel your legs moving without your will to the rythm of\n"+
"the wildest techno you have ever heard.  Some stairs lying at your\n"+
"feet lead to the restaurant build under the disco.\n";
   short_desc = "EclYpsE";
    dest_dir = ({ "/players/trix/castle/disco/grid9.c","north",
                  "/players/trix/castle/disco/grid19.c","south",
                  "/players/trix/castle/disco/d9.c","down"});
}
