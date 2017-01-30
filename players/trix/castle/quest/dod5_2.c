inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc="You chosed the wrong way, you are stuck in a featureless room, you have the\n"+ 
               "time to ponder about your faults.\n";

   short_desc ="A featureless room";

}
init(){
 ::init();
     add_action("escape","trixrules");
     }
realm(){return "NT";}
escape()
{    this_player()->move_player("the room in a flash of light#"+"room/church");
     return 1;
}
