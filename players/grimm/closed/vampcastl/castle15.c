inherit "room/room";
int flag;
realm() { return "NT"; }
reset(arg) {
monster();
if(arg)
   return;
short_desc="Sleeping Chambers";
long_desc="You have entered another coffin room where vampires sleep!\n";
dest_dir=({"players/grimm/closed/vampcastl/castle14","west"});
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
