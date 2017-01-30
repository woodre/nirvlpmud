inherit "obj/monster";
reset(arg){
   ::reset(arg);
   if(!arg) {
set_name("energizer bunny");
set_short("Energizer Bunny");
set_alias ("bunny");
set_long("A pink silly bunny drumming along across the room.\n"+
	"Kill it! (Duracell's are better).\n");
set_level(6);
set_ac(5);
set_aggressive(0);
set_wc(10);
set_a_chat_chance(50);
load_a_chat("Bunny says:  It keeps going and going...\n"); 
load_chat("Bunny says:  Nothing beats an energizer!....\n");
load_chat("Bunny says: and going and going.....\n");
set_chat_chance(50);
load_chat("Bunny says:  Nothing beats an energizer!....\n");
load_chat("Bunny says:  It keeps going and going...\n");
load_chat("Bunny says: and going and going.....\n");
set_move_at_reset(0);
set_object(this_object());
set_function("follow");
set_type ("leaves");
set_match(" ");
  }
}

follow(str){
   string who,where;
   if (sscanf(str, "%s leaves %s.\n", who, where)==2)
	call_other(this_object(), "init_command", where);
}
