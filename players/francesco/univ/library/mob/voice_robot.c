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
       add_action("answer","answer");
       }

reset(arg){
  if(arg) return;
   subject="robotics";
   set_level(1);
   set_hp(4750);
   set_wc(30);
   set_ac(15);
   set_chat_chance(10);
   typ = random(5) +1;
   if(typ == 1) 
    { load_chat("A recorded voice says:  What is the english translation for 'robotics'?\n"); }
   if(typ == 2) 
    { load_chat("A recorded voice says:  What is the english translation for 'teorie'?\n"); } 
   if(typ == 3)
    { load_chat("A recorded voice says:  What is the english translation for 'automazione'?\n"); }
   if(typ==4)
    { load_chat("A recorded voice says:  What is the english translation for 'completamente'?\n"); }
   if(typ==5)
    { load_chat("A recorded voice says:  What is the english translation for 'auto-controllate'?\n"); }
}

answer(str) {
   int level;
   if(!str){
       write("Answer what?\n");
       return 1;   
           }
   if(str=="robotics" && typ==1 || str=="teorie" && typ==2 || str=="automation" && typ==3 || str=="completely" && typ == 4 || str=="self-controlled" && typ == 5)
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
    level--;
    level = level + random(3);
    move_object(clone_object("/players/francesco/univ/library/mob/monster_lib.c"),environment(this_object()));  
    present("bookworm",environment())->set_level1(level);
    present("bookworm",environment())->set_argomento(subject);
    destruct(this_object());
    return 1;
    }
    write("Sorry, "+tpn+", your answer is not correct.\n"); 
    return 1; 
}