#include <ansi.h>
inherit "/obj/monster";
string b,c;

reset(arg){
  ::reset(arg);
  if (!arg){

  object e,f,g,h,i;
  i = clone_object("/players/zeus/desert/OBJ/quiver.c");
  move_object(i, this_object());
  h = clone_object("/players/zeus/desert/OBJ/bow.c");
  move_object(h, this_object());
  init_command("wield bow");
  g = clone_object("/players/zeus/desert/OBJ/boots.c");
  move_object(g, this_object());
  init_command("wear boots");
  f = clone_object("/players/zeus/desert/OBJ/cap.c");
  move_object(f, this_object());
  init_command("wear cap");
  e = clone_object("/players/zeus/desert/OBJ/tunic.c");
  move_object(e, this_object());
  init_command("wear tunic");

  b =({ "An agile", "A dangerous", "A muscular", "A fearsome", "A sneaky", });
  c =({ "chest", "arm", "shoulder", "leg", "thigh", "hand", "foot" });

  set_name("hunter");
  set_short(b[random(sizeof(b))]+" hunter");
  set_gender("male");
  set_race("elf");
  set_long(
    "This elven hunter appears as though he is traveling through the\n"+
    "desert.  He is clad in a tightly woven white tunic, pants, boots,\n"+
    "and a nice cap.  Slung over his back is a bow and a quiver of\n"+
    "arrows.  He looks as though he wants to be left alone.\n");
  set_level(17);
  set_ac(12);             /* mguide 14   for level 17 */
  set_wc(24);             /* mguide 24  */
  set_hp(325);            /* mguide 425 */
  set_al(200);
  set_chat_chance(3);
  set_a_chat_chance(3);
  load_chat("The elven hunter checks his quiver.\n");
  load_chat("The elven hunter peers off into the distance.\n");
  load_chat("The elven hunter surveys the area.\n");
  load_chat("The elven hunter glances at you briefly.\n");
  load_a_chat("The elven hunter says, \"You asked for it.\"\n");
  load_a_chat("The elven hunter says, \"I think not.\"\n");
/* 03/26/06 Earwax: switched to use standard mob wandering
  call_out("wander", 10);
*/
  set_wander(30);
  set_wander_interval(30);
  set_dead_ob(this_object());
  }
}

id(str){ return str == "zeus_inculta_npc"
             || str == name || str == alt_name || str == alias; }

wander(){
  int a;
  if(attacker_ob) return;
  a = random(4);
  switch(a)
  {
  case 0:   init_command("north");  break;
  case 1:   init_command("east");  break;
  case 2:   init_command("south");  break;
  case 3:   init_command("west");  break;
  }
/*
  call_out("wander", 20);
*/
}

heart_beat(){
  ::heart_beat();
  if(!environment())
    return;
  if(!attacker_ob)
    return;
  if(0 == random(4))
  {
    string q;
    int iaeht;
    iaeht = 0;
    if(!random(5))
      iaeht = 1;
    if(!present(attacker_ob, environment())) return;
    q = c[random(sizeof(c))];
    if(iaeht)
      tell_object(attacker_ob, "\n");
    tell_object(attacker_ob,
      "The elven hunter hits you in the "+q+" with an arrow!\n");
    if(iaeht)
      tell_object(attacker_ob, RED+"Blood pours from the wound!\n\n"+NORM);
    tell_room(environment(),
      "The elven hunter hits "+attacker_ob->query_name()+
      " in "+attacker_ob->query_possessive()+" "+q+" with an arrow!\n",
      ({ attacker_ob }));
    attacker_ob->hit_player(20, "other|zeus"); /* by v */
    if(iaeht)
      attacker_ob->hit_player(10, "other|zeus"); /* by v */
  }
}

monster_died()
{
  if(!(random(8)))
    move_object(clone_object("/players/fred/closed/bloodfist/obj/gem.c"), environment());
}
