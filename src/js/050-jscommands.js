/**

  Management for the #commands, whcih are commands to be typed at the chat prompt.
  If a line at the chat prompt starts with the # character, this script
  gets engaged.

  */

server.registerHook(Events.N_TEXT, "jsCommands");


function Commands(){
    this.commands = []
}

Commands.prototype.add = function(command){
    this.commands.push(command);
}

Commands.prototype.run = function(prefix, ci, args){
    var found = false;
    for(var i=0; i<this.commands.length; i++){
        var cmd = this.commands[i];
        if(cmd.prefix === prefix){
            found = true;
            cmd.fun(ci, args);
            break;
        }
    }
    if(!found){
        server.sendplayermsg(ci.clientnum, "Command #" + prefix + " not found.");
    }
}

Commands.prototype.getHelp = function(prefix){
    var str = "command not found."
    for(var i=0; i<this.commands.length; i++){
        var cmd = this.commands[i];
        if(cmd.prefix === prefix){
            str = cmd.help;
            break;
        }
    }
    return str;
}

Commands.prototype.getPrefixes = function(){
    var str = "";
    for(var i=0; i<this.commands.length; i++){
        str += " " + this.commands[i].prefix;
    }
    return str;
}

function Command(prefix, fun, help) {
    this.prefix = prefix; //the name of the command
    this.fun = fun //the function to be called to execute the command
    this.help = help //help string
}

/*
  Parse the sent text to find a possible command to be executed
  */
function jsCommands(ci, text, eventdata){
    text = text.trim(); //remove trailing whitespaces

    if(text.charAt(0) === '#'){
        text = text.slice(1)  //remove the initial #
        //server.sendservmsg("In jsCommands with " + text);
        var tokenized = text.split(" ");

        commands.run(tokenized[0], ci, text.substring(tokenized[0].length + 1));

        //make sure 'text' is not propagated to the other clients
        eventdata.bypass = true;
    }
}

var commands = new Commands() //the global commands holder
