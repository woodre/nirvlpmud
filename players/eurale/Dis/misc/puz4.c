inherit "obj/treasure";
reset(arg) {
  if(arg) return;
set_id("piece");
set_alias("piece4");
set_short("A puzzle piece");
set_long(
	"This is a piece of the Wizard's puzzle rumored to have been\n"+
	"scattered thoughout the realm long, long ago.  There are\n"+
	"some strange markings etched in the side.  Maybe you could\n"+
	"read them if you tried..\n");
    set_weight(1);
    set_value(500);
set_save_flag();
}

init() {
  ::init();
  add_action("read","read");
}

read(str) {
string s1,s2;
if(!str) { write("What would you like to read?\n"); return 1; }
sscanf(str,"%s %s",s1,s2);
  if(s1 != "the") { write ("Try <read the whatever>.\n"); return 1; }
  if(s1 == "the" && s2 != "markings") {
	write("I don't see that here!\n"); return 1; }
  write("The markings read: 4 - Z'ranthalla. \n");
return 1;
}
