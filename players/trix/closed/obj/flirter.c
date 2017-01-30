#define MASTER_R "/players/trix/closed/obj/flidaemon.c"
int muffled;

/*
query_auto_load() {
  return "/players/trix/closed/obj/flirter.c:";
}
*/
id( str ) {
        if(str=="flirter") return 1;
        return 0;
}

long() {
write("             -@Trix's flirter device (Version 4.1[Daemonized])@-\n");
write("This nice item will be very useful for you if you don't plan to spend  all your\n");
write("mudtime fighting evil dragons or picking on poor little elves.\n");
write("Type 'hkiss' if you want to see the list of the available emotes.\n");
write("Type 'fhelp' for a general help on the other functions of the flirter.\n");
}

short()
  { return "A flirter"; }

query_version() { return 4; }
get() {
        return 1;
}
drop() {
        return 1;
}
init()
{
  if(environment(this_object())->is_pet()) destruct(this_object());
  add_action( "roomtell","say");
  add_action( "donate","donate");
  add_action( "dump","dump");
  add_action( "hickey","hickey");
  add_action( "flirts","flirts");
  add_action( "fhelp","fhelp");
  add_action( "fli","fli");
  add_action( "muffli","muffli");
  add_action( "kass","kass");
  add_action( "khand","khand");
  add_action( "kcheek","kcheek");
  add_action( "kneck","kneck");
  add_action( "khead","khead");
  add_action( "kwrap","kwrap");
  add_action( "hkiss","hkiss");
  add_action( "need","need");
  add_action( "ahold","ahold");
  add_action( "ballad","ballad");
  add_action( "button","button");
  add_action( "dkiss","dkiss");
  add_action( "jeans","jeans");
  add_action( "lgaze","lgaze");
  add_action( "llick","llick");
  add_action( "lscratch","lscratch");
  add_action( "ltouch","ltouch");
  add_action( "lust","lust");
  add_action( "massage","massage");
  add_action( "mchuckle","mchuckle");
  add_action( "neck","neck");
  add_action( "nuzzle","nuzzle");
  add_action( "tlip","tlip");
  add_action( "bhug","bhug");
  add_action( "smother","smother");
  add_action( "thold","thold");
  add_action( "huggle","huggle");
  add_action( "beam","beam");
  add_action( "smile","smile");
  add_action( "beg","beg");
  add_action( "blush","blush");
  add_action("bow","bow");
  add_action( "chuckle","chuckle");
  add_action("comfort","comfort");
  add_action("cry","cry");
  add_action("cuddle","cuddle");
  add_action( "flirt","flirt");
  add_action("fondle","fondle");
  add_action("french","french");
  add_action("giggle","giggle");
  add_action( "glare","glare");
  add_action("grin","grin");
  add_action( "grope","grope");
  add_action("growl","growl");
  add_action( "high5","high5");
  add_action("hold","hold");
  add_action("hug","hug");
  add_action("kick","kick");
  add_action("kiss","kiss");
  add_action("laugh","laugh");
  add_action("lick","lick");
  add_action( "love","love");
  add_action( "moan","moan");
  add_action( "nibble","nibble");
  add_action("nod","nod");
  add_action("pat","pat");
  add_action( "poke","poke");
  add_action("pout","pout");
  add_action( "ruffle","ruffle");
  add_action("shake","shake");
  add_action( "sigh","sigh");
  add_action( "slap","slap");
  add_action( "smack","smack");
  add_action("smile","smile");
  add_action("snuggle","snuggle");
  add_action( "spank","spank");
  add_action("spit","spit");
  add_action( "tackle","tackle");
  add_action( "thank","thank");
  add_action("tickle","tickle");
  add_action("wave","wave");
  add_action( "whistle","whistle");
  add_action("wink","wink");
  add_action( "worship","worship");
#ifndef __LDMUD__
    add_action("roomsay"); add_xverb("'");
    add_action("roomsay"); add_xverb("\"");
#else
    add_action("roomsay", "'");
    add_action("roomsay", "\"");
#endif
  return 1;
}
query_muffled() { return muffled; }
roomtell(arg) { return MASTER_R->roomtell(arg); }
donate(arg) { return MASTER_R->donate(arg); }
dump(arg) { return MASTER_R->dump(arg); }
hickey(arg) { return MASTER_R->hickey(arg); }
flirts(arg) { return MASTER_R->flirts(arg); }
fhelp(arg) { return MASTER_R->fhelp(arg); }
fli(arg) { return MASTER_R->fli(arg); }
muffli() { muffled=MASTER_R->muffli(muffled); return 1; }
kass(arg) { return MASTER_R->kass(arg); }
khand(arg) { return MASTER_R->khand(arg); }
kcheek(arg) { return MASTER_R->kcheek(arg); }
kneck(arg) { return MASTER_R->kneck(arg); }
khead(arg) { return MASTER_R->khead(arg); }
kwrap(arg) { return MASTER_R->kwrap(arg); }
hkiss(arg) { return MASTER_R->hkiss(arg); }
need() { return MASTER_R->need(); }
ahold(arg) { return MASTER_R->ahold(arg); }
ballad(arg) { return MASTER_R->ballad(arg); }
button(arg) { return MASTER_R->button(arg); }
dkiss(arg) { return MASTER_R->dkiss(arg); }
jeans(arg) { return MASTER_R->jeans(arg); }
lgaze(arg) { return MASTER_R->lgaze(arg); }
llick() { return MASTER_R->llick(); }
lscratch(arg) { return MASTER_R->lscratch(arg); }
ltouch(arg) { return MASTER_R->ltouch(arg); }
lust(arg) { return MASTER_R->lust(arg); }
massage(arg) { return MASTER_R->massage(arg); }
mchuckle() { return MASTER_R->mchuckle(); }
neck(arg) { return MASTER_R->neck(arg); }
nuzzle(arg) { return MASTER_R->nuzzle(arg); }
tlip(arg) { return MASTER_R->tlip(arg); }
bhug(arg) { return MASTER_R->bhug(arg); }
smother(arg) { return MASTER_R->smother(arg); }
thold(arg) { return MASTER_R->thold(arg); }
huggle(arg) { return MASTER_R->huggle(arg); }
beam(arg) { return MASTER_R->beam(arg); }
beg(arg) { return MASTER_R->beg(arg); }
blush(arg) { return MASTER_R->blush(arg); }
bow(arg) { return MASTER_R->bow(arg); }
chuckle(arg) { return MASTER_R->chuckle(arg); }
comfort(arg) { return MASTER_R->comfort(arg); }
cry(arg) { return MASTER_R->cry(arg); }
cuddle(arg) { return MASTER_R->cuddle(arg); }
flirt(arg) { return MASTER_R->flirt(arg); }
fondle(arg) { return MASTER_R->fondle(arg); }
french(arg) { return MASTER_R->french(arg); }
giggle(arg) { return MASTER_R->giggle(arg); }
glare(arg) { return MASTER_R->glare(arg); }
grin(arg) { return MASTER_R->grin(arg); }
grope(arg) { return MASTER_R->grope(arg); }
growl(arg) { return MASTER_R->growl(arg); }
high5(arg) { return MASTER_R->high5(arg); }
hold(arg) { return MASTER_R->hold(arg); }
hug(arg) { return MASTER_R->hug(arg); }
kick(arg) { return MASTER_R->kick(arg); }
kiss(arg) { return MASTER_R->kiss(arg); }
laugh(arg) { return MASTER_R->laugh(arg); }
lick(arg) { return MASTER_R->lick(arg); }
love(arg) { return MASTER_R->love(arg); }
moan(arg) { return MASTER_R->moan(arg); }
nibble(arg) { return MASTER_R->nibble(arg); }
nod(arg) { return MASTER_R->nod(arg); }
pat(arg) { return MASTER_R->pat(arg); }
poke(arg) { return MASTER_R->poke(arg); }
pout(arg) { return MASTER_R->pout(arg); }
ruffle(arg) { return MASTER_R->ruffle(arg); }
shake(arg) { return MASTER_R->shake(arg); }
sigh(arg) { return MASTER_R->sigh(arg); }
slap(arg) { return MASTER_R->slap(arg); }
smack(arg) { return MASTER_R->smack(arg); }
smile(arg) { return MASTER_R->smile(arg); }
snuggle(arg) { return MASTER_R->snuggle(arg); }
spank(arg) { return MASTER_R->spank(arg); }
spit(arg) { return MASTER_R->spit(arg); }
tackle(arg) { return MASTER_R->tackle(arg); }
thank(arg) { return MASTER_R->thank(arg); }
tickle(arg) { return MASTER_R->tickle(arg); }
wave(arg) { return MASTER_R->wave(arg); }
whistle(arg) { return MASTER_R->whistle(arg); }
wink(arg) { return MASTER_R->wink(arg); }
worship(arg) { return MASTER_R->worship(arg); }
roomsay(str) {
    string arg;
 /*
    if(!sscanf(str,"'%s",arg)) return;
*/
    return MASTER_R->roomtell(str);
}
