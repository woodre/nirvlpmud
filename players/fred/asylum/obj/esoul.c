inherit "/obj/treasure.c";
#include <ansi.h>

reset (arg) {
	set_id("soul");
      set_alias("enraged");
	set_short("An Enraged "+BOLD+"Soul"+NORM);
	set_long(
         "  This is the soul of a enraged spirit. It was left for\n"+
         "you in hopes that you would '"+CYN+"free"+NORM+"' it once you left this\n"+
         "wretched place. Although if you are truly a selfish\n"+
         "being you may '"+CYN+"absorb"+NORM+"' it to heal your own soul...\n");
      set_weight(1);
}
init() {
	::init();
        add_action("free_it","free");
        add_action("heal_me","absorb");
	  }

free_it(str) {
	if(!str){ write("Free what?\n"); return 1; }
      if(str == "soul" || str =="enraged" || str == "enraged soul"){
         int money;
         money = 4000+random(2000); 
         this_player()->add_money(money);
         say(this_player()->query_name()+ " frees a enraged soul!\n"); 
         tell_object(this_player(),
         "You mutter a few words of reverance and a enraged soul is freed into the air...\n"+
         "The enraged soul smiles at you as it disappears.\n"+
         "You are awarded "+money+" coins for your unselfish deed.\n");
         destruct(this_object());
         this_player()->recalc_carry(); 
         return 1;
         }
	}

heal_me(str) {
  if(!str){ write("Absorb what?\n"); return 1; }
  if(str == "soul" || str =="enraged" || str == "enraged soul"){
    say(this_player()->query_name()+" absorbs a enraged soul!\n");
    tell_object(this_player(),
       "You mutter a few words as you hold the enraged soul close to your body...\n"+
       "The enraged soul "+BOLD+HIY+"Flashes"+NORM+" with light as it is absorbed into your body.\n");
    if(this_player()->query_stuffed() + 6 > (int)this_player()->query_level() * 8){
      write("You are too stuffed to absorb a lost soul.\n");     
      return 0; }
    if(this_player()->query_soaked() + 6 > (int)this_player()->query_level() * 8){
      write("You are too soaked to absorb a lost soul.\n"); 
      return 0; }  
    this_player()->heal_self(100);
    this_player()->add_stuffed(5);
    this_player()->add_soaked(5);
    destruct(this_object());
    this_player()->recalc_carry();
    return 1; 
    }
  } 
    

