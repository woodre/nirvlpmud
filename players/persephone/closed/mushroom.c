inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("mushroom");
 set_short("A Magic Mushroom");
 set_long("A bright red Magic Mushroom with some words written on\n" +
          "it. It is perhaps the trippiest mushroom you have ever seen\n\n");
 set_weight(0);
 set_value(6000);
}
get(){
 return 1;
}
init(){
 ::init();
  add_action("decipher1","decipher");
  add_action("decipher1","scry");
  add_action("decipher1","read");
  add_action("eat1","eat");
  add_action("eat1","swallow");
}
decipher1(str){
 if(str=="mushroom" || str=="note" || str=="writing"){
  write("You read a note on the Mushroom saying EAT ME.\n");
 return 1;
 }
 write("What do you want to read\n");
return 1;
}
eat1(str){
 if(str=="mushroom" || str=="funghus"){
  write("You eat the mushroom and start to feel strange almost as\n" +
        "if you are hallucinating\n\n" );
  TPL->move_player("in a puff of magical smoke#"+"players/persephone/rooms/lair_ent");
  destruct(this_object());
 return 1;
 }
 write("What do you want to eat your shoe?\n");
return 1;
}

