inherit "obj/monster.talk";
object temp, bowl2;
 
reset(arg) {
  
        ::reset(arg);
        if(!arg) {
        set_name("sboy");
	set_alias("boy");
        set_level(10);
        set_al(0);
        set_short("A Seeing Eye Boy");
        set_long("A boy that could see.\n");
        set_aggressive(0);
        set_wc(14);
        set_ac(8);
        set_chat_chance(20);
        load_chat("Boy says:  I can see...\n");
 }
}
     
