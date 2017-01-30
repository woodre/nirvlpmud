
inherit "obj/monster";

int talk;
reset(){
set_name("whiz");
set_alias("cheese");
set_alt_name("cheese whiz");
set_short("The Cheese Whiz");
set_long("The Cheese Whiz is a wise-looking, cheesy old man who smells\n"+
         "faintly of stale cheese and culture. Perhaps you should ask him\n"+
         "about a quest or something.\n"+
         "Cheeze Whiz is slightly tipsy.\n");
 set_ac(8);
 set_wc(14);
 set_hp(150);
set_level(10);
set_chat_chance(40);
load_chat("Cheese Whiz says: Would you like some cheese?\n");
load_chat("Cheese Whiz says: All these adventurers keep asking me about the statue...\n");
load_chat("Cheese Whiz says: Hmmm...this cheese needs to be more tart.\n");
load_chat("Cheese Whiz mutters something under his breath.\n");
load_chat("Cheese Whiz hiccups.\n");
load_chat("Cheese Whiz clones a can of...what else? Cheese Whiz!\n");
set_a_chat_chance(20);
load_a_chat("Cheese Whiz says: You know, you're gonna be surprised in a second.\n");
::reset(0);
}

init(){
     ::init();
    set_heart_beat(1);
}

heart_beat(){
     int n;
     if(this_object()->query_hp() < 40){
       say("Cheese Whiz says: I don't feel like getting killed today,\n"+
             "so I think I'll leave you now.\n"+
             "Cheese Whiz grins evilly.\n"+
             "Cheese Whiz waves his hand and moves to the Cheese Dimension.\n");
       destruct(this_object());
         return 1;
       }
     if(talk == 0){
     n = random(4);
     if(n == 1){
     n = random(4);
     if(n == 0){ command("north"); return 1; }
     else if(n == 1){ command("south"); return 1; }
     else if(n == 2){ command("east"); return 1; }
     else if(n == 3){ command("west"); return 1; }
     }
     }
      ::heart_beat();
     return 1;
}
catch_tell(str){
        object quest_ob;
     string a,b;
     if(sscanf(str, "%squest%s", a, b)== 2 ||
        sscanf(str, "%squest", a)== 1 ||
        sscanf(str, "quest%s", a)== 1){
        talk = 1;
        quest_ob = clone_object("players/deathmonger/QUEST/quest_ob");
        move_object(quest_ob, this_player());
        call_out("quest_intro", 2);
        return 1;
        }
}

quest_intro(){
       say("Cheese Whiz says: What? Now you want to know about the quest too?\n");
       say("Cheese Whiz sighs heavily.\n");
       this_object()->set_chat_chance(0);
       call_out("quest_talk1", 4);
       return 1;
}

quest_talk1(){
     say("Cheese Whiz says: Long ago, there was a massive statue at the gates\n");
     say("of the Abyssal Portal. This statue was enchanted by a powerful\n"+
         "demi-god known as the Highlander to serve as a barrier to the demons\n"+
     "and other foul creatures that abide in the Abyss. However, the demon\n");
     say("Demogorgon in his treachery was able to trick the Highlander\n"+
        "into revealing the secret of the statue. Demogorgon was not able to\n"+
        "destroy the statue completely but instead cut it into pieces and\n");
    say("spread them across the land, hoping that they would never be assembled\n"+
        "again. What is hoped is that someone will come along someday\n"+
        "to reassemble the statue in front of the Abyssal Portal. I don't\n");
   say("know how you can find all the pieces, but I have heard the Wizard\n"+
        "of Oz collects suck things from time to time. Anyway, the quest is\n"+
        "hopeless so you might as well give up.\n");
     call_out("quest_talk2", 7);
     return 1;
}

quest_talk2(){
       say("Cheese Whiz says: Farewell, and good luck. Remember that all is\n"+
           "not as it seems. There will be many illusions and tricks designed\n"+
           "to mislead you along the way.\n");
       this_object()->set_chat_chance(40);
       talk = 0;
       return 1;
}
