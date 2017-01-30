inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("orange");
	set_short("an orange");
	set_eater_mess("Mmmmmm... that hit the spot! (Healthy too!)\n");
	set_long("In the words of Merlyn:\n"+
	"This is a fruit. What do you think you should do with it? Stick it up your nose???\n");
	set_strength(10);
	set_value(1);
}
}
