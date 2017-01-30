inherit "obj/treasure";
init(){
   ::init();
   add_action("assemble","assemble");
}
object rod;
reset(arg){
   if(arg) return;
   set_short("A Part of the Rod of Smiting");
   set_id("mainrodpart");
   set_long("A part of the Rod of Smiting\n");
   set_weight(1);
   set_value(0);
}
assemble(arg){
   if(!arg){
      write("Assemble what?\n");
      return 1;
   }
   if(arg!="rod"){
      write("Assemble "+arg+"\n");
      return 1;
   }
   if(arg == "rod"){
      if(present("mainrodpart",this_player())){
         if(present("rodpartone",this_player())){
            if(present("rodparttwo",this_player())){
               if(present("rodpartthree",this_player())){
                  destruct(present("rodpartone",this_player()));
                  destruct(present("rodparttwo",this_player()));
                  destruct(present("rodpartthree",this_player()));
                  rod=clone_object("/players/scathe/weap/lbow");
                  move_object(rod,this_player());
                  write("You have solved this quest!\n");
                  this_player()->set_quest("rod_quest");
                  destruct(present("mainrodpart",this_player()));
                  return 1;
               }
            }
         }
      }
      write("You are missing something!!!!\n");
      return 1;
   }
   if(arg="rod"){
      write("Assemble your own "+arg+"\n");
      return 1;
   }
}
