obit_list(str) {
  call_other("/players/nooneelse/black/deathlog","deathlog",0);
  write(
"____________________ Obituary Notice ____________________\n");
  tail("/players/nooneelse/black/deathlog.txt");
  write("\n");
  return 1;
}
