inherit "/obj/monster";

int shield;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "lost girl" }) );
  shield = 500;
  set_name("girl");
  set_race("human");
  set_short("A Lost Girl");
set_long(
"A young girl, around 10 or 12 years old with dark brown hair.  She\n\
must have been out here for a few days by herself, her clothes are\n\
torn and filthy and she has scratches on her arms from a few falls\n\
she has taken. It is amazing that she has lasted this long on her\n\
own without any help. She has no chance to survive an encounter with\n\
a Walker without someone to protect her however.\n");

  set_gender("female");
  set_level(7);
  
  set_aggressive(0);
  set_al(500);
  
  set_chat_chance(10);
  load_chat("The lost girl looks at you as a tear rolls down her face.\n");
  load_chat("The lost girl says: 'I ran away as Walkers ate my Daddy.'\n\
The girl begins to sob into her hands.\n");
  load_chat("The lost girl says: 'They are everywhere, don't leave me here please!'\n");
  
}

init() {
  ::init();
}

long() {
  ::long();
  write("The shield is at: "+shield+"\n");
}

heart_beat() {
    ::heart_beat();
}

do_damage(int *damage, string *method){
  int i;
  
  if( shield ) {
    tell_room( environment(), "The girl laughs as the damage bounces off her shield.\n");
    for( i=0; i < sizeof(damage); i++) {
      shield -= damage[i];
      if( shield < 0 )
        shield = 0;
    }
  }
  else {
    return ::do_damage( damage, method);
  }
}

