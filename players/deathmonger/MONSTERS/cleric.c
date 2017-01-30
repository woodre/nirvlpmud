
inherit "obj/monster";

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
object dude, blessing;
reset(){
    set_name("svirfneblin");
    set_short("The Svirfneblin High Cleric");
    set_long("Svirfneblin are a bit theocratic in government, and so the\n"+
      "High Cleric is both spiritual and political leader of the city.\n"+
      "Svirfneblin clerics are notably powerful, and you will probably\n"+
      "want to get a blessing from him.\n");
    set_level(13);
    set_hp(195);
    set_wc(17);
    set_ac(10);
    set_chat_chance(40);
    load_chat("Svirfneblin says: What do you want me to give you?\n");
    ::reset();
}

extra_init(){
    set_heart_beat(1);
    ::init();
}

catch_tell(str){
      string a;
     if(sscanf(str, "%sblessing%s", a)== 1){
     dude = this_player();
     if(present("friend", dude)){
       say("Svirfneblin says: Well, since you have the Myconids' friendship,\n");
      say("I can give you my blessing.\n");
      say("Svirfneblin smiles happily.\n");
      call_out("talk", 5);
      return 1;
}
    say("Svirfneblin says: I don't trust anyone the Myconids don't trust.\n");
     return 1;
}
}
talk(){
say("Svirneblin says: Here is my blessing, keep it well.\n");
say("Svirfneblin chants a few choice archaic words.\n");
blessing = clone_object("players/deathmonger/QUEST/blessing");
move_object(blessing, dude);
say("You now have the cleric's blessing.\n");
return 1;
}
