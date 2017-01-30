inherit "obj/monster";
reset(arg){
   object burg,gold,gun,clip;
   ::reset(arg);
   if(arg) return;
   set_name("seller");
   set_race("human");
   set_alias("seller");
   set_short("A weapons seller");
set_long("This is the weapons seller of Trixtown, a fat man with greasy hands, wielding a\n"+
            "shotgun and eating a big cheeseburger.\n");
   set_level(20);
   set_hp(500);
   set_al(300);
   set_wc(30);
   set_ac(17);
   set_aggressive(0);
   set_chat_chance (15);
   load_chat("The seller says: Hey, if you're not gonna buy you'd better bring your ass out\n                 of here.\n");
   load_chat("The seller shines his gun.\n");
   set_a_chat_chance(15);
   load_a_chat("The seller points his gun at you.\n");
   load_a_chat("The clerk says: Hey man, you asked for this.\n");
   load_a_chat("The clerk shoots you with his gun.\n");
   gold=clone_object("obj/money");
   add_money(4500+random(200));
/* These obs don't exist.  -feld
   gun=clone_object("/players/trix/castle/obj/shotgun");
   move_object(gun,this_object());
   clip=clone_object("/players/trix/castle/obj/clippy");
   move_object(clip,this_object());
*/
   burg=clone_object("/players/trix/castle/town/monst/cheeseb.c");
   move_object(burg,this_object());
}
