inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/Tracking-D.c"

int hps;

reset(arg)
{
    object treasure;
    object heal;

    remove_call_out("fake_beat");
    call_out("fake_beat", 1);
    ::reset(arg);
    if(arg) return;
    set_name("betelgeuse");
    set_race("betelgeuse");
    set_alias("beetlejuice");
    set_short("Betelgeuse (Beetlejuice)");
    set_level(20);
    set_hp(510);
    set_al(-340);
    set_wc(27);
    set_ac(18);
    set_aggressive(0);
    set_chat_chance(15);
    load_chat("Betelgeuse goes: IT's SHOWTIME!\n");
    load_chat("Betelgeuse goes: Hey baby! Why dontcha lay down by MY side!\n");
    load_chat("Betelgeuse says: Why did the chicken cross the road?  ...cuz he FELT like it!\n");
    load_chat("Betelgeuse pulls his brain out of his head. Gross.\n");
    load_chat("Betelgeuse mumbles: That Mizan guy is a sicko!\n");
    load_chat("Betelgeuse says: I'm gonna rip his brains out when I get him...\n");
    load_chat("Betelgeuse picks his nose.\n");
    heal=clone_object("players/mizan/etheriel/heals/zagnuts.c");
    move_object(heal,this_object());
    move_object(clone_object("players/mizan/etheriel/heals/dirtbag.c"), this_object());
    move_object(clone_object("players/mizan/etheriel/items/microbe-wand.c"), this_object());
    move_object(clone_object("players/mizan/etheriel/heals/quarter-note.c"), this_object());
    enable_commands();
}

long() 
{
  write("Dressed in a tacky, dirty, slimy, and generally beat-up 'suit',\n"+
	"Betelgeuse looks more like a used car salesman rather than the\n"+
	"Bio-exorcist that he claims to be. Definitely not native to this\n"+
	"realm, his crude manners and foul mouth leave you unimpressed.\n");
  ::long();
}

fake_beat()
{
   object attacker,room;
   string attacker_name;
   string munchie;
   room=environment(this_object());
   attacker=this_object()->query_attack();
   if(attacker){
      attacker_name=attacker->query_real_name();
      if(present(attacker_name,environment(this_object()))){
        if(1 == random(20) && !present("mokbeast", room)) {
          object mokbeast;
	  mokbeast=clone_object("players/mizan/etheriel/beasties/mokbeast.c");
	  move_object(mokbeast, room);
          tell_room(room, "Betelgeuse pulls a Mokbeast out of his armpit and it joins the fray!\n");
	  mokbeast->attack_object(attacker);
        }
        if(1 == random(30) && hps < 180) {
          munchie=call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
          tell_room(room, "Betelgeuse eats "+munchie+" and goes: Ahhh!\n");
          this_object()->heal_self(30);
        }
        if(1 == random(25)) {
          tell_room(room, "Betelgeuse looks at "+capitalize(attacker_name)+" and screams: Boo!\n");
          attacker->run_away();
        }
        if(hps < 100) {
          munchie=call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
          command(munchie, this_object());
        }
        if(1==random(50)) {
          move_object(clone_object("players/mizan/etheriel/environs/exploder.c"), room);
          tell_room(room, "Betelgeuse cackles maniacally and drops something invisible.\n");
        }
      }
   }
  remove_call_out("fake_beat");
  if (environment())
    call_out("fake_beat", 2);
}
