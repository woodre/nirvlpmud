#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
int typ;
int contatore;
string subject;
inherit "obj/monster";

id(str) {return str=="voice";}

init() {
       ::init();
       add_action("whisper","whisper");
       }

reset(arg){
  if(arg) return;
   subject="production systems";
   set_level(1);
   set_hp(4750);
   set_wc(30);
   set_ac(15);
   set_chat_chance(10);
   typ = random(5) +1;
   if(typ == 1) 
    { load_chat("You notice the librarian which comes close to you and whispers:\n"+
                tpn+", help me please:  what is the english translation for 'sistemi di produzione'?\n"); }
   if(typ == 2) 
    { load_chat("You notice the librarian which comes close to you and whispers:\n"+
                tpn+", help me please:  what is the english translation for 'avanzato'?\n"); } 
   if(typ == 3)
    { load_chat("You notice the librarian which comes close to you and whispers:\n"+
                tpn+", help me please:  what is the english translation for 'processi'?\n"); }
   if(typ==4)
    { load_chat("You notice the librarian which comes close to you and whispers:\n"+
                tpn+", help me please:  what is the english translation for 'integrazione'?\n"); }
   if(typ==5)
    { load_chat("You notice the librarian which comes close to you and whispers:\n"+
                tpn+", help me please:  what is the english translation for 'fabbrica'?\n"); }
}

whisper(str) {
   int level;
   if(!str){
       write("Whisper what?\n");
       return 1;   
           }
   if(str=="production systems" && typ==1 || str=="advanced" && typ==2 || str=="processes" && typ==3 || str=="integration" && typ == 4 || str=="industry" && typ == 5)
{
    if(contatore == 1){
    write(tpn+", you have already answered,  prove your fighting ability now.\n");
    return 1; }
    write("\nAs soon as you give the correct answer, a bookworm\n"+
            "pops up from behind the shelf and suddenly exclaims:\n"+
            "''AHAHAH,  I knew that answer too!!  AHAHAH.\n....."+
            str+".....   bah,  what an easy answer.....''\n\n"+
            "You think to yourself:  'This guy is really annoying'\n");
    contatore++;
    level = tp->query_level();
    move_object(clone_object("/players/francesco/quest/mobs/monster_lib.c"),environment(this_object()));  
    present("bookworm",environment())->set_level1(level);
    present("bookworm",environment())->set_argomento(subject);
    destruct(this_object());
    return 1;
    }
    write("The librarian whispers to you:  hmmm, no, "+tpn+", your answer did not work.\n"); 
    return 1; 
}