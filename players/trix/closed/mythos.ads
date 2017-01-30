Disadvantages:

   <1> Greatest disadvantage is the fact that light does damage.
       [ see hb() function in hunger.c ]
       Basically, for each amount of light in a room the player
       trakes that amount in damage.  Conversely, if a room is
       dark (light is negative) the player will heal. [per hb]
       Since most rooms in Nirvana are lit at least with set_light(1)
       and the light value adds up per light object (often times
       the church's light is about 8 or 9), this becomes a huge 
       disadvantage.
       There are a few spells that reduce this damage for the player
       [refer to guild.spells darkness, myst, true_darkness] but for
       most parts this damage is substantial (in a pk fight all the 
       opponent needs is to carry a couple of lit torches)
       
       Note: this can kill the player. 
       
   <2> Another disadvantage is the fact that intox healing is not allowed
       the actions drink and sip have been blocked off (only allowing
       pepsi and ale- soak heals)
       
   <3> Should one die, a death sequence occurs [ refer to 
       /players/mythos/closed/guild/death dir ] One must combat a demon (or
       figure out the trick) to return to Nirvanian soil.  Else be forever
       trapped in Limbo.
   
   <4>  The Guild Hall is not protected by a shield.  The guild may be
        entered by any and the precious orb stolen.  Should it be stolen
        all guild members take 50 - 150 points of damage (can kill).
        Guild members must protect the orb, and so usage of guild spells
        in PK is only allowed in the guild hall.
        
   <5>  Players must continually sacrifice to use abilities. refer to
        guild.sac and guild.dsc
        
   <6>  Members make oaths that are somewhat detrimental to their play- i.e. 
        limits them (can not use swords, can not party etc).  This must 
        be kept as long as they are in the guild.  Should the oath be
        broken, punishment (atonment) is done.
        
Advantages:

   <1>  Because of high cost (light etc) some guild spells may go above
        what is considered legal in damage.  However, the cost of casting
        spells is balanced and sometimes imbalanced against the player 
        (like hp and sp usage, stat drain, death, etc)
        refer to guild.spells
        
   <2>  The player's mag may go above 20 to a max of 30.  This is done
        by a new stat called 'fae' that is within the guild object.
        For every 2 fae the mag goes up by 1 after mag has been set to 20
        Fae go up to 20, players start with either 1 or 3.
        
        Fae costs:  up to 16    10k xp
                    after 16    50k xp
                    
   <3>  Darkness is not a barrier to sight for the players.
   
   <4>  Diseases and poisons have less of a chance in affecting members.
   

Comments:

 Tasks:
   Each task at the end has a tendency to take a stat or two away from the 
   player.  MOst tasks give the player a sense of foreboding and bad karma.
   All hints for tasks are in the books [ ~/closed/guild/books dir ].
   Tasks are located in ~/closed/guild/tasks dir
 
    1>  To find the guild hall.  Player doesnt even get the guild object
        till this is done.  Initiation only gives player ~/closed/guild/ob.c
        Player must make an oath with some detriment
        Forces exploration.
        must be level 5 average stats of 11
        
    2>  To enter my forest (forbidden forest) [ ~/closed/guild/forest dir ]
        where hostile monsters and etc lie in wait, then find the 'stone' that
        calls the player. Forces exploration.
        must be level 6
        
    3>  Go to the library, find the scribe, and do exactly as it says.
        Teaches obediance and follow through of exact wording of commands
        must be level 7
        
    4>  Must find the Jewel of Darm.  This is located in the castle far into
        the Forbidden forest.  Once found and invoked, the Jewel will freeze 
        the player until the player types in the right response.  The wrong 
        response may do several things: nothing, drain half hp, drain stat,
        death, etc.
        Teaches obediance, forces player to think a certain way, and gives
        pieces of the storyline.
        must be level 8 and fae of 5
        
    5>  Must search in Modern Tokyo and touch Masakado's tomb.  Player then 
        engages in a bout of 3 questions that each time the player answers
        right decreases the chance of death.  If all are correct there is 
        still a 5% chance of death.
        At the end there is a surprise waiting that could kill if player
        isnt quick enough
        Forces thought process and storyline.
        must be level 9 and fae of 5
        
    6>  Player must search deep within the castle (at end of Forbidden forest)
        to find the Demon Keeper.  Demon Keeper's name, short and other
        attribs keep changing every hb, player must figure out the alias of 
        it.  Demon Keeper also stops the fight every so often.
        Once killed player must make an Oath of Vengence in which player must
        go out and kill a powerful monster or monsters- i.e. Kill Icingdeath,
        kill 100 ryo, kill Tiamat.  This Oath must be fulfilled to gain 
        next guild level.
        Forces player to become good at fighting.
        must be level 10 and fae of 5
        
    7>  Player goes to the Black Cavern in the Forest and must then hatch an 
        egg.
        Player must then answer a question.
        Forces storyline.
        must be level 15 and fae of 10
        
    8>  Must find the Hunter.  Hunter can only be found through a complicated 
        ritual concerning a bunch of knives and a magic circle.  The knives
        are each guarded by a pretty tough monster (~/closed/guild/forest/mon/
        guardian.c) and the instructions as to the placement of the knives
        etc is a bit specific.
        Forces storyline an thought process.
        must be level 16 and fae of 10
        
    9>  Player must go the Chamber of Realms and type 'hills'. Player must
        have the broadsword of banshment from saber's realm.  In the hills
        the player must search till a dragon is found, kill the dragon, 
        find the spear and with the broadsword create the Taormin.  The 
        Toarmin is then to be placed on a pedastal where a spirit then 
        attacks the player.  The spirit must be killed.
        Forces storyline and builds up for the next task.
        must be level 17 and fae of 10
        
   10>  Player must go to the Frozen Cave is the Forest and stop the opening
        of the Gates of Ebra.  Once this task is started player can never 
        leave until task is completed, i.e. player home is set to one of 
        rooms, player cant leave like the Limbo/death room.  Player must 
        really use his/her brain- basically a <3/7> quest.
        Teaches storyline and readies the player for culmination of
        story
        must be level 19 + extra level 5 and fae of 15
        
        