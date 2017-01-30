/**
 *
 * superheavies/tiamat.c
 *
 * This meant for a new class of monster. Something much bigger and heavier
 * than what is already out there without being absolutely ridiculous.
 *
 * This monster weighs in at the 10-20K (yes, 20000) hitpoint range and
 * has an average attack of 400hp per attacking round! 
 *
 * Modified 16 sep 2003
 *
 * ADJUSTED to 5x the hitpoints, max damage increased to possible 550 per strike.
 * ADJUSTED the exp to 5x as well, 500k exp per head.
 * ADJUSTED AC, boosted from 30 to 36
 *
 * -HOWEVER- the monster does not attack every round. It can take 4-8 heartbeats
 * just warming up or making the momentum to strike an attack. The result is
 * a monster that can only be attacked by a tank, robot, or similar mechanized
 * vehicle.
 *
 * Idea for this spawned from discussion with Beck, after he showed me his
 * cool-ass Power Ranger stuff. His stuff and variants of it would be excellent
 * at fighting monsters weighing in this class range, although it is currently
 * optimized for players. It would not be much of a stretch for things to change
 * on that regard though.
 *
 */


inherit "players/mizan/mbv2/monsterplus.c";
#include "/obj/ansi.h"
#include "/players/mizan/mbv2/definitions.h"
#include "/players/mizan/mbv2/router.h"

#define CREATOR            "mizan"
#define GUILD_NAME         "monster"
#define ATTACK_ROUNDS      25
/* each head is worth this amount in HP. The total hp is HEAD_HP * 5 */
#define HEAD_HP            75000

#define DAM_BASE           150
#define DAM_RAND           400
#define HIT_PROB           2
#define ACTION_LOG         "/players/mizan/logs/MBALL-TIAMAT"

/* hitpoints of the monster */
int hps;

/* the heads of this creature */
int head1, head2, head3, head4, head5;

/* which turn for which head to be attacking */
int t_head1, t_head2, t_head3, t_head4, t_head5;


