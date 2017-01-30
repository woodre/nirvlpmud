inherit "room/room";
reset(arg) {
   if(!arg) {
   set_light(1);
      short_desc = "The Master's Study";

      long_desc =
     "The walls of this study are covered with shelves of books\n"+
     "on philosophy, art, and science.  A desk in the center of the\n"+
     "room contains many scattered papers.  A comfortable\n"+
     "chair sits before a peaceful fireplace. A black pipe rests\n"+
     "on a small table next to the chair. A gray wolf sleeps on a\n"+
     "rug before the fire.\n";

   items = ({
     "books","You could spend hours simply looking at the titles\n"+
     "of all the books contained here",
     "desk","This is a large oak desk. It is covered with papers",
     "papers","Papers filled with scrawled notes, sketches, and half-\n"+
     "finished poems cover the desk",
     "chair","It looks perfect for reading by the fire",
     "fire","You gaze into the fire, lost in your thoughts..",
     "pipe","The carved pipe is made of ebony.\n"+ 
     "A 'W' is carved into the base",
     "table","A small reading table containing a pipe",
     "wolf","You think it best to let sleeping wolves lie",
  });

  dest_dir = ({
      "/players/arrina/palace/alcove.c","north",
  });
} }
