inherit "obj/monster";
	object gloves, axe;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Grave Digger");
   set_race("gravedigger");
   set_alias("digger");
	set_short("Grave Digger");
	set_long("He looks tired from digging all of the graves that\n" +
"are around you but you wonder if this old man is as weak as he looks.\n");
   set_level(14);
   set_hp(250);
   set_al(-1000);
   set_wc(22);
   set_ac(13);
   set_chance(35);
   set_spell_dam(20);
set_spell_mess2("You hear a Phuslup as the grave digger sticks his pick axe into your gut!\n");
	set_a_chat_chance(20);
   set_chat_chance(5);
load_chat("The grave digger says: What are you doing here stranger?\n");
load_chat("The grave digger says: You don't have the radiation disease do you?!\n");
load_chat("The grave digger says: Let me give you some advice.\n" +
"He leans over and whispers to you: Stay away from the ice mines, The\n" +
"mutants control that now.\n");
	gloves=clone_object("/players/dragnar/WasteLands/armor/gloves.c");
	move_object(gloves, this_object());
	axe=clone_object("/players/dragnar/WasteLands/weap/pickaxe.c");
	move_object(axe, this_object());
}
