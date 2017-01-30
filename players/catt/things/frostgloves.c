inherit "obj/armor";
reset(arg) {
if(arg) return;
set_weight(3);
set_name("gloves of frost");
set_alias("gloves");
/* Changed value from 6000 to 300 -Snow */
set_value(300);
set_ac(0);
set_short("Gloves of Frost");
set_long("Gauntlets of frost that can encase your enemy in ice\n"+
        "of the purest black. Try (frost {monster}) to use.\n");
set_type("ring");
            }
init() {
   add_action("frost","frost");
::init();
       }
frost(str) {
   object victim, owner;
owner = this_player();
victim = find_living(str);
if(!str) {
   write("Your not targeting the correctly, try agian\n");
return 1;
         }
if(str == owner->query_real_name()) {
   write("The gods won't let you use this power against yourself\n");
   return 1;
                 }
if(!victim || !living(victim)) {
   write("You can't destroy that\n");
   return 1;
                                }
if(victim->query_npc()==0 && owner->query_pl_k()==0) {
    write("Catt thunders: that player doesn't have their option set!\n");
    return 1;
                                                    }
if(victim->query_npc()==0 && owner->query_pl_k()==0) {
    write("Catt thunders: You must have your option set to do that!\n");
    return 1;
                                                        }
if(owner->query_spell_point() < 30) {
   write("Your magical strength is way too low\n");
   return 1;
    }
if(environment(owner) == environment(victim)) {
write("A BLAST of cold slams into "+victim->query_real_name()+
" encasing everything in Black Ice\n"+"\n"+
      victim->query_real_name()+" breaks free from the Black Ice\n");
say(owner->query_real_name()+" causes the very air to freeze around you\n");
 victim->attacked_by(owner);
/* Changed to conform to spell damage rules  -Snow */
victim->hit_player(15);
owner->add_spell_point(-30);
return 1;
}
}
