emote(str) {
             string message;
             if (!str) return;
             message = NAME + " " + str + "\n";
             write(message);
             say(message);
             return 1;
           }