reset(arg)
{
    object weapon;
    int a, a2;
        
    ::reset(arg);
    if(arg) return;
    set_name("tiamat");
    set_race("dragon");
    set_alias("hydra");
    set_short("Tiamat");
    set_long("  This is the most frightening thing you have ever seen. Hands down.\n"+
             "  It is a five-headed hydra that is " + HIY + "FOUR HUNDRED FUCKING FEET TALL" + NORM + ".\n\n");
    set_level(96);

    /* we use raw numbers because i overrode set_hp() */
    max_hp = HEAD_HP * 5;
    hit_point = HEAD_HP * 5;

    set_al(-260);
    set_wc(30);
    set_ac(36);
    set_aggressive(0);

    enable_commands();

    t_head1 = 20;
    t_head2 = 15;
    t_head3 = 10;
    t_head4 = 5;
    t_head5 = 1;

    set_heal(3,1);

    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_on(MODE_SPARING_NEWBIES);
    toggle_on(MODE_BALLOON_THROWER);
    toggle_on(MODE_SHIT_THROWER);
    toggle_on(MODE_CALLS_FOR_BACKUP);
    toggle_off(MODE_KID_KILLER);
    toggle_off(MODE_PET_KILLER);
    toggle_off(MODE_PK_INSTIGATOR);

    toggle_on(MODE_IS_PISSED_OFF);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 90);
    set_attribute(ATTRIB_FEARLESSNESS, 100);
    set_attribute(ATTRIB_PERCEPTION, 50);
    set_attribute(ATTRIB_CRUELTY, 90);
    set_attribute(ATTRIB_INSANITY, 10);
    set_attribute(ATTRIB_GENEROUSITY, 90);

    set_monster_guild_level(5);
    set_monster_guild_rank("Black Queen");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "Archangels");

    set_chance_of(CHANCE_CORPSE_LOOTING, 25);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 70);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 3);
    set_chance_of(CHANCE_EMOTE_PANICKED, 3);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 3);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 3);
    set_chance_of(CHANCE_EMOTE_CASUAL, 3);
    set_chance_of(CHANCE_EMOTE_SCARED, 1);
    set_chance_of(CHANCE_PELTING_THINGS, 1);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 166000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 66666);
	set_int(VAL_HUNTING_THRESHOLD, 15);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 15);


    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "Tiamat appears... angry.\n",
    });

	attacked_mchannels = ({
		"They dare attack me?\n",
        "Their destiny they can control. Their final destination they cannot.\n",
	});


    panicked_emotes = ({
        "Tiamat thinks carefully.\n",
    });

	panicked_mchannels = ({
        "Revenge is a dish best served cold.\n",
	});

    
    hit_hard_emotes = ({
        "Tiamat appears unmoved.\n",
    });

    hit_hard_mchannels = ({
        "How dare they even dream a dream.\n",
    });


    taunting_emotes = ({
        "Tiamat's mere presence and breathing shakes the room.\n",
    });

    taunting_mchannels = ({
        "Defiant they are. Destructive I am.\n",
        "Existence is transient.\n",
    });


    triumph_emotes = ({
        "Tiamat's tail crashes against the ground with a deafening BOOM!\n",
    });

    triumph_mchannels = ({
        "Victory is ours.\n",
    });


    casual_emotes = ({
        "The ground itself seems to shake and quiver in fear...\n",
    });

    casual_mchannels = ({
        "Order. Chaos. It is time to deliver both. Now.\n",
    });


    scared_emotes = ({
        "Tiamat glares at you.\n",
    });
    
    scared_mchannels = ({
        "Fear is not recognized.\n",
    });


    death_emotes = ({
        "Tiamat is DEFEATED!\n",
    });

    death_mchannels = ({
        "Impossible!\n",
    });


    shit_throw_emotes = ({
        "Tiamat shifts her weight steadily and deliberately. The ground recoils in fear!\n",
    });
    
    shit_throw_mchannels = ({
        "Base humor is still the root of all humor.\n",
    });

    
    balloon_throw_emotes = ({
        "You wonder what Tiamat would possibly be doing with a water balloon.\n",
    });

    balloon_throw_mchannels = ({
        "Heh.\n",
    });


    arrival_emotes =({
        "Tiamat... all four hundred feet of her fades into view!\n",
    });

    arrival_mchannels =({
        "I have arrived, to create, and then destroy. Mostly to destroy.\n",
    });


}

init()
{
    ::init();
    add_action("do_block", "mi");
    add_action("do_block", "missile");
    add_action("do_block", "sh");
    add_action("do_block", "shock");
    add_action("do_block", "fi");
    add_action("do_block", "fireball");
    add_action("do_block", "so");
    add_action("do_block", "sonic");

    add_action("do_retaliate", "kiss");
    add_action("do_retaliate", "fondle");
    add_action("do_retaliate", "punch");
    add_action("do_retaliate", "kick");
    add_action("do_retaliate", "grope");
    add_action("do_retaliate", "punt");
    add_action("do_retaliate", "smack");
    add_action("do_retaliate", "pelt");
    add_action("do_retaliate", "fling");
    add_action("do_retaliate", "lake");
    add_action("do_retaliate", "slap");
    add_action("do_retaliate", "laugh");
    add_action("do_retaliate", "poke");
    add_action("do_retaliate", "lick");
    add_action("do_retaliate", "hug");
    add_action("do_retaliate", "french");
    add_action("do_retaliate", "dkiss");
    add_action("do_retaliate", "sex");
    add_action("do_retaliate", "noogie");
    add_action("do_retaliate", "snicker");
    add_action("do_retaliate", "fart");
    add_action("do_retaliate", "snuggle");
    add_action("do_retaliate", "laugh");
}


long() 
{
    ::long();

    write(extra_look());
}

