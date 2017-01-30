inherit "obj/monster";
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("hiss");
   set_race("dragon");
   set_alias("dragon");
   set_short("Hiss, black dragon of acid");
   set_long("Hiss, a giant green dragon, leads the invasion force!\n");
   set_level(122);
   set_hp(1);
   set_al(-1000);
   set_wc(1);
   set_ac(1);
   set_aggressive(1);
   set_chat_chance (1);
   load_chat("Hiss hisses, 'My master, Zacor will destroy you!'\n");
   load_chat("Hiss snarls, 'We will destroy the vale!'\n");
   load_chat("'Your efforts are too little, too late,' snarls Hiss.\n");
   load_chat("Hiss cries, 'You pathetic food things. Die!'\n");
}
monster_died()
{ say(query_attack()->query_real_name()+" Killed MEEEEEE\n");
   return 1;
}
