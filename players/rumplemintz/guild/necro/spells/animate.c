#include "../defs.h"

cmd(str) {
    if(!str ){
	notify_fail("What would you like to animate?\n");
	return 0;
    }
    if(str == "zombie") return animatezombie();
    if(str == "skeleton") return animateskeleton();
    notify_fail("You don't know how to animate that.\n");
    return 0;
}

animatezombie(){
    object ob,corpse;  
    string master;
    int cost;
    if (this_player()->query_real_name() != "wocket" &&
        this_player()->query_real_name() != "rump" ) {
	notify_fail("This spell has not been completed yet.  Bug Wocket to finish it.\n");
	return 0;
    }
    corpse = present("corpse",environment(this_player()));
    ob = GOB;
    if(!ob) return 0;
    if(!GOB->checklev(8,15)) return 1;
    if(!corpse){
	notify_fail("There is no corpse here to be animated.\n"); 
	return 0; 
    }
    if(!GOB->checklev(2)) return 1;
    cost = 150;
    if(tp->query_sp() < cost) {
	notify_fail("You do not have enough spell points for this ability.\n");
	return 0; 
    }
    if(!present("corpse dust",tp)){
	notify_fail("You do not have any corpse dust.\n");
	return 0;
    }
    if(ob->query_blood() < 10 || ob->query_skin() < 5 || ob->query_heart() < 1) {
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
    ob->add_skin(-5);
    ob->add_heart(-1);
    destruct(present("corpse dust",tp));
    master = this_player()->query_real_name();
    call_out("animatezombie2",3,({ corpse, master }));
    return 1;
}

animatezombie2(mixed *stuff){
    object corpse;
    string master;
    string mname;
    int level;
    object zombie;
    corpse = stuff[0];
    master = stuff[1];
    if(!corpse) return;
    tell_room(environment(corpse),HIR+"A "+OFF+BOLD+"zombie"+HIR+" rises out of the bloody ash.\n"+OFF);
    mname = corpse->query_name();
    level = corpse->query_corpse_level();
    if(!mname) mname = "unknown victim";
    zombie = clone_object(MON+"/zombie.c");
    zombie->set_mname(mname);
    zombie->set_master(master);
    zombie->set_level(level);
    zombie->setup();
    move_object(zombie,environment(corpse));
    destruct(corpse);
}

animateskeleton(){
    object ob,corpse;  
    string master;
    int cost;
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
    call_out("animateskeleton2",3,({ corpse, master }));
    return 1;
}


animateskeleton2(mixed *stuff){
    object corpse;
    string master;
    string mname;
    int level;
    object skeleton;
    corpse = stuff[0];
    master = stuff[1];
    if(!corpse) return;
    tell_room(environment(corpse),HIR+"A "+OFF+BOLD+"skeleton"+HIR+" rises out of the bloody ash.\n"+OFF);
    mname = corpse->query_name();
    level = corpse->query_corpse_level();
    if(!mname) mname = "unknown victim";
    skeleton = clone_object(MON+"/skeleton.c");
    skeleton->set_mname(mname);
    skeleton->set_master(master);
    skeleton->setup();
    move_object(skeleton,environment(corpse));
    destruct(corpse);
}
