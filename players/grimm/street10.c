#include "/players/grimm/header"
inherit "room/room";
int flag;
reset(arg) {
flag = 0;
   if(arg)
      return;
short_desc="Dog Graveyard";
long_desc="You have walked into the dog graveyard.  This was where all the\n"+
          "dogs of the town were brought to play during the early years of\n"+
          "the town.\n";
dest_dir=({ROOT(street3),"north"});
set_light(0);
}
init() {
   add_action("dig","dig");
   ::init();
}
dig() {
   int num;
   object bone;
   if(!present("steel shovel",this_player())) {
      write("The ground is too hard.  You need a special shovel to dig here.\n");
      return 1;
   }
   write("As you dig you feel more and more like a dog.\n");
      num = random(100);
   if(num > 87 && flag != 1) {
       write("You find a bone!\n");
      flag = 1;
      bone = clone_object(DIR2(bone));
      move_object(bone,this_object());
   return 1; }
   if(flag==1) {
      write("There is nothing here now.  Try later.\n");
   return 1; }
return 1;
}
