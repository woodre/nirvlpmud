inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("joe");
   set_level(7);
   switch(random(3)+1) {
      case 1:
         set_short("Navy G.I.Joe");
         set_long("The navy joe wears a SEAL suit to protect the country"+
           "from enemies.  He is ready to fight on sea, air and land.\n");
         set_alias("navy");
         break;
      case 2:
         set_short("Marine G.I.Joe");
         set_long("The marine joe storms the beaches to push back\n"+
            "the enemy and save the country.  He looks very brave.\n");
         set_alias("marine");
         break;
      case 3:
         set_short("Army G.I.Joe");
         set_long("The army joe fights the long battles that threaten\n"+
            "the counrty.  He strides forth confidently into battle.\n");
         set_alias("army");
         break;
   }
   set_alt_name("rand_gijoe");
   set_race("action figure");
   set_hp(105);
   set_wc(11);
   set_ac(6);
   set_al(100);
   set_chat_chance(5);
   set_a_chat_chance(10);
   load_chat("Joe says, \"I am a good soldier.\"\n");
   load_chat("Joe cleans his rifle.\n");
   load_chat("Joe says, \"Let's go save the world!\"\n");
   load_a_chat("Joe pokes you with a plastic bayonette.\n");
   load_a_chat("Joe courageously fights the good fight.\n");
   load_a_chat("Joe says, \"We'll win this war.\"\n");
   load_a_chat("Joe fights valiantly.\n");
   move_object(clone_object("/players/llew/Toys/misc/rand_joe_weapon"),this_object());
}
