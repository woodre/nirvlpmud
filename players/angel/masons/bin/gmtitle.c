#include "defs.h"

status main(string str, int guild_rank) {
  string gender, title;
   
  gender = (string)this_player()->query_gender();

  if(gender == "female") {
    if(guild_rank == 3) 
      { title = "the Secret Mistress"; }
    if(guild_rank == 4) 
      { title = "the Knightess of the Sword"; }
    if(guild_rank == 5) 
      { title = "the Knightess of the East & West"; }
    if(guild_rank == 6) 
      { title = "the Knightess of the Rose Croix"; }
    if(guild_rank == 7)
      { title = "the Grand Pontiff"; }
    if(guild_rank == 8) 
      { title = "the Mistress Ad Vitam"; }
    if(guild_rank == 9)
      { title = "the Prussian Knightess"; }
    if(guild_rank == 10) 
      { title = "the Knightess of the Royal Axe"; }
    if(guild_rank == 11) 
      { title = "the Chief of the Tabernacle"; }
    if(guild_rank == 12)
      { title = "the Princess of the Tabernacle"; }
    if(guild_rank == 13) 
      { title = "the Knightess of the Brazen Serpent"; }
    if(guild_rank == 14)
      { title = "the Princess of Mercy"; }
    if(guild_rank == 15)
      { title = "the Knightess Commander of the Temple"; }
    if(guild_rank == 16)
      { title = "the Knightess of the Sun, Adept"; }
    if(guild_rank == 17)
      { title = "the Grand Scottish Knightess of St. Andrew"; }
    if(guild_rank == 18)
      { title = "the Knightess Kadosh"; }
    if(guild_rank == 19)
      { title = "the Inspector Inquisitor"; }
    if(guild_rank == 20)
      { title = "the Sublime Princess of the Royal Secret"; }
    if(guild_rank >= 30)
      { title = "the Guild Commander"; }
   } else {
  if(guild_rank == 3) { title = "the Secret Master"; }
  if(guild_rank == 4) { title = "the Knight of the Sword"; }
  if(guild_rank == 5) { title = "the Knight of the East & West"; }
  if(guild_rank == 6) { title = "the Knight of the Rose Croix"; }
  if(guild_rank == 7) { title = "the Grand Pontiff"; }
  if(guild_rank == 8) { title = "the Master Ad Vitam"; }
  if(guild_rank == 9) { title = "the Prussian Knight"; }
  if(guild_rank == 10) { title = "the Knight of the Royal Axe"; }
  if(guild_rank == 11) { title = "the Chief of the Tabernacle"; }
  if(guild_rank == 12) { title = "the Prince of the Tabernacle"; }
  if(guild_rank == 13) { title = "the Knight of the Brazen Serpent"; }
  if(guild_rank == 14) { title = "the Prince of Mercy"; }
  if(guild_rank == 15) { title = "the Knight Commander of the Temple"; }
  if(guild_rank == 16) { title = "the Knight of the Sun, Adept"; }
  if(guild_rank == 17) { title = "the Grand Scottish Knight of St. Andrew";}
  if(guild_rank == 18) { title = "the Knight Kadosh"; }
  if(guild_rank == 19) { title = "the Inspector Inquisitor"; }
  if(guild_rank == 20) { title = "the Sublime Prince of the Royal Secret"; }
  if(guild_rank >= 30) { title = "the Guild Commander"; }
  }
  call_other(this_player(),"set_title", title);
  write("You are now: "+(string)this_player()->short()+"\n");
  return 1;
}
