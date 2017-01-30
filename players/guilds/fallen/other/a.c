
/* intended for use in /players/zeus/museum/arena/ rooms */

inherit "/obj/monster";
#include "../all.h"
#define MN capitalize((string)meat->query_real_name())
object meat;
int spells;

reset(arg){
    ::reset(arg);
    if (!arg){

	spells = 0;
	set_name("zriel");
	set_short("The spirit of Zriel");
	set_race("spirit");
	set_gender("male");
	set_long(
	  "spirit..\n");
	set_level(23);
	set_ac(17);
	set_wc(30);
	set_heal(1,5);
	set_hp(1000);
	set_aggressive(0);
	set_al(0);
	set_chance(15);
	set_spell_dam(20+random(100));
	set_spell_mess1("Ani spins as winds explode from her body!\n");
	set_spell_mess2("Ani blasts you with the winds!\n");
	set_chat_chance(3);
	set_a_chat_chance(1);
	load_chat("Ani looks at you with powerful eyes.\n");
	load_chat("Ani seems to smile slightly.\n");
	load_chat("Ani grins with a strange darkness around her.\n");
	load_chat("You see a sparkle in her eyes.\n");
	load_a_chat("Ani explodes with rage.\n");
	set_dead_ob(this_object());
    }
}

/*
monster_died(){
  write_file("/players/guilds/fallen/log/NPC", ctime(time())+"   "+
       capitalize((string)attacker_ob->query_real_name())+
       " defeated Zriel.\n");
  attacker_ob->move_player("out#/players/guilds/fallen/rooms/ghall.c");
}

*/
again()
{
    if(!AO->query_ghost() && AO->is_player())
    {
	already_fight = 0; 
	::attack();
    }
}

shadowform(){
    if(attacker_ob->is_player()) return;
    tell_room(environment(),
      "\n\nZriel whispers:  Impressive "+MN+", you have learned well.\n\n"+
      "Zriel waves his hand as the shadow form dissipates...\n");
    destruct(attacker_ob);
    call_out("shadowform2", 6);
}

shadowform2(){
    tell_room(environment(),
      "\n\nZriel chants as he pulls the shadows towards him...\n");
    call_out("shadowform3", 3);
}

shadowform3(){
    tell_room(environment(),
      "Zriel grins wickedly as he"+BOLD+BLK+"  BLASTS  "+NORM+
      "you with shadows!\n\n");
    meat->hit_player(70);
    attack_object(meat);
}

weaken(a){
    tell_room(environment(),
      "\n\nZriel chuckles softly, his voice echoing off the walls...\n");
    if(meat)
    {
	tell_room(environment(),
	  "Zriel whispers:  You can not weaken me "+MN+"...\n\n\n");
    }
    else
    {
	tell_room(environment(),  
	  "Zriel whispers: You can not weaken me...\n\n\n");
    }
    armor_class += 1;
    destruct(a);
}

web(){
    tell_room(environment(),
      "\n\nZriel whispers:  You have learned muched "+MN+
      ", I am impressed.\n\n");
    end();
}

heal_self(arg){
    int armor;
    armor = -random(30);
    if(arg < armor) arg = armor;
    ::heal_self(arg);
    return 1; 
}

heart_beat(){
    ::heart_beat();
    if(!environment())
	return;
    if(present("weaken_counter", this_object()))
	weaken(present("weaken_counter", this_object()));
    if(!attacker_ob)
	return;
    if(attacker_ob->is_player())
	meat = attacker_ob;
    if(attacker_ob->query_spell_dam())
	spells++;
    if(attacker_ob->query_info() == "zeus_shadowform" && meat)
	shadowform();
    else if(this_object()->ringed())
	web();
}
