inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("cloak");
set_alias("rags");
set_size(4);
set_short("Rags");
set_long(
"These are rags put together to for a cloak.  It's not much on looks \n"
+ "but it is thick.  It will keep you warm and will probally protect you\n"
+ "a little.  It smells the dog!\n");
set_weight(2);
set_value(200);
set_ac(1);
set_type("cloak");
}
