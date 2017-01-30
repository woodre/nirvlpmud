#include "/players/pavlik/guild/mages/macs"
#define GMEM "players/pavlik/guild/mages/players/guild_members"
#define MAX 30

/* Keeps track of the Mages Donation Points (online only) */
string names;
int nums;

/* Variable to keep track of members of the Guild */
int Earth, Air, Fire, Dragons;
int Storms, Stars, Time;


reset(arg){
 if(arg) return;
 restore_object(GMEM);
 move_object(this_object(), "players/pavlik/guild/mages/rooms/master_room");
 nums = allocate(35);
 names = allocate(35);
}

/*
 * This function checks all the players on-line and finds those that
 * are in the Mages Guild.  It then adds that players name and
 * donations points into an array.
 */
get_names(){
  int i, count;
  object ob, obj;

  /* clear the arrays */
  for(i=0; i<MAX; i++){
    nums[i] = 0;
    names[i] = "noone";
  }

  count = 0;
  ob = users();

  /* find all mages and their donation point totals */
  /* ignores guild wizards */
  for(i=0; i<sizeof(ob); i++){
    if(!ob[i] || !environment(ob[i]) || query_idle(ob[i]) > 180)
      continue;
    obj = present("mageobj", ob[i]);
    if(obj && ob[i]->query_level() < 21){
      nums[count] = obj->query_donation();
      count++;
    }
  }

  return 1;
}

/*
 * This is my screwed up way of putting the donation point leaders
 * in order.  I know there must be an easier way to do this, but
 * hey, it seems to work.
 */
sort_names(){
  int i, j;
  int tmp, max;
  int amt;
  object ob, obj;

  for(i=MAX-1; i>0; i--){
    max = i;

    for(j=i-1; j>=0; j--){
      if(nums[j] <= nums[max])
        max = j;
    }

    if(max != i){
      tmp = nums[i];
      nums[i] = nums[max];
      nums[max] = tmp;
     }
  }

  ob = users();
  for(i=0; i<sizeof(ob); i++){
    obj = present("mageobj", ob[i]);
    if(obj){
      amt = obj->query_donation();
      for(j=0; j<MAX; j++){
        if(amt == nums[j])
          names[j] = ob[i]->query_real_name();
      }
    }
  }

  return 1;
}

display_names(){
  int i, size;
  string name;

write("\n"+
"---------------------------------------------------------------------\n"+
" Mage's Donation Leaders (logged on):                                \n"+
"---------------------------------------------------------------------\n");
  for(i=0; i<MAX; i++){
    if(nums[i] > 0){
      write("   ");
      write( (i+1)+".  ");
      write(capitalize(names[i]));
      size = 16 - strlen(names[i]);
      while(size > 0){
        write(" ");
        size--;
        }
      write("\t\t\t\t");
      write(nums[i]+"\n");
      }
  }
write(
"---------------------------------------------------------------------\n");
  return 1;
}

donations(){
  get_names();
  sort_names();
  display_names();
  return 1;
}

query_first(){ return names[0]; }
query_second(){ return names[1]; }

/* The following code just keeps track of how many Mages are in each
 * Order of the guild.  This is updates by the advance room.
*/
add_earth(i){ Earth += i;  save_object(GMEM); }
add_air(i){ Air += i;  save_object(GMEM); }
add_fire(i){ Fire += i;  save_object(GMEM); }
add_dragons(i){ Dragons += i;  save_object(GMEM); }
add_storms(i){ Storms += i;  save_object(GMEM); }
add_stars(i){ Stars += i;  save_object(GMEM); }
add_time(i){ Time += i;  save_object(GMEM); }

query_earth(){ return Earth; }
query_air(){ return Air; }
query_fire(){ return Fire; }
query_dragons(){ return Dragons; }
query_storms(){ return Storms; }
query_stars(){ return Stars; }
query_time(){ return Time; }

guild_members(){
int total;
total = 3 + Earth + Air + Fire + Dragons + Storms + Stars + Time;
write(
"----------------------------------------------------------------\n"+
"The Mages Guild             \n"+
"----------------------------------------------------------------\n"+
"              -+- Master of the Tower: Vertebraker -+-\n"+
"             ---Circle of Mages Council Members:---\n"+
"\n"+
"\n"+
"\n"+
"Members of the Earth:     "+Earth+"\n"+
"Members of the Air:       "+Air+"\n"+
"Members of Fire:          "+Fire+"\n"+
"Members of the Dragons:   "+Dragons+"\n"+
"Members of the Storms:    "+Storms+"\n"+
"Members of the Stars:     "+Stars+"\n"+
"Members of Time:          "+Time+"\n"+
"---------------------------------------------------------------\n"+
"There are ["+total+"] members of the Mages Guild.\n"+
"---------------------------------------------------------------\n");
return 1;
}

config1(){
 int x;
 x = this_player()->query_guild_rank();
 if(x > 71) return 1;
 else if(x >= 61) add_time(1);
 else if(x >= 51) add_stars(1);
 else if(x >= 41) add_storms(1);
 else if(x >= 31) add_dragons(1);
 else if(x >= 21) add_fire(1);
 else if(x >= 11) add_air(1);
 else if(x >= 1) add_earth(1);
 return 1;
}
