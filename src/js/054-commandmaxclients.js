/**

  Handler for the #maxclients command

  #maxclients <n> will change the maximum number of slots

  */

commands.add(new Command("maxclients", commandMaxClients, "#maxclients <n>: Change the maximum number of allowed players to n"));
function commandMaxClients(ci, args){
    if(ci.privilege < Privilege.PRIV_ADMIN)
        server.sendplayermsg(ci.clientnum, "Insufficient privilege.");
    else {
        var n = parseInt(args);
        if(isNaN(n) || n===null || n<1 || n>128){
            server.sendplayermsg(ci.clientnum, "Wrong parameter type to maxclients. Should be an int between 1 and 128.");
        } else {
            server.maxclients(n)
            server.sendplayermsg(ci.clientnum, "New maxclients is " + n);
        }
    }
}
