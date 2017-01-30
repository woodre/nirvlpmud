inherit "/obj/monster";
object ob, ob2, ob3, gold;
int which;

reset(arg) {
  ::reset(arg);
  
  gold = clone_object("obj/money");
    gold->set_money(2200 + random(1000));
    move_object(gold,this_object());
  ob = clone_object("/players/saber/weapons/ascythe.c");
    move_object(ob,this_object());
  ob2 = clone_object("/players/saber/armor/arateam.c");
    move_object(ob2, this_object());
  ob3 = clone_object("/players/saber/armor/dark_chainmail.c");
    move_object(ob3, this_object());
    
if (!arg){

which = random(3);
     init_command("wear amulet");
     init_command("wield scythe");
     init_command("wear chainmail");
     set_name("guard");
if(which == 0)  { set_short("An unholy warrior of arate");  }
if(which == 1)  { set_short("A member of the unholy guard");  }
if(which == 2)  { set_short("A sentinel of arate");  }
     set_alt_name("warrior");
     set_alias("sentinel");
     set_race( "human");
     set_long(
        "The temple of Arate is guarded by many forces, including \n"+
        "the unholy guard.  The guard is a force of evil fighting \n"+
        "an eternal battle verses the force of good.\n");
which = random(2);
if(which == 0)  {  set_gender("male");    }
if(which == 1)  {  set_gender("female");  }
     set_level(20);
     set_ac(17 + random(3));
     set_wc(29 + random(3));
     set_hp(500 + random (50));
     set_al(-900);
     set_aggressive(0);
     set_chat_chance(8);
     set_a_chat_chance(8);
     load_chat("The distant sound of chanting washes over you.\n");
     load_chat("The musky sweet smell of incense invades your senses.\n"); 
     load_a_chat("The distant sound of chanting washes over you.\n");
     load_a_chat("The musky sweet smell of incense invades your senses.\n");
     load_a_chat(short()+" casts a dark spell of healing.\n"+
                 short()+" looks stronger.\n");
     load_a_chat(short()+" screams \"\Call out the guards!\"\n");
     load_a_chat(short()+" blocks with "+this_object()->query_possessive()+" scythe.\n");
     set_chance(10);
     set_spell_dam(30);
     set_spell_mess1("\n"+short()+" calls down the power of Arate upon "+
                         this_object()->query_possessive()+" foe!\n");
     set_spell_mess2("\n"+short()+" calls down the power of Arate upon you!\n");

set_object(this_object());
   set_function("hi_there");
   set_type("arrives");
   set_match("");
        }
        }

hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  say(short()+" glares at "+who+".\n");
}  }

init()  {
  ::init();
   add_action("pass","south");
   add_action("pass","east");
   add_action("pass","west");
        }

pass()  {
if(this_player()->query_alignment() < 0)  {
  say(short()+" steps in front of "+this_player()->query_name()+".\n"+
      short()+" glares and says \"\Good shall not pass...\"\n");
  return 1;
        }
say(short()+" lets "+this_player()->query_name()+" pass.\n");
        }
