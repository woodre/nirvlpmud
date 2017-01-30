/* Changed level from 18 to 20 and hps from 100 to 1000 -Snow */
  inherit "obj/monster";
     reset(arg) {
        ::reset(arg);
	if(!arg){
   set_name("Glumdalclitch");
   set_short("Glumdalclitch---(glum for short)");
   set_alias("glum");
   set_long("The ugly sweet Brobdingnag that took care of Gulliver.\n"+
    	"Glum is about sixty feet tall who can crush u\n"+
	"with the palm of her hand.\n");
   set_level(20);
   set_ac(15);
   set_hp(1000);
   set_al(250);
   set_aggressive(0);
   set_wc(26);
   set_can_kill(6);
   set_heal(4, 50);
     set_a_chat_chance(10);
    set_chat_chance(30);
  load_chat("Glumdalclitch says: Have you see my dear sweet Gulliver?\n"); 
     load_a_chat("Glumdalclitch says: What do you think you are doing?\n");
     load_a_chat("Glumdalclitch says: If you don't stop, I will have to stomp you.\n");
  }
}
