inherit "obj/armor";
#include "/players/beck/esc.h"
reset(arg){
   ::reset(arg);
set_name("helmet");
set_alias("white_helmet");
set_short("A "+BOLD+WHITE+"White"+OFF+" Power Ranger Helmet");
set_arm_light(1);
set_long(
"This is a helmet stolen from one of the Power Rangers.\n"+
"This helmet is very strong and light.\n"+
"It will let you see in the dark when it is worn.\n"+
"");
   set_ac(2);
   set_weight(1);
   set_value(2200);
set_type("helmet");
}
wear(arg) {
if(::wear(arg));
if(!present("white_helmet", this_player())){
return;
}
if(id(arg)) {
write("You shout: It's Morphin Time\n");
say(capitalize(this_player()->query_real_name())+" shouts: IT'S MORPHIN' TIME!\n");
return 1;
}
return;
}
