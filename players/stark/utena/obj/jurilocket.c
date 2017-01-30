inherit "obj/armor";
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
  set_ac(1);
  set_type("amulet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(1100);
}

init() {
::init();
add_action("open","open");
add_action("close","close");
}

open(arg){
	if(arg=="locket"){
		if(open==0){
			this_object()->set_long("The picture inside is that of Shiori... The one Juri holds closest to her heart.\n");
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

