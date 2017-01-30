inherit "/players/beck/closed/FuzzyBeast.c";

reset(arg)
{
  if(arg) return;
set_name("pedestrian");
set_alias("pedestrian");
short_desc=({
"A nerdy looking pedestrian",
"A pedestrian looking very business like",
"A pedestrian thats a young punk",
"A pedestrian who gives you a strange look",
"A snotty pedestrian",
"A pedestrian in a hurry to go somewhere",
});
long_desc=({
"this is a pedestrian.\n",
"this pedestrian doesnt look like they want to be bothered.\n",
});
  ::reset(arg);
set_level(10);
set_hp(150);
set_wc(14);
set_ac(8);
set_aggressive(random(1));
set_al(-200);
}
