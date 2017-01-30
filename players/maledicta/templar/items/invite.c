inherit "/obj/treasure.c";
reset(arg){
  set_id("scroll");
  set_alias("KnightInvite");
  set_short("Scroll of Invitation [Templar]");
set_long(
	"This small scroll is bound with a purple line of\n"+
	"string.  It will allow you to pass unhindered into\n"+
	"the Templars Castle and walk about. Do not drop it\n"+
	"while inside, this is your only means of identifying\n"+
	"yourself to the guards. When you are finished with\n"+
	"it, please 'crumble' the scroll.\n");
  set_weight(1);
  set_value(0);
}

init(){
	::init();
	add_action("crush_it", "crumble");
}


crush_it(str){
	if(!str || str != "scroll"){
		write("crumble what?\n");
		return 1;
	}

	write("You crumble the invitation up, making it useless.\n");
	destruct(this_object());
	return 1;
}
query_save_flag(){ return 1; }
