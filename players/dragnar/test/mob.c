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
  set_level(1);
}

int calculate_worth() { return 10000000; }
