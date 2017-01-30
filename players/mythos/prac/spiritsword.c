#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("spirit sword");
    set_alias("sword");
     set_short("Sword of the Spirits");
     set_long("A large sword with a blade forged from cold steel.\n"+
              "It is covered with silver runes.\n");
    set_read("I, Dvirla, have forged this blade to bring vengance\n"+
             "against the kin of the spirits who stole my husband.\n");
    set_class(18);
    set_weight(2);
    set_value(5000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
if(call_other(this_player(), "query_attrib", "wil") > random (50))
 {
   say("The runes on the Sword of the Spirits glow a bright silver.\n"+
    "Beams of light scintillate off the blade.\n");
   write("The runes on the Sword of the Spirits glow a bright silver.\n"+
    "Beams of light scintillate off the blade.\n");
if(call_other(attacker,"id","spirit")){
if(call_other(this_player(), "query_attrib", "wil") > random(40)) {
 write("The runes on your sword glow brightly.\n"+
       "\n       S L I C E\n\n"+
     "The sword whistles a shrill howl as it pierces through "+attacker->query_name()+".\n");
  say("The runes on the Sword of the Spirit glow brightly.\n"+
      "\n       S L I C E\n\n"+
    "The sword whistles a shrill howl as it pierces through "+attacker->query_name()+".\n");
    attacker->heal_self(-13);
    }
     }
  return 7;
    }
    return;
}

query_save_flag()  { return 0; }
