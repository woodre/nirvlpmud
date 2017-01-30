inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(random(100) + 200);
   move_object(gold,this_object());
     set_name("spider");
       /* What players will see in the room  */
     set_short("Poisonous Spider");
       /* The race of the monster  */
     set_race( "spider");
       /* What players will see when they 'look' at the monster  */
     set_long("A large, dark brown, hair covered spider.  Very poisonous and dangerous.\n");
       /* The monsters level.  Be sure to check the chart for what
              the rest of its scores *should* be            */
     set_level(6);
       /* How much armor the monster has.  The higher, the harder to hit */
     set_ac(6);
       /* How well the monster attacks.  The higher, the most skilled  */
     set_wc(10);
       /* How many hit points the monster has    */
     set_hp(90);
       /* How evil/good the monster is     */
     set_al(-150);
       /* If agressive is 1, than the monster will attack others
                  even before it is attacked     */
     set_aggressive(1);
       /* The chance per heartbeat that the monster will call one
                of the load_chat() messages   */
     
       /* The chance per heartbeat that the monster is IN COMBAT
              that it will call a load_a_chat()     */
     set_a_chat_chance(40);

     load_a_chat("scree ! scree !\n");
   }
}
