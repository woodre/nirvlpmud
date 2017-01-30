/**
 *
 * superheavies/hydra.c
 *
 * This meant for a new class of monster. Something much bigger and heavier
 * than what is already out there without being absolutely ridiculous.
 *
 * This monster weighs in at the 10-20K (yes, 20000) hitpoint range and
 * has an average attack of 400hp per ROUND! Yes, PER ROUND!
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


inherit "obj/monster";

#define ATTACK_ROUNDS       25
/* each head is worth this amount in HP. The total hp is HEAD_HP * 5 */
#define HEAD_HP            10000

#define DAM_BASE           150
#define DAM_RAND           300
#define HIT_PROB           2

/* hitpoints of the monster */
int hps;

/* the heads of this creature */
int head1, head2, head3, head4, head5;

/* which turn for which head to be attacking */
int t_head1, t_head2, t_head3, t_head4, t_head5;


reset(arg)
{
    object weapon;
    object gold;
    int a, a2;
        
    ::reset(arg);
    if(arg) return;
    set_name("tiamat");
    set_race("dragon");
    set_alias("hydra");
    set_short("Tiamat");
    set_level(50);
    set_hp(HEAD_HP * 5);
    set_al(-260);
    set_wc(32);
    set_ac(50);
    set_aggressive(0);
    gold=clone_object("obj/money");
    gold->set_money(random(23000)+23000);
    move_object(gold,this_object());
    enable_commands();

    t_head1 = 20;
    t_head2 = 15;
    t_head3 = 10;
    t_head4 = 5;
    t_head5 = 1;

    set_heal(15,10);

    while(a2 < 3)
    {
        while(a < 5) 
        {
            gold=clone_object("players/mizan/etheriel/items/spuckballs-ext3.c");
            move_object(gold,this_object());
            a++;
        }
        gold = clone_object("/players/mizan/etheriel/items/spuck-flexgun.c");
        move_object(clone_object("/players/mizan/etheriel/items/spuckballs-ext3.c"), gold);
        move_object(gold, this_object());

        a2 ++;
    }


}


long() {
   write("  This is the most frightening thing you have ever seen.\n"+
       "  It is a five-headed hydra that is FOUR FUCKING HUNDRED FEET TALL.\n\n");

   write(extra_look());
}

heart_beat()
{
    int dam;
    object attacker,room;
    string attacker_name;


    /* Setup some vars */
    hps = this_object()->query_hp();
    room = environment(this_object());
    attacker = this_object()->query_attack();

    if(attacker)
    {
        attacker_name=attacker->query_real_name();

        if(present(attacker_name,environment(this_object())))
        {
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
                    tell_room(room, "The silver dragon head breathes a couple megawatts of lightning at " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam);
                }
                else {
                    tell_room(room,"The silver dragon head missed "+capitalize(attacker_name)+".\n");
                }
                if(this_object()->query_hp() < (HEAD_HP * 4)){
                    head1 = 1;
                    tell_room(room,"The silver dragon head screams and dies!\n");
                    attacker->add_exp(100000);
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
                    dam = random(DAM_RAND) + DAM_BASE;
                    tell_room(room, "The green dragon head belches steaming hot poison at " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam);
                }
                else {
                    tell_room(room,"The green dragon head missed "+capitalize(attacker_name)+".\n");
                }
                if(this_object()->query_hp() < (HEAD_HP * 3)){
                    head2 = 1;
                    tell_room(room,"The green dragon head screams and dies!\n");
                    attacker->add_exp(100000);
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
                    dam = random(DAM_RAND) + DAM_BASE;
                    tell_room(room, "The blue dragon head belches a shower of ice shards at " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam);
                }
                else {
                    tell_room(room,"The blue dragon head missed "+capitalize(attacker_name)+".\n");
                }
                if(this_object()->query_hp() < (HEAD_HP * 2)){
                    head3 = 1;
                    tell_room(room,"The blue dragon head screams and dies!\n");
                    attacker->add_exp(100000);
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
                    tell_room(room, "The black dragon head barfs a torrent of burning acid at " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam);
                }
                else {
                    tell_room(room,"The black dragon head missed "+capitalize(attacker_name)+".\n");
                }
                if(this_object()->query_hp() < (HEAD_HP)){
                    head4 = 1;
                    tell_room(room,"The black dragon head screams and dies!\n");
                    attacker->add_exp(100000);
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
                    dam = random(DAM_RAND) + DAM_BASE;
                    tell_room(room, "The red dragon head cuts loose a scorching conflaguration of fire at " + capitalize(attacker_name) + ".\n");
                    attacker->hit_player(dam);
                }
                else {
                    tell_room(room,"The red dragon head missed "+capitalize(attacker_name)+".\n");
                }
                if(this_object()->query_hp() < 100){
                    head1 = 1;
                    tell_room(room,"The red dragon head screams and dies!\n");
                    attacker->add_exp(100000);
                }
                
                ::heart_beat();
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
    
    if(hp < (HEAD_HP * 5)){desc1 = "slightly hurt.";}
    if(hp < (HEAD_HP * 4) + (HEAD_HP / 4) * 3){desc1 = "somewhat hurt.";}
    if(hp < (HEAD_HP * 4) + (HEAD_HP / 4)){desc1 = "in bad shape.";}
    if(hp < (HEAD_HP * 4)){desc1 = "dead."; desc2 = "slightly hurt.";}
    if(hp < (HEAD_HP * 3) + (HEAD_HP / 4) * 3){desc2 = "somewhat hurt.";}
    if(hp < (HEAD_HP * 3) + (HEAD_HP / 4)){desc2 = "in bad shape.";}
    if(hp < (HEAD_HP * 3)){desc2 = "dead."; desc3 = "slightly hurt.";}
    if(hp < (HEAD_HP * 2) + (HEAD_HP / 4) * 3){desc3 = "somewhat hurt.";}
    if(hp < (HEAD_HP * 2) + (HEAD_HP / 4)){desc3 = "in bad shape.";}
    if(hp < (HEAD_HP * 2)){desc3 = "dead."; desc4 = "slightly hurt.";}
    if(hp < HEAD_HP + (HEAD_HP / 4) * 3){desc4 = "somewhat hurt.";}
    if(hp < HEAD_HP + (HEAD_HP / 4)){desc4 = "in bad shape.";}
    if(hp < HEAD_HP){desc4 = "dead."; desc4 = "slightly hurt.";}
    if(hp < (HEAD_HP / 4) * 3){desc5 = "somewhat hurt.";}
    if(hp < (HEAD_HP / 4)){desc5 = "in bad shape.";}
    if(hp < (HEAD_HP / 8)){desc5 = "in very bad shape.";}
    
    return "The silver head is " + desc1 + "\n" +
           "The green head is " + desc2 + "\n" +
           "The blue head is " + desc3 + "\n" +
           "The black head is " + desc4 + "\n" +
           "The red head is " + desc5 + "\n";
}
