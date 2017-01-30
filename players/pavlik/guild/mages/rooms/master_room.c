/* this room is home to the mages master object */
/* this room also updates and displays donations standings */
#define FILENAME "players/pavlik/guild/mages/log/donation_leaders"
inherit "room/room";
static object master;
static string NAME;
static int NUM;
string leaders;
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Master's Room";
long_desc="The Master's Room.  Home of the Mage-Master!\n";
leaders = allocate(6);

dest_dir=({
 "/players/pavlik/workroom", "out",
});

restore_object(FILENAME);
   }
}

display_leaders(){
  string name;
  int i, num;

write(
"[>------------------------------------------------------------<]\n");
  sscanf(leaders[0], "%s %d", name, num);
  write("   [1] "+capitalize(name)+"\t\t"+num+"\n");
write(
"   ----------------------------------------------------------   \n");
for(i=1; i<6; i++){
  sscanf(leaders[i], "%s %d", name, num);
  write("   ["+(i+1)+"] "+capitalize(name)+"\t\t"+num+"\n");
}
write(
"[>------------------------------------------------------------<]\n");

return 1;
}

calc_leaders(NAME, NUM){
  string name;
  int i, num;
  int xx, yy;

  sscanf(leaders[5], "%s %d", name, num);

  /* if number is less than the last ranked person on the list */
  /* then we dont need to bother with any of this... */
  if(NUM < num)
    return;

  /* find out where on the list the player belongs */
  /* start at the top and search through to bottom */
  i = 0;
  sscanf(leaders[0], "%s %d", name, num);
  while(NUM < num){
    sscanf(leaders[i], "%s %d", name, num);
    i = i + 1;
  }

  /* if in 5th spot, just enter in */
  if(i == 5){
    leaders[5] = NAME+" "+NUM;
    save_object(FILENAME);
    return 1;
    }

  /* otherwise move everyone else down one and enter in */
  xx = 5;
  while(xx > i){
   leaders[xx] = leaders[xx - 1];
   xx = xx - 1;
  }
  leaders[i] = NAME+" "+NUM;

  /* this check is to make sure we dont get to make */
  /* duplication in the list, ie a player cannot be */
  /* on the list twice.  */
  for(xx=i; xx<6; xx++){
    sscanf(leaders[xx], "%s %d", name, num);
    if(name == NAME){
      for(yy=xx; yy<5; yy++)
        leaders[yy] = leaders[yy] + 1;
     leaders[5] = "vacancy 0";
    }
  }

  save_object(FILENAME);
  return 1;
}
