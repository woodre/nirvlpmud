obit_list(str) {

if(TPL < 5) {
  write("You lack the skills for this ability.\n");
  return 1; }

if(TPBPTS < 1) {
  write("You lack the blood energy to do that.\n");
  return 1; }

PFANGS->add_BLOODPTS(-1);
  call_other("/players/eurale/VAMPIRES/deathlog","deathlog",0);
  write(
"____________________ Obituary Notice ____________________\n");
  tail("/players/eurale/VAMPIRES/deathlog");
  write("\n");
  return 1;
}
