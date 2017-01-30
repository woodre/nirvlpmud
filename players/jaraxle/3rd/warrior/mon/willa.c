#include "/players/jaraxle/define.h"
inherit "obj/monster.c";
#include "/players/beck/MortalKombat/MKQuestNPC.h"

reset(arg)  
{
    object gold;
    ::reset(arg);
    if(arg) return;
    set_name("Willa");
    set_alias("maiden");
    set_alt_name("willa");
    set_race("human");
    set_short("Willa, Queen of the Warrior Maidens");
    set_long(
    "A beautiful, tall, thin, yet muscular human female.  Willa is the leader\n"+
    "of the Tree-Top Village.  She commands the Warrior Maidens.\n"+
    "Willa is "+HIR+"very"+NORM+" strong and "+HIR+"commands"+NORM+" respect for her power.\n");
    set_level(20);
    set_hp(400+random(150));
    set_al(0);
set_wc_bonus(32);
    set_ac(17+random(6));
    set_aggressive(0);
    MOCO("/players/jaraxle/3rd/warrior/weaps/w_bow.c"),this_object());
    MOCO("/players/jaraxle/3rd/warrior/weaps/E_quiver.c"),this_object());
    MOCO("/players/jaraxle/3rd/warrior/weaps/P_quiver.c"),this_object());
    MOCO("obj/soul"),this_object());
    init_command("wield bow");
    set_wc(30+random(7));
    set_dead_ob(this_object());
    set_chat_chance(4);
    load_chat("Willa looks about the room.\n");
    set_a_chat_chance(15);
    load_a_chat("Willa dive-rolls left!\n");
    gold = clone_object("obj/money");
    gold->set_money(800+random(200));
    move_object(gold,this_object());
    set_spell_mess2("Willa draws multiple arrows...\n\nAn arrow strikes your chest!\n   An arrow strikes your chest!\n      An arrow strikes your chest!\n");
move_object(clone_object("/players/dragnar/MKScar/scar.c"), this_object());
}

monster_died() {
write_file("/players/jaraxle/3rd/warrior/w_kill.log",ctime(time())+" "+HIB+""+this_player()->query_name()+""+NORM+" killed Willa.\n");
  tell_room(environment(this_object()),
        "Willa falls lifeless to the ground.\n");
return 0; }     

void heart_beat()
{
    int h;
    string ATT_NAME, msg, msg2;
    ::heart_beat();
    if((70 < random(100)) && attacker_ob)  /* code by verta */
    {
      ATT_NAME = (string)attacker_ob->query_name();
      msg = "Willa draws multiple arrows...\n\n";
      msg += "An arrow strikes "+ATT_NAME+"'s chest!\n";
      msg += "   An arrow strikes "+ATT_NAME+"'s chest!\n";
      msg += "      An arrow strikes "+ATT_NAME+"'s chest!\n";
      msg2 = "Willa draws multiple arrows from her quiver. . .\n\n" +
      "An arrow strikes your chest!\n" +
      "   An arrow strikes your chest!\n" +
      "      An arrow strikes your chest!\n";
      tell_room(environment(), msg, ({ attacker_ob }));
      tell_object(attacker_ob, msg2);
      tell_object(attacker_ob,"\
\nYou feel a skip in your "+HIR+""+BLINK+"heartbeat"+NORM+"!\n");
      tell_room(environment(), 
      ATT_NAME + " gasps for "+HIW+"air"+NORM+"!\n",
      ({ attacker_ob })); /* tell everybody, exclude attacker */
      h = ((int)attacker_ob->query_hp() / 2); /* calc half hit pts */
      attacker_ob->add_hit_point(-h); /* reduce hps */
      if((int)attacker_ob->query_hp() < 1) /* add_hp don't kill em, so */
        attacker_ob->death(); /* kill em !*/
    } /* :) */
      
}
