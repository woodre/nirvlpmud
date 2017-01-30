ttell(str){
   if(str=="ptell){
     if(present("ptell",this_player())){
     write(" your write statement\n");
     return 1;}
     if(!present("ptell",this_player())) {
     write("your other write statement\n");
     move_object(clone_object("path"),this_player());
     return 1;}
   }
