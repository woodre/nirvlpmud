#define PAIN "/players/pain/closed/items/patchd"

id(str) { return str == "patch" || str == "pains_patch"; }
short(){ return "A 'House of Pain' patch"; }
long(){
write("This is a House of Pain patch designed to show that you\n"+
      "are a fan. It is a wonderfully wrought badge with an\n"+
      "Irish flag as a background and a Shamrock in the\n"+
      "middle. Around it are the words 'Fine Malt Lyrics'.\n");
write("A beautifully made patch... type help_patch for info!\n");
}
drop(){ return 1;}
query_auto_load(){ return "players/pain/closed/items/pain_patch.c:";}
init(){
add_action("get_guild", "mage");
add_action("help_patch", "help_patch");
add_action("ick", "ick");
add_action("yuck", "yuck");
add_action("quiver", "quiver");
add_action("jump", "jump");
add_action("jazz", "jazz");
add_action("suckle", "suckle");
add_action("blow", "blow");
add_action("horny", "horny");
add_action("tongue", "tongue");
add_action("agree", "agree");
add_action("foff", "foff");
add_action("swiggle", "swiggle");
add_action("wibble", "wibble");
add_action("lake", "lake");
add_action("snort", "snort");
add_action("face", "face");
add_action("boot", "boot");
add_action("lambada", "lambada");
add_action("roll", "roll");
add_action("mood", "mood");
add_action("toss", "toss");
add_action("kissme", "kissme");
add_action("nasty", "nasty");
add_action("mosh", "mosh");
add_action("rave", "rave");
add_action("bummer", "bummer");
add_action("sucks", "sucks");
add_action("boring", "boring");
add_action("wonder", "wonder");
add_action("sdance", "sdance");
add_action("tstick", "tstick");
add_action("get_rid_of_patch", "get_rid_of_patch");
add_action("patch_news", "patch_news");
add_action("replace", "replace");
add_action("replace_all", "replace_all");
add_action("thigh", "thigh");
add_action("toe", "toe");
add_action("tell", "tell");
add_action("sleep", "sleep");
add_action("chortle", "chortle");
add_action("thwak", "thwak");
add_action("phair", "phair");
add_action("noogie", "noogie");
add_action("flirt", "flirt");
add_action("romance", "romance");
add_action("cower", "cower");
add_action("roar", "roar");
add_action("howl", "howl");
add_action("woo","woo");
add_action("wish","wish");
add_action("boggle","boggle");
add_action("flex","flex");
add_action("cheer","cheer");
add_action("fear","fears");
add_action("lag","lag");
add_action("raise","raise");
add_action("kiss","kiss2");
add_action("alive","kewlwho");
add_action("pt","pt");
add_action("pe","pe");
add_action("hush","hush");
add_action("share","share");
}


get_guild() { PAIN->get_guild(); return 1; }
help_patch() { PAIN->help_patch(); return 1; }
ick() { PAIN->ick(); return 1; }
yuck() { PAIN->yuck(); return 1; }
quiver(arg) { PAIN->quiver(arg); return 1; }
jump() { PAIN->jump(); return 1; }
jazz() { PAIN-> jazz(); return 1; }
suckle() { PAIN->suckle(); return 1; }
blow() { PAIN->blow(); return 1; }
horny() { PAIN->horny(); return 1; }
tongue(arg) { PAIN->tongue(arg); return 1; }
agree(arg) { PAIN->agree(arg); return 1; }
foff(arg) { PAIN->foff(arg); return 1; }
swiggle(arg) { PAIN->swiggle(arg); return 1; }
wibble() { PAIN->wibble(); return 1; }
lake(arg) { PAIN->lake(arg); return 1; }
snort() { PAIN->snort(); return 1; }
face(arg) { PAIN->face(arg); return 1; }
boot(arg) { PAIN->boot(arg); return 1; }
lambada(arg) { PAIN->lambada(arg); return ; }
roll() { PAIN->roll(); return 1; }
mood() { PAIN->mood(); return 1; }
toss() { PAIN->toss(); return 1; }
kissme(arg) { PAIN->kissme(arg); return 1; }
nasty() { PAIN->nasty(); return 1; }
mosh() { PAIN->mosh(); return 1; }
rave() { PAIN->rave(); return 1; }
bummer() { PAIN->bummer(); return 1; }
sucks() { PAIN->sucks(); return 1; }
boring() { PAIN->boring(); return 1; }
wonder() { PAIN->wonder(); return 1; }
sdance(arg) { PAIN->sdance(arg); return 1; }
tstick(arg) { PAIN->tstick(arg); return 1; }
get_rid_of_patch() { PAIN->get_rid_of_patch(); return 1; }
patch_news() { PAIN->patch_news(); return 1; }
replace() { PAIN->replace(); return 1; }
replace_all() { PAIN->replace_all(); return 1; }
thigh(arg) { PAIN->thigh(arg); return 1; }
toe(arg) { PAIN->toe(arg); return 1; }
tell(arg) { PAIN->tell(arg); return 1; }
sleep() { PAIN->sleep(); return 1; }
chortle() { PAIN->chortle(); return 1; }
thwak(arg) { PAIN->thwak(arg); return 1; }
phair(arg) { PAIN->phair(arg); return 1; }
noogie(arg) { PAIN->noogie(arg); return 1; }
flirt(arg) { PAIN->flirt(arg); return 1; }
romance(arg) { PAIN->romance(arg); return 1; }
cower() { PAIN->cower(); return 1; }
roar() { PAIN->roar(); return 1; }
howl() { PAIN->howl(); return 1; }
woo() {PAIN->woo(); return 1; }
wish() { PAIN->wish(); return 1; }
boggle() { PAIN->boggle(); return 1; }
flex() { PAIN->flex(); return 1; }
cheer(arg) { PAIN->cheer(arg); return 1; }
fear(arg) { PAIN->fear(arg); return 1; }
lag() { PAIN->lag(); return 1; }
raise() { PAIN->raise(); return 1; }
kiss(arg) { PAIN->kiss(arg); return 1; }
alive() { PAIN->alive(); return 1; }
pt(arg) { PAIN->pt(arg); return 1; }
pr(arg) { PAIN->pe(arg); return 1; }
hush() { PAIN->hush(); return 1; }
share(arg) { PAIN->share(arg); return 1; }
