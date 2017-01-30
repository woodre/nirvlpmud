/*
A Jester's Cap that changes the title of the player who wears it.
*/
 
#define TP this_player()
#define TPN capitalize(TP->query_name())
#define TPI call_other(TP,"query_attrib","int")
 
inherit "obj/armor";
 
init() {
  ::init();
add_action("read","read");
add_action("don_cap","wear");
}
 
reset(arg){
   ::reset(arg);
   set_name("jester cap");
   set_short("A Jester's Cap");
   set_alias("cap");
   set_long(
"Multicolored streamers fly out in all directions from this Jester's Cap.\n"+
"You can barely make out some sort of writing on the brim...\n"+
"  Perhaps you could read the cap...\n");
   set_type("helmet");
   set_ac(2);
   set_weight(1);
   set_value(500);
}
 
read(arg) {
  if(!arg) {write("Read what?\n"); return 1;}
  write(
"The writing on the cap reads:\n"+
"  BE A JESTER... WEAR THE JESTER CAP!!!\n");
return 1;
}
 
don_cap(arg) {
  if(!arg) {write("Wear what?\n"); return 1;}
 if(arg == "jester cap") {
  if(TPI > 12) {
    write("You are too intelligent to be a JESTER!\n");
return 1;
  }
else
    write("You wear the JESTER CAP!\n");
  command("wear cap",TP);
  call_other(TP,"set_title","the JESTER!");
    write("You are now a JESTER!\n");
    say(TPN+" is now a JESTER!\n");
return 1;
  }
}
