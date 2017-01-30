#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("halo");
set_alias("halo");
set_ac(0);
set_type("misc"); 
set_weight(1);
set_value(0);
set_light(-2);
}
short() { return HIW+call_other(this_player(),"query_name")+"'s black halo"+NORM; }

long(str) {
    write("This is a strange halo.  It doesnt emanate any light, but rather tends\n"+
          "to trap the light like any black object.  It can be super'activate'd \n"+
          "in order to trap even more light, for a limited period of time, though.\n"+
          "And, 'deactivate'd to reset previous light conditions.  Useful when your\n"+
          "eyes are tired and/or when you need to rest.  Someone else might find\n"+
          "other useful applications for his/her own needs.\n");
   return;}
    
init() {
   ::init();
   add_action("activate","activate");
   add_action("deactivate","deactivate");
return;}

activate(str) {
 if(!str) {notify_fail("Activate what?\n"); return 0;}
 if(str=="halo"){
   if(!present("halo",this_player())) {notify_fail("You must get the halo first.\n"); return 0;}
    write("The darkhalo had been activated already.\n");
 return 1;}
 notify_fail("Activate what?\n"); 
 return 0;
}

deactivate(str) {
 object blah;
 if(!str) {notify_fail("Deactivate what?\n"); return 0;}
 if(str=="halo"){
   if(!present("halo",this_player())) {notify_fail("You must get the halo first.\n"); return 0;}
    destruct(this_object());
    blah = clone_object("/players/francesco/closed/darkhalo.c");
    move_object(blah,this_player());
    this_player()->recalc_carry();
    write("You deactivate the halo and the rooms goes shiner.\n");
 return 1;}
 notify_fail("Deactivate what?\n"); 
 return 0;
}


