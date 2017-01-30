inherit "room/room";
#include "/players/zeus/closed/all.h"
#define LENGTH 5

object d, r;

reset(arg){
 if(arg) return;

  d = clone_object("obj/monster");
  r = clone_object("/obj/armor.c");
  r -> set_name("robe");
  r -> set_short("A baggy brown robe");
  r -> set_long("This is a baggy brown robe with a large hood.  It\n"+
    "is made from a rough material and looks very old.\n");
  r -> set_weight(1);
  r -> set_ac(1);
  move_object(r, d);
  command("wear robe", d);

  call_other(d, "set_name", "traveler");
  call_other(d, "set_alias", "man");
  call_other(d, "set_short", "An old traveler");
  call_other(d, "set_race", "human");
  call_other(d, "set_gender", "male");
  call_other(d, "set_long",
    "This is an old man who has traveled all over the areas of Nirvana.\n"+
    "He is wearing a long brown robe which hangs loosely over his body.\n"+
    "His hair is white, and he has a solemn face, but he exudes an aura\n"+
    "of quiet grace and tranquility.  You can ask him about the areas of\n"+
    "Nirvana.  Type 'ask about <name>' where name is the name of the\n"+
    "wizard's area you want information on.  To see which areas he has\n"+
    "been to, 'ask where have you been'.\n");
  call_other(d, "set_level", 14);
  call_other(d, "set_ac", 111);
  call_other(d, "set_wc", 18);
  call_other(d, "set_hp", 5000);
  call_other(d, "set_al", 200);
  call_other(d, "add_money", 1+random(200));
  call_other(d, "set_chat_chance", 1);
  call_other(d, "set_a_chat_chance", 1);
  call_other(d, "load_chat", "The old traveler looks around with a smile.\n");
  call_other(d, "load_chat", "The old traveler glances up at you.\n");
  call_other(d, "load_chat", "The old traveler smiles softly.\n");
  call_other(d, "load_chat", "The old traveler checks his pockets.\n");
  call_other(d, "load_chat", "The old traveler glances north.\n");
  call_other(d, "load_chat", "The old traveler glances down at the ground.\n");
  call_other(d, "load_a_chat", 
    "The old traveler asks, \"Why do you do this?\"\n");
  call_other(d, "load_a_chat", 
    "The old traveler asks, \"What have I done?\"\n");
  call_other(d, "load_a_chat", 
    "The old traveler says, \"This is not right.\"\n");
  move_object(d, this_object());

  short_desc="The adventurers guild";
  long_desc =
"This is a side area of the adventurers guild.  There are numerous\n"+
"tables and chairs for people to relax on.  Other buildings of the\n"+
"village can be seen all around.  The sun is shining overhead.\n";
  items=({
  "tables", "The tables are made of oak and look rather old",
  "chairs", "The chairs look old yet rather comfortable",
  "sun",  "The sun is shining down upon the village",
  "buildings", "Many other buildings of the village can be seen"+
  " in all directions",
  });
  set_light(1);
  dest_dir=({ "/room/adv_guild.c", "east"  }); 
}

void init(){
  ::init();
  add_action("info_cmd", "ask");
}

info_cmd(str){
  int x, c, suze;
  string hmm, test, heh, a, b;
  if(!present(d, this_object())) return 0;
  if(sscanf(str, "%swhere%s", a,b))
  {
    c = 1;
    test = get_dir("/open/info/");
    suze = sizeof(test);
    write(
    "\nThe old traveler says, \"These are the areas i've been to:\"\n"+GRN+
    " - --- ------- -- -------  ------------- --- --- ------\n\n  "+NORM);
    for(x = 0; x < suze; x++)
    {
      if(sscanf(test[x],"%s.nfo",hmm))
      {
        write(pad(capitalize(hmm), 12));
        if(c == LENGTH)
        {
          write("\n  ");
          c = 0;
        }
        c++;
      }
    } /* end for */
    write(GRN+"\n\n - --- ------- -- ------- "+
      " ------------- --- --- ------\n\n"+NORM);
    say("The traveler says something to "+TP->QN+".\n");
  }
  else if(sscanf(str, "about %s", b))
  {
    heh = lower_case(b);
    if(file_size("/open/info/"+heh+".nfo") > 0)
    {
      cat("/open/info/"+heh+".nfo");
      say("The traveler says something to "+TP->QN+".\n");
    }
    else return 0;
    return 1;
  }
  return 1;
}
