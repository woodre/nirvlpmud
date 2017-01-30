/* Changed level from 18 to 17, unset hp to 400, and aggressive to 1
   - Snow */
inherit "obj/monster";
object needle;
reset(arg){
    ::reset(arg);
	if (!arg){
     set_name("Mr. Joyboy");
     set_short("Mr. Joyboy");
     set_alias("joyboy");
     set_long ("Mr. Joyboy is an embalmer at Whisper Glades Funeral\n"+
	"homes.  His lips are shaped to smile all the time like Bill\n"+
        "Clinton's.\n");
	set_level(17);
       set_hp(400);
	set_ac(15);
	set_al(250);
	set_aggressive(1);
	set_a_chat_chance(40);
	set_chat_chance(40);
	load_chat("Joyboy studies your face carefully.\n");
        load_chat("Joyboy says:  Hmmm... you still lack a bit of color.\n"); 
	load_chat("Joyboy says: Come closer so I can embalm you.\n");
	load_a_chat("Joyboy laughs hysterically in your face!\n");
	load_a_chat("Joyboy says: Good good.  Better for you to die young with color than to die old.\n");
	load_a_chat("Joyboy tries to poke his venomous needle to embalm you.\n");
       needle = clone_object("players/airwoman/WEAPONS/needle");
	move_object(needle,this_object());
	command("wield needle",this_object());
	set_wc(26);
}
}
