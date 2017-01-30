inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
if(arg) return;
        set_name("hammer");
        set_class(15);
        set_value(2400);
        set_weight(6);
        set_alt_name("hammer");
        set_short("War Hammer");
set_long("This weapon has a long handles with a large hammer on top.  The hammer has a large round flat piece on one side, and a spike on the other.\n");
}
init() {

	add_action("change_short","name");
        add_action("change_long","describe");
	add_action("morph","morph");
	::init();
}
morph(str) {
if(!str) {
set_short("Tybaltin");
set_name("Tybaltin");
return 1;
}
}
change_short(str) {
set_short(str);
set_name(str);
return 1;
}
drop(str){return 0;}
change_long(str) {
set_long(str+"\n");
return 1;
}
