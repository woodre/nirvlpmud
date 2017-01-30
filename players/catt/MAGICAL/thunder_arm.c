inherit "obj/armor";
reset(arg) {
if(arg) return;
set_weight(3);
set_name("platemail of thunder");
set_alias("platemail");
set_value(3000);
set_ac(3);
set_type("armor");
set_short("Platemail of Thunder");
set_long("Platemail of Thunder is the legendary platemail Lang,\n"+
         "who was a major power before he mysteriously disappeared\n"+
         "from home and family. The armor is a brilliant grey, and while\n"+
         "not the most beautiful in coloration it is excellently crafted\n"+
         "and has some unknown power within. It is rumored that whenever\n"+
         "fought a battle that great Claps of thunder could be heard. If\n"+
         "that power could be tapped you could be very strong indeed.\n");
::reset();
            }
init() {
  add_action("clap","clap");
::init();
       }
clap(str) {
   object victim, owner;
owner = this_player();
victim = find_living(str);
if(!str) {
    write("Your not clapping towards the right target try again\n");
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
write("You clap your hands and a crack of thunder rumbles throught the air\n"+
       "putting almost all of its force on "+victim->query_real_name()+"\n");
 say(owner->query_real_name()+" claps his hands and thunder rumbles in the\n"+
     "air\n");
 victim->attacked_by(owner);
/* Changed damage from 35 to 15  -Snow */
victim->hit_player(15, "other|sonic");
owner->add_spell_point(-30);
return 1;
}
}
