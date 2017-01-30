vision <player> = spy a player                         30       4th  Shadow
fog <monster> = evoke a fog to choke the monster       30       4th
shield = raise your ac                                 50       4th
feign (simulate player's death)  =  stops monster      40       4th
aid <player> <nn> = direct sps                         nn       4th

animate dead = pet zombie                              ??       5th  Wight
ct <command> = force pet zombie to do <command>         0       5th
peace <zombie> = give the peace to your pet zombie      0       5th
quartz = create a gem of quartz                        10       5th
shadows = summon a horde of shadows                    30       5th
glare <monster> = damage spell                         40       5th

shp <nn> = stores nn/2 hps                           nn/2       6th  Wraith
ssp <nn> = stores nn/2 sps                           nn/2       6th
ghp <nn> = gets back a number of hps                    0       6th
gsp <nn> = gets back a number of sps                    0       6th
stored = shows how many hp/sp you stored                0       6th
evoke = evoke death upon the monsters in the room  20*mon       6th
turn <player> undead = recruit a player in guild        0       6th
lightning <monster> = Summon a black lightining and    50       6th
                      throw it at a monster

chill <monster> =  lowers monster's wc                 40       7th  Spectre
hand = create a spectal hand to fight with u    dam*round       7th
weaken <monster> = Lowers monster's ac                 40       7th
raise <player> = force a dead player to reincarnate   100       7th
fing <monster> = points the finger of death at a      100       7th
                 monster (lowers 10% of hps)            


