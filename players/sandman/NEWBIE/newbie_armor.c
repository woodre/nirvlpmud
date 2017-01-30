inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("newbie cloak");
set_alias("cloak");
set_short("Newbie Cloak");
set_long("A durable newbie armor.\n");
set_weight(1);
set_value(0);
set_ac(2);
set_type("armor");
}
drop(silently) {
    if (worn) {
        call_other(worn_by, "stop_wearing", name);
	worn = 0;
	worn_by = 0;
	if (!silently)
	    tell_object(environment(this_object()),"You drop your worn armor.\n");
    }
    write("The cloak dissapears in a flicker of light as leaves your hands.\n");
   destruct(this_object());
    return 1;
}

