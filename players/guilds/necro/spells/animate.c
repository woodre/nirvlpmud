#include "../defs.h"

#define UNDEAD ({ "zombie", "skeleton", })

cmd(str) {
    object ob,corpse;  
    string master;
    int cost, level;

    if(!str ){
      str = UNDEAD[ random(sizeof(UNDEAD)) ];
    }

    if( member( UNDEAD, str ) < 0 ) {
      notify_fail("You don't know how to animate that.\n");
      return 0;
    }
    corpse = present("corpse",environment(this_player()));
    ob = GOB;
    if(!ob) return 0;
    if(!GOB->checklev(3,7)) return 1;
    if(!corpse){
	notify_fail("There is no corpse here to be animated.\n"); 
	return 0; 
    }
    if(!GOB->checklev(2)) return 1;
    cost = 109 - (tp->query_guild_rank()*3);
    if(tp->query_sp() < cost) {
	notify_fail("You do not have enough spell points for this ability.\n");
	return 0; 
    }
    if(!present("corpse dust",tp)){
	notify_fail("You do not have any corpse dust.\n");
	return 0;
    }
    if(ob->query_blood() < 10) {
	notify_fail("You do not have the material componets for this spell.\n");
	return 0; 
    }
    write("You begin to mix corpse dust with blood.  You then pour your mixture down the\n"+
      "throat of your corpse.  You begin to whisper arcane words and black smoke rises\n"+
      "from the body.  "+
      HIR+"Fire takes hold and burns the body to ash.\n"+OFF);
    say(tpn+" kneels down and pours blood into the corpse's mouth.  The corpse begins to smoke\n"+
      "and then in a burst of flame is rendered to ash.\n");
    tp->add_spell_point(-cost);
    ob->add_val(3);
    ob->add_blood(-10);
    destruct(present("corpse dust",tp));
    master = this_player()->query_real_name();

    if(str == "zombie") 
      call_out("animatezombie",3,({ corpse, master }));

    if(str == "skeleton") 
      call_out("animateskeleton",3,({ corpse, master }));
    
    return 1;
}
    
configure_undead( object undead, object corpse, string master ) {
    int level;
    string mname;

    mname = corpse->query_name();
    level = corpse->query_corpse_level();
    if(!mname) mname = "unknown victim";
    undead->set_mname(mname);
    undead->set_master(master);
    undead->set_level(level);
    undead->set_exp_worth( corpse->query_exp_worth() );
    undead->setup();
    move_object(undead,environment(corpse));
    destruct(corpse);
}

animatezombie(mixed *stuff){
    object corpse, undead;
    corpse = stuff[0];

    if(!corpse || !environment(corpse) ) return;
    tell_room(environment(corpse),HIR+"A "+OFF+BOLD+"zombie"+HIR+" rises out of the bloody ash.\n"+OFF);
    undead = clone_object(MON+"/zombie.c");
    configure_undead( undead, corpse, stuff[1] );
}

animateskeleton(mixed *stuff){
    object corpse, undead;
    corpse = stuff[0];

    if(!corpse || !environment(corpse) ) return;
    tell_room(environment(corpse),HIR+"A "+OFF+BOLD+"skeleton"+HIR+" rises out of the bloody ash.\n"+OFF);
    undead = clone_object(MON+"/skeleton.c");
    configure_undead( undead, corpse, stuff[1] );
    
}
