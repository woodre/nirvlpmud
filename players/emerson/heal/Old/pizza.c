inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("pizza");
set_short("A Hot slice of Pizza");
	set_eater_mess("Yummy! Now was'nt that *BURP* good?\n");
set_long("A Hot Slice of Pizza from Pizza Hut");
	set_strength(20);
    }
}
query_save_flag()
{
     return 1;
}
