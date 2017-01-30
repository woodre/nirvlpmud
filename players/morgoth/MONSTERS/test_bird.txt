/* This gives you ALL the code of monster.c   */
inherit "/obj/monster";

/* Ignore this for now         */
reset(arg) {
   ::reset(arg);
   if (!arg) {

/* Declaring the objects ob, ob2 and ob3     */
object ob,ob2,ob3,gold;

/* This clones an object and moves it to the monster.   */
  ob2 = clone_object("/players/morgoth/WEAPONS/claws.c");
move_object(ob2,this_object());
  ob3 = clone_object("/players/morgoth/ARMOR/feathers.c");
move_object(ob3,this_object());
  ob = clone_object("/players/morgoth/OBJ/roses.c");
move_object(ob,this_object());
  gold = clone_object("obj/money");
  gold->set_money(10);
move_object(gold,this_object());

       /* The name of the monster  */
     set_name("bird");
       /* What players will see in the room  */
     set_short("A bird");
       /* The race of the monster  */
     set_race( "animal");
       /* What players will see when they 'look' at the monster  */
     set_long("A small, yellow and blue bird.\n");
       /* The monsters level.  Be sure to check the chart for what
              the rest of its scores *should* be            */
     set_level(1);
       /* How much armor the monster has.  The higher, the harder to hit */
     set_ac(2);
       /* How well the monster attacks.  The higher, the most skilled  */
     set_wc(3);
       /* How many hit points the monster has    */
     set_hp(10);
       /* How evil/good the monster is     */
     set_al(150);
       /* If agressive is 1, than the monster will attack others
                  even before it is attacked     */
     set_aggressive(0);
       /* The chance per heartbeat that the monster will call one
                of the load_chat() messages   */
     set_chat_chance(20);
       /* The chance per heartbeat that the monster is IN COMBAT
              that it will call a load_a_chat()     */
     set_a_chat_chance(25);

     load_chat("chirp....chirp....\n");

   }
}
