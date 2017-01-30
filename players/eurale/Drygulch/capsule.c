inherit "obj/treasure";
reset(arg) {
  if(arg) return;
set_id("capsule");
set_short("A shiney metallic capsule");
set_long(
	"  This round metal capsule looks large enough for a person.\n"+
	"It appears to be metal but is unlike anything you've ever seen\n"+
	"before.  It looks as if you could open it.\n");
set_weight(1);
set_value(50000);
set_save_flag();
}

get() { return 0; }
