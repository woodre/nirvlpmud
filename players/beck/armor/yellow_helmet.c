inherit "obj/armor";
reset(arg){
   ::reset(arg);
set_name("helmet");
set_alias("helmet");
set_short("A Yellow Power Ranger Helmet");
set_arm_light(1);
set_long(
"This is a helmet stolen from one of the Power Rangers.\n"+
"This helmet is very strong and light.\n"+
"It will let you see in the dark when it is worn.\n"+
"");
set_ac(1);
   set_weight(1);
   set_value(1100);
set_type("helmet");
}
wear(arg) {
if(::wear(arg));
if(id(arg)) {
write("You shout: It's Morphin Time\n");
say(capitalize(this_player()->query_real_name())+" shouts: IT'S MORPHIN' TIME!\n");
say("\n"+
"\n"+
capitalize(this_player()->query_real_name())+" shouts: Saber Tooth Tiger!\n"+
"");
return 1;
}
return;
}
