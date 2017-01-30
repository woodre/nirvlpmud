inherit "/obj/monster.c";

/* Demonstration monster by Mizan
 *
 * This demo will illustrate examples of:
 * - a monster which flees if facing combat
 *
 * - an example of an overloaded add_action() native to people who
 *   happen to be in the same room with the monster.
 */


init() 
{
    ::init();

    /* You can add your add_actions here. Just don't forget to include
     * the init() call to the superclass, which is given the :: operator.
     * If you fail, the monster will not h its full functionality as defined
     * in the superclass /obj/monster.c, which in turn also extends
     * from /obj/living.c . In summary, it would bad if the above line went
     * missing somehow.
     */
    add_action("hugme_action","hug");
}


/* This is the action that is called when someone hugs us */
hugme_action(str) 
{
    /* if we are not hugging the cactus, bounce out. This is a very simple 
     * example of course. 
     */
    if(str!="cactus") return 0;

    write("You hug the cactus. OUCH!!\n");
    say(capitalize(this_player()->query_name())+" hugs the cactus. You wince in pain just looking at it.\n");
    return 1;
}


reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("a cactus");
    set_race("cactus");
    set_short("A small, animated golden-barrel cactus");
    set_long("This is a stout green plant with yellow spikes all over it.\n"+
    "Yowsa! Looks painful if you sat on it.\n");
    set_level(2);
    set_hp(30);
    set_al(0);
    set_ac(6);
    set_wc(3);
    set_chance(10);
    set_spell_dam(2);
    set_spell_mess1("The cactus goes: Hey buddy! Do ya mind?");
    set_spell_mess2("The cactus pokes you. OUCH!!");
    set_chat_chance(5);
    load_chat("The cactus looks wistfully at you.\n");
    load_chat("The cactus says: All I want is to be hugged.\n");
    load_chat("The cactus says: A roast beef sandwich would be nice too.\n");
    load_chat("The cactus gets lost in a daydream.\n");
    treasure=clone_object("obj/money.c");
    treasure->set_money(60);
    move_object(treasure, this_object());
}

heart_beat()
{
    ::heart_beat();
    /* just like before in init(), don't forget to call the superclass. */


    /* what's going on below looks nasty. But it is a sequence of logical
     * checks. It may not be the most compact code, but it makes NO ASSUMPTIONS
     * and that is actually good. 
     * First it says... Do we have an attacker?
     * AND then does this object have an environment()?
     * AND does the attacker have an environment()?
     * AND does the attacker's environment equal ours?
     * If so... we run a random command and display an emote.
     * The level of checking on here seems anal, but if ANYTHING in the heart
     * beat fails, the player will have a monster they can whomp on to their
     * heart's content. We don't want that so it pays to be anal about this.
     */
    if(this_object()->query_attack() &&
       environment(this_object()) &&
       environment(this_object()->query_attack()) &&
       environment(this_object()) == environment(this_object()->query_attack()))
    {
        say("The cactus freaks out and tries to run away!\n");

        /* this random_move() is a method defined in monster.c */
        this_object()->random_move();

    }
}
