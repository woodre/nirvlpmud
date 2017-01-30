inherit "room/room";
int flag;
realm() { return "NT"; }
reset(arg) {
if(arg)
   return;
short_desc="Chamber of Malachi";
long_desc="You have entered the sleeping chambers of Malachi!!! Death is certain at night!!\n";
dest_dir=({"players/grimm/frst/forest1","up"});
set_light(1);
}
init() {
   object coffin;
   add_action("open","open");
   add_action("look","look");
   add_action("look","exa",1);
   add_action("look","la");
   add_action("look","l");
   ::init();
   if(!present("coffin")) {
      coffin = clone_object("players/grimm/object/coffin");
      move_object(coffin,this_object());
   }
}
look(str) {
   if(!str) return;
   if(str=="in coffin"||str=="at vampire"||str=="at malachi"||str=="vampire"||str=="malachi") {
      if(flag==0)  {write("The coffin is closed!\n");   return 1; }
      write("You have found a great vampire...destroy him!!!\n");
      return 1; 
   }
   return;
}
monster() {
   object monster;
   if(!present("vampire")) {
         monster = clone_object("players/grimm/monster/vampire2");
         move_object(monster,this_object());
   }
return 1; 
}
open(str) {
   if(!str) { write("Open what?\n");   return 1; }
   if(str!="coffin") return;
   if(flag>=1||present("vampire")) {
      write("The coffin is already open.\n");
      return 1;
   }
   write("As you open the coffin, a vampire jumps out and attacks you!\n");
   flag = 1;
   monster();
return 1; 
}
