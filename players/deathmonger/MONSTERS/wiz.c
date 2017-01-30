inherit "obj/monster";
object dude, ring;
reset(){
set_name("wizard");
set_level(21);
set_al(350);
set_short("The Wizard of Oz");
set_long("The Great and Powerful Wizard of Oz.\n");
set_chance(35);
set_spell_dam(20);
set_spell_mess1("The Wizard casts a lightning bolt.\n");
set_spell_mess2("You feel the force of the Wizard's lightning bolt.\n");
set_wc(32);
set_ac(18);
set_hp(600);
set_chat_chance(40);
load_chat("Wizard of Oz booms: I am the great and powerful Oz!\n");
load_chat("Wizard of Oz booms: I am a busy man! What do you want!?\n");
load_chat("Wizard of Oz booms: What do you mortals want!?\n");
set_a_chat_chance(65);
load_a_chat("How dare you attack me!?\n");
if(!present("ring")){
     ring = clone_object("obj/armor");
     call_other(ring, "set_name", "ring");
     call_other(ring, "set_short", "Ring of Power");
     call_other(ring, "set_ac", 1);
     call_other(ring, "set_type", "ring");
     call_other(ring, "set_value", 500);
     move_object(ring, this_object());
}
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
say("Wizard says: You are on a quest? Oh, I didn't know...\n");
say("Wizard smiles happily.\n");
this_object()->set_chat_chance(0);
        dude = this_player();
     call_out("talk1", 4);
     return 1;
}
}

talk1(){
   say("Wizards says: Well, since I know the quest you are on, for I am\n");
   say("the Great and Powerful Oz!, I have something you may be interested in\n");
   call_out("talk2", 4);
   return 1;
}
talk2(){
say("Wizard says: I collect things...and I have a piece of some\n");
   say("statue that has been carved from pure adamantite, the toughest\n");
   say("material known. It is only an arm, but it's all I have.\n");
   say("Perhaps you can find some use for it.\n");
   call_out("give", 2);
   return 1;
}

give(){
    object arm;
    arm = clone_object("players/deathmonger/QUEST/left_arm");
    move_object(arm, dude);
       tell_object(dude,
      "Wizard gives you an adamantite arm.\n");
      say("The Highlander is being held in a tower guarded by a dracolich.\n");
      say("He is the one you should ask about the quest.\n");
      say("Now I am rather busy, so be off.\n");
this_object()->set_chat_chance(40);
    return 1;
}
