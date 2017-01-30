inherit "/players/vertebraker/closed/shardak/std/emote";
inherit "/players/vertebraker/closed/shardak/std/emote";
void
reset(status arg)
{
   if(arg) return;
   ::reset();
   load_targeted_msgs(({
      "You chuckle demonically at #T#.\n",
      "#N# chuckles demonically at #T#.\n",
      "#N# chuckes demonically at you.\n",}));
   load_untargeted_msgs(({
      "You chuckle demonically.\n",
      "#N# chuckles demonically.\n"}));
}
