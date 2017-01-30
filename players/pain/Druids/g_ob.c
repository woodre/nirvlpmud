/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*                                                                    */
/*      Guild Object for the Druid Guild                              */
/*                                                                    */
/*	Pain 01/23/95                                                 */
/*                                                                    */
/*	Main Object Filename: g_ob.c                                  */
/*      Slave Object Filename: druidslave.c                           */
/*                                                                    */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#define SLAVE "/players/pain/NEW/druids/druidslave.c"
#define DRUIDS "players/pain/NEW/druids/druids/"
#define COWL this_object()
#define member this_player()
#define m_name member->query_name()
#define m_sp member->query_sp()
#define m_hp member->query_hp()

int muff;
int color;
int glevel;
int tpts;
int a_mod;
int c_mod;

static int is_casting;

query_muffs() { return muff; }
query_color() { return color; }
query_glevel() { return glevel; }
query_tpts() { return tpts; }
query_is_casting() { return is_casting; }
query_a_mod() { return a_mod; }
query_c_mod() { return c_mod; }

set_muffs(str) { muff = str; }
set_color(str) { color = str; }
set_glevel(str) { glevel = str; }
set_tpts(str) { tpts = str; }
set_is_casting(str) { is_casting = str; }
set_a_mod(str) { a_mod = str; }
set_c_mod(str) { c_mod = str; }


long() { write("A flowing, hooded cowl of dark colors that blend into\n"+
            "the forest. It seems to be alive with natural power.\n"+
            "When you wear this cowl you identify yourself as a Druid.\n"+
            "You think that you can type \"man\" for help on guild\n"+
		"information and abilities.\n"); }
 short() { return "A dark hooded cowl"; }
reset(arg) {
   if(arg)
	return;
   call_out("fixd",5);
}


drop() { return 1; }

get() { return 1; }

init_arg() {
        if(restore_object(DRUIDS+this_player()->query_real_name())) {
            write("Your stats are being restored. . . .\n");
        }
        else {
            write("Creating a stat file, please hold. . . .\n");
            saveme();
        }
        cat("/players/pain/NEW/druids/int_news");
        return;
}
init() {
	add_action("guild_title", "gtitle");
	add_action("release", "release");
	add_action("cure_f", "cure");
	add_action("ctouch", "chill");
	add_action("rain", "rain");
	add_action("comet", "comet");
	add_action("lightning", "lightning");
	add_action("skills", "skills");
	add_action("quiet", "dq");
	add_action("dtalk", "dt");
	add_action("demote", "de");
	add_action("dwho", "dw");
	add_action("quick_hp", "qhp");
	add_action("check_wear", "wear");
	add_action("check_wield", "wield");
	add_action("manual", "man");
	add_action("saveme", "saveme");
	add_action("restoreme", "restoreme");
	add_action("wolf_hound", "hound");
	add_action("quit", "quit");
}
check_wear(str) {
object what;

what = present(str,this_player());
if(!what) {
	write("You have no "+str+".\n");
	return 1;
}
if(what->query_id() != "d_arm") {
	write(capitalize(str)+" is not acceptable armor for druids.\n");
	return 1;
}
else {
	return 0;
}
}


check_wield(str) {
object what;

what = present(str,this_player());
if(!what) {
	write("You have no "+str+".\n");
	return 1;
}
if(what->query_alias() != ("club" || "stick" || "knife" || "dagger")) {
	write(capitalize(str)+" is not an acceptable weapon for druids.\n");
	return 1;
}
else {
	return 0;
}
}


saveme() {
save_object(DRUIDS+this_player()->query_real_name());
write("Druid skills and information saved.\n");
return 1;
}

restoreme() {
if(restore_object(DRUIDS+this_player()->query_real_name())) {
	write("Your stats are being restored. . . .\n");
   return 1;
}
else {
	write("Creating a stat file, please hold. . . .\n");
	saveme();
   return 1;
}
}

dwho() { SLAVE->dwho(); return 1; }
skills() { SLAVE->skills(); return 1; }
demote(str) { SLAVE->demote(str); return 1; }
dtalk(str) { SLAVE->dtalk(str); return 1; }
manual(str) { SLAVE->manual(str); return 1; }
guild_title() { SLAVE->guild_title(); return 1; }


release(str) {
if(is_casting) {
	write("You are already casting a spell, you must wait before you cast another.\n");
	return 1;
}
else {
	is_casting = 1;
	SLAVE->release(str);
	call_out("clear_is_casting",5);
	return 1;
}
}

wolf_hound() {
if(is_casting) {
        write("You are already casting a spell, you must wait before you cast another.\n");
        return 1;
}
else {
	is_casting = 1;
        SLAVE->wolfhound();
	call_out("clear_is_casting",5);
	return 1;
}
}

cure_f(str) {
if(is_casting) {
        write("You are already casting a spell, you must wait before you cast another.\n");
        return 1;
}
else {
	is_casting = 1;
        SLAVE->cure_f(str);
	call_out("clear_is_casting",5);
	return 1;
}
}

ctouch(str) {
if(is_casting) {
        write("You are already casting a spell, you must wait before you cast another.\n");
        return 1;
}
else {
	is_casting = 1;
        SLAVE->ctouch(str);
	call_out("clear_is_casting",5);
	return 1;
}
}

rain() {
if(is_casting) {
        write("You are already casting a spell, you must wait before you cast another.\n");
        return 1;
}
else {
	is_casting = 1;
        SLAVE->rain();
	call_out("clear_is_casting",5);
	return 1;
}
}

lightning(str) {
if(is_casting) {
        write("You are already casting a spell, you must wait before you cast another.\n");
        return 1;
}
else {
	is_casting = 1;
        SLAVE->lightning(str);
	call_out("clear_is_casting",5);
	return 1;
}
}

meld() {
if(is_casting) {
        write("You are already casting a spell, you must wait before you cast another.\n");
        return 1;
}
else {
	is_casting = 1;
        SLAVE->meld();	
	call_out("clear_is_casting",5);
	return 1;
}
}

clear_is_casting() { is_casting = 0; return 1; }

quick_hp() {
   write("[ "+m_name+": HP: "+m_hp+" SP: "+m_sp+" ]\n");
   return 1;
}


quiet(str) {
   if(!str) {
      write("Usage: dq <yes/no> \n");
      return 1;
   }
   if(str == "yes") {
      if(str == 1) {
	 write("You are not on the Druids' Channel!\n");
	 return 1;
      }
      muff = 1;
      write("You close the Druids' Channel.\n");
      return 1;
   }
   if(str == "no") {
      if(str == 0) {
	 write("You are already on the Druids' Channel!\n");
	 return 1;
      }
      muff = 0;
      write("You rejoin the Druids' Channel.\n");
      return 1;
   }
}

fixd() { 
if(environment(this_object())) {
	move_object(this_object(),environment(this_object())); 
	}
call_out("fixd",100);
return 1; 
}

quit() {
saveme();
if(this_player()->query_level() < 21) {
	member->quit();
}
else
	member->do_quit();
}

id(str) { return str == "cowl" || str == "p_g_ob"; }

query_auto_load() { return "players/pain/Guild/g_ob.c:"; }
