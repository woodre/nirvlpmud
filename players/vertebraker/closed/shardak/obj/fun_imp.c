void chg_cond();
/*
 * A promotion for Shardak
 */


inherit "/obj/monster";

object *x;
string cond;

void
reset(status arg)
{
    if(arg) return;

    set_level(1);
    set_hp(10000);
    set_name("imp");
    set_race("imp");
    set_gender("creature");
    set_chat_chance(5);
    load_chat("The imp grins darkly at you.\n");
    load_chat("The imp speaks to itself.\n");
    load_chat("The imp's right hand glows strangely.\n");

    chg_cond();
}

void
chg_cond()
{
    switch(random(6))
    {
      case 0: cond = "grinning"; break;
      case 1: cond = "laughing"; break;
      case 2: cond = "chortling"; break;
      case 3: cond = "chuckling"; break;
      case 4: cond = "squirming"; break;
      case 5: cond = "smiling"; break;
    }

    call_out("chg_cond", 100 + random(100));    

}
      

string
short()
{
    return "A fiendish imp (" + cond + ")";
}

void
attacked_by(object ob)
{
    tell_room(environment(), 
      "The imp is protected by a strange aura.\n");
     if(attacker_ob) { attacker_ob->stop_fight(); attacker_ob->stop_fight(); }
    stop_fight();
    stop_fight();
}

/*
void
heart_beat()
{

    ::heart_beat();

    while(attacker_ob)
    {
      attacker_ob->stop_fight();
      stop_fight();
    }

    heal_self(100000);
}
*/

void
long()
{
    write("\
A strange little imp, with a glint in his eye, and a dark\n\
cloak tossed gingerly across his shoulders.  His hair is\n\
blotchy and dark, and he holds a finger towards you, as though\n\
he is about to speak.  You spy a mark carved into his right\n\
hand and wonder about it.\n");

    if(!x) x = ({ });

    if(this_player())
    if(member_array(this_player(), x) == -1) { x += ({ this_player() });
    call_out("Speak", 3 + random(3), this_player());
    }
}

void
Speak(object ob)
{
    if(!ob) return;

    tell_object(ob, "\
The imp tells you:\n\
  \"Soon.. Soon the Master will rise!  And a world of Hell and\n\
    damnation will be visited upon the world once again.\"\n\n\
The strange creature's devilish cackle rings in your ear.\n\n");
}

status
query_prevent_shadow()
{
    return 1;
}

void
show_stats()
{
    write("Hello there!\n");
}
