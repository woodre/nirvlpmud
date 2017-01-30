inherit "/obj/treasure.c";
#include <ansi.h>

reset (arg) {
	set_id("soul");
      set_alias("tormented");
	set_short("A Tormented "+BOLD+"Soul"+NORM);
	set_long(
         "  This is the soul of a tormented spirit. It was left for\n"+
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
      if(str == "soul" || str =="tormented" || str == "tormented soul"){
         int money;
         money = 3000+random(1000); 
         this_player()->add_money(money);
         say(this_player()->query_name()+ " frees a tormented soul!\n"); 
         tell_object(this_player(),
         "You mutter a few words of reverance and a tormented soul is freed into the air...\n"+
         "The tormented soul smiles at you as it disappears.\n"+
         "You are awarded "+money+" coins for your unselfish deed.\n");
         destruct(this_object()); 
         this_player()->recalc_carry();
         return 1;
         }
	}

heal_me(str) {
  if(!str){ write("Absorb what?\n"); return 1; }
  if(str == "soul" || str =="tormented" || str == "tormented soul"){
    say(this_player()->query_name()+" absorbs a tormented soul!\n");
    tell_object(this_player(),
       "You mutter a few words as you hold the tormented soul close to your body...\n"+
       "The tormented soul "+BOLD+HIY+"Flashes"+NORM+" with light as it is absorbed into your body.\n");
    if(this_player()->query_stuffed() + 12 > (int)this_player()->query_level() * 8){
      write("You are too stuffed to absorb a lost soul.\n");     
      return 0; }
    if(this_player()->query_soaked() + 12 > (int)this_player()->query_level() * 8){
      write("You are too soaked to absorb a lost soul.\n"); 
      return 0; }  
    this_player()->heal_self(80);
    this_player()->add_stuffed(5);
    this_player()->add_soaked(5);
    destruct(this_object());
    this_player()->recalc_carry();
    return 1; 
    }
  } 
    

