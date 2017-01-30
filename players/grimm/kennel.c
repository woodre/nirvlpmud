#include "/players/grimm/header"
inherit "room/room";
reset(arg) {
  monster();
   if(arg)
      return;
short_desc="Dog Kennel";
long_desc="You have entered a kennel for dogs.  The owner has recently\n"+
          "passed away so don't bother looking for him.\n";
dest_dir=({ROOT(street8),"north"});
set_light(1);
}
monster() {
   object dog;
   if(!present("dog")) {
      dog = clone_object(DIR8(dog));
      move_object(dog,this_object());
      return 1;
   }
}
