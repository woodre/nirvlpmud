inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("student");
   set_race("human");
   set_alias("student");
   set_short("A university student");
   set_long("A typical student of GREY UNIVERSITY and as such is a snotty brat.\n"+
            "However he looks quite capable and athletic...watch out!\n");
   set_level(15);
   set_hp(225);
   set_al(-10);
   set_wc(20);
   set_ac(12);
   set_chat_chance(2);
   load_chat("Student mumbles something about you mother and a pig....\n");
   load_chat("Student says: You were SO ugly as a kid your parents had to tie\n"+
             "a steak around you're neck to get the dog to play with you!\n");
   gold=clone_object("obj/money");
   gold->set_money(1000);
   move_object(gold,this_object());
}
