inherit "obj/monster";
int intox_lvl;

int b,p6,p12,fm;

void reset(int arg) {
	::reset(arg);
	if (arg) {
	  b += 5;
	 p6 += 5;
	p12 += 5;
	 fm += 5;
	  return;
        }
	b = 30;
	p6 = 20;
	p12 = 15;
	fm = 10;
	set_name("Moe");
	set_alias("moe");
	set_short("Moe, the Bartender");
	set_long(format("This is Moe, the Bartender.  "+
		        "Barney drank all the beverages, "+
		        "and it will take a few days for the "+
		        "tavern to restock, sorry.\n", 75));
	set_level(24);
        set_gender("male");
        set_race("cartoon");
	set_wc(42);
	set_ac(22);
	set_hp(900);
/*
	set_al(1000);
*/
	set_chat_chance(10);
	load_chat("Moe says: I have good heals!\n");
        set_wc_bonus(12);
        set_ac_bonus(20);
        set_spell_dam(90);
        set_chance(33);
        set_spell_mess1("\n\tMoe punches his attacker in the stomach!\n\n");
        set_spell_mess2("\n\tMoe punches you in the stomach!\n\n");
}

list_items() {
	write("Moe says: Here's what I got...\n");
	write(pad("   Can of Duff", 20)+pad("600 coins",15));
		write(b+" are left in stock.\n");
	write(pad("   6 Pack of Duff", 20)+pad("3200 coins",15));
		write(p6+" are left in stock.\n");
	write(pad("   12 Pack of Duff",20)+pad("6000 coins",15));
	        write(p12+" are left in stock.\n");
	write(pad("   Flaming Moe", 20)+pad("10000 coins", 15));
		write(fm+" are left in stock.\n");
	return 1;
}

purchase(str) {
	object ob;
	int i;
	if (!str) 
	   return 0;
	i = this_player()->query_money();
	if (str == "duff") {
	   if (i<600) {
	      say("You don't have enough money!\n");
	      return 1;
	   }
           if (b == 0) {
              say("Moe says: Sorry, I don't have any beer left.\n");
              return 1;
	   }
	   ob = clone_object("players/gowron/room/heal/duff.c");
	   move_object(ob, this_player());
	   this_player()->add_money(-600);
	   write("You buy a can of duff.\n");
	   say(this_player()->query_name()+" buys a can of duff.\n");
	   b--;
	}
	else if (str == "6 pack") {
	   if (i<3200) {
	      say("You don't have enough money!\n");
	      return 0;
	   }
	   if (p6 == 0) {
	      say("Moe says: Sorry, I don't have any 6 packs left.\n");
	      return 1;
           }
	   ob = clone_object("players/gowron/room/heal/6pack.c");
	   move_object(ob, this_player());
	   this_player()->add_money(-3200);
	   write("You buy a 6 pack.\n");
	   say(this_player()->query_name()+" buys a 6 pack.\n");
	   p6--;
	}
	else if (str == "12 pack") {
	   if (i<6000) {
	      say("You don't have enough money!\n");
	      return 0;
	   }
           if (p12 == 0) {
	      say("Moe says: Sorry, I don't have any 12 packs left.\n");
	      return 1;
	   }
	   ob = clone_object("players/gowron/room/heal/12pack.c");
	   move_object(ob, this_player());
	   say(this_player()->query_name()+" buys a 12 pack.\n");
	   write("You buy a 12 pack.\n");
	   this_player()->add_money(-6000);
	   p12--;
	}
	else if (str == "flaming moe") {
	   if (i<10000) {
	      say("You don't have enough money!\n");
	      return 0;
	   }
           if (fm == 0) {
	      say("Moe says: Sorry, I don't have any flaming moes left.\n");
	      return 1;
	   }
	   ob = clone_object("players/gowron/room/heal/flaming_moe.c");
	   move_object(ob, this_player());
	   write("You buy a flaming Moe.\n");
	   say(this_player()->query_name()+" buys a flaming moe.\n");	   
	   this_player()->add_money(-10000);
	   fm--;
	}
	else write(str+" is not on the menu.\n");
	return 1;
}

init() {
::init();
	add_action("purchase", "buy");
	add_action("list_items", "list");
}

void
drink_beer_from_tap()
{
 object whereami;
 whereami = environment();
     if(whereami)
     tell_room(whereami,
       "\n\tMoe grabs ahold of the hose leading from the beer tap and chugs!\n\n");
       if((intox_lvl ++) > 8) intox_lvl = 8;
       set_heal(intox_lvl, ((intox_lvl/3) ? (intox_lvl / 3) : 1));
       calculate_worth();
       heal_self(20 + random(20));
}


void
smash_glasses()
{
 object whereami;
 whereami = environment();
   if(attacker_ob) 
     tell_object(attacker_ob, "\n\t\Moe hurls a bar glass at you!\n");
   if(whereami && attacker_ob)
     tell_room(whereami, "\n\t\Moe hurls a bar glass at " + attacker_ob->query_name() + "!\n", ({ attacker_ob }));
   if(!random(2)) {
     if(attacker_ob)
       tell_object(attacker_ob, "\n\t\It smashes into your face!\n\n");
     if(whereami && attacker_ob)  
       tell_room(whereami, "\n\t\It smashes into " + possessive(attacker_ob) + " face!\n", ({ attacker_ob }));
        attacker_ob->hit_player(40 + random(20));
     }
}

void
heart_beat()
{
 object whereami;
 whereami = environment();
    ::heart_beat();
    if(!whereami) return;
     if(!attacker_ob || !present(attacker_ob, whereami)) return;
     if(!random(3))
       drink_beer_from_tap();
     if(!random(5))
      smash_glasses();
}
