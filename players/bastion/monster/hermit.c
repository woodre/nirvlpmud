
#define prompt say("->> ")
#include "living.h"
string alias, info;

short() { return "an old hermit"; }

get() { return 0; }

long() {
     write("He is a kindly and very old man. He smiles at you.\n");
}


reset(arg) {
     object ob;
     if(arg) 
          return;
     name="hermit";
     alias="man";
     cap_name="Hermit";
     msgout="leaves";
     msgin="enters";
     level=20;
     is_npc=1;
     alignment=-100000;
     weapon_class=40;
     wc_bonus=-15;
     max_hp=3300;
     hit_point=3300;
     experience=1500000;
     mmsgout="disappears in a puff of smoke";
     mmsgin="arrives in a puff of smoke";
     armor_class=1000;
     ac_bonus=-750;
     enable_commands();
     spell_points=2000;
     ob=clone_object("obj/soul");
     move_object(ob, this_object());
}

id(str) { return str==name || str==alias || str==info; }

query_info() { return info; }

catch_tell(str) {
     object who;
     string a, b, c, you;
     who=this_player();
     if(!who)
          return;
     if(sscanf(str, "%s gives %s to Hermit.", a, b)==2 ||
        sscanf(str, "%s gives %s to Man.", a ,b)==2) {
          object ob, ob2;
          ob=present(b, this_object());
          if(!ob || !call_other(ob, "id", "staff of wizardry"))
               return;
          destruct(ob);
          ob2=clone_object("players/bastion/obj/quest_ob");
          ob2->set_who(call_other(this_player(), "query_real_name"));
          move_object(ob2, environment(this_object()));
          call_out("quest_done", 3); }
     if(sscanf(str, "%s hello%s", a, b)==2 ||
        sscanf(str, "%s hi%s", a, b)==2) 
          call_out("hello", 4);
     if(sscanf(str, "%s quest%s", a, b)==2)
          call_out("hello", 4);
     if(sscanf(str, "%s yes%s", a, b)==2)
          call_out("he_said_yes", 3);
     if(sscanf(str, "%s no%s", a, b)==2) {
          if(b=="\n\n") {
                    call_out("he_said_no", 3); }
     }
     /* Remove by Gnar
     write_file("/players/bastion/guild/log/hermit", str + "\n");
     */
}

hello() {
     say("\nHermit says: Eh? Hello! Didn't see you come in...\n");
     prompt;
     say("\nThe hermit smiles and looks you over.\n");
     prompt;
     call_out("ask_to_quest", 3);
}

ask_to_quest() {
     say("\nHermit says: You look the sturdy type.\n");
     prompt;
     say("\nHermit says: Could I ask you to do me a favor?\n");
     prompt;
     return 1;
}

he_said_yes() {
     say("\nHermit says: Good!\n");
     prompt;
     say("\nThe old man looks at you eagerly.\n");
     prompt;
     call_out("quest_desc", 3);
     return 1;
}

he_said_no() {
     say("\nHermit says: Ah well...Perhaps some other time then.\n");
     prompt;
     say("\nHermit sighs.\n");
     prompt;
     return 1;
}

quest_desc() {
     say("\nHermit says: Years ago I was imprisoned here by an evil mage.\n"+
         "I too was an enchanter until he stripped me of my powers,\n"+
         "leaving me a weak, old man.\n");
     prompt;
     say("\nThe old man's jaw tightens.\n");
     prompt;
     call_out("quest_desc2", 4);
     return 1;
}

quest_desc2() {
     say("\nHermit says: You can help me though! In his posession is a\n"+
         "magical staff of great power, that which he stole from me\n"+
         "long ago. It can restore my powers and let me return to my\n"+
         "former life.\n");
     prompt;
     call_out("quest_desc3", 3);
     return 1;
}

quest_desc3() {
     say("\nHermit says: The scoundrel's name is Damian. On the northern\n"+
         "shore there is a small craft. It will take you to the island\n"+
         "the fiend calls home. There you must enter his home and seek\n"+
         "the staff.\n");
     prompt;
     call_out("quest_desc4", 4);
     return 1;
}

quest_desc4() {
     say("\nHermit says: Be careful though. Normally, you might be beneath\n"+
         "his contempt, but if he discovers what you are doing...\n");
     prompt;
     say("\nThe old man looks away and shakes his head.\n");
     prompt;
     call_out("quest_desc5", 4);
     return 1;
}

quest_desc5() {
     say("\nHermit says: If you can do this for me I will be in you debt, \n"+
         "and reward you handsomely!\n");
     prompt;
     say("\nHermit says: Please hurry!\n");
     prompt;
     call_out("warn", 3);
     return 1;
}

warn() {
     say("\nHermit says: A word of warning: Deception is the least of his\n"+
         "weapons, and he is very good at that!\n");
     prompt;
     return 1;
}

quest_done() {
     object ob;
     say("\nHermit says: Congratulations fool!\n");
     prompt;
     say("\nRaising the staff above his head, he is transformed into a\n" +
         "much younger man.\n");
     prompt;
     call_out("summon_anthrax", 4);
}

summon_anthrax() {
     object ob;
     ob=clone_object("players/bastion/monster/anthrax");
     move_object(ob, environment(this_object()));
     ob->quest_done();
     destruct(this_object());
}

test(str) {
     call_out("testing", 2, 2);
     return 1;
}

testing(str) {
     write("Testing: " + str + "\n");
     return 1;
}

heart_beat() {
     attack();
     already_fight=0;
     if(!attacker_ob)
          set_heart_beat(0);
}
