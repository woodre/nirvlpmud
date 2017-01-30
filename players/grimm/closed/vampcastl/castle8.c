inherit "room/room";
int flag;
realm() { return "NT"; }
reset(arg) {
monster();
if(arg)
   return;
short_desc="Vampire Crypt";
long_desc="You have found an entrance to where vampires come to rest.\n"+
          "You can go back up through the hole if you wish.\n";
dest_dir=({"players/grimm/closed/vampcastl/castle7","up"});
set_light(1);
}
init() {
   add_action("open","open");
   ::init();
}
monster() {
   object coffin;
   flag = 0;
   if(!present("coffin")) {
   coffin = clone_object("players/grimm/object/coffin");
   move_object(coffin,this_object());
   }
return 1; 
}
open(str) {
   object vampire;
   if(!str) return;
   if((str != "coffin")&&(str != "casket")) return;
   if(flag==1) { 
      write("It is already open.\n");
   return 1; }
   flag = 1;
   vampire = clone_object("players/grimm/monster/badvamp");
   write("As you open the coffin a very large vampire jumps out!!\n");
   move_object(vampire,this_object());
return 1; 
}
