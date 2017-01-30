/**
 *
 * superheavies/dark_spuck_juggernaut.c
 *
 * This meant for a new class of monster. Something much bigger and heavier
 * than what is already out there without being absolutely ridiculous.
 *
 * This monster weighs in at the 7500 hitpoint range and
 * has an average attack of 150hp per ROUND! Yes, PER ROUND!
 *
 * -HOWEVER- the monster does not attack every round. It can take 4-8 heartbeats
 * just warming up or making the momentum to strike an attack. 
 *
 * Idea for this spawned from discussion with Beck, after he showed me his
 * cool-ass Power Ranger stuff. His stuff and variants of it would be excellent
 * at fighting monsters weighing in this class range, although it is currently
 * optimized for players. It would not be much of a stretch for things to change
 * on that regard though.
 *
 * -05 Mar 2001
 * Actually this guy is on the 'lighter' side of the superheavy range.
 *
 *
 */


inherit "obj/monster";

#define ATTACK_ROUNDS       5

/* hitpoints of the monster */
int hps;

/* which turn for which attack to be happening */
int t_smash;
int t_gun;
int t_punch;


reset(arg)
{
    object weapon;
    object ammo;
    int a;
        
    ::reset(arg);
    if(arg) return;
    set_name("Dark Spuckball Juggernaut");
    set_race("spuckball");
    set_alias("juggernaut");
    set_short("Dark Spuckball Juggernaut");
    set_level(20);
    set_hp(5000);
    set_al(-866);
    set_wc(32);
    set_ac(25);
    set_aggressive(0);
    ammo=clone_object("obj/money");
    ammo->set_money(random(200)+2000);
    move_object(ammo,this_object());
    enable_commands();

    t_smash = 7;
    t_punch = 4;
    t_gun = 1;

    set_heal(5,5);

    weapon = clone_object("/players/mizan/etheriel/items/spuck-minigun.c");

    move_object(weapon, this_object());

    while(a < 10) 
    {
        ammo = clone_object("players/mizan/etheriel/items/spuckballs-ext3.c");
        move_object(ammo, weapon);
        a++;
    }
    command("wield minigun", this_object());
}


long() 
{
   write("  Before you is a seemingly innocuous dark blue blob somewhat reminiscent\n"+
         "  of a Beano. However be warned. This is was once a member of the Legion of\n"+
         "  Spuck's forces that has turned over to the darkened side. It detects your\n"+
         "  presence and assumes the form of its figure shape... an intimidating blue blob\n"+
         "  towering 40 feet above you...\n");
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
        attacker_name=attacker->query_name();

        if(present(attacker_name,environment(this_object())))
        {

            /* THE SMASH ATTACK */
            if(attacker && t_smash > (4 + random(3)))
            {

                if(1 == random(2))
                {
                    dam = random(75) + 75;
                    tell_room(room, "Dark Spuckball Juggernaut brings its tentacle down with ungodly force!\n\n");
                    tell_room(room, " SSSSSS  MM    MM    AAAA     CCCCC   KK  KK \n");
                    tell_room(room, " SS      MMM  MMM   AA  AA   CC   CC  KK KK  \n");
                    tell_room(room, "  SSSS   MM MM MM  AA    AA  CC       KKKK   \n");
                    tell_room(room, "     SS  MM    MM  AAAAAAAA  CC   CC  KK KK  \n");
                    tell_room(room, " SSSSSS  MM    MM  AA    AA   CCCCC   KK  KK \n\n");
                    tell_room(room, capitalize(attacker_name) + " absorbs an asteroid-sized pimpslap.\n");
                    attacker->hit_player(dam);
                }
                else {
                    tell_room(room, capitalize(attacker_name)+" gets lucky as Juggernaut misses its smash attack!\n");
                }
                
                t_smash = 0;
            }
            else if(t_smash == 4)
            {
                /* tell the room of impending doom */
                tell_room(room, "You see the Juggernaut bring its tentacle about for a smash attack...\n");
                t_smash ++;
            }
            else t_smash ++;

            /* END SMASH ATTACK */



            /* THE PUNCH ATTACK */
            if(attacker && t_punch > 5)
            {

                if(1 == random(2))
                {
                    dam = random(65);
                    tell_room(room, "Dark Spuckball Juggernaut POUNDS " + capitalize(attacker_name) + " with a biznitch of a punch!\n");
                    attacker->hit_player(dam);
                }
                else {
                    tell_room(room,"Dark Spuckball Juggernaut's punch goes wild, completely missing "+capitalize(attacker_name)+".\n");
                }
                
                t_punch = 0;
            }
            else if(t_punch == 4)
            {
                /* tell the room of impending doom */
                tell_room(room, "You notice that Dark Spuckball Juggernaut is curling a tentacle, ready for a punch.\n");
                t_punch ++;
            }
            else t_punch ++;
            /* END PUNCH ATTACK */




            /* THE GUN ATTACK */
            if(attacker && t_gun > 1 + random(3))
            {

                ::heart_beat();

                if(1 == random(5))
                {
                    command("shape barrel", this_object());
                }
                t_gun = 0;
            }
            else t_gun ++;
            /* END GUN ATTACK */

            ::heart_beat();
        
        }
    }

}
