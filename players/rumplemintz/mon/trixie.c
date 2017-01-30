/*
 * Trixie
 * Original code in /room/alley.c
 *
 * Recoded by Rumplemintz@Nirvana
 */

inherit "obj/monster";

void reset(int arg){
  ::reset(arg);
  if(arg) return;

  set_name("trixie");
  set_alias("hooker");
  set_alt_name("trixie_zz");
  set_short("Trixie the hooker");
  set_long("She is rather old, and has not aged well.\n");
  set_level(1);
  set_hp(20);
  set_ep(30);
  set_ac(0);
  set_wc(5);
  set_al(125);
  enable_commands();  /* Make living - 
                         This is necessary so that catch_tell will work from
                         Other NPC's using say() or tell_room() */
}

int catch_tell(string str) {
  string a, b, c;

  write("Catch_tell will receive this as the string.\n");
  write(str);
  if (sscanf(str, "%s says: %s", a, b) == 2) {
    if ( (sscanf(b, "%sHo", c) == 1) ||
         (sscanf(b, "%sho", c) == 1) ) {
      call_out("glare", 1, a);
    }
  }
}

int glare(string str) {
  if (!str) return 0;
  if (str == "\nThe plastic Santa") {
    str = "Jolly man";
  }
  say("Trixie glares at " + str + " evilly.\n");
  say("Trixie asks: Who you callin' a Ho, " + str + "?\n");
  say("Trixie snaps her fingers in a 'Z' formation.\n");
  return 1;
}
