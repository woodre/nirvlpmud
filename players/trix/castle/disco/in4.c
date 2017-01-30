inherit "room/room";
 
reset(arg) {
  if(!present("bouncer"))
    move_object(clone_object("/players/trix/castle/dismonst/bouncer"),this_object());
   if(!present("beavis"))
    move_object(clone_object("/players/trix/castle/dismonst/beavis"),this_object());
  if(!present("butthead"))
    move_object(clone_object("/players/trix/castle/dismonst/butthead"),this_object());
   if(arg) return;
   set_light(1);
   long_desc=
"  You are in a wide space in front of the EclYpsE where people usually\n"+
"wait before entering the disco.  After all, such fun deserves a little\n"+
"waiting.\n";
   short_desc = "Outside the EclYpsE";
   dest_dir = ({ "/players/trix/castle/disco/in1.c","north",
                  "/players/trix/castle/disco/in8.c","south",
                 "/players/trix/castle/disco/in5.c","east"});
}
init()
{ ::init();
  add_action("ea","east");
  add_action("we","west");
  add_action("no","north");
  add_action("so","south");
}
we()
{  if(present("bouncer",this_object()))
      write("You struggle among the crowd to go west.\n");
}
ea()
{  if(present("bouncer",this_object()))
      write("You struggle among the crowd to go east.\n");
}
no()
{  if(present("bouncer",this_object()))
      write("You struggle among the crowd to go north.\n");
}
so()
{  if(present("bouncer",this_object()))
      write("You struggle among the crowd to go south.\n");
}
