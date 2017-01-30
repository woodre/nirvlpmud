/*
    Changelog:
	Bal 1996-03-15:
	* fixed assumptions in heart_beat (now no run-time errors)
*/
inherit "/obj/monster";
object pack, sword;

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Goro");
    set_race("goro");
    set_alias("goro");
    set_short("Goro, master of Mortal Kombat");
    set_long(
"Goro is a master at Mortal Kombat.  He is a huge creature that stands\n"+
"8 feet tall.  He has 2 sets of arms that seem like they could kill you\n"+
"with one blow.  He seems determined to beat you into bloody defeat.\n");
    set_level(20);
    set_hp(1600);
    set_al(-1000);
    set_wc(30);
    set_ac(17);
    pack = clone_object("/players/dragnar/items/mag3");
    move_object(pack,this_object());
    sword = clone_object("/players/dragnar/weapons/angel");
    move_object(sword, this_object());
}

heart_beat() {
    object att, room, johnnie;
    string nom;
 
    ::heart_beat();

    room = environment();
    if (!(att = (object) this_object()->query_attack()))
	return;
    if (att == this_object()) {
	set_hp(1600);
	stop_fight();
	if (!(att = (object) this_object()->query_attack()))
	  return;
    }
    
    nom = att->query_name();
    if(random(10) < 9) {
	tell_room(room, "Goro hit " + nom + " very hard.\n");
	att->heal_self(-5);
	if (!att) return;
    }
    if (random(10) < 6) {
	tell_room(room, "Goro smashes " + nom + " with a bone crushing sound.\n");
	att->heal_self(-5);
	if (!att) return;
    }
    if (random(10) < 4) {
	tell_room(room, "Goro massacres " + nom + " to small fragments.\n");
	att->heal_self(-10);
	if (!att) return;
    }
    if (this_object()->query_hp() < 1000) {
	say("Goro changes shape into Johnnie Cage!\n");
	johnnie = clone_object("/players/dragnar/mons/johnnie.c");
	move_object(johnnie, environment(this_object()));
	destruct(this_object());
	return;
    }
    if (att->query_hp() < 50) {
	say("Goro rips off your head!\n"+
	"You feel your spinal cord being ripped from your back.\n");
	att->hit_player(200);
    }
}
