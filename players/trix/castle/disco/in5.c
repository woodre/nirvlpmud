inherit "room/room";
 
reset(arg) {
   object bouncer;  
   int cont,i;
   if(arg) return;
   set_light(1);
   long_desc=
"  You are in a wide space in front of the EclYpsE where people usually wait\n"+
"before entering the disco.  After all, such fun deserves a little waiting.\n";
   short_desc = "Outside the EclYpsE";
   dest_dir = ({ "/players/trix/castle/disco/in4.c","west",
                 "/players/trix/castle/disco/in6.c","east"});
   cont=3+random(2);
   for(i=1;i<=cont;i++) {
   bouncer=clone_object("/players/trix/castle/dismonst/bouncer");
   move_object(bouncer,this_object());
  }
}
init()
{ ::init();
  add_action("ea","east");
  add_action("we","west");
}
we()
{  if(present("bouncer",this_object()))
      write("You struggle among the crowd to go west.\n");
}
ea()
{  if(present("bouncer",this_object()))
      write("You struggle among the crowd to go east.\n");
}
