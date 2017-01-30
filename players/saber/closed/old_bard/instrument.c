#define SAVE "players/saber/closed/old_bard/"
#define zb "zoom"
#define zbc alias == zb
#define tp this_player()
#define ep environment(this_object())
#define tpn tp->query_real_name()
#define epn ep->query_real_name()
#define MULT 31
#define MAX 7

string alias;
string song;
static int what,which,line;

id(str) { return str == "instrument" || str == alias; }

short() { if(zbc) return "A Bardic Instrument (Harp) - OBSOLETE";
          else return capitalize(alias)+" [Bard]";
        }

long() { if(zbc) 
              write("The battered remnants of a once great guild's\n"+
                    "potent tool.  Type 'toss_instrument' once you\n"+
                    "find a new guild.\n");
         else
              write("Lovingly crafted from a single piece of living wood,\n"+
                    "this instrument has been stained dark, but left unsealed.\n"+
                    "Frequent use has given it a warm, polished glow.  Strings\n"+
                    "magically enhanced by the faery glint a faint silver,\n"+
                    "touched by Crysea's sacred moonlight.  The faery \n"+
                    "woodcrafters create few instruments.  This one bears the\n"+
                    "mark of the Master Crafter Eldritchserran himself, a\n"+
                    "small star and crescent bound within the rune sigil of\n"+
                    "Crysea burned into the wood.  It is both promise and\n"+
                    "pledge to the mortal who uses it to bring forth song into\n"+
                          "the world.\n<songhelp> will help you.\n");
       }

query_auto_load() { return "/"+SAVE+"instrument.c:"; }
query_prevent_shadow() { return 1; } 

drop() { 
    if(zbc) destruct(this_object());
  return 1;
  }

get() { return 0; }
query_weight() { return 0; }

init_arg() {
  restore_object(SAVE+tpn);
   if(tpn != "mythos") {
  if(zbc) cat("/"+SAVE+"FINALNEWS");
  else cat("/"+SAVE+"NEWS");
  write("\n");
 }   /* got tired of seeing a long list of news... - mythos <7-23-1998> */
}

reset(arg) {
  if(arg) return;
  alias = zb;
  song= allocate(MULT*MAX);
  what = which = 0;
  line = 1;
}

init() {
if(!environment()) return;
tell_object(environment(),
"\n\n\n\nWITH THE REOPENING OF THE TRUE BARDS...\n"+
"THIS DISAPPEARS.\n");
destruct(this_object());
return 1;

  if(tp == ep) {
    if(restore_object(SAVE+tpn)) {
      add_action("farsong","farsong");
      add_action("farsonge","farsonge");
        add_action("farsong","fs");
        add_action("farsonge","fse");
      add_action("set_instrument","change_instrument");
      add_action("create_song","crs");
      add_action("view_song","view_song");
      add_action("autosong","autosong");
      add_action("songbreak","songbreak");
      add_action("songhelp","songhelp");
      add_action("change_title","change_title");
      add_action("update","update_instrument");
    }
  add_action("toss","toss_instrument");
  if(tp->query_level() < 20) 
    if(tp->query_guild_name() == "bard") call_out("unguild",7);
  }
}

unguild() {
if(!ep) return 1;
  ep->set_guild_name(0);
  ep->set_guild_rank(0);
  ep->set_guild_file(0);
  ep->set_guild_xp(0);
  ep->add_guild_rank(-(ep->query_guild_rank()));
  ep->add_guild_xp(-(ep->query_guild_xp()));
  tell_object(ep,"You have been unguilded.\n");
  command("save",ep);
return 1; }

initialize() {
  alias = "harp";
  save();
  move_object(this_object(),ep);
return 1; }

save() { save_object(SAVE+epn); return 1; }

toss() {
  if(restore_object(SAVE+tpn)) rm("/"+SAVE+tpn+".o"); 
  write("You toss the Obsolete Bard instrument.\n");
  destruct(this_object());
return 1; }

songhelp() { cat("/"+SAVE+"HELP"); write("\n"); return 1; }

update() {
  move_object(clone_object("/"+SAVE+"instrument.c"),tp);
  write("You update the instrument.\n");
  destruct(this_object());
return 1; }

