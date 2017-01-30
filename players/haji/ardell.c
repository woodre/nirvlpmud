inherit "obj/monster";
string chat_str;
reset(arg) {
   ::reset(0);
   if (arg) return;
   set_name("takanas");
   set_level(12);
   set_hp(700+random(100));
   set_wc(12);
   set_ac(12);
   set_al(-1000);
   set_short("TAKANAS, Spring Guardian");
   set_race("reptilia");
   set_alias("serpent");
   set_alt_name("guardian");
   set_long("ANCIENT SERPENT, Guardian of the Spring of Life\n");
   set_aggressive(1);
   set_whimpy(1);
   add_money(1000+random(100));
   if (!chat_str) {
      chat_str = allocate (2);
      chat_str[0]="For EVERY call you make of the spring, I will come and CLAIM 
a life.\n";
      chat_str[1]="For EVERY healing the spring will give, I will make a WOUND.\
n";
   }
   load_chat(20, chat_str);
}
