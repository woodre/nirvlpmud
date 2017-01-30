inherit "room/room";
 
reset(arg) {
   object bouncer;  
   int cont,i;
   if(arg) return;
   set_light(1);
   long_desc = "You are in a wide space in front of the EclYpsE, where usually people waits \n" +
               "before entering the disco, such a fun deserves a little waiting.\n";
   short_desc = "Outside the EclYpsE";
   dest_dir = ({ "/players/trix/castle/disco/in8.c","east",
                 "/players/trix/castle/disco/in2.c","northwest"});
   cont=3+random(2);
   for(i=1;i<=cont;i++) {
   bouncer=clone_object("/players/trix/castle/dismonst/bouncer");
   move_object(bouncer,this_object());
  }
}
init()
{ ::init();
  add_action("nowe","northwest");
  add_action("ea","east");
}
nowe()
{  if(present("bouncer",this_object()))
      write("You struggle among the crowd to go northwest.\n");
}
ea()
{  if(present("bouncer",this_object()))
      write("You struggle among the crowd to go east.\n");
}
