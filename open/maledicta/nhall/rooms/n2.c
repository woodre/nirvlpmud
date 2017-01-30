#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int cost;
string what;
object item;
reset(arg) {
	
set_light(1);

short_desc = "Hall of Apprentices [Heal Shop]";
long_desc =
"  This is the healshop of the Hall. Several racks of premade\n"+
"heals line the walls.  A long wooden counter stands directly\n"+
"ahead with a large wooden [sign] hanging behind it. To the\n"+
"east is the main entry hall.\n";
items = ({
"walls",
"Polished white rock which is carefully laid in a silver mortar",
"stone",
"A heavy strong stone that is nearly unbreakable",
"mortar",
"An enchanted mortar that holds the hall together",
"floor",
"A polished marble floor that you can even see your reflection in",
"sign",
"A large wooden sign that you can 'read'",
"counter",
"A long wooden counter",
"heals",
"Several heals that you can purchase",
"racks",
"Large wooden racks covered in bottles"
});

dest_dir = ({
  
  "/players/maledicta/nhall/rooms/n1.c","east",
  });

}


init(){
	::init();
	if(this_player()->query_level() > 5 && this_player()->query_level() < 20){
		write("You don't belong here!\n");
        move_object(this_player(), "/room/vill_green.c");
        tell_room(environment(tp), tpn+" arrives suddenly.\n", ({tp}));
        command("look", this_player());
	}
if(this_player()->query_level() < 20){
if(this_player()->query_guild_exp() || this_player()->query_guild_name() ||
   this_player()->query_guild_rank()){
        write("You don't belong here!\n");
        move_object(this_player(), "/room/vill_green.c");
        tell_room(environment(tp), tpn+" arrives suddenly.\n", ({tp}));
        command("look", this_player());
	}
}
	add_action("browse_it","read");
	add_action("buy_it","buy");
}


browse_it(str){
	if(!str || str != "sign"){
		write("Read what?\n");
        return 1;
	}
    
	write(
"You read the shops sign...\n\n"+
"   "+GRN+"@@@@@@@@@@@@@@@@@@@@@@@@ "+HIG+"Heal Shop"+NORM+" "+GRN+"@@@@@@@@@@@@@@@@@@@@@@@@@\n"+
"   @                                                          @\n"+
"   @  "+NORM+"[10 hp/sp heals]"+GRN+"	                                      @\n"+
"   @  "+NORM+"1. Healing balm [blue](3).........................240   "+GRN+"@\n"+
"   @  "+NORM+"2. Healing balm [green](3)........................240   "+GRN+"@\n"+
"   @  "+NORM+"3. Decanter of healing(3).........................240   "+GRN+"@\n"+
"   @  "+NORM+"[20 hp/sp heals]                                        "+GRN+"@\n"+
"   @  "+NORM+"4. Healing balm [blue](3).........................480   "+GRN+"@\n"+
"   @  "+NORM+"5. Healing balm [green](3)........................480   "+GRN+"@\n"+
"   @  "+NORM+"6. Decanter of healing(3).........................480   "+GRN+"@\n"+
"   @  "+NORM+"[30 hp/sp heals]                                        "+GRN+"@\n"+
"   "+GRN+"@  "+NORM+"7. Healing balm [blue](3).........................720   "+GRN+"@\n"+
"   "+GRN+"@  "+NORM+"8. Healing balm [green](3)........................720   "+GRN+"@\n"+
"   @  "+NORM+"9. Decanter of healing(3).........................720   "+GRN+"@\n"+
"   @	   					              @\n"+
"   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"+NORM+"\n"+
"   To purchase: "+HIG+"buy #"+NORM+"\n\n");
return 1;
}

buy_it(str){
	if(!str){
		write("buy which #?\n");
		return 1;
	}
	if(str == "1"){
	  cost = 240;
	  item = clone_object("/players/maledicta/nhall/obj/blue1.c");
	  what = "healing balm";
	  }
	else if(str == "2"){
	  cost = 240;
        item = clone_object("/players/maledicta/nhall/obj/green1.c");
	  what = "healing balm";
	  }
	else if(str == "3"){
	  cost = 240;
        item = clone_object("/players/maledicta/nhall/obj/decant1.c");
	  what = "decanter";
	  }
	else if(str == "4"){
	  cost = 480;
        item = clone_object("/players/maledicta/nhall/obj/blue2.c");
	  what = "healing balm";
	  }
	else if(str == "5"){
	  cost = 480;
        item = clone_object("/players/maledicta/nhall/obj/green2.c");
	  what = "healing balm";
	  }
    else if(str == "6"){
	  cost = 480;
        item = clone_object("/players/maledicta/nhall/obj/decant2.c");
	  what = "decanter";
	  }
    
      else if(str == "7"){
	  cost = 720;
        item = clone_object("/players/maledicta/nhall/obj/blue3.c");
	  what = "healing balm";
	  }
    else if(str == "8"){
	  cost = 720;
        item = clone_object("/players/maledicta/nhall/obj/green3.c");
	  what = "healing balm";
	  }
	else if(str == "9"){
	  cost = 720;
	  item = clone_object("/players/maledicta/nhall/obj/decant3.c");
	  what = "decanter";
	  }
	else{
	  write("You don't see that here.\n");
	  return 1;
	}	
	
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("You don't seem to have enough coins for that.\n");
    return 1;
     }	   	
 if(!this_player()->add_weight(item->query_weight())) {
    write("You can't carry that. Lighten your load.\n");
    destruct(item);
    return 1; }			
 write("You drop "+cost+" coins into a box and receive a "+what+".\n");
 say(tp->query_name() + " purchases a "+what+".\n");
 move_object(item,this_player());
 tp->add_money(-cost);
 return 1;
} 

