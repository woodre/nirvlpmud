inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("nugget");
	set_short("A large, shining, gold nugget");
set_long(
	"  This is a fairly large gold colored nugget.  It was panned \n"+
	"from the mountain stream on one of Gabby's 'lucky' days.  Too bad \n"+
	"it turned out to be pyrite... fool's gold!! \n");
    set_weight(2);
    set_value(1);
}
