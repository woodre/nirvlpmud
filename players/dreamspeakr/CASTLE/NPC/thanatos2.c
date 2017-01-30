#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/monster.c";

object new, player_ob;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

     set_name("thanatos");
     set_alias("thanatos");
     set_alt_name("thanatos");
     set_race("minor god");
     set_gender("male");
     set_short(RED+"Thanatos"+NORM+", Minor God of Death");
     set_long(
         "\n"+
         "    Dressed in all black, this hooded god stands before\n"+
         "you.  His eyes seem to glow just beyond the shroud of his\n"+
         "hood.  According to legend, he is one of the sons of Nyx, \n"+
         "the goddess of night, and lives beside the river Lethe in \n"+
         "a remote cave that he shares with his brother Hypnos, god\n"+
         "of sleep.  Evilness seems to surround this great god of \n"+
         "death.  Only the brave should type '"+RED+"tattoo me"+NORM+"'.\n"+
         "\n");

     set_level(24);
     set_hp(1000);
     set_al(-1000);
     set_aggressive(0);

  if(!present("machine")) {
    move_object(clone_object("players/dreamspeakr/CASTLE/OBJ/tatmach.c"),
     this_object()); 
    }
     init_command("wield machine");

     set_ac(19);
     set_wc(40);
     set_a_chat_chance(20);
       load_a_chat(RED+"Thanatos"+NORM+" mumbles some unrecognizable words, you become hypnotized.\n");
       load_a_chat(RED+"Thanatos "+NORM+"conjures the spirits of the dead.\n"); 
       load_a_chat(RED+"Thanatos "+NORM+"calls upon the greater Gods to curse you!\n");
}

init() {
    ::init();
    add_action("tattoo_me", "tattoo");
    player_ob=this_player();
}

tattoo_me(str){
    if(!str){
      return 0;
    }
    if(str == "me"){
      call_out("tattoo_one", 3);
      return 1;
    }
}

tattoo_one(){
    tell_room(environment(), "\n");
    tell_room(environment(), "Thanatos speaks:  I am pleased....\n");
    tell_room(environment(), "\n");
    tell_room(environment(), "Thanatos continues:  I shall perform the tattoo now on you.\n");
    tell_room(environment(), "Thanatos warns:  Sit VERY still... I am not very good yet at this....\n");
    tell_room(environment(), "\n");
    tell_room(environment(), "Thanatos laughs:  YET!!!\n");
    tell_room(environment(), "Thanatos laughs demonically!\n");
    remove_call_out("tattoo_one");
    call_out("tattoo_two", 9);
    return 1;
}

tattoo_two(){
    tell_room(environment(), "\n");
    tell_room(environment(), "Thanatos takes a seat on the stool and dons a pair of surgical gloves\n");
    tell_room(environment(), "\n");
    tell_room(environment(), "Thanatos takes a large needle from a small package and loads it \n");
    tell_room(environment(), "into the tattoo machine he brought in with him.\n");
    tell_room(environment(), "\n");
    tell_room(environment(), "Thanatos says:  Now what and where would you like for me to tattoo on you?\n");
    tell_room(environment(), "\n");
    tell_room(environment(), "Example:  'say a flying dragon on my arm'\n");
    remove_call_out("tattoo_two");
    return 1;
}

catch_tell(str) {
  string a, b, c;
  if(this_player()->query_name() && (sscanf(str, "%s says%son my%s", a, b, c)==3 )) {
    new=clone_object("/players/dreamspeakr/CASTLE/OBJ/tattoo.c");
    new->set_short(HIG+"A tattoo of"+ b + "on " + this_player()->query_possessive() + c + NORM);
    call_out("tattoo_three", 2);
  }
}  

tattoo_three() {
    tell_room(environment(), "\n");
    tell_room(environment(), "Thanatos laughs as he begins working on you.  \n");
    tell_room(environment(), "\n");
    tell_room(environment(), "As the needle pierces into your skin you begin feeling \n");
    tell_room(environment(), "squeemish, your hands sweat, you almost feel as though \n");
    tell_room(environment(), "your going to "+HIR+"PUKE"+NORM+"!\n");
    tell_room(environment(), "\n");
    remove_call_out("tattoo_three");
    call_out("tattoo_four", 9);
    return 1;
}

tattoo_four() {
    tell_room(environment(), "\n");
    tell_room(environment(), "SUDDENLY Thanatos stops and screams:\n");
    tell_room(environment(), "\n");
    tell_room(environment(), HIR+"    OHHHHHH NOOOOOOO\n"+NORM);
    tell_room(environment(), "\n");
    tell_room(environment(), "You turn white as a ghost and feel as though the world was \n");
    tell_room(environment(), "spinning in circles. \n");
    remove_call_out("tattoo_four");
    call_out("tattoo_five", 9);
    return 1;
}

tattoo_five() {
    tell_room(environment(), "\n");
    tell_room(environment(), "Thanatos begins laughing demonically as he says:  Fooled ya!!!\n");
    tell_room(environment(), "\n");
    tell_room(environment(), "Thanatos smiles and says:  Your tattoo is done my friend.\n");
    tell_room(environment(), "Thanatos says:  Hope you enjoy your tattoo, Im sure you will!\n");
    tell_room(environment(), "\n");
    tell_room(environment(), "Thanatos unstraps you from the chair.\n");
    tell_room(environment(), "\n");
    tell_room(environment(), "Thanatos gathers his things and leaves.\n");
    tell_room(environment(), "\n");
    remove_call_out("tattoo_five");
    move_object( new, player_ob );
    destruct( present("machine",this_object()) );
    destruct(this_object());
    return 1;
}
