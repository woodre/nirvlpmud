/*
A cloak that lowers intelligence for players who are 
silly enough to invoke the powers of the
Cloak of Fools...
*/
 
#define TP this_player()
#define TPN capitalize(TP->query_name())
#define TPI call_other(TP,"query_attrib","int")
 
inherit "obj/armor";
 
init() {
  ::init();
add_action("read","read");
add_action("fool_mark","FOOL");
}
 
reset(arg){
   ::reset(arg);
   set_name("cloak of fools");
   set_short("Cloak of Fools");
   set_alias("cloak");
   set_long(
"Tassles line the fringes of this long, speckled green and red cloak.\n"+
"You can barely make out some sort of writing...\n"+
"  Perhaps you could read the cloak...\n");
   set_type("misc");
   set_ac(1);
   set_weight(1);
   set_value(500);
}
 
read(arg) {
  if(!arg) {write("Read what?\n"); return 1;}
  if(TPI < 10) {
    write(
"You seem to be lacking the intelligence needed to read the cloak!\n");
return 1;
  }
else
  write(
"You peer intently at the scribbles and figure out that the runes form\n"+
"some sort of word of power...\n"+
"You interpret the word as\n"+
"\n"+
"                               FOOL\n"+
"\n"+
"Perhaps you could invoke the power of the cloak by using the command...\n");
return 1;
}
 
fool_mark() {
  if(TPI < 10) {
    write("You are not intelligent enough to invoke the FOOL!\n");
return 1;
  }
else
    write("You invoke the power of the FOOL!\n");
  call_other(TP,"raise_intelligence",-1);
    write("You feel slightly more stupid!\n");
    say(TPN+" invokes the power of the FOOL!\n");
return 1;
}
