/*  10/04/2006 - Rumplemintz
      Moved inherit above #include statement
      Changed destruct() calls, second arg is not needed - already defined
*/

inherit "room/room";

#include "/players/eurale/defs.h"

object player;
int sat;
string tpn;

reset(arg) {
    if(arg) return;
    sat = 0;
    if(!present("knight")) {
	move_object(clone_object("players/eurale/Keep/NPC/death_knight"),TO); }
    set_light(1);

    short_desc = BOLD+"The Keep"+NORM;
    long_desc =
    "  This is the grand room of the Keep's Death Knight.  Adorning\n"+
    "the walls are trophies from vanquished warriors.  There is a\n"+
    "large, throne-like chair where the knight passes judgement on\n"+
    "his inferiors.  Off to the side is a small table with chairs\n"+
    "where his guards may sit and discuss battle plans with him.\n";

    items = ({
      "trophies","Skulls, shields, swords and bits of armor",
      "chair","A black onyx chair, perfectly smooth",
      "table","A round, black onyx table",
      "chairs","Short, squat wooden chairs",
    });

    dest_dir = ({
      "players/eurale/Keep/k62.c","leave",
    });

}

realm() { return "NT"; }

init() {
    ::init();
    add_action("sit","sit");
    add_action("pray","pray");
}

sit(str) {
    if(!str) { write("You sit on the floor.\n"); return 1; }
    if(str == "chair") {
	if(present("knight")) {
	    write("The Knight bellows:  How dare you try that?\n"); return 1; }
	if(sat == 1) {
	    write("You ease yourself down into the onyx chair....\n\n");
	    say(capitalize(TPRN)+" sits in the Knight's chair...\n");
	    player = this_player();
	    call_out("dragons10",25);
	    return 1; }
	if(sat == 0) {
	    write("You ease yourself down into the onyx chair....\n\n");
	    say(capitalize(TPRN)+" sits in the Knight's chair....\n");
	    tpn = this_player()->query_name();
	    player = this_player();
	    sat = 1;
	    call_out("dragons1",5);
	    return 1; }
	return 1; }
}

dragons1() {
    tell_object(player,
      "  Your eyes become heavy and you slowly drift off into that\n"+
      "nether state between unconsciousness and reality......\n\n"+
      "Out of the dark mists a figure appears.... a huge red dragon\n"+
      "with taloned claws and coal black eyes.  Smoke rises from his\n"+
      "nostrils as he approaches near enough to whisper....\n\n");
    say(tpn+" closes "+player->query_possessive()+" eyes and relaxes...\n\n");
    call_out("dragons2",15);
    return 1; }

dragons2() {
    tell_object(player,
      "  The dragon's lips slide back in a kind of smirk and he looks\n"+
      "straight into your eyes and whispers: 'So you've decided to \n"+
      "undertake this truly dangerous mission? hehehe...'\n\n");
    call_out("dragons3",10);
    return 1; }

dragons3() {
    tell_object(player,
      "  The dragon drifts around to the side where he can speak\n"+
      "directly into your ear and continues....  He hisses: ' Let\n"+
      "me tell you a story and it will make your objective clear..'\n\n");
    say("A smirk comes across the face of "+tpn+"\n\n");
    call_out("dragons4",10);
    return 1; }

dragons4() {
    tell_object(player,
      "  You feel his breath against the side of your face and smell\n"+
      "the foul odor of rotting meat from his mouth....\n\n"+
      "He continues: 'Dragons are the true children of the Gods.  They\n"+
      "are the most majestic and dignified of all the world's creatures.\n"+
      "They are power incarnate, capable of inspiring awe and fear in\n"+
      "all who behold them....'\n\n");
    call_out("dragons5",17);
    return 1; }

dragons5() {
    tell_object(player,
      "The dragon slithers behind you and you can feel his closeness\n"+
      "on your neck as he continues his story....\n\n"+
      "  'The Gods realized this and so ordered all the dragons, both\n"+
      "good and evil to stay out of sight and work their magic in a\n"+
      "way as to be unobserved, giving credit to the mortals they\n"+
      "were serving....'\n\n");
    call_out("dragons6",15);
    return 1; }

dragons6() {
    tell_object(player,
      "There is a lull..... an eerie silence.... and then the dragon\n"+
      "appears right in front of you again.... eyes burning into yours\n"+
      "and his voice rises......\n\n"+
      "Breathing fire from his mouth he states: 'BUT SOME HAVE REFUSED\n"+
      "TO OBEY!..... AND SO MUST SUFFER THE CONSEQUENCES...'\n\n");
    say(tpn+" jerks.........\n\n");
    call_out("dragons7",15);
    return 1; }

dragons7() {
    tell_object(player,
      "  The dragon's voice turns to a whisper again: 'Your quest is\n"+
      "to find the 6 dragons who have chosen this Keep as their strong-\n"+
      "hold and kill them.  This should be done by you and you alone\n"+
      "lest the credit for their demise be spread among many and thus\n"+
      "no reward rendered....'\n\n");
    call_out("dragons8",15);
    return 1; }

