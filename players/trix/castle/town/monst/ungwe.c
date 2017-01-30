/* Changed from lev.20 to 22, hp500 to 1000, align1000 to -500,
   wc30 to 45, ac17 to 22, and added spell effects -Snow */
inherit "obj/monster";
reset(arg){
   object gold,web,sting;
   ::reset(arg);
   if(arg) return;
   set_name("ungweliante");
   enable_commands();
   set_race("spider");
   set_alias("weaver");
   set_short("Ungweliante, the darkness weaver");
   set_long(
"Before you is Ungweliante, the darkness weaver and ancestor of every\n"+
"spider.  The light seems to stop somewhat far from her.  She rules\n"+
"over an underground kingdom of dark and cold lands.\n");
   set_level(22);
   set_hp(1000);
   set_al(-500);
   set_wc(45);
   set_aggressive(1);
   set_chance(35);
   set_spell_dam(30);
   set_spell_mess1("Ungweliante sinks her fangs into her prey!\n");
   set_spell_mess2("Ungweliante sinks her fangs into your flesh!\n");
   set_chat_chance (15);
   load_chat("Ungweliante weaves her web.\n");
   load_chat("Ungweliante looks around her with her many eyes.\n");
   load_chat("The darkness around this place oppresses you.\n");
   set_a_chat_chance(15);
   load_a_chat("Ungweliante stings you hard.\n");
   load_a_chat("Ungweliante catches you in her sticky web.\n");
   web=clone_object("players/trix/castle/town/monst/web.c");
   move_object(web,this_object());
   gold=clone_object("obj/money");
   gold->set_money(2150 + random(50));
   command("wear web");
   set_ac(22);
   sting=clone_object("players/trix/castle/town/monst/sting.c");
   move_object(sting,this_object());
   move_object(gold,this_object());
}
