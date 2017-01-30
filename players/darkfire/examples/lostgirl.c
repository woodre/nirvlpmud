inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "lost girl" }) );
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
   
  move_object(clone_object("/players/dragnar/WalkingDead/obj/kill_check"), this_object());
  set_dead_ob(this_object());
  
}

init() {
  ::init();
}

heart_beat() {
    ::heart_beat();
}

monster_died() {
  object corpse;
  object item;
  
  corpse = present( "corpse", environment() );
  if( corpse ) {
    item = present( "kill_check_object", corpse );
    if( item )
      destruct( item );
  }
    return 0; 
}
