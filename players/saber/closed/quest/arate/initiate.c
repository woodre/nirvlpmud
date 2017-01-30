inherit "/obj/monster";
object ob, gold;
int which;

reset(arg) {
  ::reset(arg);
  
  gold = clone_object("obj/money");
    gold->set_money(101 + random(100));
    move_object(gold,this_object());
  ob = clone_object("/players/saber/armor/arateam.c");
    move_object(ob, this_object());
    
if (!arg){

which = random(2);
     init_command("wear amulet");
     set_name("initiate");
if(which == 0)  { set_short("An initiate of arate");  }
if(which == 1)  { set_short("A member of the initiate circle");  }
     set_alias("member");
     set_race("human");
     set_long(
        "Young men and women of promise are brought to the temple of\n"+
        "Arate to be trained for the dark priesthood.  The initiates\n"+
        "are the lowest rank of this unholy clergy, young in the ways\n"+
        "of their dark power yet devoted to their eternal battle verses\n"+
        "the forces of good.\n");
which = random(2);
if(which == 0)  {  set_gender("male");    }
if(which == 1)  {  set_gender("female");  }
     set_level(10);
     set_wc(13  + random(2));
     set_ac(7   + random(2));
     set_hp(125 + random (50));
     set_al(-900);
     set_aggressive(0);
     set_chat_chance(8);
     set_a_chat_chance(8);
     load_chat("The distant sound of chanting washes over you.\n");
     load_chat("The musky sweet smell of incense invades your senses.\n");
     load_chat("The initiate chants \"\Ra na ka mu ne so ah re to ni ki si\"\n"); 
     load_a_chat("The distant sound of chanting washes over you.\n");
     load_a_chat("The musky sweet smell of incense invades your senses.\n");
     set_chance(10);
     set_spell_dam(25);
     set_spell_mess1("\n"+short()+" chants \"\Re ke su fi nah\"\n");
     set_spell_mess2("\n"+short()+" chants \"\Re ke su fi nah\"\n"+
                      "You feel your head explode with fire.\n");

        }
        }
