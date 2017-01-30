obit_list(str) {
if(TPL < 4) {
  write("You lack the skills for this ability.\n");
  return 1; }

  call_other("/players/eurale/Vamp/deathlog","deathlog",0);
  write(
"____________________ Obituary Notice ____________________\n");
  tail("/players/eurale/Vamp/deathlog.txt");
  write("\n");
  return 1;
}
