inherit "/obj/monster";  /*  the spirit demon */
object xx;

reset(arg){
  ::reset(arg);
  if(!arg){

  set_name("spirit demon");
  set_short("A spirit demon");
  set_long(
"What you look upon is the tortured spirit of a demon.  It has a narrow\n"+
"head with sharp claws and horns, and two jagged rows of teeth.  It has\n"+
"no legs, instead it drifts softly above the ground.  Its body is almost\n"+
"entirely translucent, allowing you to see flames through it.\n");
  set_race("spirit");
  set_gender("creature");
  set_level(19);
  set_ac(4);
  set_wc(100);
  set_wc_bonus(7);
  set_hp(200);
  set_aggressive(1);
  set_al(-1000);
  set_heal(3,1);
  set_chat_chance(1);
  load_chat("The spirit screams in agony!\n");
  load_chat("The spirit cries softly.\n");
  load_chat("The spirit drifts around.\n");
  set_dead_ob(this_object());
  call_out("love", 30);
  }
}

id(str){ return (::id(str) || str == "spirit demon" || str == "daemon" ||
str == "spirit daemon" || str == "demon"); }

monster_died()
{
  object pc;
  tell_room(environment(),
  "The spirit of the demon cries out in pain...\n"+
  "The essence of the spirit drifts away...\n"+
  "Left in its place is a small gold object.\n");
  pc = clone_object("/players/zeus/realm/OBJ/talisman_piece.c");
  pc -> set_creator(attacker_ob->query_real_name());
  move_object(pc, environment());
  if(present("corpse", environment()))
    destruct(present("corpse", environment()));
  write_file("/players/zeus/log/Q", ctime(time())+" -  "+
    capitalize((string)attacker_ob->query_real_name())+
    " killed a demon spirit.\n");
}

love(){
  string w;
  if(!environment()) return;
  call_out("love", 30);
  if(!xx) return;
  if(xx->query_ghost()) return;
  if(!sscanf(file_name(environment(xx)), 
    "players/zeus/realm/d/r%s", w))
	return;
  move_object(this_object(), environment(xx));
  tell_room(environment(), "The demon spirit screams in agony!\n");
  this_object()->attack_object(xx);
}

scream(){
  if(!present(attacker_ob, environment())) return;
  tell_room(environment(),
    "The demon spirit claws at "+attacker_ob->query_name()+"'s soul!\n",
    ({ attacker_ob }));
  tell_object(attacker_ob, "The demons spirit claws at your soul!\n");
  attacker_ob->hit_player(50);
}

heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
  xx = attacker_ob;
  if(!random(7))
    scream();
}
