inherit "/obj/monster";

#include <ansi.h>

object stupidplayer;

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_name(BOLD+"Enraged Spirit"+OFF);
    set_short(BOLD+"An enraged spirit"+OFF);
    set_alias("spirit");
    set_alt_name("upset spirit");
    set_race("undead");
    set_gender("creature");
    set_long("An enraged spirit whos corpse was disturbed.  Its only mission\n"+
      "is to enact revenge against the one who had uncovered its corpse.\n"+
      "Torn rags fly back as the spirit generates its own wind.  A look\n"+
      "of torture and anguish adorns its face.\n");
    set_level(9);
    set_ac(10);
    set_wc(18+random(5));
    set_hp(200+random(80));
    set_al(-1000);
    set_chat_chance(10);
    set_a_chat_chance(10);
    load_chat("A chilling breeze fills the small chamber.\n");
    load_a_chat("The spirit howls in anger and fury...\n"); 
    set_dead_ob(this_object());
    set_heart_beat(1);
}

heart_beat(){
    ::heart_beat();
    if(!stupidplayer){
	destruct(this_object());
	return 1;
    }
    if(stupidplayer->query_ghost()){
	tell_room(environment(this_object()),"The spirit vanishes.\n");
	destruct(this_object());
    } 
    /* next line added by verte 6.11.01 */
    if(!environment() || !environment(stupidplayer)) return;
    if(environment(this_object()) != environment(stupidplayer)){
	tell_room(environment(this_object()),"The spirit vanishes.\n");
	move_object(this_object(),environment(stupidplayer));
	tell_room(environment(this_object()),"The spirit appears.\n");
    }
    if(!query_attack()){
	attack_object(stupidplayer);
    }
}

set_stupidplayer(o){ stupidplayer = o; }

monster_died(){
    if(present("corpse",environment(this_object()))){
	destruct(present("corpse",environment(this_object())));
    }
    return 1;
}

calculate_worth(){ 
    return 400;
}
