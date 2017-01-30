inherit "obj/monster";
object dude;
reset(){
set_name("highlander");
set_level(21);
set_al(350);
set_short("The Highlander");
set_long("The immortal Highlander.\n");
set_wc(32);
set_ac(18);
set_hp(600);
set_chat_chance(40);
load_chat("The Highlander thinks carefully.\n");
load_chat("The Highlander mumbles: What havoc Demogorgon must be doing!\n");
load_chat("The Highlander looks at you, then looks away.\n");
::reset();
}

init(){
   ::init();
   set_heart_beat(1);
}
catch_tell(str){
     string a, b;
    if(sscanf(str, "%squest%s", a,b)== 2 ||
       sscanf(str, "%squest", a)==1 ||
       sscanf(str, "quest%s", a)==1){
say("Highlander says: Are you the one? How could I have been so blind?\n");
say("Highlander jumps for joy.\n");
       dude = this_player();
this_object()->set_chat_chance(0);
     call_out("talk1", 4);
     return 1;
}
}

talk1(){
say("Highlander says: Demogorgon has imprisoned me here for eternity,\n");
say("and I have no magic anymore to dispell this.\n");
say("Highlander says: But I have prayed that someday an adventurer would\n");
say("reach me, and here you are...\n");
   call_out("talk2", 4);
   return 1;
}
talk2(){
say("You must seek out the scroll in the pyramid.  It is your only hope\n");
say("to defeat Demogorgon.  From there venture to the lair of the tarrasque\n");
say("where you will find an item of much importance.  You will have to them\n");
say("enter the Underdark, where deception lurks about every corner.\n");
say("I wish I could come with you, but my days are numbered.  Oh, I almost\n"+
"forgot, you'll need this!\n");
    say("Highlander tears off his right arm from his socket!\n");
   call_out("give", 2);
   return 1;
}

give(){
    object arm;
    arm = clone_object("players/deathmonger/QUEST/right_arm");
    move_object(arm, dude);
     tell_object(dude,
      "Highlander gives you an adamantite arm.\n");
     say("Highlander says: Demogorgon would never have thought to look\n");
     say("there, would he?\n");
     say("Highlander chuckles politely.\n");
    say("Highlander says: Be off now, for time is of the essence.\n");
     call_out("suicide",3);
    return 1;
}

suicide(){
     say("Highlander says: My purpose is fulfilled, and I may die in peace.\n");
     say("Highlander leaps from his tower window to his death.\n");
     destruct(this_object());
     return 1;
}
