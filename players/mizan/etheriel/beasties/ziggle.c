inherit "/players/mizan/core/monster.c";
int hps;

reset(arg)
{
   object treasure;
   object heal;
   ::reset(arg);
   if(arg) return;
   set_name("ziggle");
   set_alias("ziggle");
   set_short("A smelly Ziggle");
   set_level(5);
   set_hp(75);
   set_al(640);
   set_wc(9);
   set_ac(5);
   set_aggressive(0);
   load_chat("Something smells REALLY bad around here...\n");
   load_chat("Ziggle goes: Gloop!\n");
   load_chat("Ziggle burps noisily.\n");
   heal=clone_object("players/mizan/etheriel/heals/half-note.c");
   move_object(heal,this_object());
   enable_commands();
   set_heart_beat(1);
}

long() {
  write("This thing called 'ziggle' is a strange creature... fleshy and somewhat\n"+
	"organic in nature like yourself (compared to a Boofer for example...\n"+
	"whatever it's made of!) but that's where the similarity ends.\n"+
	"It's very hard to explain, see... like it has no eyes, and appears\n"+
	"to be just a stomach, a nose, and a mouth with a thick, blocky body.\n");
  ::long();
}

heart_beat(){
   object attacker,room;
   string attacker_name;
   ::heart_beat();
   hps=this_object()->query_hp();
   room=environment(this_object());
   if(room) {
   attacker=this_object()->query_attack();
   if(attacker){
      attacker_name=attacker->query_real_name();
      if(present(attacker_name,environment(this_object()))){
/*
        if(1 == random(5) && (attacker->query_level()) > 5) {
         if(!present("igglerot", attacker)) {
            object mokbeast;
	    mokbeast=clone_object("players/mizan/etheriel/items/igglerot.c");
	    move_object(mokbeast, attacker);
            tell_room(room, capitalize(attacker_name)+" contracts Igglerot from Ziggle!\n");
          }
        }
*/
        if(1 == random(4) && (attacker->query_level()) > 5) {
          tell_room(room, "Ziggle dealt a devastating blow to "+capitalize(attacker_name)+".\n");
          attacker->hit_player(random(40));
        }
        if(1 == random(5) && (attacker->query_level()) > 5) {
          tell_room(room, "Ziggle scares the heck out of "+capitalize(attacker_name)+".\n");
          attacker->run_away();
        }
      }
   }
   }
}