set_instrument(str) {
  if(!str) { write("change_instrument <what>\n"+
                   " what can be the following:\n"+
                   "      harp  violin  lyre  mandolin\n");
             return 1; }
  if(str != "harp" && str != "violin" && str != "lyre" &&
     str != "mandolin") {
            write("change_instrument <what>\n"+
                   " what can be the following:\n"+
                   "      harp  violin  lyre  mandolin\n");
             return 1; }
  alias = str;
  save();
  write("Your instrument has been changed to a "+alias+"\n");
return 1; }

static farsong(string msg,int mo) {
  if(!msg) return 0;
  if(!ep->on_channel("gossip")) { tell_object(ep," You are not on gossip!\n"); 
      return 1; } 
  if(mo) msg = "(Songs) "+ep->query_name()+" "+msg;
  else msg = "(Songs) "+ep->query_name()+" sings: "+msg;
  msg = format(msg,75);
  emit_channel("gossip",msg);
return 1; }

static farsonge(str) {
   if(!str) return 0;
   farsong(str,1);
return 1; }

static autosong(str) {
int moo,k;
string ch;
 if(!str) { write("autosong <1 - "+MAX+"> [type]\n"); 
            write("if type is blank then the song will be sung\n"+
                  "if type is 'g' then it will be farsung\n");
             k = 1;
             while(k < MAX+1) {
             if(song[MULT*(k-1)] != 0) write(k+": "+song[MULT*(k-1)]+"\n"); 
               else write(k+": BLANK\n");
             k = k + 1; }
             return 1; }
  ch = 0;
  if(sscanf(str,"%d %s",moo,ch) == 2) {}
  else sscanf(str,"%d",moo);
  if(moo > MAX && moo < 1) { write("songs only 1 - "+MAX+"\n"); return 1; }
  if(what > 0) { write("You are currently reciting\n"); return 1; }
  if(ch == "g") {  
   if(!tp->on_channel("gossip")) { 
     write(" You are not on gossip!\n"); 
   return 1; } 
  what = 2; }
  else what = 1; 
  which = MULT * (moo - 1); line = 1;
  set_heart_beat(1);
return 1; }

songbreak() { what = 0; 
              write("You break off in the middle of your singing.\n");
              return 1; }

static create_song(str) {
string moo;
int num,li;
	if(!str) { write("crs [song# line# what]\n"+
	                 "song# must be 1 - "+MAX+" to indicate which of the "+
	                 MAX+" songs\n"+
	                 "line# 0 - "+(MULT - 1)+" with 0 as the title\n"+
	                 "what is what that line is to say.\n"+
	                 "  with 0 to clear the line\n");
	           return 1; }
	if(sscanf(str,"%d %d %s",num,li,moo) != 3) return 0;
	if(moo == "0") moo = 0;
	if(num > (MULT-1)) { write("You can not have more than "+(MULT-1)+" lines.\n");
	                     return 1; }
	song[(num-1)*MULT +li] = moo;
	save();
return 1; }

view_song(str) {
int num,h;  
  if(!str) { write("view_song [song#]\n"); return 1; }
  sscanf(str,"%d",num);
  if(num > MAX && num < 1) return 0;
  if(song[(num - 1)*MULT] == 0) { write("Song "+num+" is blank\n"); return 1; }
  for(h=0;h<(MULT-1);h++) 
    if(song[(num-1)*MULT + h] != 0) write(h+" : "+song[(num-1)*MULT + h]+"\n");
return 1; }

static change_title(str) {
  if(!str) { write("change_title <what>\n"); return 1; }
  tp->set_title(str);
  write("Title set to "+str+"\n");
  command("save",tp);
return 1; }

heart_beat() {
  if(line > (MULT-1) || song[line+which] == 0) what = 0;
  if(what == 0) { 
    line = 1; set_heart_beat(0); return 1; }
    if(what == 1) 
       tell_room(environment(ep),
          ep->query_name()+" sings: "+song[line+which]+"\n");
    if(what == 2) farsong(" "+song[line+which]);
    line = line + 1;
}
