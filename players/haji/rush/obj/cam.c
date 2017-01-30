int val,i;
query_value() { return 750;}
id(str) {
    if (str == "camera" ) return 1;
    return 0;
   }
short() {
   return "A video camera";
  }
long() {
    write("This is a camera used by the staff at the Dave Letterman show.\n");
}
query_weight() {
return 2;
}
get() {
return 1;
}
init() {
#ifndef __LDMUD__
          add_action("blah"); add_xverb("");
#else
           add_action("blah","",3);
#endif
}
reset(arg){
    if (arg)
       return;
    val = 1;
}
blah(str) {
int x;
        x=random(34);
        i+=1;
     if(i==x) {
      write("You hear Dave Letterman's voice from the camera: May we see your photos please?\n");
      move_object(this_object(),environment(this_player()));
      say("You hear Dave Letterman's voice from the camera: May we see your photos please?\n");
      move_object(this_object(),this_player());
      i=0;
   }
}
