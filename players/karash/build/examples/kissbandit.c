/*
 *  A masked bandit!  It is the feared KISSING bandit!  (run!)
 *  Read DREAM.c after this.
 *                                                  -- Saber
 */

/* This gives you ALL the code of monster.c   */
inherit "/obj/monster";

/* Ignore this for now         */
reset(arg) {
   ::reset(arg);
   if (!arg) {

/* Declaring the objects ob, ob2 and ob3     */
object ob,ob2,ob3;

/* This clones an object and moves it to the monster.   */
  ob2 = clone_object("/players/saber/weapons/rapier.c");
move_object(ob2,this_object());
  ob3 = clone_object("/players/saber/armor/smile.c");
move_object(ob3,this_object());
  ob = clone_object("/players/saber/stuff/rose.c");
move_object(ob,this_object());

       /* The name of the monster  */
     set_name("bandit");
       /* What players will see in the room  */
     set_short("The Kissing Bandit");
       /* The race of the monster  */
     set_race( "human");
       /* What players will see when they 'look' at the monster  */
     set_long("A tall, well dressed bandit with a sparkle in his eyes\n"+
        "and a smile on his lips.\n");
       /* The monsters level.  Be sure to check the chart for what
              the rest of its scores *should* be            */
     set_level(6);
       /* How much armor the monster has.  The higher, the harder to hit */
     set_ac(6);
       /* How well the monster attacks.  The higher, the most skilled  */
     set_wc(9);
       /* How many hit points the monster has    */
     set_hp(90);
       /* How evil/good the monster is     */
     set_al(-150);
       /* If agressive is 1, than the monster will attack others
                  even before it is attacked     */
     set_aggressive(0);
       /* The chance per heartbeat that the monster will call one
                of the load_chat() messages   */
     set_chat_chance(20);
       /* The chance per heartbeat that the monster is IN COMBAT
              that it will call a load_a_chat()     */
     set_a_chat_chance(25);

     load_chat("Bandit says: Ah ha!  A new object of affection!\n");
     load_chat("Bandit sniffs a rose.\n");
     load_chat("The kissing bandit looks at you.\n"+
        "Bandit says: Hello, my name is Richard.\n"+
        "Remember that, because you'll be screaming it later tonight!\n");
     load_chat("Bandit winks at you.\n");
     load_chat("Bandit leans forward and kisses you upon the lips!\n");

     load_a_chat("Bandit leans forward and kisses you upon the lips!\n");
     load_a_chat("Bandit winks at you.\n");
     load_a_chat("Bandit smiles wickedly at you.\n");
     load_a_chat("Bandit says: You can not kill the power of love!\n");
   }
}