dragons8() {
    tell_object(player,
      "The dragon moves up very close again.... cocks his head and\n"+
      "smirks as he eyes you over once again.....\n\n"+
      "He hisses: 'I wish it were me who could feel the pleasure of\n"+
      "killing my brethren who have become insubordinate to the God's\n"+
      "wishes.  They are worthy adversaries for you, mortal!  I wish\n"+
      "you success.....'\n\n");
    say(tpn+" mumbles something incoherently....\n\n");
    call_out("dragons9",17);
    return 1; }

dragons9() {
    tell_object(player,
      "As the dragon begins to drift back into the darkness, his\n"+
      "voice can just be heard.....\n\n"+
      "'When you have finished your quest, come back to this place\n"+
      "and say [pray dragon] and I will reappear to see if you have\n"+
      "been successful.....'\n\n"+
      "'DO NOT summon me unprepared, I warn you!' hisses the Dragon\n\n"+
      "And with that, the dragon disappears... and you awaken.\n\n");
    call_out("dragons11",3);
    return 1; }

dragons10() {
    tell_object(player,
      "The chair feels pretty uncomfortable and pretty soon your\n"+
      "rump begins to hurt from the hard surface....\n\n");
    return 1; }

dragons11() {
    say(player->query_name()+" awakens from "+player->query_possessive()+
      " trancelike state....\n");
    command("look",player);
    return 1; }

pray(str) {
    if(!str) {
	write("A voice in your head says: Praying will NOT save you!\n");
	return 1; }

    if(str == "dragon") {
	player = this_player();

	if(present("knight")) {
	    write("\nThe Knight SMITES you with his DeathMace....\n\n");
	    player->heal_self(-random(100));
	    return 1; }

	if(!present("knight") && present("amphidragon",this_player()) &&
	  present("whitedragon",this_player()) && present("astraldragon",
	    this_player()) && present("kodragon",this_player()) && present
	  ("seadragon",this_player()) && ("greendragon",this_player())) {
	    write("You kneel and wait for the dragon to appear....\n\n");
	    player = this_player();
	    call_out("quest4",10);
	    return 1; }
	else {
	    write("You kneel and wait for the dragon to appear.....\n\n");
	    player = this_player();
	    call_out("quest1",10);
	    return 1; }

	return 1; }
}

quest1() {
    tell_object(player,
      "From out of the darkness comes the hulking red dragon....\n\n"+
      "He looks at you very carefully.......\n\n");
    call_out("quest2",10);
    return 1; }

quest2() {
    tell_object(player,
      "The dragons "+HIR+"BLASTS YOU WITH FLAME"+NORM+" and screams..\n"+
      "'I told you NOT to summon me unprepared.... now be gone!\'\n\n");
    player->heal_self(- (50 + random(50)));
    call_out("quest3",10);
    return 1; }

quest3() {
    tell_object(player,
      "And with that, the dragon disappears.... leaving you a smoldering\n"+
      "heap of armor and singed hair...\n\n");
    return 1; }

quest4() {
    tell_object(player,
      "You feel a presence close behind you.... and then the hulking\n"+
      "red dragon steps around in front of you.....\n\n"+
      "He moves right up close to your face and stares into your eyes...\n\n");
    call_out("quest5",10);
    return 1; }

quest5() {
    tell_object(player,
      "He stands fully erect in front of you and says: 'I see that \n"+
      "you have been busy.... and that the six renegade dragons have\n"+
      "been silenced forever......\n\n");
    call_out("quest6",10);
    return 1; }

quest6() {
    tell_object(player,
      "The dragon places one of his sharp, taloned claws on your \n"+
      "shoulder and continues....... \n\n"+
      "The Gods will be pleased to be rid of this headache.....\n"+
      "and I have been authorized to reward you for your efforts..\n\n");
    call_out("quest7",12);
    return 1; }

quest7() {
    object ob1,ob2,ob3,ob4,ob5,ob6;
    ob1 = present("amphidragon",player);
    ob2 = present("whitedragon",player);
    ob3 = present("astraldragon",player);
    ob4 = present("kodragon",player);
    ob5 = present("seadragon",player);
    ob6 = present("greendragon",player);
    tell_object(player,
      "The dragon touches you first on one shoulder and then the other..\n\n"+
      "He whispers: 'You are worthy of the rewards I now bestow upon\n"+
      "you'..... and a tingle runs through your body....\n\n"+
      "He whispers 'You have solved the Dragons of the Keep Quest.\n\n");
    player->set_quest("keep_dragons");
    /*
	destruct(ob1,player);
	destruct(ob2,player);
	destruct(ob3,player);
	destruct(ob4,player);
	destruct(ob5,player);
	destruct(ob6,player);
    */
    destruct(ob1);
    destruct(ob2);
    destruct(ob3);
    destruct(ob4);
    destruct(ob5);
    destruct(ob6);
    call_out("quest8",10);
    return 1; }

quest8() {
    tell_object(player,
      "And with that... POOF.... the dragon disappears.....\n\n");
    return 1; }
