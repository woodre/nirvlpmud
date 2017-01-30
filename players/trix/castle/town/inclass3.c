inherit "room/room";
 
reset(arg) {
    object herma;
    int flag,cont;
    if(arg) return;
    set_light(1);
   long_desc = "This is a nice classroom where Trixtown's children spend their days in happyness\n" +
               "waiting for their parents to get they back. The classroom is full of toys spread\n" +
               "everywhere, and stuck on the walls there are a lot of funny pictures drawn by \n" +
               "the kids.\n";
   short_desc = "Trixtown Municipal Infant House";
    dest_dir = ({ "/players/trix/castle/town/inhall2","south"});
    cont=0;
    while(cont<=9)
    {   flag=random(2);
        if(flag)  herma=clone_object("/players/trix/castle/town/monst/bboy.c");
        else herma=clone_object("/players/trix/castle/town/monst/bgirl.c");
        move_object(herma,this_object());
        cont++;
    }
    
}
