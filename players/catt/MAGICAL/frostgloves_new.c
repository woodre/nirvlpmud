inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_weight(3);
set_name("gloves of frost");
set_alias("gloves");
set_value(300);
set_ac(0);
set_short("Gloves of Frost");
set_long("Gauntlets of frost that can encase your enemy in ice\n"+
        "of the purest black. Try (frost {monster}) to use.\n");
set_type("gloves");
}
init() {
   add_action("frost","frost");
::init();
}
frost(str) {
   int dam;
   object victim, owner;
   owner = this_player();
if(!str) {
   write("Your not targeting the correctly, try again\n");
   return 1;
         }
victim = find_living(str);
if(str == owner->query_real_name()) {
   write("The gods won't let you use this power against yourself\n");
   return 1;
}
if(!victim)  {
  write("you can not do that.\n");
   return 1;
}
if(!victim || !living(victim)) {
   write("You can't destroy that\n");
   return 1;
}
if(!victim->query_npc()) {
  write("You may not do that.\n");
    return 1;
}
if(owner->query_spell_point() < 30) {
   write("Your magical strength is way too low\n");
   return 1;
    }
/*
if(environment(owner) == environment(victim)) {
write("A BLAST of cold slams into "+victim->query_real_name()+
" encasing everything in Black Ice\n"+"\n"+
      victim->query_real_name()+" breaks free from the Black Ice\n");
say(owner->query_real_name()+" causes the very air to freeze around you\n");
 victim->attacked_by(owner);
victim->hit_player(10, "other|ice");
owner->add_spell_point(-30);
return 1;
}
*/
   if(environment(owner) == environment(victim)) {
   dam = 15+random(15);
   owner->spell_object(victim,"Blast of Frost",({dam,"ice"}),23);
   return 1;
   }
}

query_save_flag() { return 1; }
