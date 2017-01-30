#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit MONSTER;
string pendant;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("ash");
   set_alias("ashley");
   set_alt_name("hero");
   set_gender("male");
   set_race("human");
   set_short("Ashley J. Williams");
   set_long(
      "Ash Williams stands around six feet tall and has blackish hair.  He\n"+
      "looks as if he has been through quite a bit recently, and he has an\n"+
      "assortment of scars and bloodstains covering his body, almost as\n"+
      "tattoos.  He is holding a large chainsaw and he is wearing a dark blue\n"+
      "shirt over a pair of tattered dark brown pants.  His eyes are alit with\n"+
      "both fear and confidence.. you sense that he is a man of some importance.\n");
   if(!present("chainsaw",TO)) MOCO(ED1OBJ+"chainsaw.c"),TO);
    add_money(600+random(200));
    init_command("wield chainsaw");
    enable_commands();
    set_dead_ob(TO);
    set_level(19);
    set_wc(24+random(5));
    set_ac(10+random(13));
    set_hp(400+random(151));
    set_chat_chance(10);
    load_chat("Ash says: Linda.........\n");
    load_chat("Ash says: I must get the pendant!\n");
    load_chat("Ash says: Who are you?!\n");
    load_chat("Ash checks the gasoline on the chainsaw.\n");
    load_chat("Ash paces around the room.\n");
    load_chat("Ash says: There's got to be another way out of here!\n");
    load_chat("Ash says: The bridge is out.....\n");
    load_a_chat("\n        Ash kicks his opponent in the groin!\n\n");
    load_a_chat("Ash says:  Groovy.\n");
    load_a_chat("\n  Ash slices deeply into his opponent with his chainsaw!\n\n");
    load_a_chat("Ash checks the gasoline on the chainsaw!\n");
    load_a_chat("Ash throws a chain at his opponent!\n"); }

monster_died() {


  say("\nAsh grumbles... 'I'm sure we'll meet again...'\n\n");
  say("Ash says: 'Oh yeah.. may as well keep my things too... See ya...\n"+
    "Ash hits a section of the wall and disappears.\n");
  ENV(TO)->get_outta_here();
  destruct(present("corpse",ENV(TO)));
  return 0; }
catch_tell(string str) {
    string msg;
    object chainsaw;
    chainsaw = present("chainsaw",TO);
    pendant = present("silvery pendant",TO);
    if(sscanf(str,"%s gives pendant to Ash",msg)) {
        say(
"\nAsh murmurs: 'Linda..  You must have given her final peace...  Please accept\n"+
"              this with my gratitude.... I located this secret passage when\n"+
"              I searched the catacombs below this blasted cabin...'\n\n");
say("Ash punches a section of the wall and it spins around!\n"+
"Ash says: 'Beyond is where I have hidden the Necronomicon.  Open it and you can leave this\n"+
"           place...   Good Luck....'\n"+
"Ash waves you along and then he disappears into the shadows.\n\n");
        ENV(TO)->get_outta_here();
destruct(chainsaw);
destruct(pendant);
destruct(TO);
        return 1; }
    return 1; }
