inherit "obj/armor";
  drop() { return 1; }
  query_auto_load() { return "players/stark/adrilocket:"; }

int open;
reset(arg) {
  if(arg) return;
  set_id("A golden locket");
  set_alias("locket");
  set_short("A golden locket");
  set_long(
"A thin chain of gold holds a simple golden locket.  The oval locket \n"+
"has a elegant rose sculpted on its front.  The locket can be opened \n"+
"to see the picture inside.\n");
  set_ac(0);
  set_type("amulet2");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(0);
  set_value(0);
}

init() {
::init();
add_action("open","open");
add_action("close","close");
}

open(arg){
	if(arg=="locket"){
		if(open==0){
			this_object()->set_long(
"The picture inside is that of your loving boyfriend.  \n"+
"There are two pictures of Mike Stark\n"+
"One side shows his face close up with a smile on his face\n"+
"While the other side is picture of him in a suit, dressed up for you.\n\n"+
"    I love you Kristin\n");
			write("You open the locket\n");
			open=1;
			return 1;
		}
		write("The locket is already open.\n");
		return 1;
	}
	return;
}

close(arg){
	if(arg=="locket"){
		if(open){
			this_object()->set_long(
"A thin chain of gold holds a simple golden locket.  The oval locket \n"+
"has a elegant rose engraved on the front.  The locket can be opened \n"+
"to see the picture inside.\n");
			write("You close the locket\n");
			open=0;
			return 1;
		}
		write("The locket is already closed\n");
		return 1;
	}
	return;
}

