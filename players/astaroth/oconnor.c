 
 
inherit "obj/monster";
 
object money;
init() {
  ::init();
}
 
reset(arg) {
 
   ::reset(arg);
 
   set_short("Sinead O'Connor");
   set_long("Her head is totally shaven. \n");
   set_name("sinead");
   set_alias("oconnor");
   set_race("man");
   set_al(400);
   set_wc(15);
   set_ac(10);
   set_level(16);
   set_hp(380);
   if(arg) return;
 
   set_chat_chance(10);
   load_chat("Sinead says: \"I am opposed to nationalism in any form.\"\n");
   load_chat("Sinead says: \"Yes I see how the glass is raised, I have refused to take part.\"\n");
 
}
 