heartbeat_attack()
{
    int dam;
    object attacker;
    object strongest;
    object weakest;
    object wealthiest;
    object room;
    string attacker_name;
    int ahp;


    /* Setup some vars */
    hps = query_hp();
    room = environment(this_object());
    attacker = this_object()->query_attack();
    wealthiest = get_wealthiest_player_present(this_object());
    strongest = get_strongest_player_present(this_object());
    weakest = get_weakest_player_present(this_object());

    /* debug */
/*
    if(wealthiest) say("DEBUG: Wealthiest is " + wealthiest->query_name() + ".\n");
    if(weakest) say("DEBUG: Weakest is " + weakest->query_name() + ".\n");
    if(strongest) say("DEBUG: Strongest is " + strongest->query_name() + ".\n");
    if(is(MODE_IS_PISSED_OFF)) say("DEBUG: I am pissed off.\n");
    else say("DEBUG: I am not pissed off.\n");
*/

    if(attacker)
    {
        ahp = attacker->query_hp();
        attacker_name = attacker->query_name();
        if(!attacker_name) attacker_name = "Something";

        /* HEAD ONE ATTACK */
        if(attacker && head1 == 0 && t_head1 > ATTACK_ROUNDS)
        {
            /*
             * The SILVER HEAD ATTACKS
             *
             */

            if(1 == random(HIT_PROB))
            {
                dam = random(DAM_RAND) + DAM_BASE;
                if(ahp > 2000) dam += random(2000) + 500;
                tell_room(room, "The silver dragon head breathes a couple megawatts of lightning at " + attacker_name + ".\n");
                attacker->hit_player(dam);
            }
            else {
                tell_room(room,"The silver dragon head missed "+ attacker_name+".\n");
            }
            if(this_object()->query_hp() < (HEAD_HP * 4)){
                head1 = 1;
                tell_room(room,"The silver dragon head screams and dies!\n");
                attacker->add_exp(2500000);
            }
        
            t_head1 = 0;
        }
        else if(t_head1 == (ATTACK_ROUNDS - 1))
        {
            /* tell the room of impending doom */
            tell_room(room, "You see the silver dragon head rear up for an impending strike...\n");
            t_head1 ++;
        }
        else t_head1 ++;

        /* END HEAD ONE ATTACK */



        /* HEAD TWO ATTACK */
        if(attacker && head2 == 0 && t_head2 > ATTACK_ROUNDS)
        {
            /*
             * The GREEN HEAD ATTACKS
             *
             */

            if(1 == random(HIT_PROB))
            {
                /* green head alternately will strike at the wealthiest player in the room */

                if(wealthiest &&
                   wealthiest != attacker &&
                   1 == random(3) &&
                   is(MODE_IS_PISSED_OFF))
                {
                    tell_room(room, "The green dragon head turns to face the wealthiest player present.\n");
                    dam = random(DAM_RAND) + (DAM_BASE / 2);
                    if(ahp > 2000) dam += random(2000) + 500;
                    wealthiest->attack_object(this_object());
                    wealthiest->hit_player(dam);
                }
                else
                {
                    dam = random(DAM_RAND) + DAM_BASE;
                    if(ahp > 2000) dam += random(2000) + 500;
                    tell_room(room, "The green dragon head belches steaming hot poison at " +  attacker_name + ".\n");
                    attacker->hit_player(dam);
                }
            }
            else {
                tell_room(room,"The green dragon head missed "+ attacker_name +".\n");
            }
            if(this_object()->query_hp() < (HEAD_HP * 3)){
                head2 = 1;
                tell_room(room,"The green dragon head screams and dies!\n");
                attacker->add_exp(2500000);
            }
        
            t_head2 = 0;
        }
        else if(t_head2 == (ATTACK_ROUNDS - 1))
        {
            /* tell the room of impending doom */
            tell_room(room, "You see the green dragon head rear up for an impending strike...\n");
            t_head2 ++;
        }
        else t_head2 ++;

        /* END HEAD TWO ATTACK */




        /* HEAD THREE ATTACK */
        if(attacker && head3 == 0 && t_head3 > ATTACK_ROUNDS)
        {
            /*
             * The BLUE HEAD ATTACKS
             *
             */

            if(1 == random(HIT_PROB))
            {

                if(weakest &&
                   weakest != attacker &&
                   1 == random(3) &&
                   is(MODE_IS_PISSED_OFF))
                {
                    tell_room(room, "The blue dragon head turns to face the weakest player present.\n");
                    dam = random(DAM_RAND) + (DAM_BASE / 2);
                    if(ahp > 2000) dam += random(2000) + 500;
                    weakest->attack_object(this_object());
                    weakest->hit_player(dam);
                }
                else
                {
                    dam = random(DAM_RAND) + DAM_BASE;
                    if(ahp > 1000) dam += random(5000) + 1000;
                    tell_room(room, "The blue dragon head belches a shower of ice shards at " + attacker_name + ".\n");
                    attacker->hit_player(dam);
                }
            }
            else {
                tell_room(room,"The blue dragon head missed "+ attacker_name +".\n");
            }
            if(this_object()->query_hp() < (HEAD_HP * 2)){
                head3 = 1;
                tell_room(room,"The blue dragon head screams and dies!\n");
                attacker->add_exp(2500000);
            }
        
            t_head3 = 0;
        }
        else if(t_head3 == (ATTACK_ROUNDS - 1))
        {
            /* tell the room of impending doom */
            tell_room(room, "You see the blue dragon head rear up for an impending strike...\n");
            t_head3 ++;
        }
        else t_head3 ++;

        /* END HEAD THREE ATTACK */





        /* HEAD FOUR ATTACK */
        if(attacker && head4 == 0 && t_head4 > ATTACK_ROUNDS)
        {
            /*
             * The BLACK HEAD ATTACKS
             *
             */

            if(1 == random(HIT_PROB))
            {
                dam = random(DAM_RAND) + DAM_BASE;
                if(ahp > 100000) dam += random(100000) + 50000;
                tell_room(room, "The black dragon head barfs a torrent of burning acid at " + attacker_name + ".\n");
                attacker->hit_player(dam);
            }
            else {
                tell_room(room,"The black dragon head missed "+ attacker_name+".\n");
            }
            if(this_object()->query_hp() < (HEAD_HP)){
                head4 = 1;
                tell_room(room,"The black dragon head screams and dies!\n");
                attacker->add_exp(2500000);
            }
        
            t_head4 = 0;
        }
        else if(t_head4 == (ATTACK_ROUNDS - 1))
        {
            /* tell the room of impending doom */
            tell_room(room, "You see the black dragon head rear up for an impending strike...\n");
            t_head4 ++;
        }
        else t_head4 ++;

        /* END HEAD FOUR ATTACK */


        /* HEAD FIVE ATTACK */
        if(attacker && head5 == 0 && t_head5 > ATTACK_ROUNDS)
        {
            /*
             * The RED HEAD ATTACKS
             *
             */

            if(1 == random(HIT_PROB))
            {

                if(strongest &&
                   strongest != attacker &&
                   1 == random(3) &&
                   is(MODE_IS_PISSED_OFF))
                {
                    tell_room(room, "The red dragon head turns to face the strongest player present.\n");
                    dam = random(DAM_RAND) + (DAM_BASE);
                    if(ahp > 2000) dam += random(2000) + 500;
                    strongest->attack_object(this_object());
                    strongest->hit_player(dam);
                }
                else
                {
                    dam = (random(DAM_RAND) + DAM_BASE) * 2;
                    if(ahp > 1000) dam += random(1000) + 500;
                    tell_room(room, "The red dragon head cuts loose a scorching conflaguration of fire at " + attacker_name + ".\n");
                    attacker->hit_player(dam);
                }
            }
            else {
                tell_room(room,"The red dragon head missed "+ attacker_name +".\n");
            }
            if(this_object()->query_hp() < 100){
                head1 = 1;
                tell_room(room,"The red dragon head screams and dies!\n");
                attacker->add_exp(2500000);
            }
        

            t_head5 = 0;
        }
        else if(t_head5 == (ATTACK_ROUNDS - 1))
        {
            /* tell the room of impending doom */
            tell_room(room, "You see the red dragon head rear up for an impending strike...\n");
            t_head5 ++;
        }
        else t_head5 ++;

        /* END HEAD FIVE ATTACK */


    }

}


extra_look()
{
    string desc1,desc2,desc3,desc4,desc5;
    int hp;
    hp = this_object()->query_hp();

    desc1 = "in good shape.";
    desc2 = "in good shape.";
    desc3 = "in good shape.";
    desc4 = "in good shape.";
    desc5 = "in good shape.";
    
    if(hp < (HEAD_HP * 5)) desc1 = "slightly hurt."; 

    if(hp < (HEAD_HP * 4) + (HEAD_HP / 4) * 3) desc1 = "somewhat hurt."; 
    if(hp < (HEAD_HP * 4) + (HEAD_HP / 4)) desc1 = "in bad shape."; 
    if(hp < (HEAD_HP * 4)) { desc1 = "dead."; desc2 = "slightly hurt."; }

    if(hp < (HEAD_HP * 3) + (HEAD_HP / 4) * 3) desc2 = "somewhat hurt."; 
    if(hp < (HEAD_HP * 3) + (HEAD_HP / 4)) desc2 = "in bad shape."; 
    if(hp < (HEAD_HP * 3)) { desc2 = "dead."; desc3 = "slightly hurt."; }

    if(hp < (HEAD_HP * 2) + (HEAD_HP / 4) * 3) desc3 = "somewhat hurt."; 
    if(hp < (HEAD_HP * 2) + (HEAD_HP / 4)) desc3 = "in bad shape."; 
    if(hp < (HEAD_HP * 2)) desc3 = "dead."; desc4 = "slightly hurt."; 

    if(hp < HEAD_HP + (HEAD_HP / 4) * 3) desc4 = "somewhat hurt."; 
    if(hp < HEAD_HP + (HEAD_HP / 4)) desc4 = "in bad shape."; 
    if(hp < HEAD_HP) { desc4 = "dead."; desc5 = "slightly hurt."; }

    if(hp < (HEAD_HP / 4) * 3) desc5 = "somewhat hurt."; 
    if(hp < (HEAD_HP / 4)) desc5 = "in bad shape."; 
    if(hp < (HEAD_HP / 8)) desc5 = "in very bad shape."; 
    
    return "The silver head is " + desc1 + "\n" +
           "The green head is " + desc2 + "\n" +
           "The blue head is " + desc3 + "\n" +
           "The black head is " + desc4 + "\n" +
           "The red head is " + desc5 + "\n";
}


/**
 * This blocks certain commands.
 *
 */
do_block()
{
   write("You fail.\n");
   return 1;
}

/**
 * This function blocks commands- AND gives a certain punch back.
 *
 */
do_retaliate(str) 
{
   if(!str || !id(str)) return 0;

   if(this_player() && this_player()->query_level() > 17)
   {
       write("That is not a good idea. You are too low level to do this anyhow.\n");
       return 1;
   }

   write("You fail. Watch out!\nTiamat rumbles into action...\n");
   say(this_player()->query_name() + " did something pretty stupid, pissing off Tiamat.\n");
   ::attack_object(this_player());
   return 1;
}




/**
 * We don't wimpy.
 *
 */
run_away() { return 0; }

/**
 * We protect ourselves from negative heal self. 
 *
 */
heal_self(n) 
{
   if(n < -1) return 0;
   ::heal_self(n);
}

